#include <stdio.h>
#include <math.h>

int main()
{
    float init = 7 * 30;
    float x = init, dx = 30 * sqrt(2);
    float y = init;
    float z = init;
    int i;

    printf("init=%.10f\n", init);
    printf("x=%.10f\n", x);
    printf("dx=30*sqrt(2)=%.10f\n", dx);
    printf("y=%.10f\n", y);
    printf("z=%.10f\n", z);
    printf("\n");
    printf("%2s %14s %14s %19s %13s %13s\n", "i", "x+=dx", "y+=30*sqrt(2)",
           "z=init+i*30*sqrt(2)", "x-y", "x-z");
    for (i = 1; i <= 10; i++) {
        x += dx;
        y += 30 * sqrt(2);
        z = init + i * 30 * sqrt(2);
        printf("%2d %14.10f %14.10f %14.10f      %13.10f %13.10f\n", i, x, y,
               z, x - y, x - z);
    }
}
