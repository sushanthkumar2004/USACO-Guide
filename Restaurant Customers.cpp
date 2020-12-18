//https://cses.fi/problemset/task/1619/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
 
#define FOR(i,a,b) for (int i = a; i < b; i++)
 
vector<pair<int,int>> times;
 
int main(){
    int n; cin >> n;
    FOR(i,0,n){
            int a,b; cin >> a >> b;
            times.push_back(make_pair(a,1));
            times.push_back(make_pair(b,-1));
        }
    sort(times.begin(), times.end());
    int maxCustomers = 0;
    int currentCustomers = 0;
    for (auto const&c:times){
            currentCustomers += c.second;
            maxCustomers = max(maxCustomers, currentCustomers);
        }
    cout << maxCustomers;
}
