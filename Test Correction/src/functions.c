/*
 * functions.c
 *
 *  Created on: 12.06.2017 ã.
 *      Author: justbobi
 */
#include <stdio.h>
#include "../headers/functions.h"

/*
 * Ex 1. Function for string correction.
 * Locates the character 'a' and removes it from the string.
 */
void correctStr(char *str) {
	int i, j = 0;

	while (str[i])  {
		if (str[i]!= 'a') {
			str[j++] = str[i];
		}
		i++;
	}
	str[j]= '\0';
	printf("Exercise 1 - %s\n", str);
	printf("------------------------\n");
}

/*
 * Ex 2. Function that moves bits of 32 bit numbers.
 * It uses the mask 0xff
 */
void printReverse (unsigned int num, int numLen) {
	int i;

	printf("Exercise 2 - 0x");
	for(i=0; i<numLen; i++) {
		printf("%X", (num >> (i*4)) & 0x0F);
	}

	printf("\n------------------------\n");
}

/*
 * Ex 3. Function that prints another matrix with specified sizes.
 * This matrix has to be in the lower left angle.
 */
void printMatrix(int *arr, int size, int n) {
	int existArray[20][20];
	int i,j,k = 0;

	for (i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			k %= size;
			existArray[i][j] = arr[k++];
		}
	}
	printf("Exercise 3 - ");
	for (i=0; i<n; i++) {
		for(j=20-n; j<20; j++) {
			printf("%d", existArray[j][i]);
		}
	}
}
