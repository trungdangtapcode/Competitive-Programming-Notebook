#include<bits/stdc++.h>

using namespace std;
int n, f[1005];
vector<int> a;
int main(){
	cin >> n;
	a.assign(n,0);
	for (auto& i: a) cin >> i;
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++){
		f[i] = 1;
		for (int j = 0; j < i; j++){
			if (binary_search(a.begin(),a.begin()+j,a[i]-a[j])
				||binary_search(a.begin()+j+1,a.begin()+i,a[i]-a[j])) f[i] = max(f[i],f[j]+1);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) res = max(res,f[i]);
	cout << res;
	
	return 0;
}
