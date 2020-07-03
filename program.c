#include "yespower.h"
#include <stdio.h>
#include <string.h>
#include "hextools.h"



int yespower_hash(const char *input, char *output);



int main (int argc, char **argv)
{
	//printf("%s\n", argv[1]);
	char * temp = hex2bin(argv[1]);
	char * out = malloc(256);
	char * dis = malloc(33);


	yespower_hash(temp,out);
	dis = bin2hex(out,32);
	printf("%s\n", dis);
	return 0;
}
