/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** end
*/

#include "../../include/gomoku.h"

int end(gomoku_t *gomoku, char **input_tab)
{
    (void)input_tab;
    gomoku->game_ended = true;
    return (0);
}