/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** gomoku
*/

#include "../include/gomoku.h"

void    init_gomoku(gomoku_t * gomoku)
{
    gomoku->game_ended = false;
    gomoku->game_started = false;
    gomoku->turn = 0;
    gomoku->pruning = (pruning_t){-INFINI, INFINI};
}

void    read_manager(gomoku_t * gomoku)
{
    char *  input = NULL;
    char ** input_tab = NULL;
    size_t  input_size = 0;
    int     return_value = 0;

    while (gomoku->game_ended == false && getline(&input, &input_size, stdin)) {
        input = strtok(input, "\n");
        if (input == NULL)
            continue;
        input_tab = str_to_word_array(input, " ");
        if ((return_value = manager_command(gomoku, input_tab)) == 1)
            continue;
        if (gomoku->turn == MY_TURN)
            ia(gomoku);
        if (gomoku->game_ended == false && game_over(*gomoku))
            gomoku->game_ended = true;
        free_input(&input, input_tab);
        fflush(stdout);
    }
    free(input);
}

int main(void)
{
    gomoku_t * gomoku = (gomoku_t *)malloc(sizeof(gomoku_t));

    srand(time(NULL));
    init_gomoku(gomoku);
    read_manager(gomoku);
    free(gomoku->map);
    free(gomoku);
    return (0);
}
