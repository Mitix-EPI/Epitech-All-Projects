from . import GeneralDatabase
from app.utils.JWT import JWT
from app.utils.Password import Password
from datetime import datetime

class UserDatabase(GeneralDatabase.GeneralDatabase):

    def __init__(self):
        self._table = "users"

    def check_existant_google_account(self, google_mail: str, google_token: str):
        req = "SELECT id, token FROM users WHERE google_mail = %s;"
        # req = "SELECT id, token FROM users WHERE 'google_mail' = %s AND 'google_token' = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (google_mail))
                result = cursor.fetchone()
                return result
        except Exception as e:
            print(f'E is ====== {e}')
            return None

    def check_existant_office_account(self, office_mail: str, office_token: str):
        req = "SELECT id, token FROM users WHERE office_mail = %s;"
        # req = "SELECT id, token FROM users WHERE 'office_mail' = %s AND 'office_token' = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (office_mail))
                result = cursor.fetchone()
                return result
        except Exception as e:
            print(f'E is ====== {e}')
            return None
        
    def check_existant_facebook_account(self, facebook_mail: str, facebook_token: str):
        req = "SELECT id, token FROM users WHERE facebook_mail = %s;"
        # req = "SELECT id, token FROM users WHERE 'facebook_mail' = %s AND 'facebook_token' = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (facebook_mail))
                result = cursor.fetchone()
                return result
        except Exception as e:
            print(f'E is ====== {e}')
            return None

    def check_existant_account(self, mail: str, password: str):
        req = "SELECT id, token FROM users WHERE mail = %s AND password = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (mail, Password.encrypt(password)))
                result = cursor.fetchone()
                return result
        except Exception as e:
            print(f'E is ====== {e}')
            return None

    def register_account(self, mail: str, password: str):
        req = "INSERT INTO users (mail, password, token, token_created_at) VALUES (%s, %s, %s, %s);"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (mail, Password.encrypt(password), JWT.encrypt_jwt(mail), datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S')))
                self._db.commit()
        except:
            return False
        return True

    def register_google_account(self, google_mail: str, google_token: str):
        req = "INSERT INTO users (google_mail, google_token, token, token_created_at) VALUES (%s, %s, %s, %s)"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (google_mail, google_token, JWT.encrypt_jwt(google_mail), datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S')))
                self._db.commit()
        except:
            return False
        return True

    def register_facebook_account(self, facebook_mail: str, facebook_token: str):
        req = "INSERT INTO users (facebook_mail, facebook_token, token, token_created_at) VALUES (%s, %s, %s, %s);"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (facebook_mail, facebook_token, JWT.encrypt_jwt(facebook_mail), datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S')))
                self._db.commit()
        except Exception as e:
            print(e)
            return False
        return True

    def register_office_account(self, office_mail: str, office_token: str):
        req = "INSERT INTO users (office_mail, office_token, token, token_created_at) VALUES (%s, %s, %s, %s);"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (office_mail, office_token, JWT.encrypt_jwt(office_mail), datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S')))
                self._db.commit()
        except:
            return False
        return True

    def update_token(self, token: str, token_created_at: str, id: int):
        req = "UPDATE users SET token = %s, token_created_at = %s WHERE id = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (token, token_created_at, id))
                self._db.commit()
                return True, token
        except:
            return False, ""

    def compare_token(self, token: str):
        req = "SELECT token FROM users WHERE token = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (str(token)))
                result = cursor.fetchone()
                if result[0] != token:
                    return False
        except:
            return False
        return True

    def validate_token(self, token: str):
        req = "SELECT * FROM users WHERE token = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (token))
                result = cursor.fetchone()
                # Check if token was created more than 1 hour ago
                # print(f'result ]===[ "{result}"')
                # print(f'result[10] ]===[ "{result[10]}"')
                val = (datetime.utcnow() - datetime.strptime(str(result[10]), '%Y-%m-%d %H:%M:%S')).total_seconds()
                print(f'val == {val}')
                if (datetime.utcnow() - datetime.strptime(str(result[10]), '%Y-%m-%d %H:%M:%S')).total_seconds() > 3600:
                    return False
                return True
        except Exception as e:
            print(f'E is == {e}')
            return False, -1

    def get_user_id_by_token(self, token: str):
        req = "SELECT * FROM users WHERE token = %s"

        print(f'token ===== {token}')
        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (token))
                result = cursor.fetchone()
                return True, result[0]
        except Exception as e:
            print(f'E is ====== {e}')
            return False, -1

    def get_user_by_id(self, id: int):
        req = "SELECT * FROM users WHERE id = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (id))
                result = cursor.fetchone()
                return True, result
        except:
            return False, -1
    
    def get_user_by_token(self, token: str):
        req = "SELECT * FROM users WHERE token = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (token))
                result = cursor.fetchone()
                return True, result
        except:
            return False, -1
    
    def get_user_id_by_mail(self, mail: str, type: str):
        req = ""
        if type == 'google':
            req = "SELECT * FROM users WHERE google_mail = %s"
        elif type == 'office':
            req = "SELECT * FROM users WHERE office_mail = %s"
        elif type == 'facebook':
            req = "SELECT * FROM users WHERE facebook_mail = %s"
        else:
            req = "SELECT * FROM users WHERE mail = %s"
        
        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (mail))
                result = cursor.fetchone()
                return True, result[0]
        except:
            return False, -1

    def get_token_by_user_id(self, user_id: int):
        req = "SELECT * FROM users WHERE id = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (user_id))
                result = cursor.fetchone()
                return True, result[9]
        except:
            return False, -1