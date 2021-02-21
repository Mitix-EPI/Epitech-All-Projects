##
## EPITECH PROJECT, 2020
## WEB_epytodo_2019
## File description:
## controller
##

from app import *
from flask import Flask, render_template, request, redirect, url_for, session
from app.models import *
from app.api import *


#res = self.api ...
#flash(json.loads(res))

class Controller_Authentification(object):

    def __init__(self, app, conn):
        self.app = app
        self.conn = conn
        self.api = API(app, conn)

    def register(self, request):
        try :
            username = request.form['username']
            password = request.form['password']
            res = self.api.register(username, password)
            flash(json.loads(res))
            return redirect(url_for('index'))
        except Exception as e:
            print("ERROR1")
            print(e)
            return redirect(url_for('index'))

    def signin(self, request):
        try :
            username = request.form['username']
            password = request.form['password']
            res = self.api.signin(username, password)
            flash(json.loads(res))
            if ('error' in res):
                return redirect(url_for('index'))
            elif ('result' in res):
                return redirect(url_for('user')) #bon chemin -> user
            else:
                print("ERROR2")
                return redirect(url_for('index'))
        except Exception as e:
            print("ERROR3")
            print(e)
            return redirect(url_for('index'))

    def signout(self, session):
        res = self.api.signout(session)
        flash(json.loads(res))
        print("avant?")
        return redirect(url_for('index'))


class Controller_User_and_Task(object):

    def __init__(self, app, conn):
        self.app = app
        self.conn = conn
        self.api = API(app, conn)
        self.task = Task(app, conn)

    def user(self, session):
        try :
            if not 'loggedin' in session:
                res = {}
                res['error'] = 'You must be logged in'
                res = json.dumps(res)
                flash(json.loads(res))
                return redirect(url_for('index'))
            user_id = session['id']
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            if ('error' in res):
                return redirect(url_for('index'))
            nb_tasks = self.task.get_number_tasks_by_user_id(user_id)
            not_started = self.task.get_number_tasks_not_started_by_user_id(user_id)
            in_progress = self.task.get_number_tasks_in_progress_by_user_id(user_id)
            done = self.task.get_number_tasks_done_by_user_id(user_id)
            #manque la redirection vers le HTML
            return render_template('user.html', username = session['username'], nb_tasks = nb_tasks, not_started = not_started, in_progress = in_progress, done = done)
        except Exception as e:
            print(e)
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            return redirect(url_for('index'))

    def user_task(self, session):
        try :
            if not 'loggedin' in session:
                res = {}
                res['error'] = 'You must be logged in'
                res = json.dumps(res)
                flash(json.loads(res))
                return redirect(url_for('index'))
            user_id = session['id']
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            if ('error' in res):
                return redirect(url_for('index'))
            all_tasks = self.task.get_tasks_by_user_id(user_id)
            # for i in range(0, len(all_tasks)):
            #     all_tasks[i][2] = str(all_tasks[i][2].year) + "/" + str(all_tasks[i][2].month) + "/" + str(all_tasks[i][2].day) + " " + str(all_tasks[i][2].hour) + ":" + str(all_tasks[i][2].minute) + ":" + str(all_tasks[i][2].second)
            #     all_tasks[i][3] = str(all_tasks[i][3].year) + "/" + str(all_tasks[i][3].month) + "/" + str(all_tasks[i][3].day) + " " + str(all_tasks[i][3].hour) + ":" + str(all_tasks[i][3].minute) + ":" + str(all_tasks[i][3].second)
            print(all_tasks)
            return render_template('user_task.html', all_tasks=all_tasks)
        except Exception as e:
            print(e)
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            return redirect(url_for('index'))

    def show_task_id(self, session, task_id):
        try :
            if not 'loggedin' in session:
                res = {}
                res['error'] = 'You must be logged in'
                res = json.dumps(res)
                flash(json.loads(res))
                return redirect(url_for('index'))
            user_id = session['id']
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            if ('error' in res):
                return redirect(url_for('index'))
            task = self.task.get_task_by_task_id(task_id)
            return render_template('user_task_id.html', task=task)
        except Exception as e:
            print(e)
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            return redirect(url_for('index'))

    def update_task_id(self, session, task_id, request):
        try :
            if not 'loggedin' in session:
                res = {}
                res['error'] = 'You must be logged in'
                res = json.dumps(res)
                flash(json.loads(res))
                return redirect(url_for('index'))
            user_id = session['id']
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            print('tuurfu1')
            if ('error' in res):
                return redirect(url_for('index'))
            task = self.task.get_task_by_task_id(task_id)
            print('turfu2')
            title = request.form['title']
            begin = request.form['begin']
            end = request.form['end']
            print('turfu3')
            # if self.task.check_good_format(begin, end) == False:
            #     print('turfu4')
            #     res = {}
            #     res['error'] = "Not good date format"
            #     json.dumps(res)
            #     flash(json.loads(res))
            #     return redirect(url_for('user_task'))
            statuss = request.form['status']
            print('turfu5')
            if title != task[1] and title:
                title = title
            else:
                title = task[1]

            if begin != task[1] and begin:
                begin = begin
            else:
                begin = task[2]

            if end != task[1] and end:
                end = end
            else:
                end = task[3]

            if statuss != task[1] and statuss:
                statuss = statuss
            else:
                statuss = task[4]
            print('turfu6')
            self.task.modify_task(task_id, title, begin, end, statuss)
            print('turfu7')
            res = {}
            res['result'] = "update done"
            res = json.dumps(res)
            flash(json.loads(res))
            return redirect(url_for('user_task'))
        except Exception as e:
            print(e)
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            return redirect(url_for('index'))

    def add_task(self, session, request):
        res = {}
        try :
            if not 'loggedin' in session:
                res = {}
                res['error'] = 'You must be logged in'
                res = json.dumps(res)
                flash(json.loads(res))
                return redirect(url_for('index'))
            user_id = session['id']
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            if ('error' in res):
                print('redir1')
                return redirect(url_for('index'))
            print('1')
            title = request.form['title']
            begin = request.form['begin']
            end = request.form['end']
            print('2')
            # if self.task.check_good_format(begin, end) == False:
            #     print('3')
            #     # res['error'] = "Not good date format"
            #     # json.dumps(res)
            #     # flash(json.loads(res))
            #     return redirect(url_for('user_task'))
            print('Alex cest un bg')
            status = request.form['status']
            if not begin:
                begin = "0000-00-00 00:00:00"
            if not end:
                end = "0000-00-00 00:00:00"
            self.task.add_task(user_id, title, begin, end, status)
            print('4')
            res = {}
            res['result'] = "new task added"
            res = json.dumps(res)
            flash(json.loads(res))
            print('done')
            return redirect(url_for('user_task'))
        except Exception as e:
            print('failed')
            print(e)
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            return redirect(url_for('index'))
        
    def del_task(self, session, request, task_id):
        res = {}
        try:
            if not 'loggedin' in session:
                res = {}
                res['error'] = 'You must be logged in'
                res = json.dumps(res)
                flash(json.loads(res))
                return redirect(url_for('index'))
            user_id = session['id']
            self.task.del_task(task_id)
            res['result'] = "task deleted"
            res = json.dumps(res)
            flash(json.loads(res))
            return redirect(url_for('user_task'))
        except Exception as e:
            print(e)
            res = self.api.user_res(user_id, session)
            flash(json.loads(res))
            return redirect(url_for('index'))



