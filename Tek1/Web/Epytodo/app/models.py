##
## EPITECH PROJECT, 2020
## WEB_epytodo_2019
## File description:
## models
##

from app import *
from flask import Flask, render_template, request, redirect, url_for, session

class User(object):

    def __init__(self, app, conn):
        self.app = app
        self.conn = conn

    def create_account(self, username, password):
        try:
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO %s (username, password) VALUES ('%s', '%s')" % ("user", username, password))
            self.conn.commit()
            cursor.close()
        except Exception as e :
            print("error : check_account_exists\n" + e)
            return "error"

    def check_account_exists(self, username):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM user WHERE username = '%s'" %(username))
            account = cursor.fetchone()
            cursor.close()
            if (account):
                return True
            else:
                return False
        except Exception as e :
            print("error : check_account_exists\n" + e)
            return "error"

    def check_signin(self, username, password):
        try:
            cursor = self.conn.cursor()
            cursor.execute("""SELECT * FROM user WHERE username = %s AND password = %s""", (username, password))
            account = cursor.fetchone()
            print(account)
            cursor.close()
            if (account):
                session['loggedin'] = True
                session['id'] = account[0]
                session['username'] = account[1]
                return True
            else :
                return False
        except Exception as e:
            print("error : check_signin\n" + e)
            return "error"


