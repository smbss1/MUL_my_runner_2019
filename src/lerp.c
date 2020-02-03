/*
** EPITECH PROJECT, 2019
** lerp
** File description:
** linear lerping
*/

float lerp(float a, float b, float f)
{
    return (1 - f) * a + f * b;
}