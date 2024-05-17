// https://cses.fi/problemset/task/1636/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main(){
	long long n, x; cin >> n >> x; 
    vector<long long> coins; 
    for (long long i=0; i<n;i++) {
        long long coin; cin >> coin; coins.push_back(coin); 
    }
    // subproblem f(k, x) is # ways to make x using first k coins 
    // dp[i][x] is # ways to make x with i+1 coins
    vector<int> previous_dp_values(x+1); 
    vector<int> next_dp_values(x+1); 
    vector<int> zeroes(x+1, 0); 
    
    for (long long i=0; i<x+1; i++) {
        if (i%coins[0] == 0) {
            previous_dp_values[i] = 1; 
        }
    }

    for (long long num_coins = 1; num_coins < n; num_coins++) {
        // number of coins we acc use is num_coins+1
        long long coin_of_interest = coins[num_coins]; 
        for (long long value=0; value<x+1; value++) {
            if (value - coin_of_interest >= 0) {
                next_dp_values[value] = (next_dp_values[value - coin_of_interest] + previous_dp_values[value]) % (1000000007); 
            } else {
                next_dp_values[value] = (previous_dp_values[value]); 
            }
        }
        previous_dp_values = next_dp_values; 
    }
    
    cout << previous_dp_values[x]; 
}
