// in ra các hoán vị độ dài L bằng cách sử dụng các phần tử từ mảng arr

#include <bits/stdc++.h>
using namespace std;

void convert_To_Len_th_base(int n, int arr[], int len, int L){
    for (int i = 0; i < L; i++) {
        cout << arr[n % len];
        n /= len;
    }
    cout << endl;
}
 
void print(int arr[], int len, int L){
    for (int i = 0; i < (int)pow(len, L); i++) {
        convert_To_Len_th_base(i, arr, len, L);
    }
}

int main() {
    int arr[] = { 1, 2, 3 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int L = 2;
    print(arr, len, L);
    return 0;
}
