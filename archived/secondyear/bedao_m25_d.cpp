#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
typedef pair<int,int> ii;
typedef pair<ii,ii> i4;
int n, m, p[maxN];
i4 a[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n+m+1; i++){
		cin >> a[i].second.first;
	}
	for (int i = 1; i <= n+m+1; i++){
		cin >> a[i].second.second;
	}
	for (int i = 1; i <= n+m+1; i++){
		a[i].first.first = a[i].second.first-a[i].second.second;
		a[i].first.second = i;
	}
	sort(a+1,a+n+m+1+1);
	reverse(a+1,a+n+m+1+1);
	for (int i = 1; i <= n+m+1; i++) p[a[i].first.second] = i;
	int cur = 0;
//	for (int i = 1; i<= n+m+1; i++) cout << a[i].first.first << "\n";
	for (int i = 1; i <= n; i++) cur += a[i].second.first;
	for (int i = n+m+1; i >= n+2; i--) cur += a[i].second.second;
//	cout << cur << "\n";
	for (int i = 1; i <= n+m+1; i++){
		int j = p[i];
		if (j<=n){
			cout << cur-a[j].second.first+a[n+1].second.first << " ";
		} else if (j>n+1){
			cout << cur-a[j].second.second+a[n+1].second.second << " ";
		} else {
			cout << cur << " ";
		}
	}
	cout << "\n";
}
	
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

