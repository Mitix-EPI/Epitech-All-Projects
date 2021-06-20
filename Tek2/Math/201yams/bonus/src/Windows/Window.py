import pygame
from pygame.locals import *
import os
from Windows import *
import Windows.Display.main
import Windows.Events.main
from Enums.Window import *
from Windows.Objects import *

class Window():

    screen = None
    stop = False
    width = 0
    height = 0
    fenetre = ScreenWindow.MAIN

    def __init__(self, title = "201 Yams", screenSize = (0, 0), fullscreen = True):
        if (fullscreen):
            self.screen = pygame.display.set_mode(screenSize, FULLSCREEN)
        else:
            self.sceen = pygame.display.set_mode(screenSize)
        self.width, self.height = pygame.display.get_surface().get_size()
        self.update()

    def update(self):
        clock = pygame.time.Clock()
        self.objects = []
        while True:
            clock.tick(60)
            self.screen.fill((0, 0, 0))
            self.objects = Windows.Display.main.display(self.fenetre, self.screen, (self.width, self.height), self.objects, (self.objects == []))
            self.fenetre, self.objects = Windows.Events.main.event(self.fenetre, self.objects)
            pygame.display.update()

    def getObjects(self):
        return self.objects