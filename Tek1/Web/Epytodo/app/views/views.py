# from flask import render_template
# from flask import request
from flask import Flask, render_template, request, redirect, url_for, session
import time


from app.controller import *
from flask import jsonify
import pymysql as sql
from app import *

@app.route('/', methods=['GET'])
def index():
    session.pop('loggedin', None)
    session.pop('id', None)
    session.pop('username', None)
    return render_template('index.html')

@app.route('/register', methods=['POST'])
def register(): #rajouter partout des try except pour éviter des erreurs
    controller = Controller_Authentification(app, get_connection())
    return controller.register(request)

@app.route('/signin', methods=['POST'])
def signin():
    controller = Controller_Authentification(app, get_connection())
    return controller.signin(request)

@app.route('/signout', methods=['POST'])
def signout():
    controller = Controller_Authentification(app, get_connection())
    return controller.signout(session)

@app.route('/user', methods=['GET'])
def user():
    controller = Controller_User_and_Task(app, get_connection())
    return controller.user(session)

@app.route('/user/task', methods=['GET'])
def user_task():
    controller = Controller_User_and_Task(app, get_connection())
    return controller.user_task(session)

@app.route('/user/task/<int:task_id>', methods=['GET', 'POST'])
def user_task_id(task_id):
    if request.method == 'GET':
        controller = Controller_User_and_Task(app, get_connection())
        return controller.show_task_id(session, task_id)
        # Ici c'est pour afficher uniquement la tâche en gros et pouvoir écrire l'update
        # donc c'est un formulaire pour modifier une tâche
    if request.method == 'POST':
        controller = Controller_User_and_Task(app, get_connection())
        return controller.update_task_id(session, task_id, request)
        #Ici c'est quand tu vas appuyer sur l'update et donc valider l'update dans la DB
        #là c'est quand on va appuyer sur le joli boutton et qu'on va récupérer toutes les donées
        #du formulaire

@app.route('/user/task/add', methods=['POST'])
def user_task_add():
    controller = Controller_User_and_Task(app, get_connection())
    return controller.add_task(session, request)

@app.route('/user/task/del/<int:task_id>', methods=['POST'])
def user_task_del(task_id):
    controller = Controller_User_and_Task(app, get_connection())
    return controller.del_task(session, request, task_id)