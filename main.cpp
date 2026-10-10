#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, long long balls, vector<int> &out) {
    if (depth == 0) {
        out.push_back(balls % 2);
        return;
    }
    long long left = (balls + 1) / 2;
    long long right = balls / 2;
    dfs(depth - 1, left, out);
    dfs(depth - 1, right, out);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int D; long long n;
    if (!(cin >> D >> n)) return 0;
    // compute leaf states
    vector<int> leaf_states;
    dfs(D - 1, n, leaf_states);
    // compute last ball position (node index)
    long long pos = 1;
    long long cur = n;
    for (int i = 0; i < D - 1; ++i) {
        if (cur % 2 == 1) {
            pos = pos * 2;
            cur = (cur + 1) / 2;
        } else {
            pos = pos * 2 + 1;
            cur = cur / 2;
        }
    }
    cout << pos << "\n";
    for (size_t i = 0; i < leaf_states.size(); ++i) {
        if (i) cout << ' ';
        cout << leaf_states[i];
    }
    cout << "\n";
    return 0;
}
