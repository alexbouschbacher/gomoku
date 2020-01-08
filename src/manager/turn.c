/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** turn
*/

#include "../../include/gomoku.h"

int turn(gomoku_t *gomoku, char **input_tab)
{
    char **pos = NULL;
    unsigned int x = 0;
    unsigned int y = 0;

    if (gomoku->game_started == false)
        return (1);
    if (tab_len(input_tab) == 2) {
        pos = str_to_word_array(input_tab[1], ",");
        if (tab_len(pos) != 2)
            return (1);
        x = atoi(pos[0]);
        y = atoi(pos[1]);
        if (x > gomoku->map_size || y > gomoku->map_size)
            return (1);
        update_map(gomoku, x, y, HIS_TURN);
    } else
        return (1);
    if (gomoku->turn != 0 && game_over(*gomoku)) {
        gomoku->game_ended = true;
        return (1);
    }
    gomoku->turn = MY_TURN;
    return (0);
}