//https://cses.fi/problemset/task/1662/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
    long long n; cin >> n;
    vector<long long> prefix = {0};
    for (long long i=0; i<n; i++){
        long long x; cin >> x;
        x = x%n;
        prefix.push_back(((prefix.back()+x)%n+n)%n);
    }
    long long residueCount[n] = {};
    for (long long i=0; i<n+1; i++){
        residueCount[prefix[i]]++;
    }
    long long sum = 0;
    for (long long i=0; i<n; i++){
        sum += (residueCount[i])*(residueCount[i]-1)/2;
    }
    cout << sum << endl;
}
