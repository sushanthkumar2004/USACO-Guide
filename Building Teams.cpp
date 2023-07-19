// https://cses.fi/problemset/task/1668/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    // friendships numbers 0 to V-1
    for (int i=0; i<E; i++) {
      int a, b;
      cin >> a >> b;
      adj[a-1].push_back(b-1);
      adj[b-1].push_back(a-1);
    }

    // initialize to all -1
    int visited[V];
    for (int i=0; i<V; i++) {
      visited[i] = -1;
    }

    for (int i=0; i<V; i++) {
      if (visited[i] == -1) {
        queue<int> vertex_search;
        vertex_search.push(i);

        while (!vertex_search.empty()) {
          // vertex to search
          int v = vertex_search.front();
          vertex_search.pop();

          int num0 = 0;
          int num1 = 0;
          for (int w : adj[v]) {

            if (visited[w] == 0) {
              num0 ++;
            } else if (visited[w] == 1) {
              num1 ++;
            } else {
              vertex_search.push(w);
            }
          }

          if (num0 > 0 && num1 > 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
          } else if (num0 > 0) {
            visited[v] = 1;
          } else {
            visited[v] = 0;
          }

        }
      }

    }

    for (int team : visited) {
      cout << team + 1 << " ";
    } cout << endl;
    return 0;

}
