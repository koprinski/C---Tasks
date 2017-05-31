/*
 * All necessary functions used for the Heximal Compare task
 *
 * functions.c
 *
 *  Created on: 30.05.2017 г.
 *      Author: justbobi
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../headers/functions.h"

/*
 * Checks if the input value is a whole number
 * and is it between 0 and 2^32.
 * return - integer number
 */
int checkNumber() {
	int num, inputValue;
	char term;
	inputValue = scanf("%d%c", &num, &term);

	if(inputValue != 2 || term != '\n' || num < 0 || num > pow(2,32)) {
		return 0;
	}
	else {
		return num;
	}
}

/*
 * Converts decimal numbers into heximal
 * return - char of heximal number
 */
char *convertHex(int decimalNum) {
	int quotient, remainder;
	int i,j = 0;
	char *heximalNum;
	heximalNum = (char*)malloc(sizeof(int));

	quotient = decimalNum;

	while (quotient != 0) {

		remainder = quotient % 16;
		if (remainder < 10) {
			heximalNum[j++] = 48 + remainder;
		} else {
			heximalNum[j++] = 55 + remainder;
		}
	    quotient = quotient / 16;
	}

	// display heximal value
	printf("Hex - > ");
	for (i = j; i >= 0; i--) {
		printf("%c", heximalNum[i]);
	}

	return (char *)heximalNum;

}

/*
 * Compares heximal numbers and prints results
 * If the number contains equal digits - YES
 * Else it prints No
 */
void compareHex(char *heximalNum) {
	int i,j;
	int equal = 0;
	int length = strlen(heximalNum);

	for(i = 0; i < length-1; i++) {
		// loop through numbers falling ahead
		for(j = 0; j < length-1-i; j++) {
			if(heximalNum[j] == heximalNum[j+1]) {
				equal++;
			}
		}
	}

	if (equal > 0) {
		printf("\nYour value has equal digits!  - > YES");
	} else {
		printf("\nYour value has no equal digits!  - > NO");
	}

}
