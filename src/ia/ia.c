/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** ia
*/

#include "../../include/gomoku.h"

void    ia_random(gomoku_t gomoku)
{
    unsigned int x = rand() % gomoku.map_size;
    unsigned int y = rand() % gomoku.map_size;

    best_pos((unsigned int[2]){x, y}, true);
}

int my_turn(gomoku_t gomoku, int depth, int player)
{
    int eval = 0;
    int max_eval = -INFINI;
    unsigned int * childs = get_childs(gomoku);

    for (unsigned int i = 0; i < pow(gomoku.map_size, 2); i++) {
        if (childs[i] == false)
            continue;
        update_map(&gomoku, i % gomoku.map_size, i / gomoku.map_size, player);

        // printf("MY TURN - %d DEPTH\n", depth);
        // display_array(childs, gomoku.map_size);
        // display_array(gomoku.map, gomoku.map_size);

        eval = minmax(gomoku, depth - 1, HIS_TURN);
        // printf("case %d = score %d\n", i, eval);
        update_map(&gomoku, i % gomoku.map_size, i / gomoku.map_size, 0);

        max_eval = MAX(max_eval, eval);
        if (depth == DEPTH && max_eval == eval) {
            best_pos((unsigned int[2]){
                i % gomoku.map_size, i / gomoku.map_size}, true);
        }
        gomoku.pruning.alpha = MAX(gomoku.pruning.alpha, eval);
        if (gomoku.pruning.beta <= gomoku.pruning.alpha)
            break;
    }
    free(childs);
    return (max_eval);
}

int his_turn(gomoku_t gomoku, int depth, int player)
{
    int eval = 0;
    int min_eval = INFINI;
    unsigned int * childs = get_childs(gomoku);

    for (unsigned int i = 0; i < pow(gomoku.map_size, 2); i++) {
        if (childs[i] == false)
            continue;
        update_map(&gomoku, i % gomoku.map_size, i / gomoku.map_size, player);

        // printf("ENNEMI TURN - %d DEPTH\n", depth);
        // display_array(childs, gomoku.map_size);
        // display_array(gomoku.map, gomoku.map_size);

        // eval = minmax(gomoku, depth - 1, player == 1 ? 2 : 1);
        eval = minmax(gomoku, depth - 1, MY_TURN);
        update_map(&gomoku, i % gomoku.map_size, i / gomoku.map_size, 0);

        min_eval = MIN(min_eval, eval);
        gomoku.pruning.beta = MIN(gomoku.pruning.beta, eval);
        if (gomoku.pruning.beta <= gomoku.pruning.alpha)
            break;
    }
    free(childs);
    return (min_eval);
}

int minmax(gomoku_t gomoku, int depth, int player)
{
    if (depth == 0 || game_over(gomoku))
        return (static_evaluation(&gomoku));
    if (player == MY_TURN)
        return (my_turn(gomoku, depth, player));
    return (his_turn(gomoku, depth, player));
}

int     ia(gomoku_t * gomoku)
{
    unsigned int * play_pos = NULL;
    gomoku_t copy = copy_gomoku(*gomoku);

    minmax(copy, DEPTH, MY_TURN);
    if (best_pos(NULL, false) == NULL)
        ia_random(copy);
    play_pos = best_pos(NULL, false);
    update_map(gomoku, play_pos[0], play_pos[1], MY_TURN);
    printf("%d,%d\n", play_pos[0], play_pos[1]);
    if (game_over(*gomoku)) {
        gomoku->game_ended = true;
    } else
        gomoku->turn = HIS_TURN;
    fflush(stdout);
    return (0);
}
