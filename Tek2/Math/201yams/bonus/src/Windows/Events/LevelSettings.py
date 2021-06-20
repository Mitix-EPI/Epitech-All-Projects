import pygame
from pygame.locals import *
from Windows.Objects import *
from Enums.Window import *
from Windows.Events.Game import game

def event(windowType, objects):
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                exit(0)
        if event.type == MOUSEBUTTONDOWN:
            for obj in objects:
                if obj.isHovered():
                    if obj.key == "easy":
                        game.player.rollDies()
                        windowType = ScreenWindow.GAME
                    if obj.key == "normal":
                        game.player.rollDies()
                        windowType = ScreenWindow.GAME
                    if obj.key == "difficult":
                        game.player.rollDies()
                        windowType = ScreenWindow.GAME
    return windowType