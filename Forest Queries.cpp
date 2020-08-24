//https://cses.fi/problemset/task/1652/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main(){
    int n, q; cin >> n >> q;
    int prefix[n+1][n+1];
    for (int i=0; i<=n; i++){
        prefix[0][i] = 0;
    }
    for (int i=0; i<=n; i++){
        prefix[i][0] = 0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c; cin >> c;
            if (c == '.'){
                prefix[i][j] = prefix[i][j-1];
            } else {
                prefix[i][j] = prefix[i][j-1]+1;
            }
        }
    }
    for (int i=1; i<= n; i++){
        for (int j=1; j<= n; j++){
            prefix[i][j] += prefix[i-1][j];
        }
    }
    //for (int i=0; i<n+1; i++){
    //    for (int j=0; j<n+1; j++){
    //       cout << prefix[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    for (int i=0; i<q; i++){
        int y1,x1,y2,x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << -prefix[y2][x1-1]-prefix[y1-1][x2]+prefix[y2][x2] + prefix[y1-1][x1-1] << endl;
    }
}
