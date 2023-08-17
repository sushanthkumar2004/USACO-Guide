// https://codeforces.com/contest/782/problem/B
// point is the time for the people on the left and the right should be equal
// do a binary search on the meeting point

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;

int n;
vector<double> pos;
vector<double> veloc;

pair<double, double> timeLeftRight(double meetup) {
    double timeL = 0;
    double timeR = 0;
    for (int i=0; i<n; i++) {
        if (pos[i] <= meetup) {
            timeL = max(timeL, (meetup - pos[i]) / veloc[i]);
        } else {
            timeR = max(timeR, (pos[i] - meetup) / veloc[i]);
        }
    }

    return make_pair(timeL, timeR);
}

int main() {
    cin >> n;

    double minLeft = 1000000001;
    double maxLeft = 1;

    for (int i=0; i<n; i++) {
        int p; cin >> p; pos.push_back(p); minLeft = min(minLeft, (double) p);
    }
    for (int i=0; i<n; i++) {
        int p; cin >> p; veloc.push_back(p); maxLeft = max(maxLeft, (double) p);
    }

    double low = 1;
    double high = 1000000001;

    int maxLoops = 0;

    while (low <= high && maxLoops <= 10000) {
        double mid = (high + low) / 2;
        auto [x, y] = timeLeftRight(mid);

        if (x < y) {
            low = mid;
        } else if (y < x) {
            high = mid;
        } else {
            cout << fixed << setprecision(20) << x << endl;
            return 0;
        }
        maxLoops++;
    }

    auto [x, y] = timeLeftRight((low + high) / 2);

    cout << fixed << setprecision(20) << x << endl;
    return 0;

}
