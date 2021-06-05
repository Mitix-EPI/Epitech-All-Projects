/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** pacman walls
*/

#include "PacmanWalls.hpp"


bool isInside(char c)
{
    if (c == 'd' || c == ' ' || c == 'O' || c == 'P')
        return true;
    return false;
}
bool isOutside(char c)
{
    if (c == '-')
        return true;
    return false;
}
bool isWall(char c)
{
    if (c == '#')
        return true;
    return false;
}
bool isMonsterSpawn(char c)
{
    if (c == '+' || c == '1' || c == '2' || c == '3' || c == '4')
        return true;
    return false;
}
bool isMonsterDoor(char c)
{
    if (c == '_')
        return true;
    return false;
}

Vector2i createWalls(std::unordered_map<std::string, char> square)
{
    if (isOutside(square["uleft"]) &&
        isWall(square["left"])&&
        isInside(square["dleft"]) &&
        isWall(square["down"]) &&
        isOutside(square["dright"]) &&
        isOutside(square["right"]) &&
        isOutside(square["uright"]) &&
        isOutside(square["up"]))
        return Vector2i(0, 0);
    else if (isInside(square["uleft"])&&
        isWall(square["left"]) &&
        isOutside(square["dleft"]) &&
        isWall(square["down"]) &&
        isInside(square["dright"])&&
        isInside(square["right"])&&
        isInside(square["uright"])&&
        isInside(square["up"]))
        return Vector2i(54, 9);
    else if (isInside(square["uleft"])&&
        isInside(square["left"]) &&
        isInside(square["dleft"]) &&
        isWall(square["down"]) &&
        isOutside(square["dright"])&&
        isWall(square["right"]) &&
        isInside(square["uright"])&&
        isInside(square["up"]))
        return Vector2i(63, 9);
    else if (isOutside(square["uleft"]) &&
        isOutside(square["left"]) &&
        isOutside(square["dleft"]) &&
        isWall(square["down"]) &&
        isInside(square["dright"]) &&
        isWall(square["right"]) &&
        isOutside(square["uright"]) &&
        isOutside(square["up"]))
        return Vector2i(9, 0);
    else if ((isInside(square["uleft"]) || isWall(square["uleft"])) &&
        isInside(square["left"] ) &&
        (isInside(square["dleft"]) || isWall(square["dleft"])) &&
        isWall(square["down"]) &&
        (isOutside(square["dright"]) || isWall(square["dright"])) &&
        isOutside(square["right"]) &&
        (isOutside(square["uright"]) || isWall(square["uright"])) &&
        isWall(square["up"]))
        return Vector2i(18, 0);
    else if ((isOutside(square["uleft"]) || isWall(square["uleft"])) &&
        isOutside(square["left"]) &&
        (isOutside(square["dleft"]) || isWall(square["dleft"])) &&
        isWall(square["down"]) &&
        (isInside(square["dright"]) || isWall(square["dright"])) &&
        isInside(square["right"]) &&
        (isInside(square["uright"]) || isWall(square["uright"])) &&
        isWall(square["up"]))
        return Vector2i(27, 0);
    else if (isOutside(square["uleft"])&&
        isWall(square["left"]) &&
        isInside(square["dleft"]) &&
        isInside(square["down"]) &&
        isInside(square["dright"]) &&
        isInside(square["right"]) &&
        isInside(square["uright"]) &&
        isWall(square["up"]))
        return Vector2i(90, 9);
    else if (isInside(square["uleft"]) &&
        isWall(square["left"]) &&
        isOutside(square["dleft"]) &&
        isOutside(square["down"]) &&
        isOutside(square["dright"]) &&
        isOutside(square["right"]) &&
        isOutside(square["uright"]) &&
        isWall(square["up"]))
        return Vector2i(36, 0); // 36, 0
    else if (isInside(square["uleft"])&&
        isInside(square["left"]) &&
        isInside(square["dleft"]) &&
        isInside(square["down"]) &&
        isInside(square["dright"]) &&
        isWall(square["right"]) &&
        isOutside(square["uright"]) &&
        isWall(square["up"]))
        return Vector2i(99, 9);
    else if (isOutside(square["uleft"]) &&
        isOutside(square["left"]) &&
        isOutside(square["dleft"]) &&
        isOutside(square["down"]) &&
        isOutside(square["dright"]) &&
        isWall(square["right"]) &&
        isInside(square["uright"]) &&
        isWall(square["up"]))
        return Vector2i(45, 0);
    else if (isInside(square["uleft"]) &&
        isWall(square["left"]) &&
        isWall(square["dleft"]) &&
        isWall(square["down"]) &&
        isOutside(square["uright"]) &&
        isOutside(square["right"]) &&
        isOutside(square["dright"]) &&
        isWall(square["up"]))
        return Vector2i(54, 0);
    else if (isInside(square["uright"]) &&
        isWall(square["right"]) &&
        isWall(square["dright"]) &&
        isWall(square["down"]) &&
        isOutside(square["dleft"]) &&
        isOutside(square["left"]) &&
        isOutside(square["uleft"]) &&
        isWall(square["up"]))
        return Vector2i(63, 0);
    else if (isInside(square["dleft"]) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isWall(square["down"]) &&
        isOutside(square["uright"]) &&
        isOutside(square["right"]) &&
        isOutside(square["dright"]) &&
        isWall(square["up"]))
        return Vector2i(72, 0);
    else if (isInside(square["dright"]) &&
        isWall(square["right"]) &&
        isWall(square["uright"]) &&
        isWall(square["down"]) &&
        isOutside(square["dleft"]) &&
        isOutside(square["left"]) &&
        isOutside(square["uleft"]) &&
        isWall(square["up"]))
        return Vector2i(81, 0);
    else if ((isInside(square["dleft"]) || isWall(square["dleft"])) &&
        isWall(square["left"]) &&
        (isOutside(square["uleft"]) || isWall(square["uleft"])) &&
        isOutside(square["up"]) &&
        (isOutside(square["uright"]) || isWall(square["uright"])) &&
        isWall(square["right"]) &&
        (isInside(square["dright"]) || isWall(square["dright"])) &&
        isInside(square["down"]))
        return Vector2i(90, 0);
    else if (isOutside(square["dleft"]) &&
        isOutside(square["left"]) &&
        isOutside(square["uleft"]) &&
        isOutside(square["up"]) &&
        isOutside(square["uright"]) &&
        isWall(square["right"]) &&
        isInside(square["dright"]) &&
        isInside(square["down"]))
        return Vector2i(90, 0);
    else if (isInside(square["dleft"]) &&
        isWall(square["left"]) &&
        isOutside(square["uleft"]) &&
        isOutside(square["up"]) &&
        isOutside(square["uright"]) &&
        isOutside(square["right"]) &&
        isOutside(square["dright"]) &&
        isInside(square["down"]))
        return Vector2i(90, 0);
    else if ((isInside(square["uleft"]) || isWall(square["uleft"])) &&
        isWall(square["left"]) &&
        (isOutside(square["dleft"]) || isWall(square["dleft"])) &&
        isOutside(square["down"]) &&
        (isOutside(square["dright"]) || isWall(square["dright"])) &&
        isWall(square["right"]) &&
        (isInside(square["uright"]) || isWall(square["uright"])) &&
        isInside(square["up"]))
        return Vector2i(108, 0);
    else if (isOutside(square["dleft"]) &&
        isWall(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isOutside(square["uright"]) &&
        isOutside(square["right"]) &&
        isOutside(square["dright"]) &&
        isOutside(square["down"]))
        return Vector2i(108, 0);
    else if (isOutside(square["dleft"]) &&
        isOutside(square["left"]) &&
        isOutside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isWall(square["right"]) &&
        isOutside(square["dright"]) &&
        isOutside(square["down"]))
        return Vector2i(108, 0);
    else if (isWall(square["dleft"]) &&
        isWall(square["left"]) &&
        (isInside(square["uleft"]) || isWall(square["uleft"])) &&
        isInside(square["up"]) &&
        (isInside(square["uright"]) || isWall(square["uright"])) &&
        isWall(square["right"]) &&
        isWall(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(126, 0);
    else if (isOutside(square["dleft"]) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isInside(square["right"]) &&
        isInside(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(18, 9);
    else if ((isInside(square["dleft"]) || isWall(square["dleft"])) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isWall(square["up"]) &&
        isWall(square["uright"]) &&
        isWall(square["right"]) &&
        (isInside(square["dright"]) || isWall(square["dright"])) &&
        isInside(square["down"]))
        return Vector2i(36, 9);
    else if (isWall(square["dleft"]) &&
        isWall(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isInside(square["right"]) &&
        isInside(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(54, 9);
    else if (isInside(square["dleft"]) &&
        isInside(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isWall(square["right"]) &&
        isWall(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(63, 9);
    else if (isWall(square["dleft"]) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isWall(square["up"]) &&
        (isInside(square["uright"]) || isWall(square["uright"])) &&
        isInside(square["right"]) &&
        (isInside(square["dright"]) || isWall(square["dright"])) &&
        isWall(square["down"]))
        return Vector2i(72, 9);
    else if ((isInside(square["dleft"]) || isWall(square["dleft"])) &&
        isInside(square["left"]) &&
        (isInside(square["uleft"]) || isWall(square["uleft"])) &&
        isWall(square["up"]) &&
        isWall(square["uright"]) &&
        isWall(square["right"]) &&
        isWall(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(81, 9);
    else if (isInside(square["dleft"]) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isWall(square["up"]) &&
        isInside(square["uright"]) &&
        isInside(square["right"]) &&
        isInside(square["dright"]) &&
        isInside(square["down"]))
        return Vector2i(90, 9);
    else if (isInside(square["dleft"]) &&
        isInside(square["left"]) &&
        isInside(square["uleft"]) &&
        isWall(square["up"]) &&
        isWall(square["uright"]) &&
        isWall(square["right"]) &&
        isInside(square["dright"]) &&
        isInside(square["down"]))
        return Vector2i(99, 9);
    else if (isMonsterSpawn(square["dleft"]) &&
        isWall(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isInside(square["right"]) &&
        isInside(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(108, 9);
    else if (isInside(square["dleft"]) &&
        isInside(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isWall(square["right"]) &&
        isMonsterSpawn(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(117, 9);
    else if (isInside(square["dleft"]) &&
        isWall(square["left"]) &&
        isMonsterSpawn(square["uleft"]) &&
        isWall(square["up"]) &&
        isInside(square["uright"]) &&
        isInside(square["right"]) &&
        isInside(square["dright"]) &&
        isInside(square["down"]))
        return Vector2i(126, 9);
    else if (isInside(square["dleft"]) &&
        isInside(square["left"]) &&
        isInside(square["uleft"]) &&
        isWall(square["up"]) &&
        isMonsterSpawn(square["uright"]) &&
        isWall(square["right"]) &&
        isInside(square["dright"]) &&
        isInside(square["down"]))
        return Vector2i(135, 9);
    else if (isMonsterSpawn(square["dleft"]) &&
        isWall(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isMonsterDoor(square["right"]) &&
        isMonsterSpawn(square["dright"]) &&
        isMonsterSpawn(square["down"]))
        return Vector2i(9, 18);
    else if (isInside(square["dleft"]) &&
        isWall(square["right"]) &&
        isWall(square["uright"]) &&
        isWall(square["down"]) &&
        isWall(square["dright"]) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isWall(square["up"]))
        return Vector2i(27, 18);
    else if (isInside(square["dright"]) &&
        isWall(square["right"]) &&
        isWall(square["uright"]) &&
        isWall(square["down"]) &&
        isWall(square["dleft"]) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isWall(square["up"]))
        return Vector2i(18, 18);
    else if (isInside(square["uright"]) &&
        isWall(square["right"]) &&
        isWall(square["dright"]) &&
        isWall(square["down"]) &&
        isWall(square["dleft"]) &&
        isWall(square["left"]) &&
        isWall(square["uleft"]) &&
        isWall(square["up"]))
        return Vector2i(36, 18);
    else if (isInside(square["uleft"]) &&
        isWall(square["right"]) &&
        isWall(square["uright"]) &&
        isWall(square["down"]) &&
        isWall(square["dleft"]) &&
        isWall(square["left"]) &&
        isWall(square["dright"]) &&
        isWall(square["up"]))
        return Vector2i(45, 18);
    else if (isMonsterSpawn(square["dleft"]) &&
        isMonsterDoor(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isWall(square["right"]) &&
        isMonsterSpawn(square["dright"]) &&
        isMonsterSpawn(square["down"]))
        return Vector2i(0, 18);
    else if (isWall(square["dleft"]) &&
        isWall(square["left"]) &&
        isOutside(square["uleft"]) &&
        isOutside(square["up"]) &&
        isOutside(square["uright"]) &&
        isWall(square["right"]) &&
        isInside(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(90, 18);
    else if (isInside(square["dleft"]) &&
        isWall(square["left"]) &&
        isOutside(square["uleft"]) &&
        isOutside(square["up"]) &&
        isOutside(square["uright"]) &&
        isWall(square["right"]) &&
        isWall(square["dright"]) &&
        isWall(square["down"]))
        return Vector2i(99, 18);
    else if ((isMonsterSpawn(square["dleft"]) || isWall(square["dleft"])) &&
        isWall(square["left"]) &&
        isInside(square["uleft"]) &&
        isInside(square["up"]) &&
        isInside(square["uright"]) &&
        isWall(square["right"]) &&
        (isMonsterSpawn(square["dright"]) || isWall(square["dright"])) &&
        isMonsterSpawn(square["down"]))
        return Vector2i(108, 0);
    else if ((isMonsterSpawn(square["uleft"]) || isWall(square["uleft"])) &&
        isWall(square["left"]) &&
        isInside(square["dleft"]) &&
        isInside(square["down"]) &&
        isInside(square["dright"]) &&
        isWall(square["right"]) &&
        (isMonsterSpawn(square["uright"]) || isWall(square["uright"])) &&
        isMonsterSpawn(square["up"]))
        return Vector2i(90, 0);
    else if ((isMonsterSpawn(square["uright"]) || isWall(square["uright"])) &&
        isMonsterSpawn(square["right"]) &&
        (isMonsterSpawn(square["dright"]) || isWall(square["dright"])) &&
        isWall(square["down"]) &&
        isInside(square["dleft"]) &&
        isInside(square["left"]) &&
        isInside(square["uleft"]) &&
        isWall(square["up"]))
        return Vector2i(18, 0);
    else if ((isMonsterSpawn(square["uleft"]) || isWall(square["uleft"])) &&
        isMonsterSpawn(square["left"]) &&
        (isMonsterSpawn(square["dleft"]) || isWall(square["dleft"])) &&
        isWall(square["down"]) &&
        isInside(square["dright"]) &&
        isInside(square["right"]) &&
        isInside(square["uright"]) &&
        isWall(square["up"]))
        return Vector2i(27, 0);
    return Vector2i(108, 18);
}
