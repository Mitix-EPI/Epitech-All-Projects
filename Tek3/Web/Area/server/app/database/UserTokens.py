from . import GeneralDatabase
from datetime import datetime

class UserTokensDatabase(GeneralDatabase.GeneralDatabase):

    def __init__(self):
        self._table = "user_tokens"

    def add_new_token(self, user_id, api_type, access_token, refresh_token=None):
        req = "INSERT INTO user_tokens (user_id, access_token, refresh_token, api_type, token_refreshed_at) VALUES (%s, %s, %s, %s, %s)"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (user_id, access_token, refresh_token, api_type, datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S')))
                self._db.commit()
        except:
            return False
        return True

    def update_token(self, user_id, api_type, access_token, refresh_token=None):
        req = "UPDATE user_tokens SET access_token = %s, refresh_token = %s WHERE user_id = %s AND api_type = %s"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (access_token, refresh_token, user_id, api_type))
                self._db.commit()
        except:
            return False
        return True

    def get_access_token(self, user_id, api_type):
        req = "SELECT access_token FROM user_tokens WHERE user_id = %s AND api_type = %s"

        with self._get_cursor() as cursor:
            cursor.execute(req, (user_id, api_type))
            result = cursor.fetchone()
            return result[0]

    def get_refresh_token(self, user_id, api_type):
        req = "SELECT refresh_token FROM user_tokens WHERE user_id = %s AND api_type = %s"

        with self._get_cursor() as cursor:
            cursor.execute(req, (user_id, api_type))
            result = cursor.fetchone()
            return result[0]