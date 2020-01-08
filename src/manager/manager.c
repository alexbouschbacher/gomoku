/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** manager
*/

#include "../../include/gomoku.h"

struct  command_struct command_list[NBR_MANAGER_COMMAND] = {
    {"START", &start},
    {"BOARD", &board},
    {"BEGIN", &begin},
    {"END", &end},
    {"TURN", &turn},
    {"DISPLAY", &display}
};

int     manager_command(gomoku_t * gomoku, char **input_tab)
{
    unsigned int return_value = 1;

    for (int e = 0; e < NBR_MANAGER_COMMAND; e++) {
        if (!strcmp(input_tab[0], command_list[e].name)) {
            return_value = command_list[e].manager_fptr(gomoku, input_tab);
            break;
        }
    }
    fflush(stdout);
    return (return_value);
}
