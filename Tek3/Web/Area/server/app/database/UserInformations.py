from . import GeneralDatabase
from datetime import datetime

class UserInformations(GeneralDatabase.GeneralDatabase):
    def __init__(self):
        self.table = "user_tokens"
    
    def get_user_information_by_id(self, user_id: int):
        req = "SELECT * FROM " + self.table + " WHERE user_id = %s;"
        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (user_id,))
                result = cursor.fetchall()
                return True, result
        except Exception as e:
            print(f'e is == {e}')
            return False, -1
    
    def get_user_specific_information_by_id(self, user_id: int, information_name: str):
        req = "SELECT " + information_name + " FROM " + self.table + " WHERE user_id = %s;"
        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (user_id))
                result = cursor.fetchone()
                return True, result[0]
        except Exception as e:
            print(f'e is == {e}')
            return False, -1

    def create_user_informations(self, user_id: int):
        req = "INSERT INTO " + self.table + " (user_id) VALUES (%s);"
        print(f'[create_user_informations] req == {req}')
        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (user_id,))
                self._db.commit()
                return True, cursor.lastrowid
        except Exception as e:
            print(f'e is == {e}')
            return False, -1

    def update_information(self, user_id: int, information_name: str, value: str):
        req = "UPDATE " + self.table + " SET " + information_name + "_token = %s, " + information_name + "_token_refreshed_at = %s WHERE user_id = %s;"
        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (value, datetime.now(), user_id))
                self._db.commit()
                return True, cursor.lastrowid
        except Exception as e:
            print(f'e is == {e}')
            return False, -1