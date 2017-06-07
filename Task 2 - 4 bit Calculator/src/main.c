/*
 * Main file of the 4 bit calculator task.
 * From here we start the program.
 *
 * main.c
 *
 *  Created on: 3.06.2017 г.
 *      Author: justbobi
 */

#include <stdio.h>
#include "../headers/functions.h"

/*
 * Starting point of the program
 * Here we call all our custom functions
 */
int main() {
	setbuf(stdout, NULL);

	printf("-------4 bit calculator--------\n");
	printf("Enter a whole number between 0 and 15\n");
	printf("Please enter it in this order <digit> <operator> <digit> \n-> ");
	checkNumber();

	return 0;
}
