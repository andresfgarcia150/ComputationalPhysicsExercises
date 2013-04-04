// Universidad de los Andes
// Física computacional
// Solving Second order ODEs
//		y"=-4sin(y)
// The function can be modified changing the expression of function

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define condInicial1 4
#define condInicial2 0
#define x_Final 10

// ARREGLAR: CON LOS .H

int main()
{
	int i;
	double h = 0.001;
	int n_points = x_Final/h;
	double* y1_array = malloc(sizeof(double)*n_points);
	double* x_array = malloc(sizeof(double)*n_points);
	double* y2_array = malloc(sizeof(double)*n_points);
	FILE 	*fileOut;
	if(!y1_array && !x_array && !y2_array)
	{
		printf("Problema creando el arreglo");
		exit(1);
	}
	
	y1_array[0] = condInicial1;
	y2_array[0] = condInicial2;
	x_array[0] = 0;

	fileOut = fopen("fileOut.txt","w");
	if (!fileOut)
	{
		printf("Problema creando el archivo");
		exit(1);
	}
	fprintf(fileOut,"%f    %f    %f\n", x_array[0], y1_array[0], y2_array[0]);
	for(i = 1; i<n_points; i++)
	{
		x_array[i] = i*h;
		y1_array[i] = y1_array[i-1] + slope1(x_array[i-1],y1_array[i-1],y2_array[i-1],h)*h;
		y2_array[i] = y2_array[i-1] + slope2(x_array[i-1],y1_array[i-1],y2_array[i-1],h)*h;
		fprintf(fileOut,"%f    %f    %f\n", x_array[i], y1_array[i], y2_array[i]);
	}
	fclose(fileOut);
}


