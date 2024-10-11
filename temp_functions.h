//#include <stdio.h>
//#include "main.c"
//#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <getopt.h>
//#include <locale.h>
//#include <conio.h>
//#include "temp_functions.c"
#ifndef TEMP_FUNCTION_H
#define TEMP_FUNCTION_H

#include <stdio.h>
#include <stdint.h>


// Struct definition for sensor
 struct sensor
 {
     uint16_t year;
     uint8_t month;
     uint8_t day;
     uint8_t hour;
     uint8_t minute;    
     int8_t t;
 };

//char *mont[]= {"JAN", "FEB", "MAR", "APR", "MAY", "YUN", "YUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

void print_out(struct sensor* info, int number); // печать структуры
void add_record(struct sensor* info , int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t ); // добавить запись
int add_info(struct sensor* info);//добавить записи в ручную
void change_i_j(struct sensor* info , int i, int j); //сортировка замена местами
uint32_t date_to_int(struct sensor* info);// в int
void sort_by_t(struct sensor* info , int number);// сортировка по температуре
void sort_by_date(struct sensor* info , int number);// сортировка по дате 
void sort_by_month(struct sensor* info , int number);// сортировка по месяцам в поряд возраст
float find_by_aver_mont(struct sensor* info , int number, int mon, int yea);// поиск среднеквадратич за месяц
int find_by_min_mont(struct sensor* info , int number, int mon, int yea);// поиск среднеквадратич за месяц
int find_by_max_mont(struct sensor* info , int number, int mon, int yea);// поиск среднеквадратич за месяц
float find_by_aver_year(struct sensor* info , int number, int yea);// поиск среднеквадратич за год
int find_by_min_year(struct sensor* info , int number, int yea);// поиск среднеквадратич за год
int find_by_max_year(struct sensor* info , int number, int yea);// поиск среднеквадратич за год
float find_by_aver_mont_all_year(struct sensor* info, int number, int m);
void print_month(struct sensor* info, int number, int mon, char *mont[]);

int read_file(const char *filename, struct sensor* info); //прочитать файл в стуктуру
void print_file(const char *filename);// рапечатать файл
#endif
