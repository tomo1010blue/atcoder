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
	int n, m;
	cin >> n >> m;
	vector g(n, vector<P>());
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].pb(P(c, b));
	}
	rep(i, n) {
		priority_queue<P, vector<P>, greater<P>> q;
		vector<int> dst(n, INF);
		dst[i] = 0;
		q.push(P(0, i));
		int ans = INF;
		while(!q.empty()) {
			int d = q.top().fi;
			int u = q.top().se;
			q.pop();
			if(dst[u] < d) continue;
			for(auto v : g[u]) {
				if(chmin(dst[v.se], dst[u]+v.fi)) q.push(P(dst[v.se], v.se));
				if(v.se == i) chmin(ans, dst[u]+v.fi);
			}
		}
		if(ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}