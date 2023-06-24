#include<bits/stdc++.h>

using namespace std;
vector<int> d[100005];
int cnt[100005], a[100005], n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 1e5; i++) for (int j = i; j <= 1e5; j+=i) d[j].push_back(i);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i<= n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		fill(cnt+1,cnt+m+1,0);
		int num = 0, res = 1e9;
		for (int i = 1, j = 1; i <= n; i++){
			while (num<m&&j<=n){
				for (int p: d[a[j]]){
					cnt[p]++;
					if (cnt[p]==1&&p<=m) num++;
				}
				j++;
			}
			if (num==m){
				res = min(res,a[j-1]-a[i]);
			}
			for (int p: d[a[i]]){
				cnt[p]--;
				if (cnt[p]==0&&p<=m) num--;
			}
		}
		cout << (res==1e9?-1:res) << "\n";
	}
	
	return 0;
}
