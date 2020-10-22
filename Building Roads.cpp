#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>

using namespace std;

set<int> visited;
map<int,vector<int>> graph;

void DFS(int node){
    visited.insert(node);
    for (auto const&neighbor : graph[node]){
        if (visited.find(neighbor) == visited.end()){
            DFS(neighbor);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    // map<int,vector<int>> graph;
    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //for (auto const&c:graph){
    //    cout << c.first << ": ";
    //    for (auto const&k:c.second){
    //        cout << k << ", ";
    //    }
    //}
    int connectedComponents = 0;
    vector<int> reps;
    for (int i=1; i<=n; i++){
        if (visited.find(i) == visited.end()){
            DFS(i);
            reps.push_back(i);
            connectedComponents++;
        }
    }
    cout << connectedComponents-1 << endl;
    for (int i=0; i+1<(int)reps.size(); i++){
        cout << reps[i] << " " << reps[i+1] << endl;
    }
}

