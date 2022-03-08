from pydantic import BaseModel

class TokenModel(BaseModel):
    access_token: str = None
    refresh_token: str = None