#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<int> res;
void calc(int l, int r, int cnt){
	if (cnt==0) return;
	if (cnt==1){
		res.push_back(l);
		return;
	}
	assert(cnt<=r-l+1);
	int cl = cnt/2, m = (l+r)/2;
	calc(l,m,cl);
	calc(m+1,r,cnt-cl);
}
void solve(){
	res.clear();
	cin >> n >> k;
	int a = 1<<(k-1), b = (1<<k)-1;
	for (; n>b-a+1; n--) res.push_back(1);
	calc(a,b,n);
	for (int x: res) cout << x << " "; cout << "\n";
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

