//https://cses.fi/problemset/task/1643/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
    long long n; cin >> n;
    vector<long long> prefixSum = {0};
    vector<long long> array;
    vector<long long> minLeft = {0};
    long long maxRight[n+1];
    for (long long i=0; i<n; i++){
        long long k; cin >> k; array.push_back(k);
        prefixSum.push_back(prefixSum.back()+k);
    }
    maxRight[n] = prefixSum.back();
    for (long long i=0; i<n; i++){
        minLeft.push_back(min(minLeft.back(),prefixSum[i+1]));
    }
    for (long long i=n-1; i>-1; i--){
        maxRight[i] = max(maxRight[i+1],prefixSum[i]);
    }
    long long largest = maxRight[1] - minLeft[0];
    for (long long i=0; i<n; i++){
        largest = max(maxRight[i+1]-minLeft[i], largest);
    }
    cout << largest << endl;
}
