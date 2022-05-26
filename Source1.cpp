#include <iostream>
#include <stdio.h>
#include 	<conio.h>
int main()
{
   

    FILE* f = NULL;

    errno_t error = fopen_s(&f, "\\\\.\\COM3", "rb+");
    if (error != 0)
    {
        printf("Failed to open file\r\n");
        return -1;
    }

    char buf[100];
   
    while (1)
    {
        int len = fread(buf, 1, sizeof(buf) - 1, f);

        if (len > 0)
        {
            buf[len] = 0;
            printf(buf);
        }
        if (_kbhit()) {
           
            int num = _getch();
           printf("%c", num);
            
        }
       
    }
    
    
    fclose(f);
}
