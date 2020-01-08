/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** utils
*/

#include "../include/gomoku.h"

char ** str_to_word_array(char *str, char *delim)
{
    char **tab;
    int i = 0;

    if (str == NULL)
        return (NULL);
    tab = malloc(sizeof(char *) * 4);
    tab[i] = strtok(str, delim);
    while (tab[i] != NULL)
        tab[++i] = strtok(NULL, delim);
    return (tab);
}

void free_input(char ** input, char **input_tab)
{
    // for (int i = 0; input_tab[i] != NULL; i++)
        // free(input_tab[i]);
    free(input_tab);
    free(*input);
    input_tab = NULL;
    *input = NULL;
}

int tab_len(char **tab)
{
    unsigned int count = 0;

    for (int i = 0; tab[i] != NULL; i++)
        count++;
    return (count);
}