/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203ducks-clement.muth [WSL: Ubuntu]
** File description:
** ducks
*/

#pragma once

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdnoreturn.h>
#include "../library/includes/assert.h"

typedef struct calc_s calc_t;

typedef char const *restrict const *restrict arr_const_restrict;
typedef char const *restrict str_const_restrict;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define my_free(ptr, ...) my_free(_N__ARG(__VA_ARGS__), ptr, __VA_ARGS__)

struct calc_s
{
    double a;
};


#include "inline.h"

int ducks_process(int const ac, arr_const_restrict av);