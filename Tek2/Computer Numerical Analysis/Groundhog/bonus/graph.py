#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.collections import LineCollection
from matplotlib.colors import ListedColormap, BoundaryNorm
import datetime
import sys
import re

def init_graph(temp, deviation):
    dev_tab = [[float(j) for j in i] for i in deviation]
    y_tab = [float(i) for i in temp]
    max_range = len(y_tab)
    x = np.asarray(range(0, max_range))
    y = y_tab
    y = np.asarray(y)
    z = [i - j for i, j in zip(y[:-1], y[1:])]
    z = np.asarray(z)

    x_up = np.asarray(range(0, max_range))
    y_up = [i + dev_tab[y_tab.index(i)][2] for i in y_tab]
    z_up = [i - j for i, j in zip(y_up[:-1], y_up[1:])]
    z_up = np.asarray(z_up)

    x_down = np.asarray(range(0, max_range))
    y_down = [i - dev_tab[y_tab.index(i)][2] for i in y_tab]
    z_down = [i - j for i, j in zip(y_down[:-1], y_down[1:])]
    z_down = np.asarray(z_down)

    cmap = ListedColormap(['g', 'b', 'r'])
    norm = BoundaryNorm([-100, -0.5, 0.5, 100], cmap.N)

    cmap_dev = ListedColormap(["silver"])
    points = np.array([x, y]).T.reshape(-1, 1, 2)

    segments = np.concatenate([points[:-1], points[1:]], axis=1)

    points_up = np.array([x_up, y_up]).T.reshape(-1, 1, 2)
    segments_up = np.concatenate([points_up[:-1], points_up[1:]], axis=1)

    points_down = np.array([x_down, y_down]).T.reshape(-1, 1, 2)
    segments_down = np.concatenate([points_down[:-1], points_down[1:]], axis=1)

    lc = LineCollection(segments, cmap=cmap, norm=norm)
    lc.set_array(z)
    lc.set_linewidth(3)

    lc_up = LineCollection(segments_up, cmap=cmap_dev)
    lc_up.set_array(z_up)
    lc_up.set_linewidth(1)

    lc_down = LineCollection(segments_down, cmap=cmap_dev)
    lc_down.set_array(z_down)
    lc_down.set_linewidth(1)

    fig1 = plt.figure()
    plt.gca().add_collection(lc)
    plt.gca().add_collection(lc_up)
    plt.gca().add_collection(lc_down)
    plt.xlim(- 1, max_range - 1)
    plt.ylim(min(y_down) - 2, max(y_up) + 2)
    plt.tight_layout()
    plt.show()

def errorOutput(message):
    print(message, file=sys.stderr)
    exit(84)

def openFile(filepath):
    try:
        res = []
        f = open(filepath, "r")
        for line in f:
            res.append(line)
        f.close()
        return res
    except:
        errorOutput("Error opening file")

def displayData(dataInput, dataOutput):
    init_graph(dataInput, dataOutput)

def getG(line):
    try:
        if "nan" in line.split("=")[1]:
            return 0
        return float(line.split("=")[1])
    except:
        return 0

def getR(line):
    try:
        if "nan" in line.split("=")[1]:
            return 0
        return float(line.split("=")[1])
    except:
        return 0

def getS(line):
    try:
        if "nan" in line.split("=")[1]:
            return 0
        return float(line.split("=")[1])
    except:
        return 0

def getDataInLine(line):
    res = []
    splitted = line.split("\t")
    res.append(getG(splitted[0]))
    res.append(getR(splitted[1]))
    res.append(getS(splitted[2]))
    return res

def parseOutput(file):
    res = []
    for i in file:
        if (i[0] == 'g'):
            lineData = getDataInLine(i)
            res.append(lineData)
    return res

def parseInput(file):
    res = []
    for i in file:
        if "STOP" in i:
            return res
        res.append(i)
    return res

if len(sys.argv) == 3:
    inputFile = openFile(sys.argv[1])
    outputFile = openFile(sys.argv[2])
    dataInput = parseInput(inputFile)
    dataOutput = parseOutput(outputFile)
    displayData(dataInput, dataOutput)
else:
    errorOutput("No arg. Should be ./groundhog <inputFile> <outputFile>.")