/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** board
*/

#include "../../include/gomoku.h"

void    add_piece_to_map(gomoku_t *gomoku, char **pos) {
    unsigned int x = atoi(pos[0]);
    unsigned int y = atoi(pos[1]);
    unsigned int player = atoi(pos[2]);

    update_map(gomoku, x, y, player);
}

int     board(gomoku_t *gomoku, char **input_tab)
{
    char *input = NULL;
    char **pos = NULL;
    size_t input_size = 0;

    (void)input_tab;
    if (gomoku->game_started == false)
        return (1);
    while (getline(&input, &input_size, stdin)) {
        input = strtok(input, "\n");
        if (!strcmp(input, "DONE"))
            break;
        pos = str_to_word_array(input, ",");
        if (tab_len(pos) != 3)
            return (1);
        add_piece_to_map(gomoku, pos);
    }
    gomoku->turn = MY_TURN;
    return (0);
}