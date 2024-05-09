#include<stdio.h>

main()
{
    double score[5][3] = {{80, 75, 92}, {61, 65, 71}, {59, 63, 70}, {85, 87, 90}, {76, 77, 85}};
    double get_each_class_average(double (*)[3] , int, int);
    double get_full_average(double (*)[3] , int, int);
    // 求各科平均分
    printf("Math: %lf\n", get_each_class_average(score, 5, 0));
    printf("C: %lf\n", get_each_class_average(score, 5, 1));
    printf("Foxpro: %lf\n", get_each_class_average(score, 5, 2));
    // 求总平均分
    printf("Average: %lf\n", get_full_average(score, 5, 3));
    return 0;
}

double get_each_class_average(double (*score)[3], int d1, int Class)
{
    int student;
    double average;
    for(student = 0; student < d1; student++)
    {
        average += score[student][Class];
    }
    average /= d1;
    return average;
}

double get_full_average(double (*score)[3], int student, int Class)
{
    int i, j;
    double average;
    for(i = 0; i < student; i++)
    {
        for(j = 0; j < Class; j++)
        {
            average += score[i][j];
        }
    }
    average /= student * Class;
    return average;
}