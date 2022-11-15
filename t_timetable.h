#ifndef AULA_4_T_TIMETABLE_H
#define AULA_4_T_TIMETABLE_H
#include "t_time.h"

typedef struct t_timetable {
    t_time time;
    char *description;
    struct t_timetable *next;
} t_timetable;

t_timetable *Keys;

void put(t_time key, char *val);

char *get(t_time key);

void delete(t_time key);

_Bool contains(t_time key);

_Bool is_empty();

int size();

t_time min();

t_time max();

t_time floor(t_time key);

t_time ceiling(t_time key);

int rank(t_time key);

t_time select(int k);

void delete_min();

void delete_max();

int size_range(t_time lo, t_time hi);

t_time *keys(t_time lo, t_time hi);

#endif
