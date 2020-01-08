/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** start
*/

#include "../../include/gomoku.h"

void    init_gomoku_map(gomoku_t * gomoku)
{
    unsigned int map_length = pow(gomoku->map_size, 2);

    gomoku->map = malloc(sizeof(int) * map_length);
    // gomoku->moves = malloc(sizeof(bool) * map_length);
    memset(gomoku->map, 0, sizeof(int) * map_length);
    // memset(gomoku->moves, false, sizeof(bool) * map_length);
}

int start(gomoku_t *gomoku, char **input_tab)
{
    if (gomoku->game_started == true || tab_len(input_tab) == 1)
        return (1);
    if (atoi(input_tab[1]) <= 0) {
        printf("ERROR\n");
        return (1);
    } else
        printf("OK\n");
    gomoku->map_size = 19;
    gomoku->game_started = true;
    init_gomoku_map(gomoku);
    return (0);
}