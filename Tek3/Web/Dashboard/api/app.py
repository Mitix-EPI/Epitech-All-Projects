import sys
import os
import json
from pymysql import NULL
import random
import string
import time
import requests
from flask import Flask, session, abort, redirect, jsonify, request, url_for, make_response
from connection import ConnectionDatabase
from api import API
from datetime import datetime, timedelta
from google.oauth2 import id_token
from google_auth_oauthlib.flow import Flow
from pip._vendor import cachecontrol
import google.auth.transport.requests
from flask_cors import CORS
from flask_session import Session
import uuid
from flask_restful_swagger import swagger
from flask_restful import Api
from flask_selfdoc import Autodoc

app = Flask(__name__)
secretKey = os.urandom(64)
app.config['SECRET_KEY'] = secretKey
app.config['SESSION_TYPE'] = 'filesystem'
app.config['SESSION_FILE_DIR'] = './.flask_session/'
app.secret_key = secretKey

cors = CORS(app)

Session(app)

auto = Autodoc(app)

caches_folder = "./.spotify_caches/"

if not os.path.exists(caches_folder):
    os.makedirs(caches_folder)

def session_cache_path():
    return caches_folder + session.get('uuid')

os.environ["OAUTHLIB_INSECURE_TRANSPORT"] = "1"

try:
    pass
    conn = ConnectionDatabase(app)
except:
    pass

def get_connection():
    return conn.get_connection()
  
def get_random_string(length):
    # choose from all lowercase letter
    letters = string.ascii_lowercase
    result_str = ''.join(random.choice(letters) for i in range(length))
    print("Random string of length", length, "is:", result_str)

@app.route("/")
@auto.doc()
def index():
    return 'Flask API'

def login_is_required(function):
  def wrapper(*args, **kwargs):
      if "user_id" not in session:
          abort(401) # Authentication required
      else:
          return function()
  return wrapper

@app.route('/users/register', methods=['POST'])
@auto.doc()
def register():
  '''
  Route : /users/register -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    email = NULL
    password = NULL
    keys = list(data.keys())
    if 'email' in keys:
      email = data["email"]
    if 'password' in keys:
      password = data["password"]
    if email != NULL and password != NULL:    
      return api.register(email, password)
    else:
      return { 'error': 'Error register. Not good args' }
  except Exception as e:
      print(str(e), flush=True)
      error = {
          'status': 'Error',
          'message': 'Error register'
      }
      return jsonify(error)
    
@app.route('/users/get-user', methods=['GET'])
@auto.doc()
def get_user():
  '''
  Route : /users/get-user -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    userId = request.args['id']
    return api.get_user(userId)
  except Exception as e:
    print("/users/get-user", flush=True)
    print(str(e), flush=True)
    error = {
        'error': 'Error',
        'status': 'Error',
        'message': 'Error get user'
    }
    return jsonify(error)

@app.route('/users/authenticate', methods=['POST'])
@auto.doc()
def authenticate():
  '''
  Route : /users/authenticate -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    idOAuth2 = NULL
    email = NULL
    password = NULL
    keys = list(data.keys())
    if 'email' in keys:
      email = data["email"]
    if 'password' in keys:
      password = data["password"]
    if 'idOAuth2' in keys:
      idOAuth2 = data["idOAuth2"]
    if 'service' in keys:
      service = data["service"]
    if 'urlCover' in keys:
      urlCover = data["urlCover"]
    print(idOAuth2, email, password, flush=True)
    if (idOAuth2 == NULL and email != NULL and password != NULL):
      return api.login(email, password)
    elif idOAuth2 == NULL or email == NULL or service == NULL or urlCover == NULL:
      return {
        'error': 'Error',
        'message': 'Missing Argument'
      }
    else:
      return api.login_oauth2(idOAuth2, email, service)
  except Exception as e:
      print("/users/authenticate", flush=True)
      print(str(e), flush=True)
      error = {
          'error': 'Error',
          'status': 'Error',
          'message': 'Error authenticate'
      }
      return jsonify(error)
    
@app.route('/widget/add-widget', methods=['POST'])
@auto.doc()
def add_widget():
  '''
  Route : /widget/add-widget -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    idUser = ''
    service = ''
    title = ''
    coords = ''
    date = ''
    city = ''
    urlProfile = ''
    keys = list(data.keys())
    if 'id' in keys:
      idUser = data["id"]
    if 'service' in keys:
      service = data["service"]
    if 'title' in keys:
      title = data["title"]
    if 'coords' in keys:
      coords = data["coords"]
    if 'date' in keys:
      date = data["date"]
    if 'city' in keys:
        city = data["city"]
    # if 'urlProfile' in keys:
    #       urlProfile = data["urlProfile"]
    return api.add_widget(idUser, service, title, coords, date, city, urlProfile)
  except Exception as e:
      print("/widget/add-widget", flush=True)
      print(str(e), flush=True)
      error = {
          'error': 'Error',
          'status': 'Error',
          'message': 'Error /widget/add-widget'
      }
      return jsonify(error)
    
