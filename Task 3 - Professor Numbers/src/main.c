/*
 * Main file of the Professor pattern task.
 * From here we start the program.
 * main.c
 *
 *  Created on: 17.06.2017 г.
 *      Author: justbobi
 */

#include <stdio.h>

/*
 * Pattern recursive function
 * Prints a pattern formulated from the user input
 */
void pattern(int n) {
	if (n > 0) {
		pattern(n-1);
		printf("%d", n);
		pattern(n-1);
	}
}

/*
 * Starting point of the program
 * Here we call the pattern function
 * after the user validation
 */
int main() {
	int num;
	char term;

	printf("Enter a whole number between 0 and 20 \n");
	printf("-> ");
	fflush(stdout);
	scanf("%d%c", &num, &term);

	if (num < 0 || num > 20 || term != '\n') {
		fprintf(stderr, "ERROR: Please enter your values correctly!");
	} else {
		pattern(num);
	}

	return 0;
}
