//https://cses.fi/problemset/task/1090/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include<tuple>
#include <map>
#include <math.h>
#include <unordered_set>
using namespace std;

#define FOR(i,a,b) for (ll i = a; i < b; i++)
typedef long long ll;
typedef double dd;

int main(){
    ll n,x; cin >> n >> x;
    vector<ll> weights;
    FOR(i,0,n){
        ll p; cin >> p; weights.push_back(p);
    }
    ll curLow = 0;
    ll curHigh = n-1;
    ll numBoats = 0;
    sort(weights.begin(),weights.end());
    while (curLow < curHigh){
        if (weights[curLow] + weights[curHigh] <= x){
            numBoats++;
            curLow++;
            curHigh--;
        } else {
            curHigh--;
            numBoats++;
        }
    }
    if (curLow == curHigh){
        numBoats ++;
    }
    cout << numBoats;
}
