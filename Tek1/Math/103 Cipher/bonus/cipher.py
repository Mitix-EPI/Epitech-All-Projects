#!/usr/bin/env python3

import sys
import os
from sys import stderr
from math import *
import six

def print_h():
    print("USAGE\n    ./103cipher message key flag\n\nDESCRIPTION\n    message     a message, made of ASCII characters\n    key         the encryption key, made of ASCII characters\n    flag        0 for the message to be encrypted, 1 to be decrypted")

# def check_args():
#     if (len(sys.argv) == 1):
#         sys.exit(84)
#     if (msg == "-h"):
#         print_h()
#         sys.exit(0)
#     if (len(sys.argv) != 4):
#         sys.exit(84)
#     try :
#         flag = int(i)
#     except:
#         sys.exit(84)

def print_key_matrix(matrice_key, limit):
    matrice_key_text = []
    print("Key matrix:")
    k = 0
    for a in range(limit):
        for b in range(limit):
            print("%i"%matrice_key[k], end = "")
            k += 1
            if (b + 1 < limit) :
                print("\t", end = "")
        print()
    print()

def cryptage(matrice_key, matrice_msg, limit):
    encrypted_text = []
    print_key_matrix(matrice_key, limit)
    print("Encrypted message:")
    p = 0
    line = 0
    for x in range(len(matrice_msg)):
        calcul = 0
        for y in range(limit):
            # print(p)
            # print(matrice_key[p])
            # print(matrice_msg[y + line])
            calcul += (matrice_key[p] * matrice_msg[y + line])
            p += limit
        #print(calcul, end = ' ')
        encrypted_text.append(str(calcul))
        if (x + 1) % limit == 0:
            # print("j'ai fait trois fois")
            line += limit
            p = 0
        else :
            # print("je rentre")
            p -= limit * limit
            p += 1
    res = " ".join(encrypted_text)
    print(res, end = "")
    print()
    return (res)

def create_new_matrice_separated(msg_base, matrice_crypted, matrice_key, limit, new_list_crypted, new_list_key):
    matrice_crypted = msg_base
    cache = list(map(int, matrice_crypted.split(' ')))
    matrice_crypted = cache
    #new_list_crypted = []
    a = 0
    b = 0
    i = 0
    while (i < len(matrice_crypted)):
        new_list_crypted.append([])
        b = 0
        while (b < limit):
            new_list_crypted[a].append(matrice_crypted[i])
            b += 1
            i+=1
        a+=1
    #print(new_list_crypted)
    #new_list_key = []
    a = 0
    b = 0
    i = 0
    while (a < limit):
            new_list_key.append([])
            b = 0
            while (b < limit):
                new_list_key[a].append(matrice_key[i])
                b += 1
                i += 1
            a += 1
    #print(new_list_key)
    return new_list_crypted, new_list_key

def transvection_ligne(M, i, j, l):
    M[i] = [M[i][k] + l * M[j][k] for k in range(len(M[i]))]
    return M

def echange_lignes(M, i, j):
    M[i], M[j] = M[j], M[i]
    return M

def recherche_pivot_lignes(M, i):
    m = abs(M[i][i])
    j = i
    for k in range(i + 1, len(M)):
        if abs(M[i][j]) > m:
            j = k
    return j

def extract_inverse(M):
    return [L[len(M):] for L in M]

def dilatation_ligne(M, i, l):
    M[i] = [coeff * l for coeff in M[i]]
    return M

def pivot_lignes_rebours(M):
    for i in reversed(range(len(M))):
        if (M[i][i] == 0):
            stderr.write("Error\n")
            M[i][i] = 1
        dilatation_ligne(M, i, 1 / M[i][i])
        for j in range(i):
            transvection_ligne(M, j, i, -M[j][i])
    return M

def concat_identite(A):
    return [A[i] + [1 if j== i else 0 for j in range(len(A))] for i in range(len(A))]

def pivo_lignes(M):
    for i in range(len(M)):
        j = recherche_pivot_lignes(M, i)
        if j != i:
            echange_lignes(M, i, j)
        if M[i][i] != 0:
            for j in range(i + 1, len(M)):
                transvection_ligne(M, j, i, -M[j][i] / M[i][i])
    return M

def inverse(A):
    M = concat_identite(A)
    pivo_lignes(M)
    pivot_lignes_rebours(M)
    return extract_inverse(M)

def print_inverse_key(test, limit):
    matrice_key_text = []
    print("Key matrix:")
    k = 0
    for a in range(limit):
        for b in range(limit):
            if (round(test[a][b], 3) == 0.000):
                print("0.0", end = "")
            else :
                print(round(float(test[a][b]), 3), end = "")
            if (b + 1 < limit) :
                print("\t", end = "")
        print()
    print()

def produit(A, B):
    return [[sum(L[k] * B[k][j] for k in range(len(L))) for j in range(len(B[0]))] for L in A]

def traduction(A, limit):
    res = ""
    print("Decrypted message:")
    for i in range(len(A)):
        for j in range(limit):
            if round(A[i][j]) == 0:
                print()
                return 0
            char = chr(round(A[i][j]))
            res += char
            print(char, end = "")
    print()
    return (char)

def decryptage(msg_base, matrice_key, matrice_msg,limit, matrice_crypted):
    new_list_key = []
    new_list_crypted = []
    create_new_matrice_separated(msg_base, matrice_crypted, matrice_key, limit, new_list_crypted, new_list_key)
    #print(new_list_key)
    #print(new_list_crypted)
    Test = inverse(new_list_key)
    #print(Test)
    print_inverse_key(Test, limit)
    #print(produit(new_list_crypted, Test))
    return (traduction(produit(new_list_crypted, Test), limit))

def cipher(msg, key, flag):
    #check_args()
    msg_base = msg
    matrice_key = []
    matrice_msg = []
    matrice_crypted = []
    new_list = []
    try :
        limit = int(ceil(sqrt(len(key))))
        for j in range(len(key)):
            matrice_key.append(ord(key[j]))
        j += 1
        while j != (limit * limit):
            j += 1
            matrice_key.append(0)

        for i in range(len(msg)):
            matrice_msg.append(ord(msg[i]))
        i += 1
        while i % limit:
            i += 1
            matrice_msg.append(0)
    except:
        return (84)
    print(flag)
    if (flag == 0):
        os.system('clear')
        print("message :", msg)
        print("clé de sécurité :", key)
        return (cryptage(matrice_key, matrice_msg,limit))
    elif (flag == 1):
        os.system('clear')
        return (decryptage(msg_base, matrice_key, matrice_msg,limit, matrice_crypted))
    else:
        sys.exit(84)
    #print(matrice_msg)
    # print(matrice_key)

#main()
# A = [[1, 5, 6], [2, 11, 19], [3, 19, 47]]
# B = inverse(A)
# print(B)