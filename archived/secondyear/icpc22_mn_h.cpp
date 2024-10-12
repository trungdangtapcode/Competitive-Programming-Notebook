#include<bits/stdc++.h>

using namespace std;
#define ld long double
typedef pair<ld,int> di;
const int maxN = 2e5+5, mod = 1e9+7;
int n, cnt = 0;
string l, r;
di memo[maxN][2][2];
di f(int i, bool less, bool greater){
//	cout << i << " " << less << " " << greater << "\n";
	if (i>=n) return {0.0,1};
	if (memo[i][less][greater].second!=-1) return memo[i][less][greater];
	++cnt;
	di &res = memo[i][less][greater];
	res = {-1e9, 1};
	for (int d = 0; d < 10; d++){
		if (!less&&d>r[i]-'0') continue;
		if (!greater&&d<l[i]-'0') continue;
		auto it = f(i+1, less||(d<r[i]-'0'), greater||(d>l[i]-'0'));	
		di cur = {it.first+(d==0?-1e7:logl(d)),1ll*it.second*d%mod};
		res = max(res,cur);
	}
//	assert(res.first>-1e9); //=> RE
//	cout << i << " " << less << " " << greater << " = " << res.first << ", " << res.second << "\n";
	return res;
}

void solve(){
	cin >> l >> r;
	n = r.length();
	reverse(l.begin(),l.end());
	while ((int)l.length()<n) l.push_back('0');
	reverse(l.begin(),l.end());
	
	assert(l<=r&&l.length()==r.length());
	for (int i = 0; i <= n; i++) for (int ll = 0; ll < 2; ll++) for (int g = 0; g < 2; g++)
		memo[i][ll][g] = {-1e9,-1};
	f(0,0,0);
//	assert(f(0,0,0).first>-1e9);
//	assert(cnt>1);
	cout << f(0,0,0).second << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

