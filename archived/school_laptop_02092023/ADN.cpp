#include<bits/stdc++.h>

using namespace std;

int cnt[200005], enough[200005], n, k, r, a[200005], uni;

int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> k >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) enough[i] = 1e9;
	for (int i = 0, x, y; i < r; i++){
		cin >> x >> y;
		enough[x] = y;
	} 
	int res = 1e9;
	for (int i = 1, j = 0; i <= n; i++){
		while (j<n&&uni<r){
			cnt[a[++j]]++;
			uni += cnt[a[j]]==enough[a[j]];
		}
		if (uni>=r) res = min(res,j-i+1);
		uni -= cnt[a[i]]==enough[a[i]];
		cnt[a[i]]--;
	}
	if (res==1e9){
		cout << "impossible";
	} else cout << res;
		
	return 0;
}
