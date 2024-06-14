#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5;
int n, c, a[maxN];
vector<int> vec[2];

void solve(){
	cin >> n >> c;
	vec[0].clear(); vec[1].clear();
	long long res = (c+1)*(c)/2+c+1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		vec[a[i]%2].push_back(a[i]);
		res -= (a[i]+1+1)/2;
//		cout << a[i] << " = "<< (a[i]+1)+(c-a[i]+1)-(a[i]!=0&&a[i]%2==c%2) << "\n";
	}
	sort(vec[0].begin(),vec[0].end());
	sort(vec[1].begin(),vec[1].end());
	for (int i = 1; i <= n; i++){
		int tmp = vec[a[i]%2].end()-lower_bound(vec[a[i]%2].begin(),vec[a[i]%2].end(),a[i]);
		res -= (c-a[i]+1)-(tmp);
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;	
}
