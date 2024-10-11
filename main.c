#include "temp_functions.h"
#include <stdio.h>
//#include <stdint.h>
#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
#include <getopt.h>
#include <locale.h>
#include <conio.h>
//#include "temp_functions.c"
#define SIZE 1000000
 char *mont[]= {"JAN", "FEB", "MAR", "APR", "MAY", "YUN", "YUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
 
 int main(int argc, char *argv[])
{
setlocale(LC_ALL, "");
int number_of_records = SIZE;

struct sensor* info = (struct sensor*)malloc(number_of_records * sizeof(struct sensor));
    if (info == NULL) {
        printf("Memory allocation failed!\\n");
        return 1;  // Exit if memory allocation fails
    }

int number =0;
int menu_func='1';
while ( (menu_func = getopt(argc,argv,"hf:y:m:x:a:i:p")) != -1)
{
switch (menu_func)
    {
case 'f' :
    char* f=optarg;
    if(f!=NULL)
   {
 number=read_file(f, info);
 printf("\n");
	}
    printf("\n");
    break;
case 'y' :
    int y=atoi(optarg);
   
    printf("\n");
    break;
case 'm' :
    int m=atoi(optarg);
    if(y!=0){
    printf("averege temp of month %s %5.2f", mont[m-1], find_by_aver_year(info, number, y));
    }
    else {
		printf("averege temp of month for all years %s %5.2f", mont[m-1], find_by_aver_mont_all_year(info, number, m));
		printf("\nhave not year in key print for all years");
		}
    printf("\n");
    break;    

case 'a' : //find averege
    int a=atoi(optarg);
    if(a>=1900)
    printf("\naverege temp of year %d %5.2f", a, find_by_aver_year(info, number, a));
    if(a>0 && a<13)
     {
		if(y==0)
			{printf("have not year in key");
		 	}
		else printf("averege temp of month %s year %d %5.2f", mont[a-1],y, find_by_aver_mont(info, number, a, y));	
	  }
    printf("\n");
    break;
case 'i' : //find minimum
    int i=atoi(optarg);
    if(i>12)
		{if(find_by_min_year(info, number, i)!=99)
		printf("\nminimum temp of year %d %d", y, find_by_min_year(info, number, i));
		else
		printf("\nminimum temp of year %d - have not date",i);
		}
    if(i<=12 && i>0)
		{
		
		if(y==0)
			{printf("have not year in key");
		 printf("\n");
		 break;	}
		if (find_by_min_mont(info, number, i, y)!=99)
		printf("\nminimum temp of month %s year %d %d", mont[i-1], y, find_by_min_mont(info, number, i, y) );
		else printf("\nminimum temp of month %s - have not date", mont[i-1]);
		}
	printf("\n");
    break;
case 'x' : //find maximum
    int x=atoi(optarg);
    if(x>12)
		{if(find_by_max_year(info, number, x)!=-99)
			printf("\nmaximum temp of year %d %d", x, find_by_max_year(info, number, x));
		else 
		printf("\nmaximum temp of year %d - have not date",x);
		}
    if(x<=12 && i>0)
		{
			if(y==0)
			{printf("have not year in key");
		printf("\n");
		break;}
		if(find_by_max_mont(info, number, x, y)!=-99)
		printf("\nmaximum temp of month %s year %d %d", mont[x-1], y, find_by_max_mont(info, number, x, y) );
		else
		printf("\nmaximum temp of month %s - have not date", mont[x-1]);
		}
       
    printf("\n");
    break;    
case 'h' :
    printf("\nHelp\n");
    printf("-h помощь\n");
    printf("-m:(1-12) month среднее значение температуры,по мес€цу если указан год, то года -y \n");
    printf("-y(xxxx) year год  об€зательно дл€ расчетов по мес€цам\n");
    printf("-a(xxxx) среднее значение температуры, если >1900 - расчет средней температуры за год\n");
	printf("-a(xx) среднее значение температуры, если до 12 - в мес€це года -y(xxxx) \n");
    printf("-i(>1900) min за год, если до 12 то за мес€ц(1-12) года -y(xxxx) \n");
    printf("-x(>1900) max за год, если до 12 то за мес€ц(1-12) года -y(xxxx) \n");
    printf("example: -f\"filename\" -y2021 -m9 \n");
    printf("example: -f\"filename\" -a2021 \n");
    printf("example: -f\"filename\" -y2021 -i12 \n");
    printf("-p печать всего файла\n"); // + -s сортировка по год или мес
    printf("\n");
    break;
case 'p':
	sort_by_date(info, number);
	print_file(f);
	break;
case '?': 
    printf("Error found ! Type -h\n");
    printf("\n");
    break;
default:
	printf("\nHelp\n");// hy:f:m:x:a:i:p
    printf("-h помощь\n -m(1-12) month -y(xxxx) year\n ");
    printf("-x(1-12) -x(xxxx) max \n");
    printf("-a(1-12) -a(xxxx) aver\n");
    printf("-i(1-12) -i(xxxx) min \n ");
    printf("example: -f\"filename\" -y2021 -m9 \n");
    printf("-p print file -f\"ffffff.fff\"  \n");
    printf("\n");
    break;
    } //switch
} //while
free(info);
return 0;
}
