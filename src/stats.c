#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stats.h"

double get_mean(int * array, int length)
{
	int sum = 0;
	double mean;

	for (int i = 0; i < length; i++)
	{       
		sum += array[i];
	}

	mean = sum /(float)length;
	
	return mean;
}

double get_var(int * array, int length)
{
	int varsum = 0;
	double variance, differ;
	double mean = get_mean(array, length);

	for (int i = 0; i < length; i++)
	{
		differ = array[i] - mean;
		varsum += pow(differ , 2);
	}

	variance = varsum/(float)length;
	
	return variance;
}

double Log2( double n)
{
	return log(n)/log(2);
}

