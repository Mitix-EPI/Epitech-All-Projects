import pygame
import random
import Yams.BotAnalysis as ba
from random import randrange
from Windows.Objects import *
from Windows.Events.Game import game

def getRandomDice(index):
    return game.player.getDiesNumbers()[index]

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
    if (spriteSheet.key == "dice6"):
        nb = 0
    if (spriteSheet.key == "dice7"):
        nb = 1
    if (spriteSheet.key == "dice8"):
        nb = 2
    if (spriteSheet.key == "dice9"):
        nb = 3
    if (spriteSheet.key == "dice10"):
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

def display(size):
    objects = []

    objects.append(Image.Image("background", "assets/img/background_game.png", (size[0] / 2), (size[1] / 2), event=False))

    objects.append(Text.Text("back", "Back to Menu", 150, 75, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 40)))
    objects.append(Text.Text("roll", "Roll dices", size[0] / 1.1, size[1] - 120, colorHover = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 40)))
    objects.append(Text.Text("stand", "Stand", size[0] / 1.1, size[1] - 50, font = pygame.font.Font("assets/font/Snufkin.otf", 40)))

    objects.append(SpriteSheet.SpriteSheet("dice1", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * -2 * 2, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice2", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * -1 * 2, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice3", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * 0 * 2, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice4", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * 1 * 2, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice5", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * 2 * 2, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))

    objects.append(SpriteSheet.SpriteSheet("dice6", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * -2 * 2, y = size[1] - 100, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice7", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * -1 * 2, y = size[1] - 100, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice8", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * 0 * 2, y = size[1] - 100, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice9", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * 1 * 2, y = size[1] - 100, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))
    objects.append(SpriteSheet.SpriteSheet("dice10", "assets/img/dices.png", 46, 46, 0, 0, x = size[0] / 2 + 92 * 2 * 2, y = size[1] - 100, func = diceFunctionAnimation, isAnimated = True, framePerAnim = 1))

    objects.append(Text.Text("text_score_general_you", "0", x = (size[0] / 2) - 200, y = size[1] / 2, color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 80), event = False))
    objects.append(Text.Text("text_score_general", "VS", x = (size[0] / 2), y = size[1] / 2, color = (0, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 80), event = False))
    objects.append(Text.Text("text_score_general_bot", "0", x = (size[0] / 2) + 200, y = size[1] / 2, color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 80), event = False))


    objects.append(Image.Image("selected_rect1", "assets/img/selected_rect.png", x = (size[0] / 2) + (92 * -2 * 2) + 46, y = (size[1]) - 50, event = False, visible = False))
    objects.append(Image.Image("selected_rect2", "assets/img/selected_rect.png", x = (size[0] / 2) + (92 * -1 * 2) + 46, y = (size[1]) - 50, event = False, visible = False))
    objects.append(Image.Image("selected_rect3", "assets/img/selected_rect.png", x = (size[0] / 2) + (92 * 0 * 2) + 46, y = (size[1]) - 50, event = False, visible = False))
    objects.append(Image.Image("selected_rect4", "assets/img/selected_rect.png", x = (size[0] / 2) + (92 * 1 * 2) + 46, y = (size[1]) - 50, event = False, visible = False))
    objects.append(Image.Image("selected_rect5", "assets/img/selected_rect.png", x = (size[0] / 2) + (92 * 2 * 2) + 46, y = (size[1]) - 50, event = False, visible = False))

    objects.append(Image.Image("scoreboard", "assets/img/scoreboard.png", x = size[0] / 7.68, y = (size[1] / 2) + 60, event = False))
    objects.append(Image.Image("scoreboard_selector", "assets/img/scoreboard_selector.png", x = 0, y = 0, event = False, visible = False))

    objects.append(Text.Text("scoreboard_1", "1", size[0] / 13, (size[1] / 18) * 1 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_2", "2", size[0] / 13, (size[1] / 18) * 2 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_3", "3", size[0] / 13, (size[1] / 18) * 3 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_4", "4", size[0] / 13, (size[1] / 18) * 4 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_5", "5", size[0] / 13, (size[1] / 18) * 5 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_6", "6", size[0] / 13, (size[1] / 18) * 6 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_three", "Three", size[0] / 13, (size[1] / 18) * 7 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_four", "Four", size[0] / 13, (size[1] / 18) * 8 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_yams", "Yams", size[0] / 13, (size[1] / 18) * 9 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_full", "Full", size[0] / 13, (size[1] / 18) * 10 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_smallstraight", "Small Straight", size[0] / 13, (size[1] / 18) * 11 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_straight", "Straight", size[0] / 13, (size[1] / 18) * 12 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))
    objects.append(Text.Text("scoreboard_luck", "Luck", size[0] / 13, (size[1] / 18) * 13 + (size[1] / 6) , 50, color = (0, 0, 0), colorHover = (255, 255, 255), font = pygame.font.Font("assets/font/Snufkin.otf", 25)))

    objects.append(Text.Text("scoreboard_1_you", "", (size[0] / 13) + 100, (size[1] / 18) * 1 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_1_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 1 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_2_you", "", (size[0] / 13) + 100, (size[1] / 18) * 2 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_2_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 2 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_3_you", "", (size[0] / 13) + 100, (size[1] / 18) * 3 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_3_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 3 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_4_you", "", (size[0] / 13) + 100, (size[1] / 18) * 4 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_4_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 4 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_5_you", "", (size[0] / 13) + 100, (size[1] / 18) * 5 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_5_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 5 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_6_you", "", (size[0] / 13) + 100, (size[1] / 18) * 6 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_6_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 6 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_three_you", "", (size[0] / 13) + 100, (size[1] / 18) * 7 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_three_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 7 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_four_you", "", (size[0] / 13) + 100, (size[1] / 18) * 8 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_four_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 8 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_yams_you", "", (size[0] / 13) + 100, (size[1] / 18) * 9 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_yams_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 9 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_full_you", "", (size[0] / 13) + 100, (size[1] / 18) * 10 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_full_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 10 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_smallstraight_you", "", (size[0] / 13) + 100, (size[1] / 18) * 11 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_smallstraight_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 11 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_straight_you", "", (size[0] / 13) + 100, (size[1] / 18) * 12 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_straight_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 12 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("scoreboard_luck_you", "", (size[0] / 13) + 100, (size[1] / 18) * 13 + (size[1] / 6), color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))
    objects.append(Text.Text("scoreboard_luck_bot", "", (size[0] / 13) + 200, (size[1] / 18) * 13 + (size[1] / 6), color = (255, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 25), event = False))

    objects.append(Text.Text("turn", "Tour:  ", size[0] - (size[0] / 9), size[1] / 25, event = False, color = (0, 0, 0), font = pygame.font.Font("assets/font/Snufkin.otf", 40)))
    objects.append(Text.Text("turn_custom", "You", size[0] - (size[0] / 9) + 70, size[1] / 25, event = False, color = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 40)))

    return objects
