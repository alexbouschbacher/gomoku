/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** static_eval_diag
*/

#include "../../include/gomoku.h"

group_t *get_diagonal_left(unsigned int *map, int offset)
{
    group_t *col = malloc(sizeof(col) * 20);
    int x = offset;
    int j = 0;
    int first = 1;

    col[j].nb = 0;
    for (int y = -1; ++y < SIZE; x--) {
        if (x < SIZE && x >= 0) {
            if (first-- == 1)
                col[0].turn = map[y * SIZE + x];
            if (map[y * SIZE + x] == col[j].turn) {
                col[j].nb += 1;
            } else {
                col[j++].have_next = 1;
                col[j].turn = map[y * SIZE + x];
                col[j].nb = 1;
            }
        }
    }
    col[j].have_next = 0;
    return (col);
}

int score_diagonal_left(gomoku_t *gomoku, int pos, unsigned int find)
{
    group_t *diag = get_diagonal_left(gomoku->map, pos);
    int score = 0;

    // printf("diag left: ");
    for (int i = 0; i < 20; i++) {
        // printf(" %d-%d ", diag[i].nb, diag[i].turn);
        if (diag[i].have_next == 0)
            break;
    }
    if (is_end(diag, find) == 1)
        score = INFINI;
    else
        score = calc_line(diag, find);
    // printf("%d = %d\n", pos, score);
    return (score);
}

group_t *get_diagonal_right(unsigned int *map, int offset)
{
    group_t *col = malloc(sizeof(col) * 20);
    int x = offset - SIZE;
    int j = 0;
    int first = 1;

    col[j].nb = 0;
    for (int y = -1; ++y < SIZE; x++) {
        if (x < SIZE && x >= 0) {
            if (first-- == 1)
                col[0].turn = map[y * SIZE + x];
            if (map[y * SIZE + x] == col[j].turn) {
                col[j].nb += 1;
            } else {
                col[j++].have_next = 1;
                col[j].turn = map[y * SIZE + x];
                col[j].nb = 1;
            }
        }
    }
    col[j].have_next = 0;
    return (col);
}

int score_diagonal_right(gomoku_t *gomoku, int pos, unsigned int find)
{
    group_t *diag = get_diagonal_right(gomoku->map, pos);
    int score = 0;

    // printf("diag right: ");
    for (int i = 0; i < 20; i++) {
        // printf(" %d-%d ", diag[i].nb, diag[i].turn);
        if (diag[i].have_next == 0)
            break;
    }
    if (is_end(diag, find) == 1)
        score = INFINI;
    else
        score = calc_line(diag, find);
    // printf("%d = %d\n", pos, score);
    free(diag);
    return (score);
}
