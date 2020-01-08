/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** ia_utils
*/

#include "../../include/gomoku.h"

unsigned int * best_pos(unsigned int * pos, bool state)
{
    static unsigned int * best_pos = NULL;

    if (state == true) {
        if (best_pos == NULL)
            best_pos = malloc(sizeof(int) * 2);
        best_pos[0] = pos[0];
        best_pos[1] = pos[1];
    }
    return (best_pos);
}

gomoku_t    copy_gomoku(gomoku_t gomoku)
{
    gomoku_t copy = gomoku;
    unsigned int * copy_map = malloc(sizeof(int) * pow(gomoku.map_size, 2));

    for (int i = 0; i < pow(gomoku.map_size, 2); i++)
        copy_map[i] = gomoku.map[i];
    copy.map = copy_map;
    return (copy);
}

void        update_map(
    gomoku_t * gomoku, unsigned int x, unsigned int y, unsigned int player)
{
    gomoku->map[y * gomoku->map_size + x] = player;
}

int         game_over(gomoku_t gomoku)
{
    for(int i = 0; i < SIZE; i++) {
        if (is_end(get_line(gomoku.map, i * SIZE, (i+1) * SIZE), MY_TURN) == 1\
        || is_end(get_line(gomoku.map, i * SIZE, (i+1) * SIZE), HIS_TURN) == 1\
        || is_end(get_col(gomoku.map, i), MY_TURN) == 1\
        || is_end(get_col(gomoku.map, i), HIS_TURN) == 1)
            return (1);
    }
    for(int i = 0; i < SIZE * 2 - 1; i++) {
        if (is_end(get_diagonal_left(gomoku.map, i), MY_TURN) == 1 \
        || is_end(get_diagonal_left(gomoku.map, i), HIS_TURN) == 1)
            return (1);
    }
    for(int i = 1; i < SIZE * 2; i++) {
        if (is_end(get_diagonal_right(gomoku.map, i), MY_TURN) == 1 \
        || is_end(get_diagonal_right(gomoku.map, i), HIS_TURN) == 1)
            return (1);
    }
    return (0);
}
