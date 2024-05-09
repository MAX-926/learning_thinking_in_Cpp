#include<stdio.h>

float s1, s2, s3;
float vs(float, float, float);

main()
{
    float a, b, c, v;
    printf("input a, b, c:\n");
    scanf("%f %f %f", &a, &b, &c);
    v = vs(a, b, c);
    printf("v = %f\ns1 = %f\ns2 = %f\ns3 = %f", v, s1, s2, s3);
}

float vs(float a, float b, float c)
{
    float v = a*b*c;
    s1 = a*b;
    s2 = b*c;
    s3 = a*c;
    return v;
}