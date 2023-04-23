#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
const int mod = 1e9 + 7;
ii st[1 << 21];
ii unite(const ii & a, const ii & b) {
	if (a.first == b.first) return {a.first, (a.second + b.second) % mod};
	return a > b ? a : b;
}
void update(int p, ii x, int i = 1, int l = 0, int r = 1 << 20) {
	if (l == r) st[i] = unite(st[i], x);
	else {
		int m = l + r >> 1;
		if (p <= m) update(p, x, i << 1, l, m);
		else update(p, x, i << 1 | 1, m + 1, r);
		st[i] = unite(st[i << 1], st[i << 1 | 1]);
	}
}
ii query(int s, int e, int i = 1, int l = 0, int r = 1 << 20) {
	if (e < l || r < s) return {0, 0};
	if (s <= l && r <= e) return st[i];
	int m = l + r >> 1;
	return unite(query(s, e, i << 1, l, m), query(s, e, i << 1 | 1, m + 1, r));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), ord;
	for(int & i : a) {
		cin >> i;
		ord.push_back(i);
	}
	sort(ord.begin(), ord.end());
	ord.erase(unique(ord.begin(), ord.end()), ord.end());
	for(int & i : a) {
		i = lower_bound(ord.begin(), ord.end(), i) - ord.begin() + 1;
	}

	update(0, {0, 1});
	for(int i =0; i<n; ++i) {
		auto q = query(0, a[i] - 1);
		q.first++;
		update(a[i], q);
	}
	ii ans = query(0, 1 << 20);
	cout << ans.first << ' ' << ans.second;
}