/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** static_eval
*/

#include "../../include/gomoku.h"

group_t *get_line(unsigned int *map, int start, int end)
{
    group_t *line = malloc(sizeof(line) * 20);
    int j = 0;

    line[j].nb = 0;
    line[j].turn = map[start];
    for (int i = start; i < end; i++) {
        if (map[i] == line[j].turn) {
            line[j].nb += 1;
        } else {
            line[j].have_next = 1;
            j++;
            line[j].turn = map[i];
            line[j].nb = 1;
        }
    }
    line[j].have_next = 0;
    return (line);
}

int score_line(gomoku_t *gomoku, int pos, unsigned int find)
{
    group_t *line = get_line(gomoku->map, pos * SIZE, (pos + 1) * SIZE);
    int score = 0;

    // printf("line: ");
    for (int i = 0; i < 20; i++) {
        // printf(" %d-%d ", line[i].nb, line[i].turn);
        if (line[i].have_next == 0)
            break;
    }
    if (is_end(line, find) == 1)
        score = INFINI;
    else
        score = calc_line(line, find);
    // printf("%d = %d\n", pos, score);
    free(line);
    return (score);
}

group_t *get_col(unsigned int *map, int offset)
{
    group_t *col = malloc(sizeof(col) * 20);
    int j = 0;

    col[j].nb = 0;
    col[j].turn = map[offset];
    for (int i = 0; i < SIZE; i++) {
        if (map[i * SIZE + offset] == col[j].turn) {
            col[j].nb += 1;
        } else {
            col[j].have_next = 1;
            j++;
            col[j].turn = map[i * SIZE + offset];
            col[j].nb = 1;
        }
    }
    col[j].have_next = 0;
    return (col);
}

int score_col(gomoku_t *gomoku, int pos, unsigned int find)
{
    group_t *col = get_col(gomoku->map, pos);
    int score = 0;

    for (int i = 0; i < 20; i++) {
        if (col[i].have_next == 0)
            break;
    }
    if (is_end(col, find) == 1)
        score = INFINI;
    else
        score = calc_line(col, find);
    free(col);
    return (score);
}

int static_evaluation(gomoku_t *gomoku)
{
    long score = 0;

    for(int i = 0; i < SIZE; i++) {
        score += score_line(gomoku, i, MY_TURN);
        score -= score_line(gomoku, i, HIS_TURN);
        score += score_col(gomoku, i, MY_TURN);
        score -= score_col(gomoku, i, HIS_TURN);
    }
    // printf("%d\n", score);
    for(int i = 0; i < SIZE * 2 - 1; i++) {
        // printf("-----%d-------\n", i);
        score += score_diagonal_left(gomoku, i, MY_TURN);
        // printf("%d\n", score);
        score -= score_diagonal_left(gomoku, i, HIS_TURN);
        // printf("%d\n", score);
    }
    // printf("%d\n", score);
    for(int i = 1; i < SIZE * 2; i++) {
        score += score_diagonal_right(gomoku, i, MY_TURN);
        score -= score_diagonal_right(gomoku, i, HIS_TURN);
    }
    // printf("%d\n", score);
    if (score > INFINI)
        score = INFINI;
    if (score < -INFINI)
        score = -INFINI;
    return ((int)score);
}
