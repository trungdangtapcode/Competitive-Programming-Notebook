#include<bits/stdc++.h>

using namespace std;
int n, k, a;
void solve(){
	cin >> n >> k;
	int res = 0, cnt =0;
	for (int i = 0; i < n; i++){
		cin >> a;
		cnt += (a>=k)*a;
		if (a==0&&cnt){
			++res;
			cnt -= 1;
		}
	}
	cout << res << "\n"	;
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

