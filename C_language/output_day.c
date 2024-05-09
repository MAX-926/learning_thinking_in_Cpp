#include<stdio.h>
#include<stdlib.h>
const char* output_day_name(int);

main()
{
    int day;
    printf("input a day:\n");
    scanf("%d", &day);
    if(day < 1) exit(1);
    printf("%d-->%s", day, output_day_name(day));
}

const char* output_day_name(int day)
{
    const char* dn[] = {"Illegal day", "Monday", "Tuesday", "Wensday", "Thursday", "Friday", "Saturday", "Sunday"};
    // if(day > 7 || day < 1) return "Wrong input\n";
    return (day < 8 && day >0)? dn[day]:dn[0];
}