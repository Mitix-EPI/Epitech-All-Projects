import requests

class WeatherActions:
    def __init__(self) -> None:
        self.weather_url = 'http://api.openweathermap.org/data/2.5/weather?q='
        self.weather_url2 = '&lang=en&units=metric&appid=7fcb07bf16dd0a0bb6ac7b6495d591a1'

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def weather_action(self, city, weather) -> bool:
        r = requests.get(self.weather_url + city + self.weather_url2)
        r = r.json()

        if weather == 'Rain':
            if r['weather'][0]['main'] == 'Rain':
                return True
            return False
        elif weather == 'Snow':
            if r['weather'][0]['main'] == 'Snow':
                return True
            return False
        elif weather == 'Clear':
            if r['weather'][0]['main'] == 'Clear':
                return True
            return False
        elif weather == 'Clouds':
            if r['weather'][0]['main'] == 'Clouds':
                return True
            return False
        elif weather == 'Drizzle':
            if r['weather'][0]['main'] == 'Drizzle':
                return True
            return False

    def temperature_action(self, city, operand, value) -> bool:
        r = requests.get(self.weather_url + city + self.weather_url2)
        r = r.json()

        _temp = r['main']['temp']

        if operand == '>':
            return _temp > value
        elif operand == '<':
            return _temp < value
        elif operand == '=':
            return _temp == value
        elif operand == '>=':
            return _temp >= value
        elif operand == '<=':
            return _temp <= value
        else:
            return False