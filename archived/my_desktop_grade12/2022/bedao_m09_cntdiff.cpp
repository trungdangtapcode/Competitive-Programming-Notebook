#include<bits/stdc++.h>

using namespace std;
int n, m, a[300005], cnt[300005], num;
vector<int> v;
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	
	for (int i = 1; i <= n; i++){
		a[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin();
	}
	int res = 0;
	for (int i = 1, j = 0; i+m-1 <= n; i++){
		while (j-i+1<m){
			cnt[a[++j]]++;
			if (cnt[a[j]]==1) num++;
		}
		res = max(num,res);
		cnt[a[i]]--;
		if (cnt[a[i]]==0) num--;
	}
	cout << res;	
	return 0;
}
