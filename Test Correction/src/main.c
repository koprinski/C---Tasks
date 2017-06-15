/*
 * main.c
 *
 *  Created on: 12.06.2017 ã.
 *      Author: justbobi
 */

#include <stdio.h>
#include "../headers/functions.h"

int main() {

	// Test String for Ex1
	char str[] = "aaaaasssbaacdaaaef";
	correctStr(str);

	//Reverse hex Ex2
	unsigned int numb = 1234567;
	printReverse(numb);

	//Print matrix Ex3
	int arr[6] = {1,2,3,4,5,6};
	printMatrix(arr,5,2);

	return 0;
}
