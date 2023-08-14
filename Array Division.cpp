// https://cses.fi/problemset/task/1085/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

ll n, k;
vector<ll> arr; 

bool checkSum(ll maxSum) {
    if (*max_element(arr.begin(), arr.end()) > maxSum) {
        return false;
    }
    
    ll curSum = 0;
    ll numSegments = 0;
    ll index = 0;
    
    while (index < arr.size()) {
        curSum += arr[index];
        if (curSum > maxSum) {
            curSum = 0;
            index--;
            numSegments++;
        }
        index++;
    }
    

    return numSegments + 1 <= k; 
}

int main() {
    cin >> n >> k;
    
    
    
    for (ll i=0; i<n; i++) {
        ll x; cin >> x; arr.push_back(x);
    }
    
    ll low = 1;
    ll high = 2 * pow(10, 14);
    
    while (low <= high) {
        
        ll mid = (low + high) /2;
        if (checkSum(mid)) {
            high = mid-1;
        } else {
            low = mid+1; 
        }
    }
    
    cout << low << endl; 
    
}
