#include "t_time.h"
#include <stdlib.h>
#include <string.h>

int compare(int a, int b) {
    if (a == b) return 0;
    if (a > b) return 1;
    return -1;
}

int time_cmp(t_time h1, t_time h2) {
    int condition = 1;
    for (int i = 0; i < 3; ++i) {
        if ((condition = compare(h1.time[i], h2.time[i]))) return condition;
    }
    return 0;
}

t_time set_time(const char *user_time) {
    t_time time;
    char number[3];
    strcpy(time.time_s, user_time);
    number[2] = '\0';
    for (int i = 0; i < 3; ++i) {
        number[0] = user_time[3 * i];
        number[1] = user_time[3 * i + 1];
        time.time[i] = atoi(number);
    }
    return time;
}
