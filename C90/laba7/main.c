#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f, *f1;

    struct
    {
        double G[100];
        double F[100];
        double Y[100];
    } data;

    char enter[1000];
    const double pi = 3.14;
    double a, x, x2, step;
    double memory[1];
    int i = 0;

    printf("Введите X: ");
    scanf("%s", enter);
    x = atof(enter);
    getchar();
    memset(enter, 0, 100);
    printf("Введите предел X: ");
    scanf("%s", enter);
    x2 = atof(enter);
    getchar();
    memset(enter, 0, 100);
    printf("Введите а: ");
    scanf("%s", enter);
    a = atof(enter);
    getchar();
    memset(enter, 0, 100);
    printf("Введите шаг: ");
    scanf("%s", enter);
    step = atof(enter);
    getchar();
    memset(enter, 0, 100);

    memory[0] = x;
    memory[1] = x2;

    while (x < x2)
    {
        data.G[i] = (9*(7*a*a + 39 * a * x + 20 * x*x)) /
                                (9 * a*a + 59 * a * x + 30 * x*x);
        i++;
        if (i > 100)
            break;
        x = x + step;
        if (x >= x2) {
            break;
        }
    }

    i = 0;
    x = memory[0];
    x2 = memory[1];

    while (x < x2)
    {
        data.F[i] = atan(10*a*a - 43 * a * x + 28 * x*x);
        i++;
        if (i > 100)
            break;
        x = x + step;
        if (x >= x2)
            break;

    }

    i = 0;
    x = memory[0];
    x2 = memory[1];

    while (x < x2)
    {
        data.Y[i] = log(-10*a*a + 27 *a*x + 28 * x*x + 1) / log(10);
        i++;
        if (i > 100)
            break;
        x = x + step;
        if (x >= x2)
            break;
    }

    f = fopen("/home/andrey/laba7.txt","w");  /*в фаил записываются значения переменных структуры*/
    fprintf(f, "=====================================================================================================\n");
    for (i = 0; i < 100; i++)
    {
        fprintf(f,"|%lf|%lf|%lf|\n",data.G[i], data.F[i], data.Y[i]);
        fprintf(f, "________________________________________________________________________________________________\n");
    }
    fclose(f);
    f1 = fopen("/home/andrey/laba7.txt","r"); /*с файла считываются все данные*/
    while (!feof(f1))
    {
        fscanf(f1, "%s", enter);
        printf("%s\n", enter);
    }
    fclose(f1);
    return 0;
}
