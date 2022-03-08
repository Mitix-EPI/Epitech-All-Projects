from typing import Tuple
import requests
from datetime import datetime

class FacebookActions:
    def __init__(self) -> None:
        self.facebook_url = 'https://graph.facebook.com/v13.0/'
        self.birthday_url = 'me?fields=birthday'
    
    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def check_birthday(self, token: str, last_checked_birthday: str) -> Tuple[bool, str]:
        headers = {'Authorization': 'Bearer ' + token, 'Content-Type': 'application/json'}
        r = requests.get(self.facebook_url + self.birthday_url, headers=headers)
        if r.status_code != 200:
            print(f'check_birthday: {r.status_code}', flush=True)
            return False, last_checked_birthday
        birthday = r.json()['birthday']
        today = datetime.today().strftime('%m/%d/%Y')
        print(f'check_birthday: today = [{today}] | birthday = [{birthday}]', flush=True)
        if birthday == today and today != last_checked_birthday:
            return True, today
        return False, last_checked_birthday

    def check_friends(self, token: str, number_of_friends: int, operand: str) -> bool:
        headers = {'Authorization': 'Bearer ' + token, 'Content-Type': 'application/json'}
        r = requests.get(self.facebook_url + 'me/friends', headers=headers)
        if r.status_code != 200:
            print(f'check_friends: {r.status_code}', flush=True)
            return False
        friends = r.json()['summary']['total_count']
        print(f'check_friends: friends = [{friends}] | number_of_friends = [{number_of_friends}] | operand = [{operand}]', flush=True)
        if operand == '>':
            return friends > number_of_friends
        elif operand == '<':
            return friends < number_of_friends
        elif operand == '=':
            return friends == number_of_friends
        elif operand == '>=':
            return friends >= number_of_friends
        elif operand == '<=':
            return friends <= number_of_friends
        return False