#include<bits/stdc++.h>

using namespace std;
int n, pos1, pos2, mmin = 1e9+5;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(b.begin(),b.end());
	for (int i = 0; i < n; i++){
		pos2 = lower_bound(b.begin(),b.end(),a[i])-b.begin();
		pos1 = pos2 - 1;
		if (pos2<n) mmin = min(mmin,abs(a[i]-b[pos2]));
		if (pos1>=0) mmin = min(mmin,abs(a[i]-b[pos1]));
	}
	cout << mmin;
	return 0;
}
