// https://codeforces.com/contest/1201/problem/C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n,k;

bool ok(long long newmedian, const vector<long long>& arr) {
    long long numUpdates = 0;
    for (long long i = arr.size() / 2; i < arr.size(); i++) {
        if (newmedian > arr[i]) {
            numUpdates += newmedian - arr[i];
        } else {
            break; 
        }
    }
    return numUpdates <= k;
}


int main() {
    long long low = 1;
    
    cin >> n >> k;
    
    vector<long long> arr;
    
    for (long long i=0; i<n;i++) {
        long long a; cin >> a;
        arr.push_back(a);
    }
    
    sort(arr.begin(), arr.end());
    
    long long high = k + arr.back();
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (ok(mid, arr)) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    cout << high << endl;
    return 0;
}
