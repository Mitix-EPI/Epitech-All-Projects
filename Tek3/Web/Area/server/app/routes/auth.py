from datetime import datetime
from fastapi import APIRouter
from starlette.responses import JSONResponse
from app.models.Authenticator import AuthenticationModel
from app.database.User import UserDatabase
from app.database.UserInformations import UserInformations
from app.utils.Utils import Utils
from app.utils.JWT import JWT
import requests

router = APIRouter(prefix="/auth")

@router.post("/login")
async def login(authentication: AuthenticationModel):
    user_db = UserDatabase()
    user_infos_db = UserInformations()
    time = datetime.now()
    new_token = JWT.encrypt_jwt2(Utils.get_random_string(8))
    if authentication.mail == None and authentication.password == None:
        if authentication.google_token != None:
            res = requests.get("https://www.googleapis.com/oauth2/v1/userinfo?alt=json", headers={
                "Authorization": "Bearer " + authentication.google_token
            })
            res = res.json()

            if ("email" in res):
                result = user_db.check_existant_google_account(res['email'], authentication.google_token)
            else:
                return JSONResponse({"error": "Invalid OAuth access token data."}, status_code=190)
            if result != None:
                status, newToken = user_db.update_token(new_token, datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S'), result[0])
                if status == False:
                    return JSONResponse({"error": "Couldn't update token"}, status_code=500)
                status, row_id = user_infos_db.update_information(result[0], "google", authentication.google_token)
                if status == False or row_id == -1:
                    return JSONResponse({"error": "Couldn't subscribe to google"}, status_code=500)
                return JSONResponse({"success": "Connected !", "token": newToken, "id": result[0]})
            else:
                result = user_db.register_google_account(res['email'], authentication.google_token)
                if result != None and result == True:
                    status, id = user_db.get_user_id_by_mail(res['email'], "google")
                    if status == False:
                        return JSONResponse({"error": "Couldn't get user id"}, status_code=500)
                    user_infos_db.create_user_informations(id)
                    status, row_id = user_infos_db.update_information(id, "google", authentication.google_token)
                    if status == False or row_id == -1:
                        return JSONResponse({"error": "Couldn't subscribe to google"}, status_code=500)
                    status, token = user_db.get_token_by_user_id(id)
                    return JSONResponse({"Success": "Registered !", "token": token})
                else:
                    return JSONResponse({"error": "Invalid google mail or Internal error"}, status_code=401)
        elif authentication.office_token != None:
            res = requests.get("https://graph.microsoft.com/v1.0/me", headers={
                "Authorization": "Bearer " + authentication.office_token
            })
            res = res.json()

            if ("mail" in res):
                result = user_db.check_existant_office_account(res['mail'], authentication.office_token)
            else:
                return JSONResponse({"error": "Invalid OAuth access token data."}, status_code=190)
            if result != None:
                status, newToken = user_db.update_token(new_token, datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S'), result[0])
                if status == False:
                    return JSONResponse({"error": "Couldn't update token"}, status_code=500)
                status, row_id = user_infos_db.update_information(result[0], "office", authentication.office_token)
                if status == False or row_id == -1:
                    return JSONResponse({"error": "Couldn't subscribe to office"}, status_code=500)
                return JSONResponse({"success": "Connected !", "token": newToken, "id": result[0]})
            else:
                result = user_db.register_office_account(res['mail'], authentication.office_token)
                if result != None and result == True:
                    status, id = user_db.get_user_id_by_mail(res['mail'], "office")
                    if status == False:
                        return JSONResponse({"error": "Couldn't get user id"}, status_code=500)
                    user_infos_db.create_user_informations(id)
                    status, row_id = user_infos_db.update_information(id, "office", authentication.office_token)
                    if status == False or row_id == -1:
                        return JSONResponse({"error": "Couldn't subscribe to office"}, status_code=500)
                    status, token = user_db.get_token_by_user_id(id)
                    return JSONResponse({"Success": "Registered !", "token": token})
                else:
                    return JSONResponse({"error": "Internal Error"}, status_code=500)
        elif authentication.facebook_token != None:
            res = requests.get("https://graph.facebook.com/me/?fields=id,name,email", headers={
                "Authorization": "Bearer " + authentication.facebook_token
            })
            res = res.json()

            print("res", res)
            if ("email" in res):
                result = user_db.check_existant_facebook_account(res['email'], authentication.facebook_token)
            else:
                return JSONResponse({"error": "Invalid OAuth access token data."}, status_code=190)
            print("Debug", result)
            if result != None:
                status, newToken = user_db.update_token(new_token, datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S'), result[0])
                if status == False:
                    return JSONResponse({"error": "Couldn't update token"}, status_code=500)
                status, row_id = user_infos_db.update_information(result[0], "facebook", authentication.facebook_token)
                if status == False or row_id == -1:
                    return JSONResponse({"error": "Couldn't subscribe to facebook"}, status_code=500)
                return JSONResponse({"success": "Connected !", "token": newToken, "id": result[0]})
            else:
                result = user_db.register_facebook_account(res['email'], authentication.facebook_token)
                print(result)
                if result != None and result == True:
                    status, id = user_db.get_user_id_by_mail(res['email'], "facebook")
                    if status == False:
                        return JSONResponse({"error": "Couldn't get user id"}, status_code=500)
                    user_infos_db.create_user_informations(id)
                    status, row_id = user_infos_db.update_information(id, "facebook", authentication.facebook_token)
                    if status == False or row_id == -1:
                        return JSONResponse({"error": "Couldn't subscribe to facebook"}, status_code=500)
                    status, token = user_db.get_token_by_user_id(id)
                    return JSONResponse({"Success": "Registered !", "token": token})
        return JSONResponse({"error": "Missing authentication values"})
    elif authentication.mail != None and authentication.password != None:
        result = user_db.check_existant_account(authentication.mail, authentication.password)
        if result != None:
            status, newToken = user_db.update_token(new_token, datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S'), result[0])
            if status == False:
                return JSONResponse({"error": "Couldn't update token"}, status_code=500)
            return JSONResponse({"success": "Connected !", "token": newToken, "id": result[0]})
        else:
            return JSONResponse({"error": "User is not registered or invalid mail or password"}, status_code=401)
    else:
        return JSONResponse({"error": "A value is missing"}, status_code=500)

@router.post("/register")
async def register(authentication: AuthenticationModel):
    user_db = UserDatabase()
    user_infos_db = UserInformations()
    if authentication.mail == None and authentication.password == None:
        if authentication.google_token != None:
            res = requests.get("https://www.googleapis.com/oauth2/v1/userinfo?alt=json", headers={
                "Authorization": "Bearer " + authentication.google_token
            })
            res = res.json()

            result = user_db.register_google_account(res['email'], authentication.google_token)
            if result != None and result == True:
                status, id = user_db.get_user_id_by_mail(res['email'], "google")
                if status == False:
                    return JSONResponse({"error": "Couldn't get user id"}, status_code=500)
                user_infos_db.create_user_informations(id)
                status, token = user_db.get_token_by_user_id(id)
                return JSONResponse({"Success": "Registered !", "token": token})
            else:
                return JSONResponse({"error": "User is already registered"}, status_code=401)
        elif authentication.office_token != None:
            res = requests.get("https://graph.microsoft.com/v1.0/me", headers={
                "Authorization": "Bearer " + authentication.office_token
            })
            res = res.json()

            result = user_db.register_office_account(res['mail'], authentication.office_token)
            if result != None and result == True:
                status, id = user_db.get_user_id_by_mail(res['mail'], "office")
                if status == False:
                    return JSONResponse({"error": "Couldn't get user id"}, status_code=500)
                user_infos_db.create_user_informations(id)
                status, token = user_db.get_token_by_user_id(id)
                return JSONResponse({"Success": "Registered !", "token": token})
            else:
                return JSONResponse({"error": "User is already registered"}, status_code=401)
        elif authentication.facebook_token != None:
            res = requests.get("https://graph.facebook.com/me/?fields=id,name,email", headers={
                "Authorization": "Bearer " + authentication.facebook_token
            })
            res = res.json()
            print(res)
            if ('email' in res):
                result = user_db.register_facebook_account(res['email'], authentication.facebook_token)
            else:
                return JSONResponse({"error": "Invalid OAuth access token data."}, status_code=190)
            print(result)
            if result != None and result == True:
                status, id = user_db.get_user_id_by_mail(res['email'], "facebook")
                if status == False:
                    return JSONResponse({"error": "Couldn't get user id"}, status_code=500)
                user_infos_db.create_user_informations(id)
                status, token = user_db.get_token_by_user_id(id)
                return JSONResponse({"Success": "Registered !", "token": token})
            else:
                return JSONResponse({"error": "User is already registered"}, status_code=401)
    elif authentication.mail != None and authentication.password != None:
        result = user_db.register_account(authentication.mail, authentication.password)
        if result != None and result == True:
            status, id = user_db.get_user_id_by_mail(authentication.mail, "mail")
            if status == False:
                return JSONResponse({"error": "Couldn't get user id"}, status_code=500)
            user_infos_db.create_user_informations(id)
            status, token = user_db.get_token_by_user_id(id)
            return JSONResponse({"Success": "Registered !", "token": token})
        else:
            return JSONResponse({"error": "User is already registered"}, status_code=401)
    else:
        return JSONResponse({"error": "A value is missing"}, status_code=500)