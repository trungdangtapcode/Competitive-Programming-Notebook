#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, k;
vector<ii> a;

void solve(){
	cin >> n >> k;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
		
	sort(a.begin(),a.end(),[](ii a, ii b){
		if (a.first%k==b.first%k) return a.second<b.second;
		else (a.first%k<b.first%k);
	});
	for (int i = 0; i < n-1; i++) if (a[i].first%k==a[i+1].first%k&&a[i].first>a[i+1].first){
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	return;
}

int main(){
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;
}
