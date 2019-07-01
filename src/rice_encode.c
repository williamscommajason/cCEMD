#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stats.h"
#include "rice_encode.h"

static void put_bit(FILE *fd, char bit)
{
	static unsigned char buff=0;
	static unsigned char filled=0;

	buff = buff | (bit << (7 - filled));

	if (filled == 7)

	{
		fwrite(&buff, sizeof(buff), 1, fd);
                buff = 0;
		filled = 0;
	}

        else

	        filled += 1;
}


static int * signed_to_unsigned(int * signed_array, unsigned long int L)
{
	int *unsigned_array;
	unsigned_array = (int *)malloc(sizeof(signed_array[0])*L);

	for (int i = 0; i < L; i++)
	{
		if (signed_array[i] >= 0)
		{
			unsigned_array[i] = 2 * signed_array[i];

		}
		else
		{
			unsigned_array[i] = -2 * signed_array[i] - 1;
		}

	}
        

	return unsigned_array;
}



static int get_k(int * error, int length)
{
	
	double var, std;

	var = get_var(error, length);
	std = sqrt(var);
	int k = (int) round(Log2(std));
        
	return k;
}	

void rice_code(FILE *fd, int x, int k)
{
	int q = x / (1 << k);
        	
	for (int i = 0; i < q; i++)
	{
		put_bit(fd, 1);
	}
	put_bit(fd, 0);
        
	int count = (int) k - 1;

	while (k > 0)
	{ 
		put_bit(fd, (x >> k) & 1);
	        
		k--;
	}
}

void compress(FILE *fd, int * signed_array, unsigned long int L)
{
	int *unsigned_array;
	int k;

	unsigned_array = signed_to_unsigned(signed_array, L);
	k = get_k(unsigned_array, L);
        
	for (int i = 0; i < L; i++)
	{
		rice_code(fd, unsigned_array[i], k);
	}
}

int main()
{
	int signed_array[10] = {0,1,-1,2,-2,3,-3,4,-4,5};
	FILE *fd;
	
	fd = fopen("test.bin","wb");

	if (!fd)
	{
		printf("Unable to open file!\n");
		return 1;
	}
        
	compress(fd, signed_array, 10);
	fclose(fd);
	return 0;
}
