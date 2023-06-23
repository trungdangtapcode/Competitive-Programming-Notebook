#include<bits/stdc++.h>

using namespace std;
multiset<int> ms;
int n, a[100005], q, x, y;
long long int loai;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		ms.insert(a[i]);
	}
	for (int i = 1; i <= n; i++){
		loai += n - ms.count(a[i]);
	}
	loai /= 2;
	while (q--){
		cin >> x >> y;
		loai -= n - ms.count(a[x]);
		ms.erase(ms.find(a[x]));
		a[x] += y;
		ms.insert(a[x]);
		loai += n - ms.count(a[x]);
		cout << 1ll*n*(n-1)-loai << "\n";
	}
	
	
	return 0;
}
