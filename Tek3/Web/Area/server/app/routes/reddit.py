from fastapi import APIRouter
from starlette.responses import JSONResponse
from app.services.reddit.reddit import RedditActions

router = APIRouter(prefix="/reddit")

@router.get("/link")
async def get_link():
    reddit = RedditActions()
    return JSONResponse({"link": reddit.oauth_link_generation()}, status_code=200)

@router.get("/code/{code}")
async def get_tokens(code: str):
    reddit = RedditActions()
    return JSONResponse(reddit.get_tokens(code), status_code=200)