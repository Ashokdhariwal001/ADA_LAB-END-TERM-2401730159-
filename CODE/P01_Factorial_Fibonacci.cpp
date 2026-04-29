
#include <iostream>
using namespace std;

// ---------- FACTORIAL ----------

// Recursive factorial
long long factorialRecursive(int n) {
    if (n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

// Iterative factorial
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

// ---------- FIBONACCI ----------

// Recursive Fibonacci
long long fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci
long long fibonacciIterative(int n) {
    if (n <= 1)
        return n;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// ---------- MAIN ----------
int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Factorial results
    cout << "\nFactorial (Recursive): " << factorialRecursive(n);
    cout << "\nFactorial (Iterative): " << factorialIterative(n);

    // Fibonacci results
    cout << "\nFibonacci (Recursive): " << fibonacciRecursive(n);
    cout << "\nFibonacci (Iterative): " << fibonacciIterative(n);

    // Complexity comparison
    cout << "\n\n--- Time Complexity Comparison ---\n";

    cout << "Factorial Recursive: O(n)\n";
    cout << "Factorial Iterative: O(n)\n";

    cout << "Fibonacci Recursive: O(2^n) (very slow for large n)\n";
    cout << "Fibonacci Iterative: O(n)\n";

    cout << "\n--- Space Complexity ---\n";

    cout << "Factorial Recursive: O(n) (call stack)\n";
    cout << "Factorial Iterative: O(1)\n";

    cout << "Fibonacci Recursive: O(n) (call stack)\n";
    cout << "Fibonacci Iterative: O(1)\n";

    return 0;
}