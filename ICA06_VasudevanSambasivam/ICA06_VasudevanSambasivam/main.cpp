#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Methods needed
unsigned long long isnumber(char * arrayi);//checks if inputted entry is number
void printBits(unsigned long long num, int bit);//prints bits from MSB to LSB
void reverse(unsigned long long num, int bit);//prints number in reverse
unsigned int fib(unsigned int n);//prints number in fibonacci form


int main(int argc, char** argv)
{
	unsigned long long num = 0;

	if (argc == 2)
	{
		num = isnumber(argv[1]);
		printBits(num,63);
		printf("\n");
		reverse(num, 0);
		printf("\n");
		printf("%d ", fib(num));
	}
	getchar();
	return 0;
}

unsigned long long isnumber(char * arrayi)
{
	//checks if the string entered is a number
	for (int i = 0; i < strlen(arrayi); i++)
		if (isdigit(arrayi[i]) == 0)
			return 0;
	return strtoull(arrayi, NULL, 10);
}

//prints from msb to lsb
void printBits(unsigned long long num, int bit)
{
	unsigned long long mask = 1ULL << bit;//sets mask
	//if number is a one
	if (num & mask)
		printf("1");
	//if a number is zero
	if (!(num & mask))
		printf("0");
	//if a number is null return;
	if (!bit)
		return;
	//other wise go to the next bit
	printBits(num, bit-1);
}

//prints from lsb to msb
void reverse(unsigned long long num, int bit)
{
	unsigned long long mask = 1ULL << bit;

	if (num & mask)
		printf("1");
	if (!(num & mask))
		printf("0");
	if (bit == 63)
		return;
	reverse(num, bit + 1);
}

//prints the fib number for the number inputted
unsigned int fib(unsigned int n)
{
	if (n == 0)
		return 0;
	if(n==1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}