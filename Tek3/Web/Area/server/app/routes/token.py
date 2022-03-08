from fastapi import APIRouter
from starlette.responses import JSONResponse
from app.utils.Services import Service
from app.database.User import UserDatabase
from app.database.UserTokens import UserTokensDatabase
from app.models.Token import TokenModel

router = APIRouter(prefix="/token")

@router.get("/get/{service}/{user_id}/{token}")
async def get_token(service: str, user_id: int, token: str) -> JSONResponse:
    user_db = UserDatabase()
    if user_db.compare_token(user_id, token):
        service_id = Service.get_service_id(service)
        if service_id == -1:
            return JSONResponse({"error": "Can't find this service"}, status_code=500)
        token_db = UserTokensDatabase()
        access_token = token_db.get_access_token(user_id, service_id)
        refresh_token = token_db.get_refresh_token(user_id, service_id)
        print(access_token)
        print(refresh_token)
        if access_token != None or refresh_token != None:
            return JSONResponse({"success": "Got token !", "access_token": access_token, "refresh_token": refresh_token})
        else:
            return JSONResponse({"error": "No token found for this user and this service"}, status_code=401)
    else:
        return JSONResponse({"error": "Could not identify the user"}, status_code=500)

@router.post("/set/{service}/{user_id}/{token}")
async def set_token(service: str, user_id: int, token: str, tokens: TokenModel) -> JSONResponse:
    if tokens.access_token != None or tokens.refresh_token != None:
        user_db = UserDatabase()
        if user_db.compare_token(user_id, token):
            service_id = Service.get_service_id(service)
            if service_id == -1:
                return JSONResponse({"error": "Can't find this service"}, status_code=500)
            token_db = UserTokensDatabase()
            if token_db.get_access_token(user_id, service_id) != None:
                if token_db.update_token(user_id, service_id, tokens.access_token, tokens.refresh_token):
                    return JSONResponse({"success": "Tokens updated !"}, status_code=200)
                else:
                    return JSONResponse({"error": "Error when updating tokens on database"}, status_code=500)
            else:
                if token_db.add_new_token(user_id, service_id, tokens.access_token, tokens.refresh_token):
                    return JSONResponse({"success": "Tokens added !"}, status_code=200)
                else:
                    return JSONResponse({"error": "Error when adding new tokens on database"}, status_code=401)
        else:
            return JSONResponse({"error": "Could not identify the user"}, status_code=500)
    else:
        return JSONResponse({"error": "No access token or refresh token was given"})

@router.get("/get-user/{user_token}")
async def get_user_id(user_token: str) -> JSONResponse:
    user_db = UserDatabase()
    status, user = user_db.get_user_by_token(user_token)
    print(f'get_user_id: status = {status} | user = {user}', flush=True)
    user = list(user)
    user_res = {
        "id": user[0],
        "mail": user[1],
        "google_mail": user[3],
        "google_token": user[4],
        "office_mail": user[5],
        "office_token": user[6],
        "facebook_mail": user[7],
        "facebook_token": user[8],
        "token": user[9],
        "token_created_at": user[10].__str__(),
    }
    if status and user != None:
        return JSONResponse({"success": "Got user !", "user": user_res})
    else:
        return JSONResponse({"error": "Could not identify the user"})
