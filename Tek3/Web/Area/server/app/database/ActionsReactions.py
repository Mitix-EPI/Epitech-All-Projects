from . import GeneralDatabase
from app.utils.JWT import JWT
from app.utils.Password import Password
from datetime import datetime

class ActionsReactionsDatabase(GeneralDatabase.GeneralDatabase):
    def __init__(self):
        self.table = "actions_reactions"

    def get_all_actions_reactions(self):
        req = "SELECT * FROM " + self.table + ";"

        with self._get_cursor() as cursor:
            cursor.execute(req)
            result = cursor.fetchall()
            return result
    
    def get_actions_reactions_by_user_id(self, user_id: int):
        req = "SELECT * FROM " + self.table + " WHERE user_id = %s;"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (user_id,))
                result = cursor.fetchall()
                return True, result
        except Exception as e:
            print(f'e is == {e}')
            return False, -1

    def get_actions_reactions_by_action_id(self, action_id: int):
        req = "SELECT * FROM " + self.table + " WHERE id = %s;"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (action_id,))
                result = cursor.fetchall()
                return True, result
        except:
            return False, -1

    def add_actions_reactions(self, user_id: int, action: str, reaction: str):
        req = "INSERT INTO " + self.table + " (user_id, action, reaction) VALUES (%s, %s, %s);"

        print(f'user_id: {user_id}')
        print(f'action: {action}')
        print(f'reaction: {reaction}')

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (user_id, action, reaction))
                self._db.commit()
                return True, cursor.lastrowid
        except Exception as e:
            print(f'e is == {e}')
            return False, -1

    def update_actions_reactions(self, user_id: int, action_id: int, action: str, reaction: str):
        req = "UPDATE " + self.table + " SET action = %s, reaction = %s WHERE id = %s AND user_id = %s;"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (action, reaction, action_id, user_id))
                self._db.commit()
                return True, cursor.lastrowid
        except:
            return False, -1
    
    def delete_actions_reactions(self, user_id: int, action_id: int):
        req = "DELETE FROM " + self.table + " WHERE id = %s AND user_id = %s;"

        try:
            with self._get_cursor() as cursor:
                cursor.execute(req, (action_id, user_id))
                self._db.commit()
                print(f'[delete_actions_reactions]: deleted action_id: {action_id} and user_id: {user_id}')
                print(f'[delete_actions_reactions]: cursor: {cursor}')
                return True, cursor.lastrowid
        except:
            return False, -1