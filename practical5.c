#include <stdio.h>
#include <string.h>

void LCS_length(char x[], char y[], int n, int m, int c[m+1][n+1], int b[m+1][n+1])
{
    for(int i = 1; i <= m; i++)
        c[i][0] = 0;
    for(int j = 0; j <= n; j++)
        c[0][j] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 3; 
            }
        }
    }
}

void printLCS(int i, int j, int b[i+1][j+1], char x[])
{
    if(i == 0 || j == 0)
        return;

    if(b[i][j] == 1) 
    {
        printLCS(i-1, j-1, b, x);
        printf("%c", x[i-1]);
    }
    else if(b[i][j] == 2) 
    {
        printLCS(i-1, j, b, x);
    }
    else 
    {
        printLCS(i, j-1, b, x);
    }
}

int main()
{
    char x[] = "AGCCCTAAGGGCTACCTAGCTT";
    char y[] = "GACAGCCTACAAGCGTTAGCTTG";

    int m = strlen(x);
    int n = strlen(y);

    int c[m+1][n+1];
    int b[m+1][n+1];

    LCS_length(x, y, n, m, c, b);

    printf("LCS= ");
    printLCS(m, n, b, x);
    

    return 0;
}
