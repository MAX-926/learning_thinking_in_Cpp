// 使用二维数组？

#include<stdio.h>
#include<string.h>

// America chinese france japan taiwan

main()
{
    char cn1[7], cn2[7], cn3[7], cn4[7], cn5[7];
    scanf("%s%s%s%s%s", cn1, cn2, cn3, cn4, cn5);
    // scanf("%s", cn1);
    // printf("%s%s%s%s%s", cn1, cn2, cn3, cn4, cn5);
    char* pcn[5] = {cn1, cn2, cn3, cn4, cn5};
    char* tmp;
    int i, j;
    for(i = 0; i < 5; i++)
    {
        for(j = i+1; j < 5; j++)
        {
            if(strcmp(pcn[i], pcn[j]) < 0)
            {
                tmp = pcn[i];
                pcn[i] = pcn[j];
                pcn[j] = tmp;
            }
        }
    }
    for(i = 0; i < 5; i++)
    {
        printf("%s ", pcn[i]);
    }
}

//