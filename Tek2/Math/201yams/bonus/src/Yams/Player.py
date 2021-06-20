from Yams.Dies import Dies
from Yams.Combination import Combination

class Player():

    def __init__(self, name = ""):
        self.__name = name

        self.__score = 0
        self.__dies = Dies()
        self.__selectedCombination = ""
        self.__name = ""

        self.__scoreCombinations = {
            "scoreboard_yams": -1,
            "scoreboard_four": -1,
            "scoreboard_three": -1,
            "scoreboard_full": -1,
            "scoreboard_straight": -1,
            "scoreboard_smallstraight": -1,
            "scoreboard_luck": -1,
            "scoreboard_1": -1,
            "scoreboard_2": -1,
            "scoreboard_3": -1,
            "scoreboard_4": -1,
            "scoreboard_5": -1,
            "scoreboard_6": -1,
            "scoreboard_bonus": -1,
        }
        self.__combinations = {
            "scoreboard_yams": False,
            "scoreboard_four": False,
            "scoreboard_three": False,
            "scoreboard_full": False,
            "scoreboard_straight": False,
            "scoreboard_smallstraight": False,
            "scoreboard_luck": False,
            "scoreboard_1": False,
            "scoreboard_2": False,
            "scoreboard_3": False,
            "scoreboard_4": False,
            "scoreboard_5": False,
            "scoreboard_6": False,
        }

    def getDiesNumbers(self):
        """Return dies numbers (list of int)"""
        return self.__dies.getDiesNumbers()

    def __checkBonusScore(self):
        value = 0

        if self.__scoreCombinations.get("scoreboard_bonus") == -1:
            for i in range(1, 7):
                if self.__scoreCombinations.get("scoreboard_" + str(i)) != -1:
                    value += self.__scoreCombinations.get("scoreboard_" + str(i))
            if value > 62:
                self.__scoreCombinations["scoreboard_bonus"] = 35

    def finishTurn(self):
        dies = self.getDiesNumbers()

        if self.__selectedCombination == "":
            return False
        if not self.__combinations.get(self.__selectedCombination):
            score = Combination.checkCombination(dies, self.__selectedCombination)
            self.__combinations[self.__selectedCombination] = True
            self.__scoreCombinations[self.__selectedCombination] = score
            self.__checkBonusScore()
            return True
        return False

    def getGlobalScore(self):
        score = 0

        for i in self.__scoreCombinations.keys():
            if self.__scoreCombinations.get(i) != -1:
                score += self.__scoreCombinations.get(i)
        return score

    def hasAllScore(self):
        for i in self.__combinations.keys():
            if not self.__combinations.get(i):
                return False
        return True

    def setKeepDie(self, index):
        self.__dies.setKeepDie(index)

    def dieIsKeep(self, index):
        return self.__dies.isKeepDie(index)

    def setSelectedCombination(self, name):
        self.__selectedCombination = name

    def getSelectedCombination(self):
        return self.__selectedCombination

    def getScoreCombination(self, name):
        return self.__scoreCombinations.get(name)

    def rollDies(self):
        self.__dies.roll()

    def getNumberRolls(self):
        return self.__dies.getNumberRolls()

    def getName(self):
        return self.__name

    def reset(self):
        self.__dies.reset()