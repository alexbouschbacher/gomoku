/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** get_childs
*/

#include "../../include/gomoku.h"

const int surroundings[8][2] = {
    {-1, 1}, {0, 1}, {1, 1}, {1, 0},
    {1, -1}, {0, -1}, {-1, -1}, {-1, 0}
};

void    browse_surroundings(
    gomoku_t gomoku, unsigned int * childs, unsigned int x, unsigned int y)
{
    int offseted_x = 0;
    int offseted_y = 0;
    int coord = 0;

    for (int i = 0; i < 8; i++) {
        offseted_x = x + surroundings[i][0];
        offseted_y = y + surroundings[i][1];
        if (offseted_x < 0 || offseted_x >= (int)gomoku.map_size ||
            offseted_y < 0 || offseted_y >= (int)gomoku.map_size)
                continue;
        coord = offseted_y * gomoku.map_size + offseted_x;
        if (gomoku.map[coord] == 0 && childs[coord] == false)
            childs[coord] = true;
    }
}

void    check_case(
    gomoku_t gomoku, unsigned int * childs, unsigned int x, unsigned int y)
{
    if (gomoku.map[y * gomoku.map_size + x] != 0)
        browse_surroundings(gomoku, childs, x, y);
}

unsigned int *  get_childs(gomoku_t gomoku)
{
    unsigned int * childs = malloc(sizeof(unsigned) * pow(gomoku.map_size, 2));

    memset(childs, false, sizeof(unsigned) * pow(gomoku.map_size, 2));
    for (unsigned int x = 0; x < gomoku.map_size; x++)
        for (unsigned int y = 0; y < gomoku.map_size; y++)
            check_case(gomoku, childs, x, y);
    return (childs);
}