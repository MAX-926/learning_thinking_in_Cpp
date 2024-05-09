#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        FILE *fp;
        if(!(fp = fopen(argv[1], "rt")))
        {
            printf("\nerror on opening file %s", argv[1]);
            printf("\nplease strike any key to continue...");
            getchar();
            exit(1);
        }
        char ch  = fgetc(fp);
        while(ch != EOF)
        {
            // printf("%c", ch);
            fputc(ch, stdout);// stdout 即为显示器的抽象文件
            ch = fgetc(fp);
        }
        fclose(fp);
        return 0;
    }
    else if(argc == 3)
    {
        FILE *fps, *fpd;
        fps = fopen(argv[1], "rt");
        fpd = fopen(argv[2], "wt");
        if(!(fps && fpd))
        {
            printf("\n error occur in opening file %s or file %s", argv[1], argv[2]);
            printf("\nplease strike any key to continue...");
            //        fclose(fps);
            //        fclose(fpd);
            getchar();
            exit(1);
        }
        char ch = fgetc(fps);
        while(ch != EOF)
        {
            fputc(ch, fpd);
            ch = fgetc(fps);
        }
        fclose(fps);
        fclose(fpd);
        return 0;
    }
    else
    {
        printf("error input, please try again...\n");
        exit(1);
    }
    return 0;
}