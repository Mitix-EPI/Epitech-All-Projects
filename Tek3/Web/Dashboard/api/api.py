from os import error
from flask import Flask, render_template, request, redirect, url_for, session
from flask import jsonify
from passlib.hash import pbkdf2_sha256 as sha256
import requests
import argparse
import spotipy
from pyyoutube import Api as YoutubeApi
import json

def generateHash(password):
    return sha256.hash(password)

def verifyHash(password, hash):
    return sha256.verify(password, hash)

caches_folder = "./.spotify_caches/"

def session_cache_path():
    return caches_folder + session.get('uuid')

defaultCover = "https://marketplace.canva.com/EAENvp21inc/1/0/1600w/canva-simple-work-linkedin-banner-qt_TMRJF4m0.jpg"

class API(object):

    def __init__(self, app, conn):
        self.app = app
        self.conn = conn
        
    def isAlreadyLoginWithService(self, idOAuth2, service):
        try:
            self.conn.ping()  # reconnecting mysql
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM user WHERE idOAuth2 = '%s' and service = '%s'" % (idOAuth2, service))
            account = cursor.fetchone()
            cursor.close()
            print("Account : ", str(account), flush=True)
            if (account):
                return True
            else:
                return False
        except Exception as e :
            print("error : isAlreadyLoginWithService", flush=True)
            print(e, flush=True)
            return True

    def getIdFromEmail(self, email):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM user WHERE email = '%s'" % (email))
            account = cursor.fetchone()
            cursor.close()
            if (account):
                return str(account[0])
            else:
                return "error"
        except Exception as e :
            print("error : getIdFromEmail\n", str(e), flush=True)
            return "error"

    def checkAccountExists(self, email):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM user WHERE email = '%s'" % (str(email)))
            account = cursor.fetchone()
            cursor.close()
            if (account):
                return True
            else:
                return False
        except Exception as e :
            print("error : check_account_exists\n", str(e), flush=True)
            return "error"
        
    def createAccountOAuth2(self, idOAuth2, email, service):
        try:
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO `user` (`email`, `idOAuth2`, `service`, `urlCover`) VALUES (%s, %s, %s, %s)", (email, idOAuth2, service, defaultCover))
            self.conn.commit()
            cursor.close()
            return True
        except Exception as e :
            print("error : Create Account\n", str(e), flush=True)
            return False
        
    def getAccountOAuth2(self, email, service):
        try:
            self.conn.ping()  # reconnecting mysql
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM user WHERE email = '%s' AND service = '%s'" % (email, service))
            account = cursor.fetchone()
            cursor.close()
            print(account, flush=True)
            res = {
                "id": account[0],
                "email": account[1],
                "password": account[2],
                "idOAuth2": account[3],
                "service": account[4],
                "urlCover": account[5]
            }
            return res
        except Exception as e :
            print("error : getAccountOAuth2 -> ", str(e), "\n", flush=True)
            return "error"

    def createAccount(self, email, password):
        try:
            hashedPassword = generateHash(password)
            service = "None"
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO `user` (`email`, `password`, `service`, `urlCover`) VALUES (%s, %s, %s, %s)", (email, hashedPassword, service, defaultCover))
            self.conn.commit()
            cursor.close()
            return True
        except Exception as e :
            print("error : Create Account\n", str(e), flush=True)
            return False

    def loginAccount(self, email, password):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM `user` WHERE `email` = %s", (email))
            account = cursor.fetchone()
            cursor.close()
            if (account):
                if verifyHash(password, account[2]):
                    session['loggedin'] = True
                    session['id'] = account[0]
                    session['email'] = account[1]
                    res['result'] = "Login successful"
                    res['id'] = account[0]
                    res['user'] = self.getAccountOAuth2(email, 'None')
                    return res
                res['error'] = "Login or password does not match"
                return res
            else:
                res['error'] = "Account doesn't exist"
                return res
        except Exception as e:
            print("error : check_signin\n", str(e), flush=True)
            res['error'] = "internal error"
            return res

    def signout(self):
        res = {}
        session.pop('loggedin', None)
        session.pop('id', None)
        session.pop('email', None)
        res['result'] = "signout successful"
        return json.dumps(res)

    def register(self, email, password):
        res = {}
        isExists = self.checkAccountExists(email)
        if isExists:
            res['error'] = "Account already exists"
        else:
            self.createAccount(email, password)
            res['result'] = "Account created"
        return jsonify(res)

    def login(self, email, password):
        res = self.loginAccount(email, password)
        return jsonify(res)
    
    def login_oauth2(self, idOAuth2, email, service):
        res = {}
        try:
            print('login_oauth2', idOAuth2, service, email, flush=True)
            if (self.isAlreadyLoginWithService(idOAuth2, service) == True):
                print("Already Login / Login Successful", flush=True)
                user = self.getAccountOAuth2(email, service)
                if user != "error":
                    res['result'] = "Login Successful"
                    res['user'] = user
                else:
                    res['error'] = "Error"
            elif (self.isAlreadyLoginWithService(idOAuth2, service) == False):
                if self.createAccountOAuth2(idOAuth2, email, service):
                    res['result'] = "Account created + Login Successful"
                    res['user'] = self.getAccountOAuth2(email, service)
                else:
                    res['error'] = "Error registering OAuth2"
            else:
                res["error"] = "Error login_oauth2 x isAlreadyLoginWithService"
            return jsonify(res);
        except Exception as e:
            print("error : login_oauth2\n", str(e), flush=True)
            res['error'] = "internal error"
            return res

    def add_widget(self, idUser, service, title, coords, date, city, urlProfile):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO `widget` (`user_id`, `service`, `title`, `city`, `date`, `urlProfile`,`x`, `y`) VALUES (%s, %s, %s, %s, %s, %s, %s, %s)", (idUser, service, title, city, date, urlProfile, coords['x'], coords['y']))
            self.conn.commit()
            cursor.close()
            res['result'] = 'Widget added successfully'
            res['widgets'] = self.get_widgets_by_id(idUser)['widgets']
            return res
        except Exception as e:
            print("error : add_widget\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
        
    def get_widgets_by_id(self, idUser):
        res = {}
        try:
            res['widgets'] = []
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM widget WHERE user_id = '%s'" % (idUser))
            widgets = cursor.fetchall()
            cursor.close()
            if (widgets):
                for widget in widgets:
                    res['widgets'].append({
                        'id': widget[0],
                        'service': widget[2],
                        'title': widget[3],
                        'city': widget[4],
                        'date': widget[5],
                        'urlProfile': widget[6],
                        'x': widget[7],
                        'y': widget[8]
                    })
                res['result'] = 'Widgets found successfully'
            else:
                res['result'] = "No Widgets found"
            return res
        except Exception as e:
            print("error : get_widgets_by_id\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
        
    def delete_widget_by_id(self, idWidget):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("DELETE FROM widget WHERE id = '%s'" % (idWidget))
            self.conn.commit()
            cursor.close()
            res['widgets'] = self.get_widgets_by_id(session['id'])['widgets']
            res['result'] = 'Widget deleted successfully'
            return res
        except Exception as e:
            print("error : delete_widget_by_id\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
        
    def save_widget_position(self, idWidget, position):
        res = {}
        try:
            x = position['x']
            y = position['y']
            cursor = self.conn.cursor()
            cursor.execute("UPDATE widget SET x=%i, y=%i WHERE id='%s'" % (int(x), int(y), idWidget))
            self.conn.commit()
            cursor.close()
            res['result'] = 'Widget position saved successfully'
            return res
        except Exception as e:
            print("error : save_widget_position\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
            
    def get_photo_of_today_nasa(self):
      NASA_API_KEY = "vZR2hNKNdZqOtapcpWWIJhv7SvhAMmFPF1rmOOAr"
      link = "https://api.nasa.gov/planetary/apod?api_key=" + NASA_API_KEY
      resp = requests.get(url=link)
      data = resp.json()
      return data
  
    def get_photo_of_the_day_nasa(self, date):
        NASA_API_KEY = "vZR2hNKNdZqOtapcpWWIJhv7SvhAMmFPF1rmOOAr"
        link = "https://api.nasa.gov/planetary/apod?api_key=" + NASA_API_KEY + "&date=" + date
        resp = requests.get(url=link)
        data = resp.json()
        return data
    
    def search_nasa_image(self, search):
        res = {}
        try:
            link = "https://images-api.nasa.gov/search?q=" + search + '&media_type=image'
            resp = requests.get(url=link)
            data = resp.json()
            res['result'] = data['collection']['items'][0]
            return res
        except Exception as e:
            print("error : save_url_profile\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
    
    def save_url_profile(self, idWidget, urlProfile):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("UPDATE widget SET urlProfile='%s' WHERE id='%s'" % (urlProfile, idWidget))
            self.conn.commit()
            cursor.close()
            res['result'] = 'UrlProfile saved successfully'
            return res
        except Exception as e:
            print("error : save_url_profile\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
    
    def save_date_nasa_photo_widget(self, idWidget, date):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("UPDATE widget SET date='%s' WHERE id='%s'" % (date, idWidget))
            self.conn.commit()
            cursor.close()
            res['result'] = 'Date saved successfully'
            return res
        except Exception as e:
            print("error : save_date_nasa_photo_widget\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
  
    def update_url_cover(self, userId, urlCover):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("UPDATE user SET urlCover = '%s' WHERE id = '%s'" % (urlCover, userId))
            self.conn.commit()
            cursor.close()
            res['result'] = "OK"
            return res
        except MySQLdb.IntegrityError:
            print("failed to insert values")
            res['error'] = "Failed to insert values"
            return res
        except Exception as e:
            print("error : update_url_cover\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
        
    def get_user(self, userId):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM user WHERE id = '%s'" % (userId))
            account = cursor.fetchone()
            cursor.close()
            if (account):
                res = {
                    "id": account[0],
                    "email": account[1],
                    "password": account[2],
                    "idOAuth2": account[3],
                    "service": account[4],
                    "urlCover": account[5]
                }
            else:
                res['error'] = "Account doesn't exist"
            return res
        except Exception as e:
            print("error : get_user\n", str(e), flush=True)
            res['error'] = "internal error"
            return res

    def get_latest_playlist(self, authToken):
      res = {}
      try:
        sp = spotipy.Spotify(auth=authToken)
        return sp.current_user_playlists(limit=1)['items'][0]
      except Exception as e:
        print("error : get_latest_playlist\n", str(e), flush=True)
        res['error'] = "internal error"
        return res

    def get_recents_tracks(self, authToken, tracksNumber):
      res = {}
      if not tracksNumber:
          tracksNumber = 3
      try:
        sp = spotipy.Spotify(auth=authToken)
        res = sp.current_user_recently_played(limit=tracksNumber)
        return res
      except Exception as e:
        print("error : get_recents_tracks\n", str(e), flush=True)
        res['error'] = "internal error"
        return res
    
    def get_current_weather(self, city):
        res = {}
        apiKey = 'e381bdc76673f44388c308956e09f15f'
        link = 'https://api.openweathermap.org/data/2.5/weather?q=' + city + '&appid=' + apiKey
        try:
            resp = requests.get(url=link)
            data = resp.json()
            data['temperature'] = int(float(data['main']['temp']) - 273.15)
            return data
        except Exception as e:
            print("error : get_current_weather\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
        
    def get_current_weather_by_coords(self, lat, lon):
        res = {}
        apiKey = 'e381bdc76673f44388c308956e09f15f'
        link = 'https://api.openweathermap.org/data/2.5/weather?lat=' + lat + '&lon=' + lon + '&appid=' + apiKey
        try:
            resp = requests.get(url=link)
            data = resp.json()
            data['temperature'] = int(float(data['main']['temp']) - 273.15)
            return data
        except Exception as e:
            print("error : get_current_weather_by_coords\n", str(e), flush=True)
            res['error'] = "internal error"
            return res

    def save_city_weather_widget(self, idWidget, city):
        res = {}
        try:
            cursor = self.conn.cursor()
            cursor.execute("UPDATE widget SET city='%s' WHERE id='%s'" % (city, idWidget))
            self.conn.commit()
            cursor.close()
            res['result'] = 'City saved successfully'
            return res
        except Exception as e:
            print("error : save_city_weather_widget\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
        
    def get_forecast_weather(self, city):
        res = {}
        apiKey = 'e97561e3e83949a8a01104032212611'
        link = 'http://api.weatherapi.com/v1/forecast.json?key=' + apiKey + '&q=' + city + '&days=3&aqi=no&alerts=no'
        try:
            resp = requests.get(url=link)
            data = resp.json()
            return data
        except Exception as e:
            print("error : get_current_weather\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
            
    def get_currency_convertor(self, first, second):
        res = {}
        CURRENCY_API_KEY = "2c08c7dfd312fa2156bb"
        link = 'https://free.currconv.com/api/v7/convert?q=' + first + '_' + second + ',' +  second + '_' + first + '&compact=ultra&apiKey=' + CURRENCY_API_KEY
        try:
            resp = requests.get(url=link)
            data = resp.json()
            res['result'] = data
            return res
        except Exception as e:
            print("error : get_currency_convertor\n", str(e), flush=True)
            res['error'] = "internal error"
            return res

    def get_cryptocurrency_convertor(self, first, second):
        res= {}
        link = 'https://min-api.cryptocompare.com/data/price?fsym='+ first + '&tsyms=' + second
        try:
            resp = requests.get(url=link)
            data = resp.json()
            res['result'] = data
            return res
        except Exception as e:
            print("error : get_cryptocurrency_convertor\n", str(e), flush=True)
            res['error'] = "internal error"
            return res

    def get_number_subscribers_youtube_channel(self, youtubeChannelName):
        res = {}
        apiKey = 'AIzaSyBOCLFDDz4wHFmatH-fPxsjjRnBfPzcOFQ'
        try:
            api = YoutubeApi(api_key=apiKey)
            r = api.search_by_keywords(q=youtubeChannelName, search_type=["channel"], count=2, limit=2)
            idChannel = r.items[0].snippet.channelId
            channel = api.get_channel_info(channel_id=idChannel)
            if (channel.items):
                res['result'] = {
                    'subscriberCount': channel.items[0].statistics.subscriberCount,
                    'channel': channel.items[0].snippet
                }
            else:
                res['result'] = {
                    'error': 'Youtube url not updated',
                    'msg': 'Channel not found.'
                }
            return jsonify(res)
        except Exception as e:
            print("error : get_number_subscribers_youtube_channel\n", str(e), flush=True)
            res['error'] = "internal error"
            res['message'] = 'Youtube Data API exceded'
            return res
        
    def get_channel_ID(self, youtubeChannelName):
        res = {}
        apiKey = 'AIzaSyBOCLFDDz4wHFmatH-fPxsjjRnBfPzcOFQ'
        try:
            api = YoutubeApi(api_key=apiKey)
            r = api.search_by_keywords(q=youtubeChannelName, search_type=["channel"], count=2, limit=2)
            idChannel = r.items[0].snippet.channelId
            if (idChannel):
                res['result'] = idChannel
            else:
                res['result'] = {
                    'error': 'Youtube url not updated',
                    'msg': 'Channel not found.'
                }
            return jsonify(res)
        except Exception as e:
            print("error : get_channel_ID\n", str(e), flush=True)
            res['error'] = "internal error"
            res['message'] = 'Youtube Data API exceded'
            return res
        
    def get_latest_video(self, youtubeChannelName):
        res = {}
        apiKey = 'AIzaSyBOCLFDDz4wHFmatH-fPxsjjRnBfPzcOFQ'
        try:
            api = YoutubeApi(api_key=apiKey)
            r = api.search_by_keywords(q=youtubeChannelName, search_type=["channel"], count=2, limit=2)
            idChannel = r.items[0].snippet.channelId
            link = 'https://www.googleapis.com/youtube/v3/search?key=' + apiKey + '&channelId=' + idChannel + '&part=snippet,id&order=date&maxResults=2'
            resp = requests.get(url=link)
            data = resp.json()
            if (data):
                res['result'] = data['items'][0]
            else:
                res['result'] = {
                    'error': 'Youtube url not updated',
                    'msg': 'Channel not found.'
                }
            return jsonify(res)
        except Exception as e:
            print("error : get_channel_ID\n", str(e), flush=True)
            res['error'] = "internal error"
            res['message'] = 'Youtube Data API exceded'
            return res
        
    def getGithubAccount(self, githubNameAccount):
        res = {}
        githubApiKey = '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'
        try:
            link = 'https://api.github.com/search/users?q=' + githubNameAccount
            resp = requests.get(url=link)
            data = resp.json()
            if (data):
                print(data, flush=True)
                if (data['total_count'] > 0):
                    res['result'] = data['items'][0];
                    return res
                else:
                    res['result'] = 'Github account not found'
                    return res
            else:
                res['error'] = 'Error response github api'
                return res
        except Exception as e:
            print("error : getGithubAccount\n", str(e), flush=True)
            res['error'] = "internal error"
            return res
