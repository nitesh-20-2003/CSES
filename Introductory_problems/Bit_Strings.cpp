#include <iostream>

/**
 * @brief Calculates the number of trailing zeros in the factorial of a given number n.
 *
 * The number of trailing zeros in n! is determined by the number of times 10 is a factor
 * in its prime factorization. Since 10 = 2 * 5, and the number of factors of 2 is always
 * greater than or equal to the number of factors of 5, the problem reduces to counting
 * the number of factors of 5.
 *
 * This can be found using Legendre's formula:
 * Zeros = floor(n/5) + floor(n/25) + floor(n/125) + ...
 *
 * @param n The non-negative integer for which to calculate the trailing zeros in n!.
 * The constraint is 1 <= n <= 10^9.
 * @return The total count of trailing zeros in n!.
 */
long long countTrailingZeros(int n) {
    // Initialize count of trailing zeros
    long long count = 0;

    // The loop calculates floor(n/5), floor(n/25), floor(n/125), and so on,
    // and adds them to the count.
    // We use a long long for 'i' to prevent potential overflow as 'i' can get large,
    // though for n <= 10^9, it will not exceed the long long limit.
    for (long long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }

    return count;
}

int main() {
    // Fast I/O for performance, useful in competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    // Read the integer n from standard input
    std::cin >> n;

    // Calculate the result and print it to standard output
    std::cout << countTrailingZeros(n) << std::endl;

    return 0;
}
