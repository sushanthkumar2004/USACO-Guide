// https://judge.yosupo.jp/problem/static_range_sum
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N,Q; cin >> N >> Q;
    long long array[N];
    long long prefix[N+1];
    for (long long i=0; i<N; i++){
        long long a; cin >> a; array[i] = a;
    }
    prefix[0] = 0;
    for (long long i=1; i<=N; i++){
        prefix[i] = prefix[i-1]+array[i-1];
    }
    for (int i=0; i<Q; i++){
        int l,r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << endl;
    }
}
