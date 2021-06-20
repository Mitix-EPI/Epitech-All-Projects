import pygame
from pygame.locals import *
from Windows.Objects.Object import *

pygame.font.init()

class Text(MyObject):
    key = None
    label = None
    x = 0
    y = 0
    width = 0
    height = 0
    event = True
    color = (255, 255, 255)
    colorHover = (255, 0, 0)
    font = None
    isHover = False
    textObject = None

    def __init__(self, key, label, x = 0, y = 0, event = True, color = (255, 255, 255), colorHover = (255, 0, 0), font = pygame.font.SysFont('arial', 32)):
        self.key = key
        self.label = label
        self.x = x
        self.y = y
        self.event = event
        self.color = color
        self.colorHover = colorHover
        self.font = font
        self.typeObject = "text"

        self.setSize()
        self.createObject(pygame.mouse.get_pos())

    def setSize(self):
        self.width, self.height = self.font.size(self.label)
        self.x -= self.width / 2
        self.y -= self.height / 2

    def getColor(self):
        return self.color

    def setColor(self, color):
        self.color = color
        self.width, self.height = self.font.size(self.label)
        self.createObject(pygame.mouse.get_pos())

    def getLabel(self):
        return self.label

    def setLabel(self, label):
        self.label = label
        self.width, self.height = self.font.size(self.label)
        self.createObject(pygame.mouse.get_pos())

    def setPosition(self, x, y):
        self.x = x
        self.y = y

    def getPosition(self):
        return [self.x, self.y]

    def createObject(self, mouse):
        self.textObject = self.font.render(self.label, 1, self.color)

        self.setMousePosition(mouse)

    def setMousePosition(self, mouse):
        if (self.event):
            self.textObject = self.font.render(self.label, 1, self.color)
            self.isHover = False
            if (mouse[0] >= self.x - 10 and mouse[0] <= self.x + self.width + 10):
                if (mouse[1] >= self.y - 10 and mouse[1] <= self.y + self.height + 10):
                    self.textObject = self.font.render(self.label, 1, self.colorHover)
                    self.isHover = True

    def isHovered(self):
        return self.isHover

    def draw(self, screen):
        mouse = pygame.mouse.get_pos()
        self.setMousePosition(mouse)
        screen.blit(self.textObject, (self.x, self.y))