//https://cses.fi/problemset/task/1650/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main(){
    int n, q; cin >> n >> q;
    int prefix[n+1];
    prefix[0] = 0;
    for (int i=0; i<n; i++){
        int c; cin >> c;
        prefix[i+1] = prefix[i]^c;
    }
    for (int i=0; i<q; i++){
        int a,b; cin >> a >> b;
        int x = prefix[a-1];
        int y = prefix[b];
        cout << (x^y) << endl;
    }
}