class Task(object):

    def __init__(self, app, conn):
        self.app = app
        self.conn = conn

    def check_task_id_exists(self, task_id):
        try :
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM task WHERE task_id = '%s'" % (task_id))
            account = cursor.fetchone()
            cursor.close()
            if (account):
                return True
            else :
                return False
        except Exception as e:
            print("error : check_task_id_exists\n" + e)
            return "error"

    def check_good_format(self, begin, end):
        tmp_begin = begin.split(" ")
        tmp_end = end.split(" ")

        if len(tmp_begin) != 2 or len(tmp_end) != 2:
            return False

        tmp2_begin = tmp_begin[0].split("-")
        tmp2_end = tmp_end[0].split("-")

        if len(tmp2_begin) != 3 or len(tmp2_end) != 3:
            return False

        tmp3_begin = tmp_begin[1].split(":")
        tmp3_end = tmp_end[1].split(":")

        del tmp_begin
        del tmp_end

        if len(tmp3_begin) != 3 or len(tmp3_end) != 3:
            return False

        try:
            int(tmp2_begin[0])
            int(tmp2_begin[1])
            int(tmp2_begin[2])
            int(tmp2_end[0])
            int(tmp2_end[1])
            int(tmp2_end[2])
            int(tmp3_begin[0])
            int(tmp3_begin[1])
            int(tmp3_begin[2])
            int(tmp3_end[0])
            int(tmp3_end[1])
            int(tmp3_end[2])
        except:
            return False

        if len(tmp2_begin[0]) != 4 or len(tmp2_begin[1]) != 2 or len(tmp2_begin[2]) != 2 or len(tmp2_end[0]) != 4 or len(tmp2_end[1]) != 2 or len(tmp2_end[2]) != 2:
            return False
        if len(tmp3_begin[0]) != 2 or len(tmp3_begin[1]) != 2 or len(tmp3_begin[2]) != 2 or len(tmp3_end[0]) != 2 or len(tmp3_end[1]) != 2 or len(tmp3_end[2]) != 2:
            return False

        del tmp2_begin
        del tmp2_end
        del tmp3_begin
        del tmp3_end

        return True

        #return True if both are well formated
        #return False if one of them is not (or both)

        #YYYY-MM-DD HH:mm:SS  TMP2 = YYYY-MM-DD  |   TMP3 = HH:mm:SS

    def modify_task(self, task_id, title, begin, end, status):
        cursor = self.conn.cursor()
        cursor.execute("SELECT * FROM task WHERE task_id = '%s'" % (task_id))
        cursor.execute("UPDATE task SET title = '%s', begin = '%s', end = '%s', status = '%s'" % (title, begin, end, status))
        self.conn.commit()
        cursor.close()

    def get_number_tasks_by_user_id(self, user_id):
        tasks = self.get_tasks_by_user_id(user_id)
        return len(tasks)

    def get_number_tasks_not_started_by_user_id(self, user_id):
        tasks = []
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT fk_task_id FROM %s WHERE fk_user_id = '%d'" % ("user_has_task", int(user_id)))
            lyst = list(cursor.fetchall())
            cursor.close()
            for id in lyst:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM %s WHERE task_id = '%s' AND status = '%s'" % ("task", id[0], "not started"))
                try :
                    task = list(cursor.fetchall()[0])
                    tasks.append(task)
                    cursor.close()
                except:
                    cursor.close()
                print("après")
            return (len(tasks))
        except Exception as e:
            print("notstarted" + str(e))
            return (False)

    def get_number_tasks_in_progress_by_user_id(self, user_id):
        tasks = []
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT fk_task_id FROM %s WHERE fk_user_id = '%d'" % ("user_has_task", int(user_id)))
            lyst = list(cursor.fetchall())
            cursor.close()
            for id in lyst:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM %s WHERE task_id = '%s' AND status = '%s'" % ("task", id[0], "in progress"))
                try :
                    task = list(cursor.fetchall()[0])
                    tasks.append(task)
                    cursor.close()
                except:
                    cursor.close()
            return (len(tasks))
        except Exception as e:
            print("progress " + str(e))
            return (False)

    def get_number_tasks_done_by_user_id(self, user_id):
        tasks = []
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT fk_task_id FROM %s WHERE fk_user_id = '%d'" % ("user_has_task", int(user_id)))
            lyst = list(cursor.fetchall())
            cursor.close()
            for id in lyst:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM %s WHERE task_id = '%s' AND status = '%s'" % ("task", id[0], "done"))
                try :
                    task = list(cursor.fetchall()[0])
                    tasks.append(task)
                    cursor.close()
                except:
                    cursor.close()
                print("après")
            return (len(tasks))
        except Exception as e:
            print("done" + str(e))
            return (False)

    def get_tasks_by_user_id(self, user_id):
        tasks = []
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT fk_task_id FROM %s WHERE fk_user_id = '%d'" % ("user_has_task", int(user_id)))
            lyst = list(cursor.fetchall())
            cursor.close()
            print(lyst)
            for id in lyst:
                print(id)
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM %s WHERE task_id = '%d'" % ("task", id[0]))
                try :
                    task = list(cursor.fetchall()[0])
                    tasks.append(task)
                    cursor.close()
                except:
                    cursor.close()
            return (tasks)
        except Exception as e:
            print("get_tasks" + str(e))
            return False

    def get_task_by_task_id(self, task_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM %s WHERE task_id = '%d'" % ("task", task_id))
            try :
                task = list(cursor.fetchall()[0])
                cursor.close()
            except:
                cursor.close()
            return (task)
        except Exception as e:
            print("get_tasks" + str(e))
            return False

    def add_task(self, user_id, title, begin, end, status):
        try:
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO %s (title, begin, end, status) VALUES ('%s', '%s', '%s', '%s')" % ("task", title, begin, end, status))
            self.conn.commit()
            id = cursor.lastrowid
            cursor.close()
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO %s (fk_user_id, fk_task_id) VALUES ('%d', '%d')" % ("user_has_task", user_id, id))
            self.conn.commit()
            cursor.close()
        except Exception as e :
            print("add\n" + str(e))
            return "error"

    def del_task(self, task_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("DELETE FROM task WHERE task_id = '%d'" % (task_id))
            self.conn.commit()
            cursor.close()
            cursor = self.conn.cursor()
            cursor.execute("DELETE FROM user_has_task WHERE fk_task_id = '%d'" % (task_id))
            self.conn.commit()
            cursor.close()
        except Exception as e:
            print("error \n" + str(e))
            return "error"
