//Another  submission https://codeforces.com/contest/1354/submission/80577471 
// https://codeforces.com/contest/1354/problem/D


#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define all(cont) cont.begin(), cont.end()
#define unique(a)  sort(all(a)) , (a).erase(unique((a).begin(), (a).end()),(a).end())
#define rall(cont) cont.rbegin(), cont.rend()
#define sz(x) (int)(x).size()
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PB push_back
#define endl "\n"
#define f first
#define s second
#define mset(m,v) memset(m,v,sizeof(m))
#define mod 1000000007
const int N = 1e6 + 5;
#define PI acos(-1.0)
long double EPS = 1e-9;
typedef long long ll;
#define int long long
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
#define pqll_max priority_queue<ll> // max heap. push(),pop(),top(),size(),empty()
#define pqll_min priority_queue<ll,vector<ll>,greater<ll> >
#define lb(v,val)   lower_bound(v.begin(),v.end(),val) //first equal to or lower than [------------
#define ub(v,val)   upper_bound(v.begin(),v.end(),val) //first greater than ------------)
#define bs(v,x) binary_search(v.begin(),v.end(),x)
inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x; }
inline ll sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
inline ll mul(ll x, ll y) { return (x%mod * 1ll * y%mod) % mod; }
inline ll pwr(ll a, ll b) { ll x = 1 % mod; while (b) { if (b & 1) x = mul(x, a); a = mul(a, a); b >>= 1; }return x % mod; }
inline ll inv(ll a) { return pwr(a, mod - 2) % mod; }
ll gcd(ll a, ll b) { if (!a)return b % mod; return gcd(b%a, a) % mod; }
#define debug(x) cout << #x << " = " << x << endl;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#define in(container) for (auto &it : container) cin>>it;
#define out(container) for (auto it : container) cout << it << " "; cout << endl;
int fen[N];
void update(int i, int add) {
	while (i > 0 && i < N) {
		fen[i] += add;
		i += (i&(-i));
	}
}
int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += fen[i];
		i = i - (i&(-i));
	}
	return s;
}
void solve() {
	int n, q;
	cin >> n >> q;
	rep(i, n) {
		int num;
		cin >> num;
		update(num, 1);
	}
	while (q--) {
		int x;
		cin >> x;
		if (x > 0) {
			update(x, 1);
		}
		else {
			x *= -1;
			int low = 0;
			int high = N;
			while (low < high) {
				int mid = (low + high) / 2;
				int val = sum(mid);
				if (x <= val) {
					high = mid;
				}
				else low = mid + 1;
			}
			update(low, -1);
		}

	}

	if (sum(N)<=0) {
		cout << 0 << endl;
	}
	else {
		int x = 1;
		int low = 0;
		int high = N;
		while (low < high) {
			int mid = (low + high) / 2;
			int val = sum(mid);
			if (x <= val) {
				high = mid;
			}
			else low = mid + 1;
		}
		cout << low << endl;
		
	}
}
signed main()
{
	fastio;
	//cout<<fixed<<setprecision(15);
	//clock_t begin = clock();
	int tc;
	tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
	//clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
}


//Error?
// clear lists for every test case
// print new line for each tc
// check for int or ll
// check if problem can be solved without any heavy DS like priority_queue or map


