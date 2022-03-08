import hashlib
from base64 import b64encode

class Password():
    @staticmethod
    def encrypt(password):
        hash_pass = hashlib.sha512(password.encode("ascii") + b"area_lgcar").digest()
        for i in range(0, 10):
            hash_pass = hashlib.sha512(hash_pass + b"area_lgcar_security").digest()
        hash_pass = b64encode(hash_pass).decode("utf-8")
        return hash_pass