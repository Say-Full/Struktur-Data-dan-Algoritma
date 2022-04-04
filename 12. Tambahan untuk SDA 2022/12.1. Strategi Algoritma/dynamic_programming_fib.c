#include<stdio.h>

// Dynamic Programming - Memoization
int arr[5];

int fib_memoization(int n) // Asumsikan n >= 0
{
    // Klo n = 0, maka fib_memoization(0) = 0 dan klo n = 1, maka fib_memoization(1) = 1
    if(n <= 1) {
        return n;
    }

    if(arr[n] != 0) {
        return arr[n];
    }

    arr[n] = fib_memoization(n - 2) + fib_memoization(n - 1);

    return arr[n];
}


/*
// Dynamic Programming - Tubulation
int fib_tubulation(int n) // Asumsikan n >= 0
{
    if(n <= 1) {
        return n;
    }

    int arr[7];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        arr[i] = arr[i - 2] + arr[i - 1];
    }

    return arr[n];
}
*/

int main()
{
    printf("%d", fib_memoization(5));
}