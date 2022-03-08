from fastapi import APIRouter
from starlette.responses import JSONResponse
from app.services.spotify.spotify import SpotifyActions

router = APIRouter(prefix="/spotify")

@router.get("/link")
async def get_link():
    spotify = SpotifyActions()
    return JSONResponse({"link": spotify.oauth_link_generation()}, status_code=200)

@router.get("/code/{code}")
async def get_tokens(code: str):
    spotify = SpotifyActions()
    return JSONResponse(spotify.get_tokens(code), status_code=200)