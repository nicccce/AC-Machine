//  https://codeforces.com/contest/2156/problem/D
#include <bits/stdc++.h>

using i64 = long long;

int ask(int i, int x) {
	std::cout << "? " << i << " " << x << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void solve() {
	int n;
	std::cin >> n;
	int m = 0;
	for (int i = 20; i >= 0; -- i) {
		if (n >> i & 1) {
			m = i;
			break;
		}
	}

	int f[20][2]{};
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= m; ++ j) {
			f[j][i >> j & 1] += 1;
		}
	}

	std::vector<int> a;
	for (int i = 1; i < n; ++ i) {
		a.push_back(i);
	}

	auto b = a;
	b.push_back(n);

	int tot = 0;
	std::vector<int> st(n + 1);
	for (int i = 0; i <= m && b.size() > 1; ++ i) {
		std::vector<int> na[2];
		for (auto & x : a) {
			na[ask(x, 1 << i)].push_back(x);
		}

		if (na[0].size() < f[i][0]) {
			a = na[0];
			std::vector<int> nb;
			for (auto & x : b) {
				if (x >> i & 1) {
					st[x] = 1;
					for (int j = i + 1; j <= m; ++ j) {
						-- f[j][x >> j & 1];
					}
				} else {
					nb.push_back(x);
				}
			}

			b = nb;
		} else {
			a = na[1];
			std::vector<int> nb;
			for (auto & x : b) {
				if (x >> i & 1) {
					nb.push_back(x);
				} else {
					st[x] = 1;
					for (int j = i + 1; j <= m; ++ j) {
						-- f[j][x >> j & 1];
					}
				}
			}

			b = nb;
		}
	}

	for (int i = 1; i <= n; ++ i) {
		if (!st[i]) {
			std::cout << "! " << i << std::endl;
			return;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	while (t -- ) {
		solve();
	}
	return 0;
}
