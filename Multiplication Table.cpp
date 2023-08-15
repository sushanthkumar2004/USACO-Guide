//https://cses.fi/problemset/task/2422/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

ll n;

bool checkPastMean(ll mid) {
    ll elementsLeft = 0;
    for (ll i=1; i<=n; i++) {
        elementsLeft += min(n, mid / i);
        if (elementsLeft >= (n*n+1) / 2) {
            return true;
        }
    }
    if (elementsLeft >= (n*n+1) / 2) {
        return true;
    }
    return false;
}



int main() {
    cin >> n;
    
    ll low, high;
    low = 1;
    high = n*n;
    
    
    while (low <= high) {
        ll mid = (low+high) /2;
        if (checkPastMean(mid)) {
            high = mid-1; 
        } else {
            low = mid+1;
        }
    }
    cout << low << endl; // 6172827160
}
