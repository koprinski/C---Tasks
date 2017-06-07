/*
 * All necessary functions used for the 4 bit calculator
 *
 * functions.c
 *
 *  Created on: 3.06.2017 г.
 *      Author: justbobi
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/functions.h"

/*
 * Checks if the input value is a whole number
 * and is it between 0 and 15.
 */
void checkNumber() {
	int firstNumber, secondNumber;
	int i = 0;
	char operator;
	char option[10];
	char line[10];
	char *numbers[32];
	char *token;
	char *copy; // keeps copy of the string for the operator
	char *err1;
	char *err2;

	if(fgets(line, sizeof(line), stdin)) {
		if (1 == sscanf(line, "%[^\n]%*c", option)) {
			if (strlen(option) < 6) {

				copy = strdup(option);
				token = strtok(option , "-,+,*,/,%");

				while( token != NULL ) {
					numbers[i++] = token;
					token = strtok(NULL, "-,+,*,/,%");
				}

				operator = copy[strtok(option , "-,+,*,/,%")-option+strlen(strtok(option , "-,+,*,/,%"))];

				if (i != 2) {
					fprintf(stderr, "ERROR: Please enter your values correctly!");
				} else {
					//firstNumber = atoi(numbers[0]);
					//secondNumber = atoi(numbers[1]);

					firstNumber = (int) strtol(numbers[0], &err1, 10);
					secondNumber = (int) strtol(numbers[1], &err2, 10);

					if (err1 == numbers[0] || err2 == numbers[1]) {
						fprintf(stderr, "ERROR: Please enter your input in the correct order!");
					} else if (firstNumber>=0 && secondNumber>=0) {

						calculate(firstNumber, secondNumber, operator);

						if (copy != NULL) {
							free(copy);
						}
					} else {
						fprintf(stderr, "ERROR: Please enter your values correctly!");
					}
				}
			} else {
				fprintf(stderr, "ERROR: Your input is too long. Please enter your values correctly!");
			}
		} else {
			fprintf(stderr, "ERROR: You can't enter blank space. Please enter your values correctly!");
		}
	 }
}

/*
 * Calculates the values after the user input.
 */
void calculate(int firstNumber, int secondNumber, char operator) {
	int result, flag = 0;

	if (firstNumber > 16) {
		firstNumber = firstNumber - 16;
	}
	if (secondNumber > 16) {
		secondNumber = secondNumber - 16;
	}

	switch (operator) {
		case '+' :
			result = firstNumber + secondNumber;
			break;
		case '-' :
			result = firstNumber - secondNumber;
			break;
		case '*' :
			result = firstNumber * secondNumber;
			break;
		case '/' :
			if (secondNumber != 0) {
				result = firstNumber / secondNumber;
			} else {
				flag = 1;
				//printf("Division by zero!");
				fprintf(stderr, "ERROR: Division by zero!");
			}
			break;
		case '%' :
			if (secondNumber != 0) {
				result = firstNumber % secondNumber;
			} else {
				flag = 1;
				//printf("Division by zero!");
				fprintf(stderr, "ERROR: Division by zero!");
			}
			break;
		default:
			//printf("Please write a correct operator!");
			fprintf(stderr, "ERROR: Please write a correct operator!");
	}

	if (result > 16) {
		result = result - 16;
	} else if (result < 0) {
		result = 16 + result;
	}
	if (flag != 1) {
		printf("\nresult : %d", result);
	}
}
