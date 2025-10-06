#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e6 + 2; // Maximum possible deficit + 1
vector<long long> fenwick(MAX);

void update(int idx, long long val) {
    for (; idx < MAX; idx += idx & -idx) {
        fenwick[idx] += val;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += fenwick[idx];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ac, dr;
    cin >> ac >> dr;
    int n;
    cin >> n;
    vector<int> a(n + 1), d(n + 1);
    vector<long long> def(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        def[i] = max(0, a[i] - ac) + max(0, d[i] - dr);
        update(def[i] + 1, 1);
    }

    int m;
    cin >> m;
    while (m--) {
        int k, naj, ndj;
        cin >> k >> naj >> ndj;

        update(def[k] + 1, -1);
        def[k] = max(0, naj - ac) + max(0, ndj - dr);
        update(def[k] + 1, 1); 
        a[k] = naj;
        d[k] = ndj;
        long long p = 0;
        while (true) {
            long long count = query(p + 1);
            if (count <= p) break;
            p = count;
        }
        cout << p << '\n';
    }

    return 0;
}