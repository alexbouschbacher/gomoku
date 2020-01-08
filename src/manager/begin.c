/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** begin
*/

#include "../../include/gomoku.h"

int begin(gomoku_t *gomoku, char **input_tab)
{
    (void)input_tab;
    if (gomoku->game_started == false)
        return (1);
    gomoku->turn = MY_TURN;
    return (0);
}