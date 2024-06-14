#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
void solve(){
	int n;
	cin >> n;
	vector<ii> a(n);
	vector<int> res(n);
	for (int i = 0; i< n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(),a.end());
	int cur = n+1;
	for (ii x: a) res[x.second] = --cur;
	for (int x: res) cout << x << " "; cout << "\n"; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
