#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int index_mas, si_mas;
    const double pi = 3.14;
    double sx, ex, x, a, G, F, Y, step, min_mas, max_mas;
    char Function, off;
    for (;;) { /*start*/
        printf("Введите начальное значение Х:");
        scanf("%lf", &sx);
        printf("Введите конечное значение Х:");
        scanf("%lf", &ex);
        printf("Введите значение A:");
        scanf("%lf", &a);
        printf("Введите шаг:");
        scanf("%lf", &step);
        index_mas = (int) ceil(fabs(sx) * fabs(ex) / step + 10);
        double mas[index_mas];
        si_mas = 0;
        for(;;) { /*funk*/
            printf("Введите название функции(G, F, Y):\n");
            scanf("%s", &Function);
            switch (Function) {
                case 'G':
                    for (x = sx; x <= ex; x += step) {
                      if ((9 * a*a + 59 * a * x + 30 * x*x) != 0) {
                            G = (9*(7*a*a + 39 * a * x + 20 * x*x)) /
                                (9 * a*a + 59 * a * x + 30 * x*x);
                        } else
                            printf("При X = %lf, A = %lf, функцию вычислить невозможно.\n", x, a);
                        mas[si_mas] = G;
                        si_mas += 1;
                    }
                    break;
                case 'F':
                    for (x = sx; x <= ex; x += step) {
                      if (atan(10*a*a - 43 * a * x + 28 * x*x) != 0) {
                         F = atan(10*a*a - 43 * a * x + 28 * x*x);
                        } else
                            printf("При X = %lf, A = %lf, функцию вычислить невозможно.\n", x, a);
                        mas[si_mas] = F;
                        si_mas += 1;
                    }
                    break;
                case 'Y':
                    for (x = sx; x <= ex; x += step) {
                      if ((log(-10*a*a + 27 *a*x + 28 * x*x + 1)) / log(10) < 0) {
                         Y = log(-10*a*a + 27 *a*x + 28 * x*x + 1) / log(10);
                        } else
                            printf("При X = %lf, A = %lf, функцию вычислить невозможно.\n", x, a);
                        mas[si_mas] = Y;
                        si_mas += 1;
                    }
                    break;
                default:
                    printf("Неправильно выбрана функция.");
                    continue;
            }
            break;
        }
        si_mas = 0;
        min_mas = mas[0];
        max_mas = mas[0];
        printf("╔═════════╦═════════╦═════════╗\n");
        printf("║    X    ║    A    ║    %c    ║\n", Function);
        printf("╠═════════╬═════════╬═════════╣\n");
        for (x = sx; x <= ex; x += step) {
            printf("║%9.3lf║%9.3lf║%9.3lf║\n", x, a, mas[si_mas]);
            si_mas += 1;
            if (mas[si_mas] > max_mas)
                max_mas = mas[si_mas];
            if ((mas[si_mas] < min_mas) && (fabs(mas[si_mas]) >= 0.001))
                min_mas = mas[si_mas];
        }
        printf("╚═════════╩═════════╩═════════╝\n");
        printf(" Минимальное значение  = %9.3lf\n Максимальное значение = %9.3lf\n", min_mas, max_mas);

        for(;;) { /*off*/
            printf("Продолжить работу программы?(y/n)\n");
            scanf("%s", &off);
            switch (off) {
                case 'y':
                    break;
                case 'n':
                    exit(0);
                default:
                    printf("Неправильно введен ответ.\n");
                    continue;
            }
            break;
        }
    }
}
