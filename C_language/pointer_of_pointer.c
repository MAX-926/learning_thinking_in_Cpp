// #include<stdio.h>

// main()
// {
//     const char *ca[] = {"MAX", "MutoRikako"};
//     const char **pcp;
//     pcp = ca;
//     int i;
//     size_t len = sizeof(ca) / sizeof(*ca);
//     for(i = 0; i < 2; i++)
//         printf("%s\n", pcp + i);
// }

#include<stdio.h>
main(int argc,char *argv)
{ while(argc-->1) printf("%s\n",*++argv); }