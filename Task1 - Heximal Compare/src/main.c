/*
 * Main file of the heximal - compare task.
 * From here we start the program.
 *
 * main.c
 *
 *  Created on: 30.05.2017 ã.
 *      Author: justbobi
 */

#include <stdio.h>
#include "../headers/functions.h"

/*
 * Starting point of the program
 * Here we call all our custom functions
 */
int main () {
	setbuf(stdout, NULL);

	printf("Enter a whole number between 0 and 2^32 : ");
	long long validDecimal = checkNumber();

	if (validDecimal == 0) {
		printf("Your input value is incorrect!\n");
	} else {
		compareHex(convertHex(validDecimal));
	}

	return 0;
}