@app.route('/widget/get-widgets-by-user', methods=['POST'])
@auto.doc()
def get_widgets_by_user():
  '''
  Route : /widget/get-widgets-by-user -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    idUser = NULL
    keys = list(data.keys())
    if 'id' in keys:
      idUser = data["id"]
    return api.get_widgets_by_id(idUser)
  except Exception as e:
      print("/widget/add-widget", flush=True)
      print(str(e), flush=True)
      error = {
          'error': 'Error',
          'status': 'Error',
          'message': 'Error /widget/get-widgets_by_id'
      }
      return jsonify(error)    

@app.route('/widget/delete-widget', methods=['POST'])
@auto.doc()
def delete_widget():
  '''
  Route : /widget/delete-widget -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    idWidget = NULL
    keys = list(data.keys())
    if 'id' in keys:
      idWidget = data["id"]
    return api.delete_widget_by_id(idWidget)
  except Exception as e:
      print("/widget/add-widget", flush=True)
      print(str(e), flush=True)
      error = {
          'error': 'Error',
          'status': 'Error',
          'message': 'Error /widget/delete-widget'
      }
      return jsonify(error)
    
@app.route('/widget/save-widget-position', methods=['POST'])
@auto.doc()
def save_widget_position():
  '''
  Route : /widget/save-widget-position -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    idWidget = NULL
    position = NULL
    keys = list(data.keys())
    if 'id' in keys:
      idWidget = data["id"]
    if 'position' in keys:
      position = data["position"]
    return api.save_widget_position(idWidget, position)
  except Exception as e:
      print("/widget/add-widget", flush=True)
      print(str(e), flush=True)
      error = {
          'error': 'Error',
          'status': 'Error',
          'message': 'Error /widget/save-widget-position'
      }
      return jsonify(error)
    
@app.route('/widget/save-url-profile', methods=['POST'])
@auto.doc()
def save_url_profile():
  '''
  Route : /widget/save-url-profile -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    idWidget = NULL
    urlProfile = NULL
    keys = list(data.keys())
    if 'id' in keys:
      idWidget = data["id"]
    if 'urlProfile' in keys:
      urlProfile = data["urlProfile"]
    return api.save_url_profile(idWidget, urlProfile)
  except Exception as e:
      print("/widget/save-url-profile", flush=True)
      print(str(e), flush=True)
      error = {
          'error': 'Error',
          'status': 'Error',
          'message': 'Error /widget/save-url-profile'
      }
      return jsonify(error)

    
@app.route("/nasa/photo-of-today", methods=['GET'])
@auto.doc()
def get_photo_of_today():
  '''
  Route : /nasa/photo-of-today -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    return api.get_photo_of_today_nasa()
  except Exception as e:
    return { 'error': 'Error', 'message': 'Error get photo of today' }
  
@app.route("/nasa/photo-of-the-day", methods=['GET'])
@auto.doc()
def get_photo_of_the_day():
  '''
  Route : /nasa/photo-of-the-day -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    date = request.args['date']
    return api.get_photo_of_the_day_nasa(date)
  except Exception as e:
    return { 'error': 'Error', 'message': 'Error get photo of the day' }
  
@app.route("/nasa/save-date-to-nasa-photo-widget", methods=['POST'])
@auto.doc()
def save_date_nasa_photo_widget():
  '''
  Route : /nasa/save-date-to-nasa-photo-widget -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    widgetId = data['id']
    date = data['date']
    return api.save_date_nasa_photo_widget(widgetId, date)
  except Exception as e:
    return { 'error': 'Error', 'message': 'Error /nasa/save_date_nasa_photo_widget/' }
  
@app.route("/nasa/search-image", methods=['GET'])
@auto.doc()
def search_nasa_image():
  '''
  Route : /nasa/search-image -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    search = request.args['search']
    return api.search_nasa_image(search)
  except Exception as e:
    return { 'error': 'Error', 'message': 'Error /nasa/search-image' }
  
