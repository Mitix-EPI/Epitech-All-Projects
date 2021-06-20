import pygame
from pygame.locals import *
from Windows.Objects import *
from Enums.Window import *
from Yams import *

def updateScoreBot(objects):
    combination = game.bot.getSelectedCombination()
    for obj in objects:
        if combination + "_bot" == obj.key:
            score = str(game.bot.getScoreCombination(combination))
            obj.setLabel(score)
            break
    globalScore = str(game.bot.getGlobalScore())
    for obj in objects:
        if obj.key == "text_score_general_bot":
            obj.setLabel(globalScore)
            return

def updateScoreYou(objects):
    combination = getSelectedCombine(objects)
    for obj in objects:
        if combination + "_you" == obj.key:
            score = str(game.player.getScoreCombination(combination))
            obj.setLabel(score)
            break
    globalScore = str(game.player.getGlobalScore())
    for obj in objects:
        if obj.key == "text_score_general_you":
            obj.setLabel(globalScore)
            return

def changeTurn(objects):
    turn_custom = getObj("turn_custom", objects)
    if (turn_custom.getLabel() == "You"):
        turn_custom.setLabel("Bot")
        turn_custom.setColor((255, 0, 0))
    else:
        turn_custom.setLabel("You")
        turn_custom.setColor((126, 254, 106))

def resetSelectedCombination(objects):
    selector = getObj("scoreboard_selector", objects)
    selector.setVisible(False)

def getSelectedCombine(objects):
    width, height = pygame.display.get_surface().get_size()
    selector = getObj("scoreboard_selector", objects)
    y = selector.getPosition()[1] + 13
    if y == (height / 18) * 1 + (height / 6):
        return "scoreboard_1"
    if y == (height / 18) * 2 + (height / 6):
        return "scoreboard_2"
    if y == (height / 18) * 3 + (height / 6):
        return "scoreboard_3"
    if y == (height / 18) * 4 + (height / 6):
        return "scoreboard_4"
    if y == (height / 18) * 5 + (height / 6):
        return "scoreboard_5"
    if y == (height / 18) * 6 + (height / 6):
        return "scoreboard_6"
    if y == (height / 18) * 7 + (height / 6):
        return "scoreboard_three"
    if y == (height / 18) * 8 + (height / 6):
        return "scoreboard_four"
    if y == (height / 18) * 9 + (height / 6):
        return "scoreboard_yams"
    if y == (height / 18) * 10 + (height / 6):
        return "scoreboard_full"
    if y == (height / 18) * 11 + (height / 6):
        return "scoreboard_smallstraight"
    if y == (height / 18) * 12 + (height / 6):
        return "scoreboard_straight"
    if y == (height / 18) * 13 + (height / 6):
        return "scoreboard_luck"
    return None

def setScoreboardSelectorPos(obj, objects):
    selector = getObj("scoreboard_selector", objects)
    selector.setVisible(True)
    x = obj.getPosition()[0]
    y = obj.getPosition()[1]
    selector.setPosition(x - 40, y)

def resetSelectedRect(objects):
    for obj in objects:
        if obj.key == "selected_rect1":
            obj.setVisible(False)
        if obj.key == "selected_rect2":
            obj.setVisible(False)
        if obj.key == "selected_rect3":
            obj.setVisible(False)
        if obj.key == "selected_rect4":
            obj.setVisible(False)
        if obj.key == "selected_rect5":
            obj.setVisible(False)

def setSelectedRectPosition(objects, key):
    rectSelected = None
    for obj in objects:
        if (key == "dice6" and obj.key == "selected_rect1"):
            rectSelected = obj
            game.player.setKeepDie(0)
        if (key == "dice7" and obj.key == "selected_rect2"):
            rectSelected = obj
            game.player.setKeepDie(1)
        if (key == "dice8" and obj.key == "selected_rect3"):
            rectSelected = obj
            game.player.setKeepDie(2)
        if (key == "dice9" and obj.key == "selected_rect4"):
            rectSelected = obj
            game.player.setKeepDie(3)
        if (key == "dice10" and obj.key == "selected_rect5"):
            rectSelected = obj
            game.player.setKeepDie(4)
    if rectSelected == None:
        return
    visible = rectSelected.isVisible()
    rectSelected.setVisible(not visible)

def rollDices(objects):
    for obj in objects:
        if obj.key == "dice6" and not game.player.dieIsKeep(0):
            obj.setIsAnimated(True)
        if obj.key == "dice7" and not game.player.dieIsKeep(1):
            obj.setIsAnimated(True)
        if obj.key == "dice8" and not game.player.dieIsKeep(2):
            obj.setIsAnimated(True)
        if obj.key == "dice9" and not game.player.dieIsKeep(3):
            obj.setIsAnimated(True)
        if obj.key == "dice10" and not game.player.dieIsKeep(4):
            obj.setIsAnimated(True)

def isSelectedSelectorRect(objects):
    selector = getObj("scoreboard_selector", objects)
    return selector.isVisible()

def getObj(name, objects):
    for obj in objects:
        if obj.key == name:
            return obj

def event(windowType, objects):
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                exit(0)
        if event.type == MOUSEBUTTONDOWN:
            for obj in objects:
                if obj.isHovered():
                    if obj.key == "back":
                        game.reset()
                        windowType = ScreenWindow.MAIN
                    if obj.key == "roll":
                        if game.player.getNumberRolls() != 0 and game.turn:
                            game.player.rollDies()
                            rollDices(objects)
                    if obj.key == "stand":
                        if game.turn:
                            if game.stand(objects) and isSelectedSelectorRect(objects):
                                resetSelectedRect(objects)
                                resetSelectedCombination(objects)
                                changeTurn(objects)
                                updateScoreYou(objects)
                    if "dice" in obj.key:
                        if game.turn:
                            setSelectedRectPosition(objects, obj.key)
                    if "scoreboard_" in obj.key and game.turn:
                        setScoreboardSelectorPos(obj, objects)
                        game.player.setSelectedCombination(getSelectedCombine(objects))
    if not game.turn:
        game.updateBot(objects)
        if game.turn:
            changeTurn(objects)
            game.player.rollDies()
            rollDices(objects)
            updateScoreBot(objects)
            # bot score change
            # game.bot.getScoreCombination(scoreboard_name)
    return windowType

game = Game.Game()