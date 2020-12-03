//https://cses.fi/problemset/task/1192/

#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++) 

int n,m;
char grid[1001][1001];

void floodfill(int r, int c){
    grid[r][c] = '#';
    vector<int> ii = {-1,1,0,0};
    vector<int> jj = {0,0,1,-1};
    
    for (int i=0; i<4; i++){
        if (r+ii[i] >= 0 && r+ii[i] < n && c+jj[i] >= 0 && c+jj[i] < m){
            if (grid[r+ii[i]][c+jj[i]] == '.'){
                floodfill(r+ii[i],c+jj[i]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    FOR(i,0,n){
        FOR(j,0,m){
            cin >> grid[i][j];
        }
    }
    int count = 0;
    FOR(i,0,n){
        FOR(j,0,m){
            if (grid[i][j] == '.'){
                floodfill(i,j);
                count++;
            }
        }
    }
    cout << count << endl; 
}
