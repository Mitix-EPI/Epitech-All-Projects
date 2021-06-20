from threading import Thread
from Yams.Probability import YamsProbability
import time

game = None

def setGame(gamee):
    global game
    game = gamee

def getRandomDice(index):
    global game
    return game.bot.getDiesNumbers()[index]

positions = []
positions.append({"x": 0, "y": 0})
positions.append({"x": 0, "y": 368})
positions.append({"x": 368, "y": 368})
positions.append({"x": 0, "y": 736})
positions.append({"x": 0, "y": 0})
positions.append({"x": 1104, "y": 368})
positions.append({"x": 736, "y": 368})

def diceFunctionAnimation(spriteSheet):
    nb = 0
    if (spriteSheet.key == "dice1"):
        nb = 0
    if (spriteSheet.key == "dice2"):
        nb = 1
    if (spriteSheet.key == "dice3"):
        nb = 2
    if (spriteSheet.key == "dice4"):
        nb = 3
    if (spriteSheet.key == "dice5"):
        nb = 4
    numberDice = getRandomDice(nb)
    top = spriteSheet.getRectPosition()[0]
    left = spriteSheet.getRectPosition()[1]
    if spriteSheet.counter >= 1:
        if positions[numberDice]["x"] == left and positions[numberDice]["y"] == top:
            spriteSheet.setIsAnimated(False)
            spriteSheet.counter = 0
            return

    if top <= 0:
        if spriteSheet.counter < 1:
            spriteSheet.counter += 1
        spriteSheet.tmp = 0
        spriteSheet.top += spriteSheet.height
        return
    elif spriteSheet.tmp:
        spriteSheet.top -= spriteSheet.height
        spriteSheet.left = 0
    elif top >= 0 and top < 736 and left >= 0 and left < 1380:
        spriteSheet.left += spriteSheet.height
    elif left >= 1380:
        spriteSheet.top += spriteSheet.height
        spriteSheet.left = 0
    else:
        spriteSheet.tmp = True
        return

class BotAnalysis(Thread):
    game = None
    __action = ""
    order = ["luck", "yams", "1", "2", "four", "straight", "full", "smallstraight", "3", "three", "4", "5", "6"]

    def __init__(self):
        Thread.__init__(self)

    def setGame(self, game):
        self.game = game

    def getAction(self):
        return self.__action

    def __getWorstCombination(self):
        for i in self.order:
            if self.game.bot.getScoreCombination("scoreboard_" + i) == -1:
                return i

    def __getProbabilities(self, dies):
        probabilities = {}

        probabilities["luck_6"] = 0.01
        if self.game.bot.getScoreCombination("scoreboard_yams") == -1:
            for i in range(1, 7): # Yams
                probabilities["yams_" + str(i)] = YamsProbability.probability(dies, "yams", i)
        if self.game.bot.getScoreCombination("scoreboard_four") == -1:
            for i in range(1, 7): # Carré
                probabilities["four_" + str(i)] = YamsProbability.probability(dies, "four", i)
        if self.game.bot.getScoreCombination("scoreboard_three") == -1:
            for i in range(1, 7): # Brelan
                probabilities["three_" + str(i)] = YamsProbability.probability(dies, "three", i)
        if self.game.bot.getScoreCombination("scoreboard_straight") == -1:
            for i in range(5, 7): # Suite
                probabilities["straight_" + str(i)] = YamsProbability.probability(dies, "straight", i)
        if self.game.bot.getScoreCombination("scoreboard_smallstraight") == -1:
            for i in range(5, 7): # Petite suite
                probabilities["smallstraight_" + str(i)] = YamsProbability.probability(dies, "straight", i)
        if self.game.bot.getScoreCombination("scoreboard_6") == -1:
            probabilities["6"] = YamsProbability.probability(dies, "yams", 6)
        if self.game.bot.getScoreCombination("scoreboard_5") == -1:
            probabilities["5"] = YamsProbability.probability(dies, "yams", 5)
        if self.game.bot.getScoreCombination("scoreboard_4") == -1:
            probabilities["4"] = YamsProbability.probability(dies, "yams", 4)
        if self.game.bot.getScoreCombination("scoreboard_3") == -1:
            probabilities["3"] = YamsProbability.probability(dies, "yams", 3)
        if self.game.bot.getScoreCombination("scoreboard_2") == -1:
            probabilities["2"] = YamsProbability.probability(dies, "yams", 2)
        if self.game.bot.getScoreCombination("scoreboard_1") == -1:
            probabilities["1"] = YamsProbability.probability(dies, "yams", 1)
        if self.game.bot.getScoreCombination("scoreboard_full") == -1: # Full
            for i in range(1, 7):
                for p in range(1, 7):
                    if i == p:
                        continue
                    probabilities["full_" + str(i) + "_" + str(p)] = YamsProbability.probability(dies, "full", [i, p])
        best_proba = 0.0
        best_combi = ""
        for key in probabilities.keys():
            if probabilities.get(key) > best_proba:
                best_proba = probabilities.get(key)
                best_combi = key
        return [best_combi, best_proba]

    def setKeepDices(self, dies, values):
        for i in range(0, len(dies)):
            if dies[i] in values:
                if not self.game.bot.dieIsKeep(i):
                    self.game.bot.setKeepDie(i)
            elif self.game.bot.dieIsKeep(i):
                self.game.bot.setKeepDie(i)

    def run(self):
        time.sleep(5)
        dies = self.game.bot.getDiesNumbers()

        bestCombination = self.__getProbabilities(dies)
        if bestCombination[1] >= 100:
            self.__action = "stand"
            self.game.bot.setSelectedCombination("scoreboard_" + bestCombination[0].split("_")[0])
        else:
            self.__action = "roll"
            values = bestCombination[0].split("_")[1:]
            for i in range(0, len(values)):
                values[i] = int(values[i])
            if "straight" in bestCombination[0].split("_")[0]:
                straight_number = values[0]
                for i in range(0, 5):
                    if self.game.bot.dieIsKeep(i):
                        self.game.bot.setKeepDie(i)
                while straight_number > 0:
                    dieKeep = False
                    for i in range(0, 5):
                        if not dieKeep and dies[i] == straight_number:
                            self.game.bot.setKeepDie(i)
                            dieKeep = True
                    straight_number -= 1
            else:
                self.setKeepDices(dies, values)
            self.game.bot.setSelectedCombination("scoreboard_" + self.__getWorstCombination())
        return