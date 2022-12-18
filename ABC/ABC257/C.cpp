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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	vector<pair<int, char>> a;
	rep(i, n) {
		int g;
		cin >> g;
		a.pb({g, s[i]});
		if(s[i] == '1') ++ans;
	}
	sort(all(a));
	int x = ans;
	rep(i, n) {
		if(a[i].se == '1') --x;
		else ++x;
		if(i < n - 1) {
			if(a[i].fi != a[i+1].fi) chmax(ans, x);
		} else {
			chmax(ans, x);
		}
	}
	cout << ans << endl;
	return 0;
}