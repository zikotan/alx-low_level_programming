/**
 * add - Adds two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The sum of the two integers
 */
int add(int a, int b) {
    return a + b;
}

/**
 * sub - Subtracts two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The result of subtracting the second integer from the first
 */
int sub(int a, int b) {
    return a - b;
}

/**
 * mul - Multiplies two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The product of the two integers
 */
int mul(int a, int b) {
    return a * b;
}

/**
 * div - Divides two integers
 * @a: The numerator
 * @b: The denominator
 *
 * Return: The result of dividing the numerator by the denominator
 */
int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        // Handle division by zero (you may choose an appropriate action)
        return 0;
    }
}

/**
 * mod - Computes the remainder of the division of two integers
 * @a: The numerator
 * @b: The denominator
 *
 * Return: The remainder of the division
 */
int mod(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        // Handle modulo by zero (you may choose an appropriate action)
        return 0;
    }
}
