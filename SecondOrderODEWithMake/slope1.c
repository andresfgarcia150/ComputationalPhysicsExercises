#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double slope1(double x, double y1, double y2, double h)
{
	double k1 = y2;
	double k2 = y2 + k1*h/2;
	double k3 = y2 + k2*h/2;
	double k4 = y2 + k3*h;
	return (k1+2*k2+2*k3+k4)/6;
}
