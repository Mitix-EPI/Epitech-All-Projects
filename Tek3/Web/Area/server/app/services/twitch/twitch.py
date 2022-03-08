from datetime import datetime
import requests
import os

class TwitchActions:
    def __init__(self) -> None:
        self.get_user_id_url = 'https://api.twitch.tv/helix/users?login='
        self.get_user_informations_url = 'https://api.twitch.tv/helix/streams?user_id='

        self.refresh_token_url1 = 'https://id.twitch.tv/oauth2/token?grant_type=refresh_token&refresh_token='
        self.refresh_token_url2 = '&client_id='
        self.refresh_token_url3 = '&client_secret='

        self.client_id = os.getenv('TWITCH_CLIENT_ID')
        self.client_secret = os.getenv('TWITCH_CLIENT_SECRET')
        self.client_refresh_token = os.getenv('TWITCH_REFRESH_TOKEN')
        self.token, self.expires_in = self.get_token()
        self.token_refreshed_at = datetime.now()

    def get_token(self) -> str:
        try:
            url = self.refresh_token_url1 + self.client_refresh_token + self.refresh_token_url2 + self.client_id + self.refresh_token_url3 + self.client_secret
            r = requests.post(url, headers={
                'Content-Type': 'application/json'
            })

            return r.json()['access_token'], r.json()['expires_in']
        except:
            return '', 100

    def check_for_refresh(self) -> None:
        # if (datetime.now - token_refreshed_at) is more than (expires_in - 2 minutes) thyen refresh token
        if (datetime.now() - self.token_refreshed_at).seconds > (self.expires_in - 120):
            self.token, self.expires_in = self.get_token()
            self.token_refreshed_at = datetime.now()

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def check_user_streaming(self, username: str, already_checked: bool) -> bool:
        self.check_for_refresh()
        print(f'check_user_streaming: {username}', flush=True)
        r = requests.get(self.get_user_id_url + username, headers={
            'Authorization': 'Bearer ' + self.token,
            'Content-Type': 'application/json',
            'Client-ID': self.client_id
        })

        if r.status_code != 200:
            print(f'check_user_streaming: {username} - {r.status_code} | {r.json()}', flush=True)
            return False, False
        print(f'check_user_streaming: {username} - {r.status_code} | {r.json()}', flush=True)
        user_id = r.json()['data'][0]['id']
        r = requests.get(self.get_user_informations_url + user_id, headers={
            'Authorization': 'Bearer ' + self.token,
            'Content-Type': 'application/json',
            'Client-ID': self.client_id
        })

        if r.status_code != 200 or r.json()['data'] == []:
            print(f'check_user_streaming: {username} - False | {r.json()}', flush=True)
            return False, False
        if already_checked == True :
            print(f'already_checked: {already_checked}', flush=True)
            return False, True
        print(f'check_user_streaming: {username} - True | {r.json()}', flush=True)
        return True, True

    def check_user_current_viewers(self, username: str, operand: str, value: int, already_checked: bool) -> bool:
        self.check_for_refresh()
        r = requests.get(self.get_user_id_url + username, headers={
            'Authorization': 'Bearer ' + self.token,
            'Content-Type': 'application/json',
            'Client-ID': self.client_id
        })
        if r.status_code != 200:
            return False, False
        user_id = r.json()['data'][0]['id']
        r = requests.get(self.get_user_informations_url + user_id, headers={
            'Authorization': 'Bearer ' + self.token,
            'Content-Type': 'application/json',
            'Client-ID': self.client_id
        })

        if r.status_code != 200 or r.json()['data'] == []:
            return False, False
        current_viewers = r.json()['data'][0]['viewer_count']

        if already_checked == True :
            return False, True

        if operand == '>':
            return current_viewers > value, current_viewers > value
        elif operand == '<':
            return current_viewers < value, current_viewers < value
        elif operand == '=':
            return current_viewers == value, current_viewers == value
        elif operand == '>=':
            return current_viewers >= value, current_viewers >= value
        elif operand == '<=':
            return current_viewers <= value, current_viewers <= value
        else:
            return False, False