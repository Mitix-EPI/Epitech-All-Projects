import jwt

class JWT():
    @staticmethod
    def encrypt_jwt(mail):
        encoded_jwt = jwt.encode({"mail": mail}, "area_lgcar", algorithm="HS256")
        return encoded_jwt

    def encrypt_jwt2(random: str):
        encoded_jwt = jwt.encode({"random": random}, "area_lgcar", algorithm="HS256")
        return encoded_jwt

    def decrypt_jwt(encoded_jwt):
        decoded_jwt = jwt.decode(encoded_jwt, "area_lgcar", algorithms=["HS256"])
        return decoded_jwt