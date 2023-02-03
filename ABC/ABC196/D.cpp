#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, r) repl(i, 0, r)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(x) ((int) (x).size())
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using mint = modint1000000007;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
template<class T> inline bool chmin(T &a, T b){
	if(a > b){a = b; return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a < b){a = b; return true;}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	vector used(16, vector<bool>(16));
	auto dfs = [&](auto f, int i, int j, int a, int b) -> ll {
		if(a < 0 || b < 0) return 0;
		if(j == w) j = 0, ++i;
		if(i == h) return 1;
		if(used[i][j]) return f(f, i, j+1, a, b);
		ll res = 0;
		used[i][j] = true;
		res += f(f, i, j+1, a, b-1);
		if(j+1 < w && !used[i][j+1]) {
			used[i][j+1] = true;
			res += f(f, i, j+1, a-1, b);
			used[i][j+1] = false;
		}
		if(i+1 < h && !used[i+1][j]) {
			used[i+1][j] = true;
			res += f(f, i, j+1, a-1, b);
			used[i+1][j] = false;
		}
		used[i][j] = false;
		return res;
	};
	cout << dfs(dfs, 0, 0, a, b) << endl;
	return 0;
}