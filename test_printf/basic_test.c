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
	/*
	printf("char: |%c|\n", 'Q');
	printf("char: |%hhc|\n", 'Q');
	printf("char: |%llc|\n", 'Q');
	printf("char: |%hc|\n", 'Q');
	printf("char: |%lc|\n", 'Q');
	printf("char: |%5c|\n", 'Q');
	printf("char: |%#c|\n", 'Q');
	printf("char: |%0c|\n", 'Q');
	printf("char: |%-5c|\n", 'Q');
	printf("char: |% 5c|\n", 'Q');
	*/
	/************************************************************************/
	//test for flag 
	/************************************************************************/
	printf("hh:|%hhd|\n", 12);
	printf("h:|%hd|\n", 12);
	printf("ll:|%lld|\n", 12);
	printf("l:|%ld|\n", 12);
	printf("L:|%Ld|\n", 12);
	printf("#:|%#d|\n", 12);
	return (0);
}
