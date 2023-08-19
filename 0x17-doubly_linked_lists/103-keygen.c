#include<stdio.h>
#include <string.h>
#include<stdlib.h>

/**
 * main - it generates key depending on a username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	unsigned int z, b;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	p[0] = l[(len ^ 59) & 63];
	for (z = 0, add = 0; z < len; z++)
		add += argv[1][z];
	p[1] = l[(add ^ 79) & 63];
	for (z = 0, b = 1; z < len; z++)
		b *= argv[1][z];
	p[2] = l[(b ^ 85) & 63];
	for (b = argv[1][0], z = 0; z < len; z++)
		if ((char)b <= argv[1][z])
			b = argv[1][z];
	srand(b ^ 14);
	p[3] = l[rand() & 63];
	for (b = 0, z = 0; z < len; z++)
		b += argv[1][z] * argv[1][z];
	p[4] = l[(b ^ 239) & 63];
	for (b = 0, z = 0; (char)z < argv[1][0]; z++)
		b = rand();
	p[5] = l[(b ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
