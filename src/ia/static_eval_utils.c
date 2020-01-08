/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** static_eval_utils
*/

#include "../../include/gomoku.h"

int is_end(group_t *line, unsigned int find)
{
    for (int i = 0; 1 ;i++) {
        if (line[i].nb == 5 && line[i].turn == find)
            return (1);
        if (line[i].have_next == 0)
            break;
    }
    return (0);
}

int is_win(group_t *line, unsigned int find, int len)
{
    for (int i = 0; i < len - 2; i++) {
        if (line[i].nb >= 1 && line[i].turn == 0 && line[i+1].nb == 4 &&
            line[i+1].turn == find && line[i+2].nb >= 1 && line[i+2].turn == 0)
            return (1);
    }
    return (0);
}

int is_alone(group_t *line, int i, int len)
{
    if (i == 0 || i == len - 1)
        return 1;
    if (line[i-1].turn == 0 && line[i+1].turn == 0)
        if (line[i-1].nb + line[i].nb + line[i+1].nb >= 6)
            return 2;
    return 1;
}

int is_lock(group_t *line, int i, unsigned int find)
{
    unsigned int opp = (find == MY_TURN) ? HIS_TURN : MY_TURN;

    if (i == 0 && line[i + 1].turn == opp)
        return (1);
    if (line[i].have_next == 0 && line[i - 1].turn == opp)
        return (1);
    if (line[i - 1].turn == opp && line[i + 1].turn == opp)
        return (1);
    return (0);
}

int is_group(group_t *line, int i, int len, unsigned int find)
{
    if (i == len - 2)
        return 1;
    if (line[i+1].turn == 0 && line[i+1].nb == 1 && line[i+2].turn == find)
        if (line[i].nb + line[i+1].nb + line[i+2].nb >= 5)
            return 2;
    return 1;
}

int calc_line(group_t *line, unsigned int find)
{
    int len = 0;
    int score = 0;

    while(line[len++].have_next);
    for (int i = 0; i < len; i++) {
        if (line[i].turn == find) {
            // printf("group %d is lock = %d\n", i, is_lock(line, i, find));
            if (is_lock(line, i, find) == 1)
                score += 0;
            else
                score += line[i].nb * is_alone(line, i, len);
                // * is_group(line, i, len, find);
        }
    }
    return (score);
}
