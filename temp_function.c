#include "temp_function.h"

void print_out(struct sensor* info, int number) {
    printf("========================\n");
    for(int i = 0; i < number; i++)
        printf("%04d/%02d/%02d %02d:%02d t=%3d\n",
               info[i].year, info[i].month, info[i].day,
               info[i].hour, info[i].minute, info[i].t);
    printf("========================\n");
}

void add_record(struct sensor* info, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t) {
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].t = t;
}

int add_info(struct sensor* info) {
    int counter = 0;
    add_record(info, counter++, 2023, 11, 16, 0, 0, 19);
    add_record(info, counter++, 2021, 9, 16, 0, 0, 8);
    add_record(info, counter++, 2021, 9, 16, 0, 0, -18);
    add_record(info, counter++, 2021, 9, 16, 0, 0, 9);
    add_record(info, counter++, 2021, 10, 16, 0, 0, 22);
    add_record(info, counter++, 2021, 8, 16, 0, 0, -1);
    add_record(info, counter++, 2022, 9, 16, 0, 0, -5);
    add_record(info, counter++, 2022, 7, 16, 0, 0, 8);
    return counter;
}

void change_i_j(struct sensor* info, int i, int j) {
    struct sensor temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

void sort_by_t(struct sensor* info, int number) {
    for(int i = 0; i < number; i++)
        for(int j = i; j < number; j++)
            if(info[i].t > info[j].t)
                change_i_j(info, i, j);
}

uint32_t date_to_int(struct sensor* info) {
    return (info->year << 16) | (info->month << 8) | info->day;
}
