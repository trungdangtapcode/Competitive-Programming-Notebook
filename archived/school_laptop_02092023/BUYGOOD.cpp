#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, m, s[105], p[105], w[105], f[10005];
typedef pair<int,pair<int,int>> iii;
vector<iii> x;
main(){
	
	cin >> n >> m;
	x.assign(m,{0,{0,0}});
	for (int i = 0; i < m; i++) cin >> x[i].second.first >> x[i].first >> x[i].second.second;
	sort(x.begin(),x.end());
	for (int i = 0; i < m; i++) p[i] = x[i].first, s[i] = x[i].second.first, w[i] = x[i].second.second;
//	for (int i = 0; i < m; i++) cout << s[i] << " " << p[i] << " " << w[i] << endl;
	for (int i = 1; i <= n; i++) f[i] = 1e18;
	for (int i = m-1; i >= 0; i--){
		for (int j = n; j >= 0; j--){
			f[j] = min(f[j],f[j-min(s[i],j)]+min(s[i],j)*p[i]+w[i]);
		}
//		for (int i = 0; i <= n; i++) cout << f[i] << " ";
//		cout << endl;
	}
	cout << f[n];
	
	return 0;
}
