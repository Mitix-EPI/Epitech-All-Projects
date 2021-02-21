from flask import Flask
import os
from app.connection import *
import locale

app = Flask(__name__, template_folder="./views/templates", static_folder="./views/static")
app.secret_key = os.urandom(24)
app.config.from_object('config')

conn = ConnectionDataBase(app)

def get_connection():
    return conn.get_connection()

from app.views import views
