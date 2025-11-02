#include <stdio.h>
#include <string.h>

#define max(a, b) ((a > b) ? a : b)

void LRS_length(char x[], int n, int c[n+1][n+1])
{
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (x[i-1] == x[j-1] && i != j)
                c[i][j] = 1 + c[i-1][j-1];
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }
}

void printLRS(char x[], int n, int c[n+1][n+1], int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (x[i-1] == x[j-1] && i != j) {
        printLRS(x, n, c, i-1, j-1);
        printf("%c", x[i-1]);   
    }
    else if (c[i-1][j] > c[i][j-1])
        printLRS(x, n, c, i-1, j);
    else
        printLRS(x, n, c, i, j-1);
}

int main()
{
    char x[] = "AABEBCDD";
    int n = strlen(x);

    int c[n+1][n+1];
    LRS_length(x, n, c);

    printf("Longest Repeated Subsequence = ");
    printLRS(x, n, c, n, n);
    printf("\n");

    return 0;
}
