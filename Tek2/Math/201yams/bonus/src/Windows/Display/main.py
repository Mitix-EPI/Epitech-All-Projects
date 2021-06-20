from Windows.Display import *
from Windows.Objects import *
from Enums.Window import *

functions = {
    ScreenWindow.MAIN: MainMenu.display,
    ScreenWindow.LEVEL_SETTINGS: LevelSettings.display,
    ScreenWindow.GAME: Game.display,
}

def display(windowType, screen, size, objects, isNotObject):
    if (isNotObject):
        objects = functions.get(windowType)(size)

    Object.drawObjects(objects, screen)
    return objects