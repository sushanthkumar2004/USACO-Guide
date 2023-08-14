// https://codeforces.com/contest/702/problem/C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ok(long long r, vector<long long>& cities, vector<long long>& towers) {
    long long pc = 0;
    long long pt = 0;
    
    while (pt < towers.size() && pc < cities.size()) {
        
        if (abs(towers[pt] - cities[pc]) <= r) {
            pc++;
        } else {
            pt++;
        }
    }
    if (pc < cities.size()) {
        return false; // r too small
    } else {
        return true; 
    }
}


int main() {
    long long n,m;
    cin >> n >> m;
    vector<long long> cities;
    vector<long long> towers; 
    
    for (long long i=0; i<n; i++) {
        long long p; cin >> p;
        cities.push_back(p);
    }
    
    for (long long i=0; i<m; i++) {
        long long p; cin >> p;
        towers.push_back(p);
    }
    
    // for (auto const&c:cities) {
    //     cout << c<<endl;
    // }

    long long low = 0;
    long long high = 2000000001;
    

    while (low <= high) {
        
        long long mid = (low + high)/2;
        if (ok(mid, cities, towers)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl; 
}
