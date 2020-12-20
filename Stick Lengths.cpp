//https://cses.fi/problemset/task/1074/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include<tuple>
#include <map>
using namespace std;
 
#define FOR(i,a,b) for (ll i = a; i < b; i++)
typedef long long ll;
typedef double dd;


int main(){
    // Im so certain the median just works. 
    int N; cin >> N;
    vector<int> P;
    FOR(i,0,N){
        int p; cin >> p; P.push_back(p);
    }
    sort(P.begin(), P.end());
    if (P.size()%2 == 1){
        int mid = (P.size()-1)/2;
        int midVal = P[mid];
        int sum = 0;
        for (auto const&c:P){
            sum += abs(midVal - c);
        }
        cout << sum;
    } else {
        int mid = (P.size())/2;
        int midVal = P[mid];
        int sum = 0;
        for (auto const&c:P){
            sum += abs(midVal - c);
        }
        
        int mid2 = (P.size())/2-1;
        int midVal2 = P[mid2];
        int sum2 = 0;
        for (auto const&c:P){
            sum2 += abs(midVal2 - c);
        }
        
        int midVal3 = (midVal + midVal2)/2;
        sum3 = 0;
        for (auto const&c:P){
            sum3 += abs(midVal3 - c);
        }
        cout << min(sum,min(sum2,sum3));
    }
}
