// https://cses.fi/problemset/result/9287860/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <numeric>
using namespace std;

struct Task {
    long long a, d; 
}; 

struct cmp {
	bool operator()(const Task &x, const Task &y) const { return x.a < y.a; }
};


int main(){
    // write out the equation
    // we essentially want to sort so that we do the lightest task first.
    // essentially the last deadline has to endure all of the other tasks being done. 
    // and to do this we essentially get like
    // d1 + ... +dn - n*a(first task) + ... 1 * a(last task)
    // so obviously make first taks tiny and last task huge. 
    long long N; cin >> N;
    vector<Task> tasks; 
    for (long long i=0; i<N; i++){
        long long a,d; 
        cin >> a >> d; 
        tasks.push_back({a,d}); 
    } 
    sort(tasks.begin(), tasks.end(), cmp()); 

    long long time = 0; 
    long long reward = 0; 
    for (auto task: tasks) {
        time += task.a;
        // cout << time << "," << task.d << endl; 
        reward += (task.d - time); 
    }
    cout << reward; 
}
