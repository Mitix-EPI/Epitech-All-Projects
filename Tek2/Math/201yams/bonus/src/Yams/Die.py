from random import randint

class Die():
    __number = 0
    __keep = False

    def __init__(self, number = 0):
        self.__number = number

    def roll(self):
        self.__number = randint(1, 6)

    def getNumber(self):
        return self.__number

    def setKeep(self):
        self.__keep = not self.__keep

    def isKeep(self):
        return self.__keep