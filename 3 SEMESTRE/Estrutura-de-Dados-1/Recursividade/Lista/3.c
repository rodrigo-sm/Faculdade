#include <stdio.h>

void agrupa(int, int, int, int[][*], int, int);

int main()
{
    int l, c;
    scanf("%d %d", &l, &c);
    int i, j, m[l][c];
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int n = 1;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            if(m[i][j] == 1) {
            n++;
            agrupa(n, l, c, m, i, j);
            }
        }
    }
    printf("%d\n", --n);
}

void agrupa(int n, int l, int c, int m[][c], int i, int j)
{
    if (m[i][j] == 1) {
        m[i][j] = n;
        agrupa(n, l, c, m, i + 1, j);
        agrupa(n, l, c, m, i - 1, j);
        agrupa(n, l, c, m, i, j + 1);
        agrupa(n, l, c, m, i, j - 1);

    }
}
