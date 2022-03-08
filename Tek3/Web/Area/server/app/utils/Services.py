from enum import Enum
from typing import Final

SERVICE_LIST: Final = ['discord', 'intra', 'nasa', 'twitter', 'reddit',
                    'youtube', 'weather', 'crypto', 'twitch', 'google_calendar',
                    'spotify', 'timer', 'facebook', 'league_of_legends', 'pornhub',
                    'farmersworld']

class ServiceEnum(Enum):
    DISCORD = 1,
    INTRA = 2,
    NASA = 3,
    TWITTER = 4,
    REDDIT = 5,
    YOUTUBE = 6,
    WEATHER = 7,
    CRYPTO = 8,
    TWITCH = 9,
    GOOGLE_CALENDAR = 10,
    SPOTIFY = 11,
    TIMER = 12,
    FACEBOOK = 13,
    LEAGUE_OF_LEGENDS = 14,
    PORNHUB = 15,
    FARMERSWORLD = 16

class Service():

    @staticmethod
    def get_service_name(service_id: int) -> str:
        return SERVICE_LIST[service_id]

    @staticmethod
    def get_service_id(service_name: str) -> int:
        try:
            return SERVICE_LIST.index(service_name)
        except:
            return -1