@app.route("/users/update-url-cover", methods=['POST'])
@auto.doc()
def update_url_cover():
  '''
  Route : /users/update-url-cover -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    userId = data["id"]
    urlCover = data['urlCover']
    return api.update_url_cover(userId, urlCover)
  except Exception as e:
    return { 'error': 'Error', 'message': 'Error update url cover' }

@app.route("/spotify/get-latest-playlist", methods=['GET'])
@auto.doc()
def get_latest_playlist():
  '''
  Route : /spotify/get-latest-playlist -> Method=GET
  '''
  res = {}
  api = API(app, get_connection())
  try:
    authToken = request.args['authToken']
    return api.get_latest_playlist(authToken)
  except Exception as e:
    print(e);
    return { 'error': 'Error', 'message': 'Error /spotify/get_latest_playlist/' }
  
@app.route("/spotify/get-recent-tracks", methods=['GET'])
@auto.doc()
def get_recents_tracks():
  '''
  Route : /spotify/get-latest-playlist -> Method=GET
  '''
  res = {}
  api = API(app, get_connection())
  try:
    tracksNumber = NULL
    authToken = request.args['authToken']
    if request.args['tracksNumber']:
        tracksNumber = request.args['tracksNumber']
    return api.get_recents_tracks(authToken, tracksNumber)
  except Exception as e:
    print(e, flush=True);
    return { 'error': 'Error', 'message': 'API Data Exceeded' }
  
@app.route("/weather/get-current-weather", methods=['GET'])
@auto.doc()
def get_current_weather():
  '''
  Route : /weather/get-current-weather -> Method=GET
  '''
  res = {}
  api = API(app, get_connection())
  try:
    city = request.args['city']
    return api.get_current_weather(city)
  except Exception as e:
    print(e);
    return { 'error': 'Error', 'message': 'Error /weather/get-current-weather' }

@app.route("/weather/get-current-weather-by-coords", methods=['GET'])
@auto.doc()
def get_current_weather_by_coords():
  '''
  Route : /weather/get-current-weather-by-coords -> Method=GET
  '''
  res = {}
  api = API(app, get_connection())
  try:
    lat = request.args['lat']
    lon = request.args['lon']
    return api.get_current_weather_by_coords(lat, lon)
  except Exception as e:
    print(e);
    return { 'error': 'Error', 'message': 'Error /weather/get_current_weather_by_coords' }
  
@app.route("/weather/save-city-to-weather-widget", methods=['POST'])
@auto.doc()
def save_city_weather_widget():
  '''
  Route : /weather/save-city-to-weather-widget -> Method=POST
  '''
  api = API(app, get_connection())
  try:
    data = json.loads(request.data.decode("utf-8"))
    widgetId = data['id']
    city = data['city']
    return api.save_city_weather_widget(widgetId, city)
  except Exception as e:
    return { 'error': 'Error', 'message': 'Error /weather/save-city-to-weather-widget' }
  
  
@app.route("/weather/get-forecast-weather", methods=['GET'])
@auto.doc()
def get_forecast_weather():
  '''
  Route : /weather/get-forecast-weather -> Method=GET
  '''
  res = {}
  api = API(app, get_connection())
  try:
    city = request.args['city']
    return api.get_forecast_weather(city)
  except Exception as e:
    print(e);
    return { 'error': 'Error', 'message': 'Error /weather/get-forecast-weather' }

@app.route("/currency/currency-convertor", methods=['GET'])
@auto.doc()
def get_currency_convertor():
  '''
  Route : /currency/currency-convertor -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    baseCurrency = request.args['baseCurrency']
    targetCurrency = request.args['targetCurrency']
    return api.get_currency_convertor(baseCurrency, targetCurrency)
  except Exception as e:
    print(e);
    return { 'error': 'Error', 'message': 'Error /currency/currency-convertor' }

@app.route("/currency/crypto-convertor", methods=['GET'])
@auto.doc()
def get_cryptocurrency_convertor():
  '''
  Route : /currency/crypto-convertor -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    baseCryptoCurrency = request.args['baseCryptoCurrency']
    targetCryptoCurrency = request.args['targetCryptoCurrency']
    return api.get_cryptocurrency_convertor(baseCryptoCurrency, targetCryptoCurrency)
  except Exception as e:
    print(e);
    return { 'error': 'Error', 'message': 'Error /currency/crypto-convertor' }
  
@app.route("/youtube/number-subscribers", methods=['GET'])
@auto.doc()
def get_number_subscribers():
  '''
  Route : /youtube/number-subscribers -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    channelName = request.args['channelName']
    return api.get_number_subscribers_youtube_channel(channelName)
  except Exception as e:
    print(e, flush=True);
    return { 'error': 'Error', 'message': 'Error /youtube/number-subscribers' }
  
