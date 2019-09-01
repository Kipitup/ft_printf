#include <stdio.h>

int		main()
{/*
	printf("%#hhhMol%%%\n");
	printf("%-5%\n");
*/
	printf("4567 |%-10]hello5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("4567 |%-10h", 12);
	printf("|%10.5d|\n", -12);
	printf("|%10d|\n\n", -12);
	printf("|%0.10d|\n", -12); 
	printf("|%-10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);
	printf("|%c|\n", "qwdsad");
	return (0);
}
