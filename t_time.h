#ifndef AULA_4_T_TIME_H
#define AULA_4_T_TIME_H

typedef struct t_time{
    char time_s[9];
    int time[3];
} t_time;

int time_cmp(t_time h1, t_time h2);

t_time set_time(const char *user_time);

#endif

