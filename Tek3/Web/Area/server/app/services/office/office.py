import requests

class OfficeActions:
    def __init__(self) -> None:
        self.get_inbox_url = 'https://graph.microsoft.com/v1.0/me/messages'

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def check_inbox_specific_message(
        self, token: str,
        subject_to_check: str,
        last_checked_subject: str,
        last_checked_datetime
    ) -> bool:
        headers = {'Authorization': 'Bearer ' + token, 'Content-Type': 'application/json'}
        r = requests.get(self.get_inbox_url, headers=headers)
        if r.status_code != 200:
            print(f'check_inbox_specific_message: {r.status_code}', flush=True)
            return False, last_checked_subject, last_checked_datetime
        messages = r.json()['value']
        for message in messages:
            #check if message['subject'] contains subject_to_check
            print(f'check_inbox_specific_message: {message["subject"]}', flush=True)
            if subject_to_check in message['subject']:
                if message['subject'] == last_checked_subject:
                    return False, last_checked_subject, last_checked_datetime
                return True, message['subject'], message['receivedDateTime']
        print(f'check_inbox_specific_message: {r.status_code}', flush=True)
        return False, last_checked_subject, last_checked_datetime