@app.route("/youtube/get-channel-id", methods=['GET'])
@auto.doc()
def get_channel_ID():
  '''
  Route : /youtube/get-channel-id -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    channelName = request.args['channelName']
    return api.get_channel_ID(channelName)
  except Exception as e:
    print(e, flush=True);
    return { 'error': 'Error', 'message': 'Error /youtube/get-channel-id' }
  
@app.route("/youtube/get-last-video", methods=['GET'])
@auto.doc()
def get_latest_video():
  '''
  Route : /youtube/get-last-video -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    channelName = request.args['channelName']
    return api.get_latest_video(channelName)
  except Exception as e:
    print(e, flush=True);
    return { 'error': 'Error', 'message': 'Error /youtube/get-last-video' }
  
@app.route("/github/get-github-account", methods=['GET'])
@auto.doc()
def get_github_account():
  '''
  Route : /github/get-github-account -> Method=GET
  '''
  api = API(app, get_connection())
  try:
    accountName = request.args['accountName']
    return api.getGithubAccount(accountName)
  except Exception as e:
    print(e, flush=True);
    return { 'error': 'Error', 'message': 'Error /github/get-github-account' }

@app.route("/protected_area")
@auto.doc()
@login_is_required
def protected_area():
  '''
  Route : /protected_area
  '''
  return 'Protected !<a href="/logout">Logout</a>'
  
@app.route("/about.json", methods=['GET'])
@auto.doc()
def about():
  '''
  Route : /about.json -> Method=GET
  '''
  res = {}
  res['client'] = {
    'host': request.remote_addr,
  }
  res['server'] = {
    'current_time': int(time.time()),
    'services' : [
      {
        'name': 'Weather',
        'widgets': [
          {
            'name': 'Current weather',
            'description': 'Display the temperature for a city today',
            'params': [{
              'name': 'city',
              'type': 'string'
            }]
          },
          {
            'name': 'Forecast weather',
            'description': 'Display the temperature for a city with 3 days of prediction',
            'params': [{
              'name': 'city',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'Spotify',
        'widgets': [
          {
            'name': 'Recent tracks',
            'description': 'Display your Spotify latest played tracks',
            'params': [{
              'name': 'authToken',
              'type': 'string'
            }]
          },
          {
            'name': 'Weekly playlist',
            'description': 'Show you your spotify weekly recommanded playlist',
            'params': [{
              'name': 'authToken',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'NASA',
        'widgets': [
          {
            'name': 'Astronomy Picture Of the Day',
            'description': 'Display the latest NASA picture',
          },
          {
            'name': 'Astronomy Picture Of X Day',
            'description': 'Display the APOD of a selected date',
            'params': [{
              'name': 'date',
              'type': 'string'
            }]
          },
          {
            'name': 'Search Image',
            'description': 'Search images on NASA database',
            'params': [{
              'name': 'search',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'CurrencyConverter',
        'widgets': [
          {
            'name': 'Price converter',
            'description': 'Convert the base currency to the target currency',
            'params': [{
              'name': 'baseCurrency',
              'type': 'string'
            },
            {
              'name': 'targetCurrency',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'Youtube',
        'widgets': [
          {
            'name': 'Number of subscribers',
            'description': 'Show youtube channel informations',
            'params': [{
              'name': 'channelName',
              'type': 'string'
            }]
          },
          {
            'name': 'Last video',
            'description': 'Show the last video of a youtuber',
            'params': [{
              'name': 'channelName',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'Github',
        'widgets': [
          {
            'name': 'Github profile stat',
            'description': 'Show the statistics of github account',
            'params': [{
              'name': 'channelName',
              'type': 'string'
            }]
          },
          {
            'name': 'Laguages stat',
            'description': 'Display the language stats of github account',
            'params': [{
              'name': 'channelName',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'CurrencyConverter',
        'widgets': [
          {
            'name': 'Price converter',
            'description': 'Convert the base currency to the target currency',
            'params': [{
              'name': 'baseCurrency',
              'type': 'string'
            },
            {
              'name': 'targetCurrency',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'CurrencyCryptoConverter',
        'widgets': [
          {
            'name': 'Price converter',
            'description': 'Convert the crypto base currency to the crypto target currency',
            'params': [{
              'name': 'baseCryptoCurrency',
              'type': 'string'
            },
            {
              'name': 'targetCryptoCurrency',
              'type': 'string'
            }]
          }
        ]
      },
      {
        'name': 'Youtube',
        'widgets': [
          {
            'name': 'Number of subscribers',
            'description': 'Show youtube channel informations',
            'params': [{
              'name': 'channelName',
              'type': 'string'
            }]
          },
          {
            'name': 'Last video',
            'description': 'Show the last video of a youtuber',
            'params': [{
              'name': 'channelName',
              'type': 'string'
            }]
          }
        ]
      }
    ]
  }
  return jsonify(res)

@app.route('/documentation')
def documentation():
  '''
  Route : /documentation
  '''
  return auto.html()

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=8089, debug=True)
