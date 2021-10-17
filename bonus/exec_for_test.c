/*
** EPITECH PROJECT, 2021
** 204ducks [WSL: Ubuntu]
** File description:
** exec_for_test
*/

/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203hotline-clement.muth [WSL: Ubuntu]
** File description:
** main
*/

#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include "ducks.h"
#include "../library/utils/includes/index.h"

calc_t *calc = NULL;

noreturn bool help(str_const_restrict _filepath, int const _output)
{
    char *lineptr = NULL;
    size_t i = 500;
    FILE *stream = GET(FILE *, {
        my_assert(_filepath, PROTO_DATA, ASSERT_INFO("Cannot read property '_filepath' of undefined", ERR_TYPE, FAIL_EXEC), NULL);
        return (fopen(_filepath, "r"));
    });

    while (-1 != getline(&lineptr, &i, stream) && (printf("%s", lineptr)));
    free(lineptr);
    fclose(stream);
    exit(_output);
}

static void write_time(double _v, str_const_restrict _message)
{
    printf("%s: %dm ", _message, (int)_v);
    while (1 < _v && (--_v));
    if (10 > _v * 60) printf("0");
    printf("%ds\n", (my_strcmp("Average return time", _message) ? (int)(_v * 60) : (int)(_v * 60 + 1)));
}

static void average_time()
{
    double res, dev = 0.0;
    double t = 0.001;

    for (; fact(calc->a, t); t += 0.001) res += (fact(calc->a, t) / 10 * t);
    res /= 100;
    res += 1 / 60;
    write_time(res, "Average return time");
    for (; 0 < t; t -= 0.001) dev += pow(t - res, 2) * (fact(calc->a, t) / 10);
    dev /= 100;
    printf("Standard deviation: %.3f\n", sqrt(dev));
}

static double get_time_back(int const _percent)
{
    double t = 0.0;

    for (double res = 0.0; (_percent - 0.01) > res; t += 1) res += fact(calc->a, t / 100);
    return t / 100;
}

static void ducks()
{
    average_time();
    write_time(get_time_back(50), "Time after which 50% of the ducks are back");
    write_time(get_time_back(99), "Time after which 99% of the ducks are back");
    double minute_1 = derive(calc->a, 1) - derive(calc->a, 0);
    double minute_2 = derive(calc->a, 2) - derive(calc->a, 0);

    printf("Percentage of ducks back after 1 minute: %.1lf%%\n", minute_1 * 100);
    printf("Percentage of ducks back after 2 minutes: %.1lf%%\n", minute_2 * 100);
}

static void arg_handling(int const _ac, arr_const_restrict _av)
{
    _av++;
    if (2 != _ac) eraise();
    if (!issdigit(*_av)) eraise();
    calc->a = atof(*_av);
    if (0 > calc->a || 2.5 < calc->a) eraise();
}

int ducks_process(int const ac, arr_const_restrict av)
{
    errno = 0;
    calc = malloc(sizeof(calc_t));
    my_assert(calc != NULL, PROTO_DATA, ASSERT_INFO(strerror(errno), ERR_ALC84, FAIL_EXEC), NULL);
    if (2 == ac && !strcmp(av[1], "-h")) help("./help.txt", 0);
    arg_handling(ac, av);
    ducks();
    my_free(calc, NULL);
    return (0);
}