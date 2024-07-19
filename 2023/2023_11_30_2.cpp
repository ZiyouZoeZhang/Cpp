#include <iostream>
#include <deque>
using namespace std;

int cal(int maxi);
int check_Cur(int cur, int m, bool front, int f, int s);

deque<int> nums;
int T;

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        nums.clear();
        int n, maxi = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int s;
            cin >> s;
            nums.push_back(s);
            maxi = max(maxi, s);
        }
        if (maxi == 0)
            cout << 0 << endl;
        else
            cout << cal(maxi) << endl;
    }
}

int cal(int m) {
    int front = 0, back = 0, count = 0;
    while (!nums.empty()) {
        int cur = 0;
        while (!nums.empty() && cur < m) {
            cur += nums.front();
            nums.pop_front();
            count++;
        }
        count--;
        if (cur == m)
            front++;
        else
            m = check_Cur(cur, m, true, front, back), front = 0, back = 0;

        if (nums.empty())
            break;

        cur = 0;
        while (!nums.empty() && cur < m) {
            cur += nums.back();
            nums.pop_back();
            count++;
        }
        count--;
        if (cur == m)
            back++;
        else
            m = check_Cur(cur, m, false, front, back), front = 0, back = 0;

        if (nums.empty())
            break;
    }
    if (!nums.empty() && front > 0 && back > 0 && nums.front() != m)
        count += 2;
    else if (!nums.empty() && nums.front() != m)
        count++;
    return count;
}

int check_Cur(int cur, int m, bool front, int f, int s) {
    if (front)
        nums.push_front(cur);
    else
        nums.push_back(cur);

    while (f-- > 0)
        nums.push_front(m);
    while (s-- > 0)
        nums.push_back(m);

    if (cur < m)
        m = m + cur;
    if (cur > m)
        m = cur;
    return m;
}
