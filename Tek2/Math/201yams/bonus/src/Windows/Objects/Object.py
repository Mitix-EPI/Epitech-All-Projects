class MyObject():
    typeObject = None

def drawObjects(objects, screen):
    for obj in objects:
        obj.draw(screen)