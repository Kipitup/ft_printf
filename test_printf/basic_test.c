#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

int		main(int ac, char **av)
{
	(void)ac;
	int64_t oct = 15616165651;
	/*
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
	printf("|%-010.5.3d|\n", -12);
	printf("|%-010.-5.50-.d|\n", -12);
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
	   printf("h: |%ahs|\n", av[1]);
	   printf("hh: |%hhs|\n", av[1]);
	   printf("l: |%ls|\n", av[1]);
	   printf("ll: |%lls|\n", av[1]);
	   */
	/************************************************************************/
	//test for decimal
	///************************************************************************/
	/*
	printf("hh:|%hhd|\n", 12);
	printf("h:|%hd|\n", 12);
	printf("ll:|%lld|\n", 12);
	printf("l:|%ld|\n", 12);
	printf("L:|%Ld|\n", 12);
	printf("#:|%#d|\n", 12);
	*/
	/************************************************************************/
	//test for pointer 
	/************************************************************************/
/*	printf("hh:|%hhp|\n", ptr);
	printf("h:|%hp|\n", ptr);
	printf("ll:|%llp|\n", ptr);
	printf("l:|%lp|\n", ptr);
*/
	/************************************************************************/
	//test for octal 
	/************************************************************************/
	printf("octal:|%o|\n", oct);
	printf("hh:|%hho|\n", oct);
	printf("h:|%ho|\n", oct);
	printf("ll:|%llo|\n", oct);
	printf("l:|%lo|\n", oct);

	return (0);
}
