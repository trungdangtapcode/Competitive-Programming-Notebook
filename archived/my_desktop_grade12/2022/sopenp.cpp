#include<bits/stdc++.h>

using namespace std;
int n, a[1200005], l, u, num1, num2, cnt1[1200005], cnt2[1200005];
vector<int> v;
long long res;
int main(){
	cin >> n >> l >> u;
	for (int i = 1; i <= n; i++){
		cin >>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for (int i = 1; i<= n; i++) a[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin();
	for (int i = 1, j1 = 0, j2 = 0; i <= n; i++){
		while (j1<n&&num1<l){
			cnt1[a[++j1]]++;
			if (cnt1[a[j1]]==1) num1++;
		}
		while (j2<=n&&num2<=u){
			cnt2[a[++j2]]++;
			if (cnt2[a[j2]]==1) num2++;
		}
		if (cnt2[a[j2]]==1) num2--;
		cnt2[a[j2--]]--;
		if (num1>=l&&num2<=u){
			res += j2-j1+1;
		}
		cnt1[a[i]]--; cnt2[a[i]]--;
		if (cnt1[a[i]]==0) num1--;
		if (cnt2[a[i]]==0) num2--;
	}
	cout << res;
	return 0;
}
