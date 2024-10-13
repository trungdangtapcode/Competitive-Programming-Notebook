#include<bits/stdc++.h>

using namespace std;
#define ld long double
typedef pair<ld,int> di;
const int maxN = 5e5+5, mod = 1e9+7;
int n, cnt = 0;
string l, r;
di memo[maxN][2][2];
di f(int i, bool less, bool greater){
//	cout << i << " " << less << " " << greater << "\n";
	if (i>=n) return {0.0,1};
	if (memo[i][less][greater].second!=-1) return memo[i][less][greater];
	++cnt;
	di &res = memo[i][less][greater];
	res = {-1e18, 0};
	for (int d = 0; d < 10; d++){
		if (!less&&d>r[i]-'0') continue;
		if (!greater&&d<l[i]-'0') continue;
		auto it = f(i+1, less||(d<r[i]-'0'), greater||(d>l[i]-'0'));
		di cur = {it.first+(d==0?-1e12:logl(d)),1ll*it.second*d%mod};
		res = max(res,cur);
	}
	assert(res.first>-1e18); 
//	cout << i << " " << less << " " << greater << " = " << res.first << ", " << res.second << "\n";
	return res;
}

void solve(){
	cin >> l >> r;
//	assert(r=="0");
	n = r.length();
	reverse(l.begin(),l.end());
	while ((int)l.length()<n) l.push_back('0');
	reverse(l.begin(),l.end());
	
	assert(l<=r&&l.length()==r.length());
//	for (int i = 0; i < n; i++) if (l[i]=='0'&&r[i]=='0'){
//		cout << 0 << "\n";
//		return;
//	}
//	assert(r[0]!='0');
	for (int i = 0; i <= n; i++) for (int ll = 0; ll < 2; ll++) for (int gg = 0; gg < 2; gg++)
		memo[i][ll][gg] = {-1e18,-1};
	auto it = f(0,0,0);
//	assert(f(0,0,0).first>logl(0));
//	assert(cnt>1);
//	assert(f(0,0,0).first>-1e9);
//	assert(f(0,0,0).second!=0);
//	if (it.first<=-1e9){
//		cout << "0\n";
//		return;
//	}
	if (it.first<=-1e9){
		assert(it.second==0);
		cout << 0 << "\n";
		return;
	}
	assert(f(0,0,0).second!=0);
	cout << it.second << "\n";
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

