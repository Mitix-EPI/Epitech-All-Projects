import pygame
from pygame.locals import *
from Windows.Objects import *
from Windows.Events import *
from Enums.Window import *

functions = {
    ScreenWindow.MAIN: MainMenu.event,
    ScreenWindow.LEVEL_SETTINGS: LevelSettings.event,
    ScreenWindow.GAME: Game.event
}

def event(windowType, objects):
    fenetre = functions.get(windowType)(windowType, objects)
    if (fenetre != windowType):
        objects = []
    return fenetre, objects