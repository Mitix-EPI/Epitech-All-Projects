import Exceptions.Exceptions as Crash
from Yams.Die import Die

class Dies():
    __dies = []
    __number = 5
    __rolls = 3

    def __init__(self):
        self.reset()

    def reset(self):
        """Reset dies (number of rolls and dies number)"""

        self.__resetDies()
        self.__resetRolls()

    def roll(self):
        """Roll all dies that aren't kept"""

        if self.__rolls > 0:
            for die in self.__dies:
                if not die.isKeep():
                    die.roll()
            self.__rolls -= 1

    def setKeepDie(self, index):
        """Set die at index to keep or not
        :param index: Index at the list (between 0 and 4)"""

        if index < 0 or index > len(self.__dies):
            raise Crash.OutOfRange("Index " + str(index) + " is out of range ! (Must be between 0 and 4)", 6)
        self.__dies[index].setKeep()

    def isKeepDie(self, index):
        """Return boolean if die is keep
        :param index: Index at the list (between 0 and 4)"""

        if index < 0 or index > len(self.__dies):
            raise Crash.OutOfRange("Index " + str(index) + " is out of range ! (Must be between 0 and 4)", 6)
        return self.__dies[index].isKeep()

    def getDiesNumbers(self):
        """Get number dies list of int"""
        liste = []

        for i in self.__dies:
            liste.append(i.getNumber())
        return liste

    def getNumberRolls(self):
        """Get rolls number left"""
        return self.__rolls

    def __resetDies(self):
        self.__dies = [Die() for i in range(0, 5)]

    def __resetRolls(self):
        self.__rolls = 3