/*
 * Custom library used for our functions
 *
 * functions.h
 *
 *  Created on: 30.05.2017 г.
 *      Author: justbobi
 */

/*
 * Checks if the input value is a whole number
 * and is it between 0 and 2^32.
 */
extern int checkNumber();

/*
 * Converts decimal numbers into heximal
 */
extern char *convertHex(int decimalNum);

/*
 * Compares heximal numbers and prints results
 * If the number contains equal digits - YES
 * Else it prints No
 */
extern void compareHex(char *heximalNum);
