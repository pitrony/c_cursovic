#include "temp_functions.h"
//#include "main.c"
//#include <stdint.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <getopt.h>
//#include <locale.h>
//#include <conio.h>




void print_out(struct sensor* info, int number)
{
    printf("========================\n");
    for(int i=0;i<number; i++)
            printf("%04d/%02d/%02d %02d:%02d t=%3d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].hour,
			info[i].minute,
            info[i].t);
     printf("========================\n");
}
void add_record(struct sensor* info , int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t )
{
	info[number].year=year;
	info[number].month=month;
	info[number].day=day;
	info[number].hour=hour;
	info[number].minute=minute;
	info[number].t=t;
}
int add_info(struct sensor* info)
{
int counter =0;
add_record(info, counter++,2023,11,16,0,0,19);
add_record(info, counter++,2021,9,16,0,0,8);
add_record(info, counter++,2021,9,16,0,0,-18);
add_record(info, counter++,2021,9,16,0,0,9);
add_record(info, counter++,2021,10,16,0,0,22);
add_record(info, counter++,2021,8,16,0,0,-1);
add_record(info, counter++,2022,9,16,0,0,-5);
add_record(info, counter++,2022,7,16,0,0,8);
return counter;
}

void change_i_j(struct sensor* info , int i, int j) //сортировка замена местами
{
    struct sensor temp;
    temp= info[i];
    info[i]=info[j];
    info[j]=temp;
}
uint32_t date_to_int(struct sensor* info)
{return (info->year<<16)|(info->month<<8)|info->day;}
 
 void sort_by_t(struct sensor* info , int number)// сортировка по температуре 
{
for(int i=0; i<number; i++)
    for(int j=i; j<number;j++)
        if(info[i].t>=info[j].t)
            change_i_j(info, i, j);
}
 void sort_by_date(struct sensor* info , int number)// сортировка по дате 
{
for(int i=0; i<number; i++)
    for(int j=i; j<number;j++)
        if(date_to_int(info+i)>=date_to_int(info+j))
            change_i_j(info, i, j);
}


 void sort_by_month(struct sensor* info , int number)// сортировка по месяцам в поряд возраст
{
for(int i=0; i<number; i++)
    for(int j=i; j<number;j++)
        if(info[i].month>=info[j].month)
            change_i_j(info, i, j);
}
float find_by_aver_mont(struct sensor* info , int number, int mon, int yea)// поиск среднеквадратич за месяц
{
uint32_t count=0;
float sum=0.0;
float rez=0;
for(int i=0; i<number; i++)
        if(info[i].month==mon && info[i].year==yea )
            {count++;
			sum=sum+info[i].t;
             }
rez=sum/count;            
return rez;    
}
int find_by_min_mont(struct sensor* info , int number, int mon, int yea)// поиск среднеквадратич за месяц
{
int min=99;//struct sensor tempinfo;
for(int i=0; i<number; i++)
{
  if(info[i].month==mon && info[i].year==yea)
	{
	if(info[i].t < min)
	min=info[i].t;
	}
}//for
return min;           
}
int find_by_max_mont(struct sensor* info , int number, int mon, int yea)// поиск среднеквадратич за месяц
{
int max=-99;//struct sensor tempinfo;
for(int i=0; i<number; i++)
{
  if(info[i].month==mon && info[i].year==yea)
	{
	if(info[i].t > max)
	max=info[i].t;
	}
}//for
return max;           
}
float find_by_aver_year(struct sensor* info , int number, int yea)// поиск среднеквадратич за год
{
uint32_t count=0;
float sum=0.0;
float rez=0;
for(int i=0; i<number; i++)
        if(info[i].year==yea)
            {count++;
			sum=sum+info[i].t;
             }
rez=sum/count;            
return rez;    
}
int find_by_min_year(struct sensor* info , int number, int yea)// поиск среднеквадратич за год
{
int min=99;//struct sensor tempinfo;
for(int i=0; i<number; i++)
{
  if(info[i].year==yea)
	{
	if(info[i].t < min)
	min=info[i].t;
	}
}//for
return min;           
}
int find_by_max_year(struct sensor* info , int number, int yea)// поиск среднеквадратич за год
{
int max=-99;//struct sensor tempinfo;
for(int i=0; i<number; i++)
{
  if(info[i].year==yea)
	{
	if(info[i].t > max)
	max=info[i].t;
	}
}//for
return max;           
}
float find_by_aver_mont_all_year(struct sensor* info, int number, int m)
{
	sort_by_date(info, number);	//sort by year then every year aver by month
	uint32_t count=0;
float sum=0.0;
float rez=0;
for(int i=0; i<number; i++)
        if(info[i].month==m)
            {count++;
			sum=sum+info[i].t;
             }
rez=sum/count;            
return rez;    

	//printf("\n");
	m=m+0.0;
	return m;
	}


void print_month(struct sensor* info, int number, int mon, char *mont[])
{
    printf("****************************\n");
    //char tt;
    for(int i=0;i<number; i++)
            {if(info[i].month==mon)
				{//enum number_month tt = mon;
					//printf("%c", tt);
				printf("* %s  ", mont[(info[i].month)-1]);
				printf("%04d-%02d %02d:%02d t=%3d *\n",
				info[i].year,
				info[i].day,
				info[i].hour,
				info[i].minute,
				info[i].t);}
            else if (mon==0)
            printf("%04d-%02d-%02d %02d:%02d t=%3d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].hour,
			info[i].minute,
            info[i].t);
            }
     printf("****************************\n");
}
void print_file(const char *filename)
{
	int N=6;
	FILE *open;
//char *name[]=filename;
open=fopen(filename, "r");
if(open!=NULL)
{
int Y,M,D,H,I,t;
int r;
int count_line=0;
char ch=0;
while((r=fscanf(open,"%d;%d;%d;%d;%d;%d", &Y,&M,&D,&H,&I,&t))>0)
{
	count_line++;
if(r<N)	
	{
		do
		{
			putchar(ch);
			ch=fgetc(open);
		}while(EOF!=ch && '\n'!=ch);
		ch=0;
		printf("  ");
		printf("error in line = %d ", count_line);
		printf("\n");
	}
	else
	printf("%d = %d/%d/%d %d:%d t=%d\n", count_line,Y,M,D,H,I,t);
}
}
else printf("file not open!");
	
	
	}
	
int read_file(const char *filename, struct sensor* info)
{
	int count=0;
	int count_line=0;
	int N=6; //struct number
	FILE *open;
//char *name[]=filename;
open=fopen(filename, "r");
if(open!=NULL)
{
int Y,M,D,H,I,t;
int r;
char ch=0;
while((r=fscanf(open,"%d;%d;%d;%d;%d;%d", &Y,&M,&D,&H,&I,&t))>0)
{
	count_line++;
if(r<N)	
	{
		do
		{
			putchar(ch);
			ch=fgetc(open);
		}while(EOF!=ch && '\n'!=ch);
		ch=0;
		printf("  ");
		printf("error in line = %d ", count_line);
		printf("\n");
	}
	else
	//printf("%d = %d/%d/%d %d:%d t=%d\n", count_line,Y,M,D,H,I,t);
   add_record(info,count++,Y,M,D,H,I,t);
}
}
else printf("file not open!");
	
	return count;
	}

