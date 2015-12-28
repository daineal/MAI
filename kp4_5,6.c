
#include <stdio.h>
#include <math.h>
#include <tgmath.h>
#include <float.h>
double f5(double x) //ФУНКЦИЯ ВАРИАНТА 5 В ВИДЕ F(x)=0
{
    return sqrt(1-x)-tan(x);
}
double df5(double x) //ПЕРВАЯ ПРОИЗВОДНАЯ ФУНКЦИИ ВАРИАНТА 5
{
    return -1/(2*sqrt(1-x)) - 1/(cos(x)*cos(x));
}
double af5(double x) //ФУНКЦИЯ ВАРИАНТА 5 В ВИДЕ x=f(x)
{
    return atan(sqrt(1-x));
}
double f6(double x) //ФУНКЦИЯ ВАРИАНТА 6 В ВИДЕ F(x)=0
{
    return x+cos(pow(x,0.52)+2);
}
double df6(double x) //ПЕРВАЯ ПРОИЗВОДНАЯ ФУНКЦИИ ВАРИАНТА 6
{
    return 1-0.52*sin(pow(x,0.52)+2)/pow(x,0.48);
}
double af6(double x) //ФУНКЦИЯ ВАРИАНТА 6 В ВИДЕ F(x)=0
{
    return -cos(pow(x,0.52)+2);
}

double dichotomy(double (*f)(double x), double eps, double a, double b)
{
	double infimum = a;
	double supremum = b;
	double tmp;

	while (fabs(infimum - supremum) >= eps)
	{
		tmp = (infimum + supremum) / 2.0;

		if (f(infimum) * f(tmp) > 0.0) infimum = tmp;
		else supremum = tmp;
	}

	return ((infimum + supremum) / 2.0);
}

double iteration(double (*f)(double x), double eps, double a, double b)
{
	double x1 = a;
	double x2 = (a + b) / 2.0;

	while (fabs(x2 - x1) >= eps)
	{
		x1 = x2;
		x2 = f(x1);
	}

	return x1;
}

double newton(double (*f)(double x), double (*f1)(double x), double eps, double a, double b)
{
	double x1 = a;
	double x2 = (a + b) / 2.0;

	while (fabs(x2 - x1) >= eps)
	{
		x1 = x2;
		x2 = x1 - f(x1) / f1(x1);
	}

	return x1;
}

int main(void)
{
	double eps = 0.000001;

	double d5 = dichotomy(f5, eps, 0, 1);
	double i5 = iteration(af5, eps, 0, 1);
	double n5 = newton(f5, df5, eps, 0, 1);

	double d6 = dichotomy(f6, eps, 0.5, 1);
	double i6 = iteration(af6, eps, 0.5, 1);
	double n6 = newton(f6, df6, eps, 0.5, 1);

	printf("╔═══════════╦══════════╦═══════════════╦═══════════════════════╦════════════╦═══════════╦══════════╗\n");
	printf("║ Уравнение ║ Отрезок  ║ Базовый метод ║ Прибл. значение корня ║ Дихотомии  ║ Итераций  ║ Ньютона  ║\n");
	printf("╟═══════════╬══════════╬═══════════════╬═══════════════════════╬════════════╬═══════════╬══════════╣\n");
	printf("║     5     ║ [0, 1]   ║    дихотомии  ║         0.5768        ║%.9f ║%.8f ║%.7f ║\n", d5,i5, n5);
	printf("╟═══════════╬══════════╬═══════════════╬═══════════════════════╬════════════╬═══════════╬══════════╣\n");
	printf("║     6     ║ [0.5, 1] ║    итерации   ║         0.9892        ║%.9f ║%.8f ║%.7f ║\n", d6, i6, n6);
	printf("╚═══════════╩══════════╩═══════════════╩═══════════════════════╩════════════╩═══════════╩══════════╝\n");
	printf("Точность: %.6f\n", eps);
	return 0;
}
