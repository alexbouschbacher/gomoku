/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** display
*/

#include "../../include/gomoku.h"

void    print_piece(unsigned int * array, int array_size, int x, int y)
{
    if (array[y * array_size + x] == 1)
        printf("\033[0;31m");
    else if (array[y * array_size + x] == 2)
        printf("\033[0;34m");
    printf("%d", array[y * array_size + x]);
    printf("\033[0m");
}

void    print_array(unsigned int * array, int array_size, int x, int y)
{
    if (y == -2) {
        printf("%s%d%s", x == 0 ? "   | " : "", x, x < 10 ? "  " : " ");
    } else if (y == -1) {
        printf("%s---", x == 0 ? "---|-" : "");
    } else {
        if (x == 0)
            printf("%d%s| ", y, y < 10 ? "  " : " ");
        print_piece(array, array_size, x, y);
        if (x != array_size - 1)
            printf(", ");
    }
}

void    display_array(unsigned int * array, int array_size)
{
    for (int y = -2; y < array_size; y++) {
        for (int x = 0; x < array_size; x++)
            print_array(array, array_size, x, y);
        printf("\n");
    }
    printf("\n");
}

int     display(gomoku_t * gomoku, char **input_tab)
{
    (void)input_tab;
    if (gomoku->game_started == false)
        return (1);
    display_array(gomoku->map, gomoku->map_size);
    return (0);
}