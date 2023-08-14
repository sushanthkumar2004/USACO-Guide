//https://cses.fi/problemset/task/1620/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

long long n,t;

bool canMake(ll maxTime, vector<ll>& times) {
    ll maxProducts = 0;
    
    for (auto const& machine: times) {
        maxProducts += maxTime / machine; 
        if (maxProducts >= t) {
            return true; 
        }
    }
    
    return maxProducts >= t; // false means too small
}


int main() {
    
    cin >> n >> t;
    
    vector<ll> times; 
    for (long long i=0; i<n; i++) {
        long long time;
        cin >> time;
        times.push_back(time);
    }
    
    ll low = 1;
    ll high = pow(10, 18)+1;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canMake(mid, times)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << low << endl; 
    
    
    
}
