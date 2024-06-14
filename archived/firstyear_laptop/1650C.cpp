#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, m;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
iii a[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> a[i].second.first >> a[i].first;
		a[i].second.second = i;
	}
	sort(a+1,a+m+1);
	long long res = 0;
	vector<ii> vec;
	for (int i = 1; i <= 2*n; i++) res += a[i].first, vec.push_back(a[i].second);
	cout << res << "\n";
	sort(vec.begin(),vec.end());
	for (int i = 0; i < n; i++){
		cout << vec[i].second << " " << vec[2*n-1-i].second << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

