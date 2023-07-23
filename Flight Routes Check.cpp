// https://cses.fi/problemset/task/1682
// Idea is to reverse edges of the graph and see which nodes
// are reachable from node 1. Used a marked array of length 100000 to do this
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool marked_g[100000];
bool marked_g_rev[100000];

void dfs(int root, vector<int> adj_list[], bool marked[]) {
    marked[root] = true; 
    stack<int> fringe;
    fringe.push(root);
    
    while (!fringe.empty()) {
        int node = fringe.top();
        fringe.pop();
        marked[node] = true; 
        for (int neighbor : adj_list[node]) {
            if (!marked[neighbor]) {
                fringe.push(neighbor); 
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> G_adj[n];
    vector<int> G_rev_adj[n];
    
    for (int i = 0; i < n; i++) {
        marked_g_rev[i] = false; 
        marked_g[i] = false; 
    }
    
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b; 
        G_adj[a-1].push_back(b-1);
        G_rev_adj[b-1].push_back(a-1);
    }
    
    dfs(0, G_adj, marked_g);
    dfs(0, G_rev_adj, marked_g_rev);
    
    int unreachable_rev = 0;

    for (int i = 0; i < n; i++ ){
        if (marked_g[i] == false) {
            cout << "NO" << endl;
            cout << 1 << " " << i+1;
            return 0;
        }
        
        if (marked_g_rev[i] != marked_g[i]) {
            cout << "NO" << endl;
            if (marked_g[i]) {
                cout << i+1 << " " << 1;
            } else {
                cout << 1 << " " << i+1;
            }
            return 0; 
        }
        
    }
    
    
    cout << "YES";
}
