#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double slope2(double x, double y1, double y2, double h)
{
	double k1 = function(x,y1);
	double k2 = function(x + h/2, y1 + k1*h/2);
	double k3 = function(x + h/2, y1 + k2*h/2);
	double k4 = function(x + h, y1 + k3*h);
	return (k1+2*k2+2*k3+k4)/6;
}
