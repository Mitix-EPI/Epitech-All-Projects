##
## EPITECH PROJECT, 2020
## WEB_epytodo_2019
## File description:
## connection
##

from app import *
import pymysql as sql

class ConnectionDataBase(object):

    def __init__(self, app):
        self.app = app
        self.conn = None
        self.set_connection(app.config)

    def set_connection(self, config):
        try:
            if config['DATABASE_SOCK'] == None:
                self.conn = sql.connect(host = config['DATABASE_HOST'],
                                         user = config['DATABASE_USER'],
                                         password = config['DATABASE_PASS'],
                                         db = config['DATABASE_NAME'])
            else:
                self.conn = sql.connect(unix = config['DATABASE_SOCK'],
                                         user = config['DATABASE_USER'],
                                         password = config['DATABASE_PASS'],
                                         db = config['DATABASE_NAME'])
            if self.conn == None:
                raise Exception
        except (Exception) as error:
            print(error)
            exit(84)

    def get_connection(self):
        return (self.conn)