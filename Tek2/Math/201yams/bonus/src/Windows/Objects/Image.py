import pygame
from pygame.locals import *
from Windows.Objects.Object import *

class Image(MyObject):

    key = None
    path = None
    x = 0
    y = 0
    left = 0
    top = 0
    plusLeft = 0
    plusTop = 0
    maxLeft = 0
    maxTop = 0
    event = True
    isHover = False
    image = None
    imageObjects = None
    totalImages = 0
    actualIndex = 0
    frames = 0
    framePerAnim = 0

    def __init__(self, key, path, x = 0, y = 0, left = 0, top = 0, plusLeft = 0, plusTop = 0, maxLeft = 0, maxTop = 0, framePerAnim = 0, event = True, visible = True):
        self.key = key
        self.path = path
        self.x = x
        self.y = y
        self.left = left
        self.top = top
        self.plusLeft = plusLeft
        self.plusTop = plusTop
        self.maxLeft = maxLeft
        self.maxTop = maxTop
        self.framePerAnim = framePerAnim
        self.event = event
        self.typeObject = "image"
        self.visible = visible

        self.createImage()

    def createImage(self):
        self.image = pygame.image.load(self.path).convert_alpha()
        if (self.maxLeft > 0):
            self.imageObjects = []
            self.width = self.left
            self.height = self.top
            top = 0
            left = 0
            while (top + self.height <= self.maxTop or left + self.width <= self.maxLeft):
                left = 0
                while (left + self.width <= self.maxLeft):
                    self.imageObjects.append(self.image.subsurface([left, top, self.width, self.height]))
                    left += self.plusLeft
                top += self.plusTop
            self.totalImages = len(self.imageObjects)
        else:
            self.width, self.height = self.image.get_rect().size
        self.x -= self.width / 2
        self.y -= self.height / 2
        self.setHovered(pygame.mouse.get_pos())

    def setHovered(self, mouse):
        if (self.event):
            self.isHover = False
            if (mouse[0] >= self.x - 10 and mouse[0] <= self.x + self.width + 10):
                if (mouse[1] >= self.y - 10 and mouse[1] <= self.y + self.height + 10):
                    self.isHover = True

    def isHovered(self):
        return self.isHover

    def isVisible(self):
        return self.visible

    def getPosition(self):
        return [self.x, self.y]

    def setPosition(self, x, y):
        self.x = x
        self.y = y

    def setVisible(self, visible):
        self.visible = visible
        if self.visible:
            self.image.set_alpha(255)
        else:
            self.image.set_alpha(0)

    def checkAnimation(self):
        self.frames += 1
        if (self.frames % self.framePerAnim == 0):
            self.frames = 0
            self.actualIndex += 1
            if (self.actualIndex >= self.totalImages):
                self.actualIndex = 0

    def draw(self, screen):
        if self.isVisible():
            mouse = pygame.mouse.get_pos()
            if (self.maxLeft > 0):
                self.checkAnimation()
                screen.blit(self.imageObjects[self.actualIndex], (self.x, self.y))
            else:
                screen.blit(self.image, (self.x, self.y))