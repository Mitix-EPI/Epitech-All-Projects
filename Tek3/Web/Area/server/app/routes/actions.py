from pydantic import BaseModel
from fastapi import APIRouter, Header, Request
from starlette.responses import JSONResponse
from app.models.Authenticator import AuthenticationModel
from app.database.ActionsReactions import ActionsReactionsDatabase
from app.database.User import UserDatabase
import json

router = APIRouter(prefix="/actions_reactions")

class DeleteActionModel(BaseModel):
    action_id: int = None

class UpdateActionModel(BaseModel):
    action_id: int = None
    action_reaction: str = None

@router.get("/retrieve")
async def retrieve_actions_reactions(x_token: str = Header(None)):
    token = x_token.split(" ")[1]
    user_db = UserDatabase()
    actions_reactions_db = ActionsReactionsDatabase()

    isLogged = user_db.validate_token(token)
    if isLogged == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, user_id = user_db.get_user_id_by_token(token)
    if status == False:
        return JSONResponse({"error": "Invalid token."}, status_code=401)
    status, actions_reactions = actions_reactions_db.get_actions_reactions_by_user_id(user_id)
    if status == False:
        return JSONResponse({"error": "Couldn't retrieve actions reactions", "actions_reactions": actions_reactions}, status_code=500)
    return JSONResponse({"actions_reactions": actions_reactions})

@router.post("/add_reaction")
async def add_action_reaction(request: Request, x_token: str = Header(None)):
# async def add_action_reaction(addActionModel: Request, x_token: str = Header(None)):
    token = x_token.split(" ")[1]
    user_db = UserDatabase()
    actions_reactions_db = ActionsReactionsDatabase()

    # req_info = await addActionModel.json()
    # print(f'req_info: {req_info}')
    # print(f'addActionModel: {addActionModel}')

    # action_reactions = json.loads(addActionModel)
    action_reactions = await request.json()


    print(f'action_reactions: {action_reactions}')
    action = action_reactions["action"]
    reaction = action_reactions["reaction"]

    print(f'action ==== {action}')
    print(f'reaction ==== {reaction}')

    # stringify action
    _action = json.dumps(action)
    _reaction = json.dumps(reaction)
    print(f'_action ==== "{_action}"')
    print(f'_reaction ==== "{_reaction}"')

    isLogged = user_db.validate_token(token)
    if isLogged == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, user_id = user_db.get_user_id_by_token(token)
    if status == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, action_id = actions_reactions_db.add_actions_reactions(user_id, _action, _reaction)
    if status == False:
        return JSONResponse({"error": "Couldn't add action reaction"}, status_code=500)
    return JSONResponse({"success": "Action reaction added !", "action_id": action_id})

@router.post("/delete_reaction")
async def delete_action_reaction(deleteActionModel: DeleteActionModel, x_token: str = Header(None)):
    token = x_token.split(" ")[1]
    user_db = UserDatabase()
    actions_reactions_db = ActionsReactionsDatabase()

    isLogged = user_db.validate_token(token)
    if isLogged == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, user_id = user_db.get_user_id_by_token(token)
    if status == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, action_id = actions_reactions_db.delete_actions_reactions(user_id, deleteActionModel.action_id)
    if status == False:
        return JSONResponse({"error": "Couldn't delete action reaction"}, status_code=500)
    return JSONResponse({"success": "Action reaction deleted !", "action_id": action_id})

@router.post("/update_reaction")
async def update_action_reaction(updateActionModel: UpdateActionModel, x_token: str = Header(None)):
    token = x_token.split(" ")[1]
    user_db = UserDatabase()
    actions_reactions_db = ActionsReactionsDatabase()

    action_reactions = json.loads(updateActionModel.action_reaction)
    action = action_reactions["action"]
    reaction = action_reactions["reaction"]

    _action = json.dumps(action)
    _reaction = json.dumps(reaction)

    isLogged = user_db.validate_token(token)
    if isLogged == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, user_id = user_db.get_user_id_by_token(token)
    if status == False:
        return JSONResponse({"error": "Invalid token"}, status_code=401)
    status, action_id = actions_reactions_db.update_actions_reactions(user_id, updateActionModel.action_id, _action, _reaction)
    if status == False:
        return JSONResponse({"error": "Couldn't update action reaction"}, status_code=500)
    return JSONResponse({"success": "Action reaction updated !"})