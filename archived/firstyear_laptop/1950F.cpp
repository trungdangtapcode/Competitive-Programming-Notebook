#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b, c;
void solve(){
	cin >> a >> b >>c;
	if (a!=c-1){
		cout << -1 << "\n";
		return;
	}
	if (a+b==0){
		cout << (c==1?0:-1) << "\n";
		return;
	}
	int base = 1;
	int res = 0;
	while (base<a){
		res++;
		base = base*2+1;
	}
	int tmp = base-a;
	int x = (1<<res)-tmp;
	b -= tmp;
	while (b>0){
		b -= 2*x+tmp;
		res++;
	}
	cout << res+1 << "\n";
	return;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
	solve();
}

