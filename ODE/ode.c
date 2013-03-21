// Universidad de los Andes
// Física computacional
// Solving ODE
//		y' = 1 + y**2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define condInicial 0
#define x_Final 1

double function(double y, double x);
double slope(double x, double y, double h);

int main()
{
	int i;
	double h = 0.01;
	int n_points = x_Final/h;
	double* y_array = malloc(sizeof(double)*n_points);
	double* x_array = malloc(sizeof(double)*n_points);
	double* y_array_RK = malloc(sizeof(double)*n_points);
	FILE 	*fileOut;
	if(!y_array && !x_array && !y_array_RK)
	{
		printf("Problema creando el arreglo");
		exit(1);
	}
	
	y_array[0] = condInicial;
	y_array_RK[0] = condInicial;
	x_array[0] = 0;

	fileOut = fopen("fileOut.txt","w");
	if (!fileOut)
	{
		printf("Problema creando el archivo");
		exit(1);
	}
	fprintf(fileOut,"%f    %f    %f\n", x_array[0], y_array[0], y_array_RK[0]);
	for(i = 1; i<n_points; i++)
	{
		x_array[i] = i*h;
		y_array[i] = y_array[i-1] + h*function(x_array[i-1],y_array[i-1]);
		y_array_RK[i] = y_array_RK[i-1] + slope(x_array[i-1],y_array_RK[i-1],h)*h;
		fprintf(fileOut,"%f    %f    %f\n", x_array[i], y_array[i], y_array_RK[i]);
	}
	fclose(fileOut);
}

double function(double x, double y)
{
	return (1+y*y);
}

double slope(double x, double y, double h)
{
	double k1 = function(y,x);
	double k2 = function(x + h/2, y + k1*h/2);
	double k3 = function(x + h/2, y + k2*h/2);
	double k4 = function(x + h, y + k3*h);
	return (k1+2*k2+2*k3+k4)/6;
}
