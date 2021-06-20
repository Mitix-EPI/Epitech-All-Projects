#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.collections import LineCollection
from matplotlib.colors import ListedColormap, BoundaryNorm
from scipy.interpolate import spline
import datetime
import sys
import re

def getTabX(data):
    res = []

    for i in data:
        res.append(int(i[0]))
    return res

def getTabY(data):
    res = []

    for i in data:
        res.append(float(i[1]))
    return res

def init_graph(data):
    X = np.array(getTabX(data))
    Y = np.array(getTabY(data))

    xnew = np.linspace(X.min(), X.max(), 300)

    power_smooth = spline(X, Y, xnew)

    plt.plot(xnew,power_smooth)

    # plt.scatter(X, Y)
    plt.xlim(0, 200)
    plt.ylim(0, max(Y) * 1.2)
    plt.show()

def errorOutput(message):
    print(message, file=sys.stderr)
    exit(84)

def openFile(filepath):
    try:
        res = []
        f = open(filepath, "r")
        for line in f:
            res.append(line[0: len(line) - 1])
        f.close()
        return res
    except:
        errorOutput("Error opening file")

def displayData(dataInput):
    init_graph(dataInput)

def parseInput(file):
    res = []
    for i in file:
        tmp = i.split(" ")
        res.append(tmp)
    return res

if len(sys.argv) == 2:
    inputFile = openFile(sys.argv[1])
    dataInput = parseInput(inputFile)
    displayData(dataInput)
else:
    errorOutput("No arg")