//https://codeforces.com/problemset/problem/1359/C

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int c, h, temp; 
        cin >> h >> c >> temp; 
        if (2*temp <= h+c) {
            cout << 2 << endl; 
        } else {
            // n+1 h and n c
            // (n+1)(h-t)-n(t-c) over 2n+1
            int n = (h - temp) / (2 * temp - c - h); 
            if ((2*n + 3) * abs((n+1)*(h-temp) + n * (c-temp)) <= (2*n+1) * abs((n+2)*(h-temp)+(n+1)*(c-temp))) {
                cout << 2*n+1 << endl;
            } else {
                cout << 2*n+3 << endl; 
            }
        }
    }
}
