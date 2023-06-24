#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
ii a[100005], f[3], new_f[3];
int n, k, res;
main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	sort(a,a+n);
	f[1] = f[2] = {-1e18,-1e18};
	for (int i = 0; i < n; i++){
//		memset(new_f,,sizeof(new_f))
		for (int j = 0; j < 3; j++){
			new_f[j] = max(ii{f[(j-a[i].second%3+3*3)%3].first+1,f[(j-a[i].second%3+3*3)%3].second+a[i].first},f[j]);
		}
		for (int j = 0; j < 3; j++) f[j] = new_f[j];
		for (int j = 0; j < 3; j++){
			cout << j << " {" << f[j].first << "," << f[j].second << "}\n";
			if (j==0&f[j].second<=k) res = max(res,f[j].first);
		}
	}
	cout << res;
	
	return 0;
}
