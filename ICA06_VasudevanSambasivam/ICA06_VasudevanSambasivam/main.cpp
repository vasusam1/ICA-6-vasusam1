#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

unsigned long long isnumber(char * arrayi);
void printBits(unsigned long long num, int bit);
unsigned long long reverse(unsigned long long num);

int main(int argc, char** argv)
{
	unsigned long long num = 0;
	unsigned long long reverse_num = 0;

	if (argc == 2)
	{
		num = isnumber(argv[1]);
		printBits(num,63);
		printf("\n");
		reverse_num = reverse(isnumber(argv[1]));
		printBits(reverse_num, 63);
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

void printBits(unsigned long long num, int bit)
{
	unsigned long long mask = 1ULL << bit;

	if (num & mask)
		printf("1");
	if (!(num & mask))
		printf("0");
	if (!bit)
		return;
	printBits(num, bit-1);
}

unsigned long long reverse(unsigned long long num)
{
	unsigned long long bits = sizeof(num) * 8;
	unsigned long long reverse_num = 0;
	for (unsigned long long i = 0; i < bits; i++)
	{
		if ((num & (1 << i)))
			reverse_num |= 1 << ((bits - 1) - i);
	}
	return reverse_num;
}