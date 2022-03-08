import os
from uuid import uuid4
from datetime import datetime
import urllib.parse
import requests

state_list = []

class SpotifyActions():
    def __init__(self) -> None:
        self.base_link = "https://api.spotify.com/"
        self.redirect_uri = "http://localhost:8081/auth/spotify"
        self.token_json = None

    def oauth_link_generation(self) -> str:
        state = uuid4()
        state_list.append({"state": state, "created": datetime.now()})
        base_url = "https://accounts.spotify.com/authorize?"
        params = {
            "client_id": os.getenv("SPOTIFY_CLIENT"),
            "response_type": "code",
            "state": state,
            "redirect_uri": self.redirect_uri,
            "scope": "user-read-private user-read-email",
        }
        url = base_url + urllib.parse.urlencode(params)
        return url

    def get_tokens(self, code: str):
        client_auth = requests.auth.HTTPBasicAuth(os.getenv("SPOTIFY_CLIENT"), os.getenv("SPOTIFY_API"))
        post_data = {"grant_type": "authorization_code", "code": code, "redirect_uri": self.redirect_uri}
        headers = {"User-agent": "AREA Spotify API"}

        response = requests.post("https://accounts.spotify.com/api/token", headers=headers, auth=client_auth, data=post_data)
        self.token_json = response.json()
        return self.token_json

    def check_artist_subscribers(self, token: str, artist: str, value: int, operand: str) -> bool:
        headers = {"Content-Type": "application/json", "Authorization": "Bearer " + str(token)}
        response = requests.get(self.base_link + "v1/search?q=" + artist + "&type=artist&limit=1", headers=headers)
        response_json = response.json()

        try:
            result = int(response_json["artists"]["items"][0]["followers"]["total"])
        except:
            return False
        if operand == ">":
            return result > value
        elif operand == "<":
            return result < value
        elif operand == "=":
            return result == value
        elif operand == "!=":
            return result != value
        elif operand == ">=":
            return result >= value
        elif operand == "<=":
            return result <= value
        return False

    def check_artist_popularity(self, token: str, artist: str, value: int, operand: str) -> bool:
        headers = {"Content-Type": "application/json", "Authorization": "Bearer " + str(token)}
        response = requests.get(self.base_link + "v1/search?q=" + artist + "&type=artist&limit=1", headers=headers)
        response_json = response.json()

        try:
            result = int(response_json["artists"]["items"][0]["popularity"])
        except:
            return False
        if operand == ">":
            return result > value
        elif operand == "<":
            return result < value
        elif operand == "=":
            return result == value
        elif operand == ">=":
            return result >= value
        elif operand == "<=":
            return result <= value
        return False

    def check_track_popularity(self, token: str, track: str, value: int, operand: str) -> bool:
        headers = {"Content-Type": "application/json", "Authorization": "Bearer " + str(token)}
        response = requests.get(self.base_link + "v1/search?q=" + track + "&type=track&limit=1", headers=headers)
        response_json = response.json()

        try:
            result = int(response_json["tracks"]["items"][0]["popularity"])
        except:
            return False
        if operand == ">":
            return result > value
        elif operand == "<":
            return result < value
        elif operand == "=":
            return result == value
        elif operand == ">=":
            return result >= value
        elif operand == "<=":
            return result <= value
        return False

    def check_last_release_artist_name(self, token: str, value: str, operand: str) -> bool:
        headers = {"Content-Type": "application/json", "Authorization": "Bearer " + str(token)}
        response = requests.get(self.base_link + "v1/browse/new-releases?limit=1", headers=headers)
        response_json = response.json()

        try:
            result: str = response_json["albums"]["items"][0]["artists"]["name"]
        except:
            return False
        if operand == "start with":
            return result.startswith(value)
        elif operand == "not start with":
            return not result.startswith(value)
        elif operand == "end with":
            return result.endswith(value)
        elif operand == "not end with":
            return not result.endswith(value)
        elif operand == "=":
            return result == value
        return False

    def check_last_release_artist_name_with_country_code(self, token: str, country_code: str, value: str, operand: str) -> bool:
        headers = {"Content-Type": "application/json", "Authorization": "Bearer " + str(token)}
        response = requests.get(self.base_link + "v1/browse/new-releases?limit=1&country=" + country_code, headers=headers)
        response_json = response.json()

        try:
            result: str = response_json["albums"]["items"][0]["artists"]["name"]
        except:
            return False
        if operand == "start with":
            return result.startswith(value)
        elif operand == "not start with":
            return not result.startswith(value)
        elif operand == "end with":
            return result.endswith(value)
        elif operand == "not end with":
            return not result.endswith(value)
        elif operand == "=":
            return result == value
        return False