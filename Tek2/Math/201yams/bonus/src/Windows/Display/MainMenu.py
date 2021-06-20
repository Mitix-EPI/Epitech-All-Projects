import pygame
import random
from Windows.Objects import *

def display(size):
    objects = []

    objects.append(Image.Image("background", "assets/img/background_menu.png", (size[0] / 2), (size[1] / 2), event=False))
    objects.append(Text.Text("play", "Play", (size[0] / 2) - 800, (size[1] / 2) - 100, 50, colorHover = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 80)))
    objects.append(Text.Text("exit", "Exit", (size[0] / 2) - 800, (size[1] / 2) + 100, 50, font = pygame.font.Font("assets/font/Snufkin.otf", 80)))
    return objects

# def display(size):
#     objects = []

#     objects.append(Image.Image("background", "data/img/fond.png", (size[0] / 2), (size[1] / 2), 1920, 1080, 1, 1313, 6120, 1313, 5, event=False))
#     objects.append(Image.Image("floor", "data/img/platform.png", (size[0] / 2), (size[1] / 2), event=False))
#     objects.append(Image.Image("house1", "data/img/house.png", random.randint(10, size[0] / 4), size[1] - 155, event=False))
#     objects.append(Image.Image("house2", "data/img/house.png", random.randint(size[0] / 4, size[0] / 2), size[1] - 155, event=False))
#     objects.append(Image.Image("house3", "data/img/house.png", random.randint(size[0] / 2, size[0] // 1.2), size[1] - 155, event=False))
#     objects.append(Text.Text("title", "Loup-garou", (size[0] / 2), 50, event=False, font=pygame.font.SysFont('arial', 64)))
#     objects.append(Text.Text("newGame", "Lancer une partie", (size[0] / 2), (size[1] / 2)))
#     objects.append(Text.Text("gameParams", "Compositions", (size[0] / 2), (size[1] / 2) + 70))
#     objects.append(Text.Text("shop", "Boutique", (size[0] / 2), (size[1] / 2) + 140))
#     objects.append(Text.Text("options", "Options", (size[0] / 2), (size[1] / 2) + 210))
#     objects.append(Text.Text("quit", "Quitter le jeu", (size[0] / 2), (size[1] / 2) + 280))
#     return objects