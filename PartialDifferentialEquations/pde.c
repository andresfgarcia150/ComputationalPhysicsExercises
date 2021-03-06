// Universidad de los Andes
// Andrés Felipe García Albarracín
// Partial differential equations
// Carmen VIEJA FEA

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

double initialCondition (double x);

int main ()
{ 
	int i = 0;	
	int n_points = 1000;
	double delta_t = 0.0005;
	double* x_array = malloc(sizeof(double)*n_points);
	double* u_old = malloc(sizeof(double)*n_points);
	double* u_new = malloc(sizeof(double)*n_points);
	double* u_init = malloc(sizeof(double)*n_points);
	
	FILE 	*fileOut;
	fileOut = fopen("fileOut.txt","w");
	if (!fileOut)
	{
		printf("Problema creando el archivo");
		exit(1);
	}

	if(!x_array || !u_new || !u_old || !u_init)
	{
		printf("Problema creando el arreglo");
		exit(1);
	}
	
	// Initialization of time array and initial condition	
	for (i = 0; i<n_points; i++)
	{
		x_array[i] = (i*1.0)/(n_points-1);
		u_init[i] = initialCondition(x_array[i]);
	}

	// Boundary condition
	u_init[0]=0.0;
	u_init[n_points-1] = 0.0;
	u_new[0]=0.0;
	u_new[n_points-1] = 0.0;
	
	double delta_x = x_array[1]-x_array[0];
	double c = 1.0;
	double r = c*delta_t/delta_x;

	for (i = 0; i<n_points; i++)
		u_old[i] = u_init[i];

	// First iteration
	for (i = 1;i<n_points-1;i++)
	{
		u_new[i] = u_old[i] + r*r/2*(u_old[i+1]-2*u_old[i]+u_old[i-1]);
	}
	

	// Saving file
	for (i = 0; i<n_points;i++)
	{
		fprintf(fileOut,"%f    %f    %f\n", x_array[i], u_init[i], u_new[i]);
	}
	fclose(fileOut);


}

double initialCondition (double x)
{
	return exp(-((x-0.3)*(x-0.3))/0.01);
}
