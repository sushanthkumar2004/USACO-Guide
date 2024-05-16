//https://codeforces.com/contest/862/problem/B
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
	unordered_map<long long, vector<long long>> graph; 
    long long n; cin >> n;

    for (long long i=0; i<n-1; i++) {
        long long a, b; cin >> a >> b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<long long> BFSQueue; 
    unordered_set<long long> visited; 
    visited.insert(1); 
    BFSQueue.push(1); 
    long long depths[n+1];
    depths[0] = -1; 
    depths[1] = 0; 
    while (!BFSQueue.empty()) {
        long long curNode = BFSQueue.front();
        BFSQueue.pop();

        for (auto const&node: graph[curNode]) {
            if (visited.find(node) == visited.end()) {
                BFSQueue.push(node); 
                visited.insert(node); 
                depths[node] = depths[curNode] + 1; 
            }
        }
    }
    long long nodes_U = 0; 
    for (auto const&c : depths) {
        if (c % 2 == 0) {
            nodes_U ++; 
        }
    } 
    cout << nodes_U * (n - nodes_U) - (n-1); 
}
