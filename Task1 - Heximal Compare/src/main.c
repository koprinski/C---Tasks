/*
 * Main file of the heximal - compare task.
 * From here we start the program.
 *
 * main.c
 *
 *  Created on: 30.05.2017 г.
 *      Author: justbobi
 */

#include <stdio.h>

/*
 * Starting point of the program
 * Here we call all our custom functions
 */
int main () {
	setbuf(stdout, NULL);
	char *heximalNum;
	heximalNum = (char*)malloc(sizeof(int));

	printf("Enter a whole number between 0 and 2^32 : ");
	int validDecimal = checkNumber();

	if (validDecimal == 0) {
		printf("Your input value is incorrect!\n");
	} else {
		heximalNum = convertHex(validDecimal);
		compareHex(heximalNum);
	}

	return 0;
}
