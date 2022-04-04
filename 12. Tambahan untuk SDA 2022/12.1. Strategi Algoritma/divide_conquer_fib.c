#include<stdio.h>

int fib(int n) // Pastikan n >= 0
{
    if(n <= 1) {
        return n;
    }

    return fib(n - 2) + fib(n - 1);
}

int main()
{
    printf("%d", fib(5));
} 