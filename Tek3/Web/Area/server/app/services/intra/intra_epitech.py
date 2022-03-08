import requests

class IntraEpitechActions:
    def __init__(self) -> None:
        self.intra_epitech_url = 'https://intra.epitech.eu/'

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################
    def __request__profil(self, auth_token):
        r = requests.get(self.intra_epitech_url + auth_token + "/user?format=json")
        return r.json()

    def getLogTime(self, auth_token, log_time) -> bool:
        logtime = self.__request__profil(auth_token)["nsstat"]["active"]
        if (int(logtime) < int(log_time)) :
            return False
        return True

    def getCredits(self, auth_token, credits_to_check) -> bool:
        credits = self.__request__profil(auth_token)["credits"]
        if (credits < credits_to_check) :
            return False
        return True
    def getGpa(self, auth_token, gpa_to_check) -> bool:
        gpa = self.__request__profil(auth_token)["gpa"][0]["gpa"]
        if (gpa < gpa_to_check) :
            return False
        return True