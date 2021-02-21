#!/usr/bin/env python3

import sys
import os
import time

"""
    Décale de n place(s) dans la table ASCII
"""
def letterShift(letter, n):
    return chr((ord(letter) + n) % 255)

"""
    Crypte un texte
"""
def encryptText(text, n):
    encryptText = ""

    for i in range(0, len(text)):
        character = text[i]

        if character != " ":
            encryptText = encryptText + letterShift(character, n)
        else:
            encryptText = encryptText + " "

    return encryptText


"""
    Décrypte un texte
"""
def decryptText(text, n):
    decryptText = ""

    for i in range(0, len(text)):
        character = text[i]

        if character != " ":
            decryptText = decryptText + letterShift(character, int("-" + str(n)))
        else:
            decryptText = decryptText + " "

    return decryptText


"""
    Crypte un texte avec une clé saisie par l'utilisateur
"""
def encryptTextKey(text, key):
    encryptText = ""

    for i in range(0, len(text)):
        character = text[i]

        if character != " ":
            encryptText = encryptText + letterShift(character, int(key[i % len(key)]))
        else:
            encryptText = encryptText + " "

    return encryptText


"""
    Décrypte le texte avec la clé saisie par l'utilisateur
"""
def decryptTextKey(text, key):
    decryptText = ''

    for i in range(0, len(text)):
        character = text[i]

        if character != " ":
            decryptText = decryptText + letterShift(character, int("-" + str(key[i % len(key)])))
        else:
            decryptText = decryptText + " "

    return decryptText
"""
    Crypte le contenu d'un fichier texte
"""
def encryptFile(file, key):
    file = open(file, 'r')
    text = file.read()
    file.close()
    encryptFile = encryptTextKey(text, key)
    file = open('texte_crypte', 'w')
    file.write(encryptFile)
    file.close()


"""
    Décrypte le contenu d'un fichier
"""
def decryptFile(file, key):
    file = open(file, 'r')
    encryptText = file.read()
    file.close()
    decryptText = decryptTextKey(encryptText, key)
    file = open('texte_decrypte', 'w')
    file.write(decryptText)
    file.close()


def cesar_crypted(text, shift):
    os.system('clear')
    print ("======= CRYPTAGE =======")
    encrypttext = encryptText(text, int(shift))
    print ("Texte crypté : ", encrypttext)
    return (encrypttext)

def cesar_crypted2(text, shift):
    os.system('clear')
    print ("======= CRYPTAGE =======")
    encrypttext = encryptText(text, int(shift))
    print ("Texte crypté : ", encrypttext)
    return (encrypttext)

def cesar_decrypted(encryptText, shift):
    os.system('clear')
    print ("======= DECRYPTAGE =======")
    decrypttext = decryptText(encryptText, int(shift))
    print ("Texte décrypté : ", decrypttext)
    return (decrypttext)

def cesar_decrypted2(encryptText, shift):
    # os.system('clear')
    # print ("======= DECRYPTAGE =======")
    decrypttext = decryptText(encryptText, int(shift))
    # print ("Texte décrypté : ", decrypttext)
    return (decrypttext)

def try_force_brut(msg, key):
    mystery = cesar_crypted2(msg, key)
    force = ""
    i = 0
    debut = time.time()
    while (mystery != force) :
        force = cesar_decrypted2(mystery, i)
        i += 1
    fin = time.time()
    return (fin - debut)
