// https://dmoj.ca/problem/acsl1p4
// Point is that you use a reversed graph again to run DFS. If A loses to a bunch of people that eventually lose to B,
// check the reversed graph to see if there are a bunch of people that B lost to that eventually lost to A
// This shows that there is a cycle between A and B.
// To be exact, run dfs on every node on the normal and reversed graph and compare marked vertices 

#include <iostream>
#include <vector>
#include <algorithm> 
#include <stack>

using namespace std;

void dfs(int root, vector<int> graph[], bool marked[]) {
    marked[root] = true;
    stack<int> fringe;
    fringe.push(root);
    
    while (!fringe.empty()) {
        int node = fringe.top();
        fringe.pop();
        marked[node] = true;
        
        for (int neighbor : graph[node]) {
            if (!marked[neighbor]) {
                fringe.push(neighbor);
            }
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> graph[N];
    vector<int> graph_rev[N]; 
    
    for (int i=0;i<K;i++) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        if (sa > sb) {
            graph[b-1].push_back(a-1);
            graph_rev[a-1].push_back(b-1);
        } else {
            graph[a-1].push_back(b-1);
            graph_rev[b-1].push_back(a-1);
        }
    }
    
    int cnt_undecidable = 0;
    
    for (int root=0; root < N; root++) {
        bool marked[N] = {false};
        bool marked_rev[N] = {false};
        
        
        dfs(root, graph, marked);
        dfs(root, graph_rev, marked_rev);
        marked[root] = false;
        marked_rev[root] = false; 
        
        for (int j=0;j<N;j++){
            if (marked[j] == marked_rev[j] && marked[j] == true) {
                cnt_undecidable ++;
                break; 
            }
        } 
    }
    
    cout << cnt_undecidable << endl; 
    
}
