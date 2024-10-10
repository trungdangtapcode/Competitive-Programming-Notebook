#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	set<int> sa, sb;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		if (y==0){
			sa.insert(x);
		} else sb.insert(x);
	}
	long long res = 0;
	for (int x: sa){
		if (!sb.count(x)) continue;
		res += sa.size()+sb.size()-2;
	}
	for (int x: sa){
		if (sb.count(x+1)&&sb.count(x-1)) res++;
	}
	for (int x: sb){
		if (sa.count(x+1)&&sa.count(x-1)) res++;
	}
	cout << res << "\n";
//	exit(0);
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

