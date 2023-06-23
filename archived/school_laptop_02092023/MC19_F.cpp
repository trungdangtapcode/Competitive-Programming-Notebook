#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
ii f[(1<<21)];
int a[1000005], n;

ii add(ii a, ii b){
	if (a<b) swap(a,b);
	return {a.first,max(a.second,b.first)};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		f[a[i]] = add(f[a[i]],{i,0});
	}
	for (int i = 0; i < 21; i++){
		for (int mask = 0; mask < (1<<21); mask++) if (mask&(1<<i)){
			f[mask^(1<<i)] = add(f[mask^(1<<i)],f[mask]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n-2; i++){
		int mask = 0;
		for (int j = 20; j >= 0; j--) if (!(a[i]&(1<<j))&&f[mask|(1<<j)].second>i) mask |= (1<<j);
		res = max(res,a[i]|mask);
	}
	cout << res;
	return 0;
}
