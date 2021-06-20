import pygame
import random
from Windows.Objects import *

def display(size):
    objects = []

    objects.append(Image.Image("background", "assets/img/background_menu.png", (size[0] / 2), (size[1] / 2), event=False))
    objects.append(Text.Text("level", "Levels:", (size[0] / 2) - 790, (size[1] / 2) - 130, font = pygame.font.Font("assets/font/Snufkin.otf", 80), event=False))
    objects.append(Text.Text("easy", "Easy", (size[0] / 2) - 790, (size[1] / 2), 50, colorHover = (126, 254, 106), font = pygame.font.Font("assets/font/Snufkin.otf", 50)))
    objects.append(Text.Text("normal", "Normal", (size[0] / 2) - 790, (size[1] / 2) + 100, 50, colorHover = (248, 251, 28), font = pygame.font.Font("assets/font/Snufkin.otf", 50)))
    objects.append(Text.Text("difficult", "Difficult", (size[0] / 2) - 790, (size[1] / 2) + 200, 50, colorHover = (247, 57, 27), font = pygame.font.Font("assets/font/Snufkin.otf", 50)))
    return objects