#include<bits/stdc++.h>

using namespace std;
int m, a[500005];

int checktree(int l, int r){
	if (l==r) return 0;
	int res = 0;
	int m = (l+r)/2;
	if (a[l]>a[m+1]){
		for (int i = 0; i < m-l+1; i++) swap(a[l+i],a[m+1+i]);
		res++;
	}
	for (int i = 0, mmax = -1e9, mmin = 1e9; i < m-l+1; i++){
		mmax = max(mmax,a[l+i]);
		mmin = min(mmin,a[m+1+i]);
		if (mmax>=mmin) return 1e7;
	}
	return checktree(l,m)+checktree(m+1,r)+res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> m;
		for (int i = 1; i <= m; i++) cin >> a[i];
		int res = checktree(1,m);
		cout << (res<1e7?res:-1) << "\n";
	}
	return 0;
}
