#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> a, l, decr, inc;

int main(){
	freopen("WAVIO.INP","r",stdin);
	freopen("WAVIO.OUT","w",stdout);
	
	cin >> n;
	a.assign(n+5,0); inc.assign(n+5,0); decr.assign(n+5,0);
	l.assign(n+5,1e9); //listed
	l[0] = -1e9;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		int pos = lower_bound(l.begin(),l.end(),a[i])-l.begin();
		inc[i] = pos;
		l[pos] = a[i];
	}
	l.assign(n+5,1e9); l[0] = -1e9;
	for (int i = n-1; i >= 0; i--){
		int pos = lower_bound(l.begin(),l.end(),a[i])-l.begin();
		decr[i] = pos;
		l[pos] = a[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) if (inc[i]>1&&decr[i]>1) res = max(res,inc[i]+decr[i]-1);
	cout << res;
	
	
	return 0;
}
