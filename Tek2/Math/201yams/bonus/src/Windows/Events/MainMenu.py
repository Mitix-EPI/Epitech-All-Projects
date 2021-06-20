import pygame
from pygame.locals import *
from Windows.Objects import *
from Enums.Window import *

def event(windowType, objects):
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                exit(0)
        if event.type == MOUSEBUTTONDOWN:
            for obj in objects:
                if obj.isHovered():
                    if obj.key == "play":
                        windowType = ScreenWindow.LEVEL_SETTINGS
                    if obj.key == "exit":
                        exit(0)
    return windowType

# def event(windowType, objects):
#     for event in pygame.event.get():
#         if event.type == KEYDOWN:
#             if event.unicode == "q":
#                 exit(0)
#         if event.type == MOUSEBUTTONDOWN:
#             for obj in objects:
#                 if obj.isHovered():
#                     if obj.key == "newGame":
#                         print("Nouvelle partie")
#                     elif obj.key == "gameParams":
#                         windowType = ScreenWindow.COMPO
#                     elif obj.key == "shop":
#                         print("Magasin")
#                     elif obj.key == "options":
#                         print("Options")
#                     elif obj.key == "quit":
#                         exit(0)
#     return windowType