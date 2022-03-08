from pydantic import BaseModel
from fastapi import APIRouter, Header, Request
from starlette.responses import JSONResponse
from app.database.UserInformations import UserInformations
from app.database.User import UserDatabase
import json

router = APIRouter(prefix="/subscribe")

class SubscribeModel(BaseModel):
    token: str = None

@router.post("/{service}")
async def subscribe(service: str, subscribeModel: SubscribeModel, x_token: str = Header(None)):
    print(f'x_token: {x_token}')
    token = x_token.split(" ")[1]
    user_db = UserDatabase()
    user_informations_db = UserInformations()

    isLogged = user_db.validate_token(token)
    if isLogged == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, user_id = user_db.get_user_id_by_token(token)
    if status == False:
        return JSONResponse({"error": "Invalid token."}, status_code=401)
    if service == "google":
        status, row_id = user_informations_db.update_information(user_id, "google", subscribeModel.token)
        if status == False or row_id == -1:
            return JSONResponse({"error": "Couldn't subscribe to google"}, status_code=500)
        else:
            return JSONResponse({"message": "Subscribed to google"})
    elif service == "office":
        status, row_id = user_informations_db.update_information(user_id, "office", subscribeModel.token)
        if status == False or row_id == -1:
            return JSONResponse({"error": "Couldn't subscribe to office"}, status_code=500)
        else:
            return JSONResponse({"message": "Subscribed to office"})
    elif service == "facebook":
        status, row_id = user_informations_db.update_information(user_id, "facebook", subscribeModel.token)
        if status == False or row_id == -1:
            return JSONResponse({"error": "Couldn't subscribe to facebook"}, status_code=500)
        else:
            return JSONResponse({"message": "Subscribed to facebook"})
    elif service == "epitech_intra":
        status, row_id = user_informations_db.update_information(user_id, "epitech_intra", subscribeModel.token)
        if status == False or row_id == -1:
            return JSONResponse({"error": "Couldn't subscribe to epitech's intranet"}, status_code=500)
        else:
            return JSONResponse({"message": "Subscribed to epitech's intranet"})
    elif service == "reddit":
        status, row_id = user_informations_db.update_information(user_id, "reddit", subscribeModel.token)
        if status == False or row_id == -1:
            return JSONResponse({"error": "Couldn't subscribe to reddit"}, status_code=500)
        else:
            return JSONResponse({"message": "Subscribed to reddit"})
    elif service == "spotify":
        status, row_id = user_informations_db.update_information(user_id, "spotify", subscribeModel.token)
        if status == False or row_id == -1:
            return JSONResponse({"error": "Couldn't subscribe to spotify"}, status_code=500)
        else:
            return JSONResponse({"message": "Subscribed to spotify"})
    else:
        return JSONResponse({"error": "Invalid service"}, status_code=400)

@router.get("")
async def get_subscriptions(x_token: str = Header(None)):
    token = x_token.split(" ")[1]
    user_db = UserDatabase()
    user_informations_db = UserInformations()

    isLogged = user_db.validate_token(token)
    if isLogged == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, user_id = user_db.get_user_id_by_token(token)
    if status == False:
        return JSONResponse({"error": "Invalid token."}, status_code=401)
    status, subscriptions = user_informations_db.get_user_information_by_id(user_id)
    if status == False:
        return JSONResponse({"error": "Couldn't get subscriptions."}, status_code=500)
    else:
        # print(f"subs obj ===== {subscriptions}")
        # print(f"subs obj[0] ===== {subscriptions[0]}")
        # print(f"subs obj[0][4] ===== {subscriptions[0][4]}")
        return JSONResponse({
            "google": True if subscriptions[0][2] != None else False,
            "office": True if subscriptions[0][4] != None else False,
            "facebook": True if subscriptions[0][6] != None else False,
            "epitech_intra": True if subscriptions[0][8] != None else False,
            "reddit": True if subscriptions[0][10] != None else False,
            "spotify": True if subscriptions[0][12] != None else False
        }, status_code=200)