#ifndef TEMP_FUNCTION_H
#define TEMP_FUNCTION_H

#include <stdio.h>
#include <stdint.h>

// Struct definition for sensor
struct sensor {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
};

// Function prototypes
void print_out(struct sensor* info, int number);
void add_record(struct sensor* info, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t);
int add_info(struct sensor* info);
void change_i_j(struct sensor* info, int i, int j);
void sort_by_t(struct sensor* info, int number);
uint32_t date_to_int(struct sensor* info);

#endif
