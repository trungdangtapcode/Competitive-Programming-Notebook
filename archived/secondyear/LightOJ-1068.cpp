#include<bits/stdc++.h>

using namespace std;
int n, a, b, k;
int memo[10][82][82][2];
string sa, sb;
void fixlength(string &s, int l){
	int x = l-s.length();
	string res;
	for (int i = 0; i < x; i++) res.push_back('0');
	s = res+s;
}
int calc(string &s, int pos, int sum, int rem, int smaller){
	if (pos>=n) return sum%k==0&&rem%k==0;
	if (memo[pos][sum][rem][smaller]!=-1) 
		return memo[pos][sum][rem][smaller];
	int &res = memo[pos][sum][rem][smaller];
	res = 0;
	int cur = s[pos]-'0';
//	cout << pos  << " " << sum << " " << rem << " " << smaller << " d = " << s << '\n';
	for (int d = 0; d < 10; d++){
		if (!smaller&&d>cur) continue;
		int nsum = sum+d;
		int nsmaller = smaller||d<cur;
		int nrem = (rem*10+d)%k;
		res += calc(s,pos+1,nsum,nrem,nsmaller);
	}
	return res;
}

void solve(){
	cin >> a >> b >> k;
	if (k>81){
		cout << 0 << '\n';
		return;
	}
	a--;
	sa = to_string(a);
	sb = to_string(b);
	n = max(sa.length(),sb.length());
	fixlength(sa,n);
	fixlength(sb,n);
	memset(memo,-1,sizeof(memo));
	int res1 = calc(sa,0,0,0,0); 
	memset(memo,-1,sizeof(memo));
	int res2 = calc(sb,0,0,0,0);
	cout << res2-res1 << "\n"; 
//	exit(0);
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	for (int i = 1;  i <= t; i++){
		cout << "Case " << i << ": ";
		solve();
	}
}

