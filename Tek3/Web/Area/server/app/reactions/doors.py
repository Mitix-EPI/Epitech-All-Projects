import requests

class Doors:
    def __init__(self) -> None:
        self.doors_url = 'https://epi-logue.eu/api/doors_open?login='
        self.doors_url2 = '&door_name='

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def doors_reaction(self, login, door_name) -> bool:
        url = self.doors_url + login + self.doors_url2 + door_name
    
        r = requests.get(self.doors_url + login + self.doors_url2 + door_name)
        r = r.json()

        return True