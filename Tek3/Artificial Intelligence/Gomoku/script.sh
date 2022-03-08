#!/bin/sh

pip install pyinstaller
pyinstaller src/main.py --onefile -n pbrain-gomoku-ai.exe
cp dist/pbrain-gomoku-ai.exe dist/pbrain-gomoku-ai
cp dist/* .


# C:\Users\Alexandre\AppData\Local\Programs\Python\Python37-32\Scripts\pyinstaller.exe --onefile .\main.py -n pbrain-gomoku-ai.exe