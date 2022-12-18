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
	vector<vector<int>> c(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> c[i][j];
	auto min_iter = min_element(all(c[0]));
	int dist = min_iter - c[0].begin();
	vector<int> a(n);
	rep(i, n) a[i] = c[i][dist];
	set<vector<int>> st;
	rep(i, n) {
		rep(j, n) {
			c[i][j] -= a[i];
			if(c[i][j] < 0) {
				cout << "No" << endl;
				return 0;
			}
		}
		st.insert(c[i]);
	}
	if(st.size() != 1) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	auto itr =  st.begin();
	vector<int> b(n);
	b = *itr;
	rep(i, n-1) cout << a[i] << " ";
	cout << a[n-1] << endl;
	rep(i, n-1) cout << b[i] << " ";
	cout << b[n-1] << endl;
	return 0;
}