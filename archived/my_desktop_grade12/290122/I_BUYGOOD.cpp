#include<bits/stdc++.h>

using namespace std;
int n, m, f[10005];
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
iii a[105];
int main(){
	cin >> n >> m;
	for (int i =0; i < m; i++) cin >> a[i].first.second >> a[i].first.first >> a[i].second;
	sort(a,a+m);
	for (int i = 1; i <= n; i++) f[i] = 1e9;
	for (int i = m-1; i >= 0; i--){
		for (int j = n; j >= 0; j--){
			f[j] = min(f[j],f[j-min(j,a[i].first.second)]+a[i].second+min(j,a[i].first.second)*a[i].first.first);
		}
	}
	cout << f[n];
	
	return 0;
}
