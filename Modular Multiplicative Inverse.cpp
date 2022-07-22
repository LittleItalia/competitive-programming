#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int extended_gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return  gcd;
}

void inv(int a, int b) {
    int x, y;
    int gcd = extended_gcd(a, b, x, y);
    if(gcd != 1) 
        cout << "Khong ton tai nghich dao modulo";
    else 
        cout << (x % b + b) % b << '\n';
}

int main() {
  
  
}
