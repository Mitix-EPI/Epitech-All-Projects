from datetime import datetime
import requests

class GoogleActions:
    def __init__(self) -> None:
        self.get_calendar_events_url: str = 'https://www.googleapis.com/calendar/v3/calendars/primary/events'

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def check_calendar_events(self, token: str, date: str, last_event_checked: str) -> bool:
        if (date == ''):
            r = requests.get(self.get_calendar_events_url + f'?timeMin={datetime.now().strftime("%Y-%m-%dT00:00:01Z")}&timeMax={datetime.now().strftime("%Y-%m-%dT23:59:59Z")}', headers={
                'Authorization': 'Bearer ' + token,
                'Content-Type': 'application/json'
            })

            if r.status_code != 200:
                return False, last_event_checked
            if r.json()['items'] == []:
                return False, 
            if r.json()['items'][0]['summary'] == last_event_checked:
                print(f'check_calendar_events: {r.status_code} | {r.json()}', flush=True)
                return False, last_event_checked
        else :
            r = requests.get(self.get_calendar_events_url + f'?timeMin={datetime.strptime(date, "%d-%m-%y").strftime("%Y-%m-%dT%00:00:00Z")}&timeMax={datetime.strptime(date, "%d-%m-%y").strftime("%Y-%m-%dT23:59:59Z")}', headers={
                'Authorization': 'Bearer ' + token,
                'Content-Type': 'application/json'

            })            
            if r.status_code != 200:
                return False, last_event_checked
            if r.json()['items'] == []:
                return False, last_event_checked
            if r.json()['items'][0]['summary'] == last_event_checked:
                return False, last_event_checked
        return True, r.json()['items'][0]['summary']
