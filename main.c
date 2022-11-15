#include <stdio.h>
#include <stdlib.h>
#include "t_time.h"
#include "t_timetable.h"

int main()
{
    t_time h1;
    t_time h2;
    t_time h3;
    t_time h4;
    char *var = NULL;

    h1 = set_time("02:00:00");
    h2 = set_time("04:00:00");
    h3 = set_time("14:00:00");
    h4 = set_time("15:30:00");
    printf("\n %d \n", time_cmp(h1, h2));
    printf("\n %d \n", time_cmp(h2, h1));
    printf("\n %d \n", time_cmp(h3, h4));
    printf("\n %d \n", time_cmp(h4, h3));
    put(h1, "scranton");
    put(set_time("03:00:00"), "seattle");
    put(set_time("04:00:00"), "chicago");
    put(h2, "houston");
    printf("\n %s \n", get(h1));
    printf("\n %s \n", get(h2));
    printf("\n %s \n", get(h3));
    printf("\n %s \n", get(h4));
    printf("\n %s \n", keys(h1, h2)[0].time_s);
    printf("\n %d \n", rank(h2));
    printf("\n %d \n", contains(h2));
}
