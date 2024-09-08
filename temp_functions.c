 #include<stdio.h>
 #include "temp_functions.h"
 #include <stdint.h>
#define SIZE 80
struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;    
    int8_t t;
};
void print_out(struct sensor* info, int number)
{
    printf("========================\n");
    for(int i=0;i<number; i++)
            printf("%04d-%02d-%02d t=%3d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].t);
     printf("========================\n");
}
void change_i_j(struct sensor* info , int i, int j) //сортировка замена местами
{
    struct sensor temp;
    temp= info[i];
    info[i]=info[j];
    info[j]=temp;
}
uint32_t Date_to_int(struct sensor* info)
{return (info->year<<16)|(info->month<<8)|info->day;}
 void sort_by_t(struct sensor* info , int number)// сортировка по температуре ?
{
for(int i=0; i<number; i++)
    for(int j=i; j<number;j++)
        if(info[i].t>=info[j].t)
            change_i_j(info, i, j);
}
// void sort_by_t_m(struct sensor* info , int i) // сортировка среднемесячная температура в месяце
// {}
// void sort_by_t_m_min(struct sensor* info , int i) //сортировка минимальная температура в месяце
// {}
// void sort_by_t_m_max(struct sensor* info , int i) //сортировка максимальная температура в месяце
// {}
// void sort_by_t_y(struct sensor* info , int i) // сортировка среднемесячная температура в году
// {}
// void sort_by_t_y_min(struct sensor* info , int i) //сортировка минимальная температура в году
// {}
// void sort_by_t_y_max(struct sensor* info , int i) //сортировка максимальная температура в году
// {}
/*
Разбор файла с ошибками без fscanf
Файлы текстовые
 int counter = 0;
int arr[N] = {0};
char ch;
 while((ch=fgetc(open))!=EOF)
 {
 if(ch==';')
 {
 counter++;
 if(counter>N)
 counter = 0;
 }
 else if(ch=='\n')
 {
 if(counter == 2)
 printf("%d = %d;%d;%d\n",
counter, arr[0],arr[1],arr[2]);
 else
 printf("ERROR %d =
%d;%d;%d\n",
counter,arr[0],arr[1],arr[2]);
 counter = 0;
 arr[0]=arr[1]=arr[2]=0;
 }
 else if(ch>='0' && ch<='9')
 arr[counter] = arr[counter]*10
+ ch - '0';
 else if(ch != 0xD)
 counter = 0;
}
*/
