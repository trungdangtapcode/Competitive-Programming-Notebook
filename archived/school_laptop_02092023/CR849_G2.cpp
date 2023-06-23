#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, c, a[200005];
typedef pair<int,int> ii;
ii b[200005];

int res_check = 0;
bool check(){
	int cc = c;
	for (int i = 1; i <= n; i++){
		if (a[i]+i<=a[i]+n+1-i) b[i].second = -1; else b[i].second = 1;
		b[i].first = min(a[i]+i,a[i]+n+1-i);
	}
	sort(b+1,b+n+1);
	int first_ap = 0;
	for (int i = 1; i <= n; i++) if (b[i].second==-1){
		first_ap = i;
		break;
	}
	res_check = 0;
	bool ok = false;
	for (int i = 1; i <= n; i++){
		if (cc<b[i].first) break;
		res_check++;
		cc -= b[i].first;
		if (b[i].second==-1) ok = true;
	}
	if (ok==false){
		int res = 1;
		bool ok2 = false;
		cc = c;
		if (cc<b[first_ap].first) return 0;
		cc -= b[first_ap].first;
		for (int i = 1; i<= n; i++){
			if (i==first_ap) continue;
			if (cc<b[i].first) break;
			cc -= b[i].first;
			res++;
		}
		if (res==res_check) return 1;
	}
	return ok;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> c;
		cin >> a[1];
		int best = 1;
		for (int i = 2; i <= n; i++){
			cin >> a[i];
			if (a[best]+best>a[i]+i) best = i;
		}
		if (check()){
			cout << res_check << "\n";
			continue;
		}
		if (a[best]+best>c){
			cout << 0 << "\n";
			continue;
		}
		c -= a[best]+best;
		for (int i = 1; i <= n; i++){
			a[i] = min(a[i]+i,a[i]+n+1-i);
		}
		a[best] = 2e9;
		sort(a+1,a+n+1);
		int res = 1;
		for (int i = 1; i<= n; i++){
			if (c<a[i]) break;
			c -= a[i];
			res++;
		}
		cout << res << "\n";
	}
	
	return 0;
}
