#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, p, a[100005], b[100005], res = -1;
ii x[100005];
int main(){
	cin >> n >> p;
	for (int i = 0; i < n; i++){
		cin >> x[i].first;
		if (i) x[i].first += x[i-1].first;
		x[i].second = i;
	}
	sort(x,x+n);
	for (int i = 0; i < n; i++){
		a[i] = x[i].first;
		b[i] = x[i].second;
	}
	for (int i = n-2; i >= 0; i--) b[i] = max(b[i],b[i+1]);
	for (int i = 0; i < n; i++){
		int cur = a[i];
		int pos = lower_bound(a,a+n,cur+p) - a;
		if (pos<n) res = max(res,b[pos]-x[i].second);
	}
	cout << res;
	
	
	return 0;
}
