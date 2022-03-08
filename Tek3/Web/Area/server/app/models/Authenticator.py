from pydantic import BaseModel

class AuthenticationModel(BaseModel):
    mail: str = None
    password: str = None
    google_token: str = None
    facebook_token: str = None
    # google_mail: str = None
    # office_mail: str = None
    # facebook_mail: str = None
    office_token: str = None