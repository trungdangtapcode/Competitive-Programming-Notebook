#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
long long int cur, sum, res;
int n;
vector<ii> a;

void solve(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	
	cin >> n;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i+1;
	sort(a.begin(),a.end());
	cur = 0; sum = 0; res = 0;
	for (int i = 0; i < n; i++){
		if (cur==a[i].first){
			res += sum*(n-a[i].second+1); 
			sum += a[i].second;
		} else {
			cur = a[i].first;
			sum = a[i].second;
		}
	}
	cout << res << '\n';
}

int main(){
	
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
