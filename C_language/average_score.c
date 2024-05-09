#include<stdio.h>

main()
{
    float average(float [], int);
    float score[5];
    int i;
    printf("input 5 score:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%f", &score[i]);
        // fflush(stdin);
    }
    printf("%f", average(score, 5));
}

float average(float score[], int len)
{
    int i, sum = 0;
    for(i = 0; i < len; i++)
    {
        sum += score[i];
    }
    return sum / len;
}