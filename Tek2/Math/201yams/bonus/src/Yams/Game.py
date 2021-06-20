from Yams.Player import Player
from Yams.BotAnalysis import BotAnalysis, diceFunctionAnimation, setGame
from random import randint, choice

botNames = ["Juanito", "Cyril", "Uichaa", "Paradou", "Licorne"]

class Game():

    player = Player()
    bot = Player(choice(botNames))
    turn = True # true si player, sinon false
    __botAnalysis = BotAnalysis()
    __isEnded = False

    def __init__(self):
        pass

    def animateBotDies(self, objects):
        self.bot.rollDies()
        setGame(self)
        for obj in objects:
            if obj.key == "dice1":
                obj.setAnimation(diceFunctionAnimation)
                if not self.bot.dieIsKeep(0):
                    obj.setIsAnimated(True)
            elif obj.key == "dice2":
                obj.setAnimation(diceFunctionAnimation)
                if not self.bot.dieIsKeep(1):
                    obj.setIsAnimated(True)
            elif obj.key == "dice3":
                obj.setAnimation(diceFunctionAnimation)
                if not self.bot.dieIsKeep(2):
                    obj.setIsAnimated(True)
            elif obj.key == "dice4":
                obj.setAnimation(diceFunctionAnimation)
                if not self.bot.dieIsKeep(3):
                    obj.setIsAnimated(True)
            elif obj.key == "dice5":
                obj.setAnimation(diceFunctionAnimation)
                if not self.bot.dieIsKeep(4):
                    obj.setIsAnimated(True)

    def changeTurn(self, objects):
        self.reset()
        self.turn = not self.turn

        if not self.turn and not self.__isEnded:
            self.bot.reset()
            self.animateBotDies(objects)
            self.__botAnalysis.setGame(self)
            self.__botAnalysis.start()
        elif not self.__isEnded:
            self.player.reset()

    def gameIsEnded(self):
        if self.player.hasAllScore() and self.bot.hasAllScore():
            self.__isEnded = True

    def reset(self):
        if self.turn and not self.__isEnded:
            self.player.reset()
        elif not self.__isEnded:
            self.bot.reset()

    def stand(self, objects):
        ret = False
        if self.turn and not self.__isEnded:
            ret = self.player.finishTurn()
            self.gameIsEnded()
        elif not self.__isEnded:
            ret = self.bot.finishTurn()
            self.gameIsEnded()
        if ret:
            self.changeTurn(objects)
        return ret

    def updateBot(self, objects):
        if not self.__botAnalysis.is_alive():
            if self.bot.getNumberRolls() != 0:
                action = self.__botAnalysis.getAction()
                if action == "stand":
                    self.__botAnalysis = BotAnalysis()
                    self.__botAnalysis.setGame(self)
                    self.stand(objects)
                elif action == "roll":
                    self.animateBotDies(objects)

                    self.__botAnalysis = BotAnalysis()
                    self.__botAnalysis.setGame(self)
                    self.__botAnalysis.start()
                else:
                    self.__botAnalysis = BotAnalysis()
                    self.__botAnalysis.setGame(self)
                    self.stand(objects)
            else:
                self.__botAnalysis = BotAnalysis()
                self.__botAnalysis.setGame(self)
                self.stand(objects)