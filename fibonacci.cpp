#include <iostream>

using namespace std;

int fibonacci(int n) {
    int fib_2 = 0;
    int fib_1 = 1;
    int fib = 0;
    if(n == 0) return 0;
    if(n == 1) return 1;
    for(int i=2; i<=n; i++){
        fib = fib_1 + fib_2;
        fib_2 = fib_1;
        fib_1 = fib;
    }
    
    
    return fib;
}
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}