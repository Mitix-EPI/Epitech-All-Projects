import pymysql

class GeneralDatabase():
    _db = pymysql.connect(
            host="db",
            user="admin",
            password="admin",
            database="area"
        )

    def __init__(self):
        pass

    def _get_cursor(self):
        return self._db.cursor()

    def get_table(self):
        return self._table

    # def __del__(self):
        # self._db.close()