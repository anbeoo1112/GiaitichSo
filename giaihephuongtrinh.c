#include <stdio.h>

int main() {
    FILE *f;
    f = fopen("INP.TXT", "rt");
    int a1, b1, c1, a2, b2, c2;
    double d, dx, dy, x, y;
    fscanf(f, "%d%d%d", &a1, &b1, &c1);
    fscanf(f, "%d%d%d", &a2, &b2, &c2);
    d = a1 * b2 - a2 * b1;
    dx = c1 * b2 - c2 * b1;
    dy = a1 * c2 - a2 * c1;
    fclose(f);
    f = fopen("OUT.TXT", "wt");
    if (d != 0) {
        x = (double)dx / d;
        y = (double)dy / d;
        fprintf(f, "x = %lf\n", x);
        fprintf(f, "y = %lf\n", y);
    }
    fclose(f);

    return 0;
}
