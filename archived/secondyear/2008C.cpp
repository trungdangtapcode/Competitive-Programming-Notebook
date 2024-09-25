#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b, len;
bool check(int x){
	return x*(x+1)/2<=len;
}
void solve(){
	cin >> a >> b;
	len = b-a;
	int l = 0, h = 1e9, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			l = m+1;
			res = m;
		} else h = m-1;
	}
	cout << res+1 << '\n';
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

