//https://cses.fi/problemset/task/1661/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int main(){
    long long n, x; cin >> n >> x;
    long long prefix[n+1];
    prefix[0] = 0;
    for (long long i=0; i<n; i++){
        long long c; cin >> c;
        prefix[i+1] = prefix[i] + c;
    }
    long long count = 0;
    map<long long, long long> tally2;
    for (int i=0; i<=n; i++){
        count += tally2[prefix[i]-x];
        tally2[prefix[i]] += 1;
    }
    cout << count << endl;
}
