// https://atcoder.jp/contests/abc125/tasks/abc125_c

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <numeric>
using namespace std;


int main(){
    int N; cin >> N;
    int leftToRight[N]; 
    int RightToLeft[N]; 
    vector<int> nums; 
    for (int i=0; i<N; i++) {
        int x; cin >> x; 
        nums.push_back(x); 
    }
    leftToRight[0] = nums[0]; 
    RightToLeft[N-1] = nums[N-1]; 
    for (int j=1; j<N;j++) {
        leftToRight[j] = gcd(nums[j], leftToRight[j-1]); 
    }
    for (int j = N-2; j>=0 ; j--) {
        RightToLeft[j] = gcd(nums[j], RightToLeft[j+1]);
    }

    // for (auto i : RightToLeft) std::cout << i << ' ';
    // for (auto i : leftToRight) std::cout << i << ' ';
    // cout << endl; 
    int bestGCD = max(leftToRight[N-2], RightToLeft[1]); 
    for (int j=0; j<N-2; j++) {
        bestGCD = max(bestGCD, gcd(leftToRight[j], RightToLeft[j+2])); 
    }
    cout << bestGCD << endl; 
}
