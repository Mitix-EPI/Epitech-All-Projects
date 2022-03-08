import requests
import json

class SendMail:
    def __init__(self) -> None:
        self.mail_url = 'https://graph.microsoft.com/v1.0/me/sendMail'

    #################################################################################################
    #                                            REACTIONS                                          #
    #################################################################################################

    def send_mail_office(self, token: str, mail_to: str, subject: str, content: str) -> bool:
        try :
            headers = {'Authorization': 'Bearer ' + token, 'Content-Type': 'application/json'}
            data = {
                "message": {
                    "subject": subject,
                    "body": {
                        "contentType": "Text",
                        "content": content
                    },
                    "toRecipients": [
                        {
                            "emailAddress": {
                                "address": mail_to
                            }
                        }
                    ]
                }
            }
            # data = json.dumps(data)
            r = requests.post(self.mail_url, json=data, headers=headers)

            if r.status_code != 202:
                print(f'send_mail_office: {r.status_code}', flush=True)
                return False
            print("mail sent", flush=True)
            return True
        except Exception as e:
            print(f'send_mail_office: {e}', flush=True)
            return False