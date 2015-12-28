#include <stdio.h>
#include <math.h>

double epsilon()
{
	double eps = 1.0;

	while (eps / 2.0 + 1.0 > 1.0) eps /= 2.0;

	return eps;
}

int main(void)
{
	const double a = 0, b = 0.5;
	double tayVal, realVal, tmp, eps = epsilon(), x = a;
	int n, k, i, step;

	printf("Введите n: ");
	scanf("%d", &n);
	printf("Введите k: ");
	scanf("%d", &k);

	printf("Машинное эпсилон для типа double = %1.50f\n", eps);
	printf("        Таблица значений ряда Тейлора и стандартной функции для f(x)=1/(2x-5)\n");
	printf("╔═══════╦══════════════════════════════╦══════════════════════════════╦════════════════╗\n");
	printf("║   x   ║     част. сумма для ряда     ║       значения функции       ║ число итераций ║\n");
	printf("╟═══════╬══════════════════════════════╬══════════════════════════════╬════════════════╣\n");

	for (i = 0; i <= n; i++)
	{
		step = 0;
		tayVal = 0;
		realVal = 1/(2*x-5);

		while (1)
		{
			step++;
			tmp = -pow(2,step-1)*pow(x,step-1)/pow(5,step);
			tayVal += tmp;

			if (fabs(realVal - tayVal) < eps * k || step == 100) break;
		}

		printf("║%7.2f║%30.20f║%30.20f║%16d║\n", x, tayVal, realVal, step);

		x += (b - a) / n;
	}

	printf("╚═══════╩══════════════════════════════╩══════════════════════════════╩════════════════╝\n");

	return 0;
}
