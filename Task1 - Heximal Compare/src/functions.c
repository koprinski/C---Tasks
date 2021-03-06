/*
 * All necessary functions used for the Heximal Compare task
 *
 * functions.c
 *
 *  Created on: 30.05.2017 �.
 *      Author: justbobi
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/functions.h"


/*
 * Checks if the input value is a whole number
 * and is it between 0 and 2^32.
 * return - integer number
 */
long long checkNumber() {
	long long num, inputValue;
	char term;

	inputValue = scanf("%lli%c", &num, &term);

	if(inputValue != 2 || term != '\n' || num < 0 || num >= pow(2,32)) {
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
char *convertHex(long long decimalNum) {
	long long quotient, remainder;
	int i,j = 0;
	int n = 0;
	char *heximalNum;
	quotient = decimalNum;

	while (decimalNum != 0) {
		decimalNum = decimalNum / 16;
		n++;
	}
	heximalNum = malloc((n*4) + 1);

	while (quotient != 0) {
		remainder = quotient % 16;
		if (remainder < 10) {
			remainder = 48 + remainder;
		} else {
			remainder = 55 + remainder;
		}

		heximalNum[j++] = remainder;
		quotient = quotient / 16;
	}
	heximalNum[j] = '\0';


	// display heximal value
	printf("Hex - > ");
	for (i = j-1; i >= 0; i--) {
		printf("%c", heximalNum[i]);
	}

	return heximalNum;
}

/*
 * Compares heximal numbers and prints results
 * If the number contains equal digits - YES
 * Else it prints No
 */
void compareHex(char *heximalNum) {
	size_t length = strlen(heximalNum);
	int i = checkArray(heximalNum, length);

	if (i == 1) {
		printf("\nYour value has equal digits!  - > YES");
	} else if (i == 0) {
		printf("\nYour value has no equal digits!  - > NO");
	} else if (i == 2) {
		printf("\nYour value has only one digit after the conversion!  - > NO");
	}
	if (heximalNum != NULL) {
		free(heximalNum);
	}

}

/*
 * Inner function for checking if all array elements are equal
 * return 2 - Only one digit after the hex conversion
 * return 1 - True
 * return 0 - False
 */
int checkArray(char *arr, int n) {
	int i;
	if (n == 1) {
		return 2;
	}
	for (i = 0; i < n - 1; i++) {
		if (arr[i] != arr[i + 1])
			return 0;
	}
	return 1;
}
