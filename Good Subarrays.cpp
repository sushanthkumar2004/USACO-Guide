// https://codeforces.com/contest/1398/problem/C
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector> 
#include <unordered_map> 

using namespace std; 

int main() {
    // Write C++ code here
    long long t;
    cin >> t;
    for (long long j=0; j<t; j++) {
        long long n; cin >> n;
        string digits; cin >> digits; 
        vector<long long> arr; 
        for (long long i=0; i < digits.size(); i++) {
            arr.push_back(digits[i] - '0');
        }
        vector<long long> dp_arr;
        dp_arr.push_back(0); 
        for (long long i=0; i<digits.size(); i++) {
            dp_arr.push_back(dp_arr.back() + arr[i]);
        }

        for (long long i=0; i<dp_arr.size(); i++) {
            dp_arr[i] -= i; 
        }

        unordered_map<long long, long long> counts; 
        for (auto const&c : dp_arr) {
            counts[c] ++ ; 
        } 
        long long sum = 0; 
        for (auto const& pair_of : counts) {
            sum += ((pair_of.second) * (pair_of.second - 1)) / 2; 
        }
        cout << sum << endl; 
    }
}
