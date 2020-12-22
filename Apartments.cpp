//https://cses.fi/problemset/task/1084/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define FOR(i,a,b) for (ll i = a; i < b; i++)
typedef long long ll;
typedef double dd;

ll lowerBound(vector<ll> X, ll low, ll hi, ll target){
    ll ans = hi+1;
    while (low <= hi){
        ll mid = (low+hi)/2;
        if (X[mid] <= target){
            hi = mid-1;
            ans = mid;
        } else {
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    // Im so certain the median just works.
    ll n,m,k; cin >> n >> m >> k;
    vector<ll> A;
    FOR(i,0,n){
        ll a; cin >> a; A.push_back(a);
    }

    vector<ll> B;
    FOR(i,0,m){
        ll b; cin >> b; B.push_back(b);
    }
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    ll happy  = 0;
    ll curIndex = 0;
    for (auto const&b:B){
        while (curIndex < A.size()){
            if (A[curIndex] - k > b){
                curIndex++;
            } else {
                break;
            }
        }
        if (curIndex < A.size()){
            if (A[curIndex] + k >= b){
                //implies that A.front() -k <= b
                happy ++;
                curIndex++;
            }
        }
    }
    cout << happy;
}
