##
## EPITECH PROJECT, 2020
## WEB_epytodo_2019
## File description:
## api
##

from app import *
from flask import Flask, render_template, request, redirect, url_for, session
from flask import jsonify
from flask import *
from app.models import *


class API(object):

    def __init__(self, app, conn):
        self.app = app
        self.conn = conn
        self.user = User(app, conn)
        self.task = Task(app, conn)

    def default(self, id, all_id): #cette fonction représente les trucs par défaut, mais elle ne fonctionne pas vraiment
        res = {} #elle sert juste de démonstration
        if ('loggedin' not in session):
            res['error'] = "you must be logged in"
        if (id not in all_id):
            res['error'] = "task id does not exist"
        if ('loggedin' in session): #cette condition et ce résultat sont des exemples
            res['result'] = "Bravo, tu es connecté"
        else : #si c'est une autre error qui est présente, il faut renvoyer le résultat ci dessous
            res['error'] = "internal error"
        return json.dumps(res)

    def register(self, username, password):
        res = {}
        if not username.isalnum() or not username or not password:
            res['error'] = "internal error"
        else :
            tmp = self.user.check_account_exists(username)
            if tmp == True:
                res['error'] = "account already exists"
            elif tmp == False:
                self.user.create_account(username, password)
                res['result'] = "account created"
            else:
                res['error'] = "internal error"
        return json.dumps(res)

    def signin(self, username, password):
        res = {}
        if not username.isalnum() or not username or not password:
            res['error'] = "internal error"
        else :
            tmp = self.user.check_signin(username, password)
            if tmp == True:
                res['result'] = "signin successful"
            elif tmp == False :
                res['error'] = "login or password does not match"
            else:
                res['error'] = "internal error"
        return json.dumps(res)

    def signout(self, session):
        res = {}
        session.pop('loggedin', None)
        session.pop('id', None)
        session.pop('username', None)
        res['result'] = "signout successful"
        return json.dumps(res)

    def user_res(self, user_id, session):
        res = {}
        if not session:
            res['error'] = "you must be logged in"
        username = session['username']
        if not username.isalnum() or not username:
            res['error'] = "internal error"
        else:
            if session['loggedin'] == False:
                res['error'] = "you must be logged in"
        return json.dumps(res)

    def task_id(self, task_id):
        res = {}
        if ('loggedin' not in session):
            res['error'] = "you must be logged in"
        else :
            tmp = self.task.check_task_id_exists(task_id)
            if tmp == False:
                res['error'] = "task id does not exist"
            elif tmp == "error":
                res['error'] = "internal error"
        return json.dumps(res)

    def user_task(self, task_id, user_id, title, begin, end, status):
        res = {}
        if ('loggedin' not in session):
            res['error'] = "you must be logged in"
        else :
            tmp = self.task.check_task_id_exists(task_id)
            if tmp == False:
                res['error'] = "task id does not exist"
            elif tmp == "error":
                res['error'] = "internal error"
            else :
                if (not self.task.check_good_format(begin, end)): #TA GRAMS FAUT CHECK SI LE BEGIN ET LE END EST DANS LE FORMAT
                    res['error'] = "internal error"           #YYYY-MM-DD HH:mm:SS
        return json.dumps(res)

    def task_id_mod(self, task_id, title, begin, end, status):
        res = {}
        if ('loggedin' not in session):
            res['error'] = "you must be logged in"
        else :
            tmp = self.task.check_task_id_exists(task_id)
            if tmp == False:
                res['error'] = "task id does not exist"
            elif tmp == "error":
                res['error'] = "internal error"
            else :
                if (not self.task.check_good_format(begin, end)):
                    res['error'] = "internal error"
                else:
                    self.task.modify_task(task_id, title, begin, end, status)
                    res['result'] = "update done"
        return json.dumps(res)

    def task_id_add(self, title, begin, end, status):
        res = {}
        if ('loggedin' not in session):
            res['error'] = "you must be logged in"
        else :
            if (not self.task.check_good_format(begin, end)):
                res['error'] = "internal error"
            else:
                self.task.add_task(title, begin, end, status)
                res['result'] = "new task added"
        return json.dumps(res)

    def task_id_def(self, task_id):
        res = {}
        if ('loggedin' not in session):
            res['error'] = "you must be logged in"
        else :
            tmp = self.task.check_task_id_exists(task_id)
            if (tmp == False):
                res['error'] = "task id does not exist"
            elif (tmp == "error"):
                res['error'] = "internal error"
            else:
                self.task.del_task(task_id)
                res['result'] = "task deleted"
        return json.dumps(res)

