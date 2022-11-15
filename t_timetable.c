#include "t_timetable.h"
#include <malloc.h>

_Bool is_empty() {
    return Keys == NULL ? 1 : 0;
}

int size() {
    if (is_empty()) return 0;
    int counter = 0;

    t_timetable *queue = Keys;
    while (queue != NULL) {
        counter++;
        queue = queue->next;
    }

    return counter;
}

void put(t_time key, char *val) {
    if (val == NULL || val[0] == '\0') {
        delete(key);
        return;
    }

    t_timetable *new_queue = (t_timetable *) malloc(sizeof(t_timetable));

    new_queue->time = key;
    new_queue->description = val;

    if (is_empty()) {
        new_queue->next = NULL;
        Keys = new_queue;
        return;
    }

    t_timetable *current_queue = Keys;
    t_timetable *last_queue = NULL;
    while (current_queue != NULL && time_cmp(current_queue->time, key) == -1) {
        last_queue = current_queue;
        current_queue = current_queue->next;
    }

    new_queue->next = current_queue;

    if (last_queue == NULL) Keys = new_queue;
    else last_queue->next = new_queue;

}

_Bool contains(t_time key) {
    if (is_empty()) return 0;

    t_timetable *queue = Keys;
    while (queue != NULL) {
        if (time_cmp(key, queue->time) == 0) return 1;
        queue = queue->next;
    }

    return 0;
}

void delete(t_time key) {
    if (is_empty()) return;

    t_timetable *queue = Keys;
    t_timetable *last_queue;
    while (queue != NULL && time_cmp(key, queue->time) != 0) {
        last_queue = queue;
        queue = queue->next;
    }

    if (queue == NULL) return;
    if (queue == Keys) Keys = queue->next;
    else last_queue->next = queue->next;

    free(queue);
}

char *get(t_time key) {
    if (is_empty()) return NULL;

    t_timetable *queue = Keys;
    while (queue != NULL && time_cmp(queue->time, key) != 0) {
        queue = queue->next;
    }

    if (queue == NULL) return NULL;
    return queue->description;
}

t_time min() {
    t_time key;
    t_timetable *queue = Keys;

    if (is_empty()) return set_time("00:00:00");

    while ((queue = queue->next) != NULL) {
        if (time_cmp(queue->time, key) == -1) key = queue->time;
    }

    return key;
}

t_time max() {
    t_time key;
    t_timetable *queue = Keys;

    if (is_empty()) return set_time("00:00:00");

    while ((queue = queue->next) != NULL) {
        if (time_cmp(queue->time, key) == 1) key = queue->time;
    }

    return key;
}

t_time ceiling(t_time key) {
    if (is_empty()) return set_time("00:00:00");

    t_timetable *queue = Keys;
    while (queue != NULL && time_cmp(key, queue->time) != 0) {
        queue = queue->next;
    }

    if (queue == NULL) return set_time("00:00:00");
    return queue->time;
}

t_time floor(t_time key) {
    if (is_empty()) return set_time("00:00:00");

    t_timetable *queue = Keys;
    t_timetable *last_queue;
    while (queue != NULL && time_cmp(key, queue->time) != 0) {
        last_queue = queue;
        queue = queue->next;
    }

    if (queue == NULL) return set_time("00:00:00");
    return last_queue->time;
}

int rank(t_time key) {
    if (is_empty()) return 0;

    int counter = 0;
    t_timetable *queue = Keys;
    while (queue != NULL && time_cmp(key, queue->time) != 0) {
        counter++;
        queue = queue->next;
    }
    return queue == NULL ? 0 : counter;
}

void delete_min() {
    if (is_empty()) return;

    if (Keys->next == NULL) {
        free(Keys);
        return;
    }

    t_timetable *deleted_queue = Keys;
    Keys = Keys->next;
    free(deleted_queue);

}

void delete_max() {
    if (is_empty()) return;

    if (Keys->next == NULL) {
        free(Keys);
        return;
    }

    t_timetable *last_queue, *current_queue = Keys;

    while (current_queue->next != NULL) {
        last_queue = current_queue;
        current_queue = current_queue->next;
    }

    last_queue->next = NULL;
    free(current_queue);
}

int size_range(t_time lo, t_time hi) {
    if (time_cmp(lo, hi) == 0 || is_empty() || time_cmp(lo, hi) == 1) return 0;

    int counter = 0;
    t_timetable *queue = Keys;
    while (queue != NULL && time_cmp(queue->time, lo) != 0) queue->next;
    while ((queue = queue->next) != NULL && time_cmp(queue->time, hi) != 0) counter++;

    return counter;
}

t_time select(int k) {
    if (is_empty()) return set_time("00:00:00");

    t_timetable *queue = Keys;
    int counter = 0;
    while (queue != NULL && counter < k) {
        queue = queue->next;
        counter++;
    }

    if (queue == NULL) return set_time("00:00:00");

    return queue->time;
}

t_time *keys(t_time lo, t_time hi) {
    int size = size_range(lo, hi);
    if (size == 0) return NULL;

    t_time *range_of_keys = malloc(size * sizeof(t_time));

    int counter = 0;
    t_timetable *queue = Keys;
    while (queue != NULL && time_cmp(queue->time, lo) != 0) queue->next;
    while ((queue = queue->next) != NULL && time_cmp(queue->time, hi) != 0) {
        range_of_keys[counter] = queue->time;
        counter++;
    }

    return range_of_keys;
}
