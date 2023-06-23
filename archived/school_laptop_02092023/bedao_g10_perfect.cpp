#include<bits/stdc++.h>

using namespace std;

int mmax[100005][20], mmin[100005][20], a[100005], n, q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--){
		mmax[i][0] = mmin[i][0] = a[i];
		for (int j = 1; j < 20; j++) mmax[i][j] = max(mmax[i][j-1],mmax[min(i+(1<<(j-1)),n)][j-1]);
		for (int j = 1; j < 20; j++) mmin[i][j] = min(mmin[i][j-1],mmin[min(i+(1<<(j-1)),n)][j-1]);
	}
	while (q--){
		int l, r, tmp;
		cin >> tmp >> r;
		int x = -1e9, y = 1e9;
		l = tmp;
		for (int i = 19; i >= 0; i--) if (l+(1<<i)-1<=r) x = max(x,mmax[l][i]), l = l+(1<<i);
		l = tmp;
		for (int i = 19; i >= 0; i--) if (l+(1<<i)-1<=r) y = min(y,mmin[l][i]), l = l+(1<<i);
//		cout << y << " -> " << x<< endl;
		cout << (x-y+1==r-tmp+1?"YES\n":"NO\n");
	}
	
	return 0;
}
