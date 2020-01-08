/*
** EPITECH PROJECT, 2019
** Sans titre(Espace de travail)
** File description:
** gomoku
*/

#ifndef GOMOKU_H_
#define GOMOKU_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>
    #include <time.h>

    #define MY_TURN 1
    #define HIS_TURN 2

    #define DEPTH 1

    #define INFINI 1000000
    #define SIZE 19

    #define NBR_MANAGER_COMMAND 6
    #define MAX(x,y) ((x) >= (y)) ? (x) : (y)
    #define MIN(x,y) ((x) <= (y)) ? (x) : (y)

    typedef struct pruning_s {
        int alpha;
        int beta;
    } pruning_t;

    typedef struct gomoku_s {
        unsigned int *  map;
        unsigned int    map_size;
        unsigned int    turn;
        bool            game_started;
        bool            game_ended;
        pruning_t       pruning;
    } gomoku_t;

    struct command_struct {
        char * name;
        int (*manager_fptr)(gomoku_t *gomoku, char **input_tab);
    };

    typedef struct group_s {
        unsigned int    nb;
        unsigned int    turn;
        int             have_next;
    } group_t;

    /* ------------ MANAGER ----------- */
    int     manager_command(gomoku_t * gomoku, char **input_tab);
    int     start(gomoku_t * gomoku, char **input_tab);
    int     begin(gomoku_t * gomoku, char **input_tab);
    int     board(gomoku_t * gomoku, char **input_tab);
    int     end(gomoku_t * gomoku, char **input_tab);
    int     turn(gomoku_t * gomoku, char **input_tab);
    int     display(gomoku_t * gomoku, char **input_tab);
    void    display_array(unsigned int * array, int array_size);


    /* ------------ IA ----------- */
    int ia(gomoku_t * gomoku);
    int minmax(gomoku_t gomoku, int depth, int player);
    int my_turn(gomoku_t gomoku, int depth, int player);
    int his_turn(gomoku_t gomoku, int depth, int player);

        /* ------------ IA | Utils ----------- */
        unsigned int *  best_pos(unsigned int * pos, bool state);
        gomoku_t        copy_gomoku(gomoku_t gomoku);
        void            update_map(
            gomoku_t * gomoku, unsigned int x,
            unsigned int y, unsigned int player);
        int             game_over(gomoku_t gomoku);

        /* ------------ IA | GetChilds ----------- */
        unsigned int *  get_childs(gomoku_t gomoku);
        void            check_case(
            gomoku_t gomoku, unsigned int * childs,
            unsigned int x, unsigned int y);
        void            browse_surroundings(
            gomoku_t gomoku, unsigned int * childs,
            unsigned int x, unsigned int y);

        /* ------------ IA | StaticEvaluation ----------- */
        int         static_evaluation(gomoku_t *gomoku);
        int         score_line(gomoku_t *gomoku, int pos, unsigned int find);
        int         score_col(gomoku_t *gomoku, int pos, unsigned int find);
        int         score_diagonal_left(
            gomoku_t *gomoku, int pos, unsigned int find);
        int         score_diagonal_right(
            gomoku_t *gomoku, int pos, unsigned int find);
        group_t *   get_line(unsigned int *map, int start, int end);
        group_t *   get_col(unsigned int *map, int offset);
        group_t *   get_diagonal_left(unsigned int *map, int offset);
        group_t *   get_diagonal_right(unsigned int *map, int offset);

        /* ------------ IA | StaticEvaluation Utils ----------- */
        int calc_line(group_t *line, unsigned int find);
        int is_alone(group_t *line, int i, int len);
        int is_end(group_t *line, unsigned int find);
        int is_lock(group_t *line, int i, unsigned int find);
        int is_group(group_t *line, int i, int len, unsigned int find);


    /* ------------ UTILS ----------- */
    char ** str_to_word_array(char *str, char *delim);
    void    free_input(char ** input, char **input_tab);
    int     tab_len(char **tab);


#endif /* !GOMOKU_H_ */
