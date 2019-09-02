#include <stdio.h>

int		main()
{/*
	printf("%#hhhMol%%%\n");
	printf("%-5%\n");

	printf("4567 |%-10]hello5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("4567 |%-10h", 12);
	printf("|%10.5d|\n", -12);
	printf("|%10d|\n\n", -12);
	printf("|%0.10d|\n", -12); 
	printf("|%-10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);
*/
	/************************************************************************/
	//test for char
	/************************************************************************/
	printf("char: |%c|\n", 'q');
	printf("char: |%hhc|\n", 'q');
	printf("char: |%llc|\n", 'q');
	printf("char: |%hc|\n", 'q');
	printf("char: |%lc|\n", 'q');
	printf("char: |%+c|\n", 'q');
	printf("char: |%-5c|\n", 'q');
	printf("char: |%#c|\n", 'q');
	printf("char: |%0c|\n", 'q');
	printf("char: |% 5c|\n", 'q');
	return (0);
}
