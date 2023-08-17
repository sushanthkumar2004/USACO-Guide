//https://codeforces.com/problemset/problem/1117/C
// Binary search on answer

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

string wind;
vector<ll> posAfterWindDays;
ll x1, y1, x2, y2;

vector<long long> calc_motion_vec(long long days) {
    long long multiply = (days) / (wind.size());
    long long x = posAfterWindDays[0] * multiply;
    long long y = posAfterWindDays[1] * multiply;
    long long additional = days - multiply * wind.size();

    for (long long i=0; i<additional; i++) {
        char c = wind[i];
        if (c == 'U') {
            y += 1;
        } else if (c == 'D') {
            y -= 1;
        } else if (c == 'R') {
            x += 1;
        } else {
            x -= 1;
        }
    }

    return {x,y};
}

bool doable_in_k_days(long long days) {
    vector<long long> windVec = calc_motion_vec(days);
    long long x = x1 + windVec[0];
    long long y = y1 + windVec[1];

    return days >= abs(x - x2) + abs(y-y2);
}

int main() {
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    long long n;
    cin >> n;
    cin >> wind;

    posAfterWindDays = {0,0};
    for (auto const& c : wind) {
        if (c == 'U') {
            posAfterWindDays[1] += 1;
        } else if (c == 'D') {
            posAfterWindDays[1] -= 1;
        } else if (c == 'R') {
            posAfterWindDays[0] += 1;
        } else {
            posAfterWindDays[0] -= 1;
        }
    }

    ll low = 0;
    ll high = 10000000000000000;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (doable_in_k_days(mid)) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    if (low <= 10000000000000000)
        cout << low << endl;
    else
        cout << -1 << endl;
    return 0;

}
