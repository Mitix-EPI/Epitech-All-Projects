import pygame
from pygame.locals import *
from Windows.Objects.Object import *

class SpriteSheet(MyObject):

    def __init__(self, key, filename, width, height, top, left, x = 0, y = 0, func = None, isAnimated = 0, framePerAnim = 5, event = True):
        """Load the sheet."""

        try:
            self.key = key
            self.sheet = pygame.image.load(filename)
            self.width = width * 2
            self.height = height * 2
            self.sheet = pygame.transform.rotozoom(self.sheet.copy(), 0, 2)
            self.top = top
            self.left = left
            self.x = x
            self.y = y
            self.func = func
            self.isAnimated = isAnimated
            self.frames = 0
            self.framePerAnim = framePerAnim
            self.tmp = False
            self.isHover = False
            self.counter = 0
            self.typeObject = "spritesheet"
            self.event = True

        except pygame.error as e:
            print(f"Unable to load spritesheet image: {filename}")
            raise SystemExit(e)

    def imageAt(self, x, y, colorKey = None):
        """Load a specific image from a specific rectangle."""
        # Loads image from x, y, x + offset, y + offset.

        image = pygame.Surface([self.width, self.height], pygame.SRCALPHA)
        if colorKey is not None:
            if colorKey is -1:
                colorKey = image.get_at((0, 0))
            image.set_colorkey(colorKey, pygame.RLEACCEL)
        # else:
            # image.set_colorkey((0, 0, 0))
        image.blit(self.sheet, (0, 0), (x, y, self.width, self.height))
        self.setHovered(pygame.mouse.get_pos())
        return image

    def setHovered(self, mouse):
        if (self.event):
            self.isHover = False
            if (mouse[0] >= self.x - 10 and mouse[0] <= self.x + self.width + 10):
                if (mouse[1] >= self.y - 10 and mouse[1] <= self.y + self.width + 10):
                    self.isHover = True

    def isHovered(self):
        return self.isHover

    def imagesAt(self, rects, colorKey = None):
        """Load a whole bunch of images and return them as a list"""
        return [self.image_at(rect, colorKey) for rect in rects]

    def loadStrip(self, rect, imageCount, colorKey = None):
        """Load a whole strip of images, and return them as a list."""
        tups = [(rect[0] + rect[2] * x, rect[1], rect[2], rect[3])
                for x in range(imageCount)]

        return self.imageAt(tups, colorKey)

    def setIsAnimated(self, isAnimated):
        """Bool"""
        if (isAnimated):
            self.frames = 0
        self.isAnimated = isAnimated

    def checkAnimation(self):
        self.frames += 1
        if (self.frames % self.framePerAnim == 0):
            self.frames = 0
            return True
        return False

    def getIsAnimated(self):
        return self.isAnimated

    def setAnimation(self, func):
        self.func = func

    def applyAnimation(self):
        self.func(self)

    def setPosition(self, x, y):
        self.x = x
        self.y = y

    def setRectPosition(self, top, left):
        self.top = top
        self.left = left

    def setBorderSize(self, width, height):
        self.width = width
        self.height = height

    def getPosition(self):
        return [self.x, self.y]

    def getRectPosition(self):
        return [self.top, self.left]

    def getBorderSize(self):
        return [self.width, self.height]

    def draw(self, screen):
        if (self.isAnimated and self.checkAnimation()):
            self.applyAnimation()
        screen.blit(self.imageAt(self.left, self.top), (self.x, self.y))