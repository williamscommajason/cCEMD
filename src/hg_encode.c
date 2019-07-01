#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stats.h"
#include "rice_encode.h"
#include "hg_encode.h"

char * zero_padding(char char_array)
{
        char zero[]= "0";

	return (char *)strcat((char *)zero, (char *)char_array);
}


int main()
{
	char char_array[] = "11111";
	char padded[] = zero_padding(char_array);
	printf("This string is %s\n",padded);

	return 0;
}
