/*
** EPITECH PROJECT, 2021
** 204ducks [WSL: Ubuntu]
** File description:
** test_ducks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ducks.h"

Test(basic_test, ducks_exit, .exit_code=0)
{
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = "./204ducks";
    arr[1] = "0.6";
    arr[2] = NULL;
    ducks_process(2, (arr_const_restrict)arr);
}

Test(number_with_too_many_decimals, ducks_exit, .exit_code=0)
{
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = "./204ducks";
    arr[1] = "0.602828282882";
    arr[2] = NULL;
    ducks_process(2, (arr_const_restrict)arr);
}

Test(negative_number_test, ducks_exit, .exit_code=84)
{
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = "./204ducks";
    arr[1] = "-1";
    arr[2] = NULL;
    ducks_process(2, (arr_const_restrict)arr);
}

Test(too_height_number_test, ducks_exit, .exit_code=84)
{
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = "./204ducks";
    arr[1] = "10";
    arr[2] = NULL;
    ducks_process(2, (arr_const_restrict)arr);
}