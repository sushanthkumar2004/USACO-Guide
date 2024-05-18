// https://codeforces.com/problemset/problem/1227/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;


int main(){
    int t; cin >> t; 
	
    for (int T=0; T<t; T++) {
        vector<int> numbers; 
        int n; cin >> n;
        for (int i=0; i<n; i++) {
            int x; cin >> x; 
            numbers.push_back(x); 
        }
        bool used[n+1] = {false}; 
        int currentNumber = numbers[0];
        used[currentNumber] = true; 
        int leastUnusedNumberPtr = 1; 

        vector<int> permutation; 
        permutation.push_back(currentNumber); 
        for (int i=1; i <n; i++) {
            if (currentNumber == numbers[i]) {
                while (leastUnusedNumberPtr<=n && used[leastUnusedNumberPtr]) {
                    leastUnusedNumberPtr++; 
                }
                if (!used[leastUnusedNumberPtr] && leastUnusedNumberPtr < currentNumber) {
                    permutation.push_back(leastUnusedNumberPtr); 
                    used[leastUnusedNumberPtr] = 1;
                }
            } else {
                permutation.push_back(numbers[i]); 
                currentNumber = numbers[i]; 
                used[numbers[i]] = 1;
            }
        }
        if (permutation.size() == n) {
            for (auto const&c: permutation) {
                        cout <<c << " ";
                    } cout << endl; 
        } else {
            cout << -1 << endl; 
        }
        
    }
}
