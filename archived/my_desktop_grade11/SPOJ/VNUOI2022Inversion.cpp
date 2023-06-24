//y chang bai: https://oj.vnoi.info/problem/icpc21_mn_i

#include <bits/stdc++.h>

using namespace std;
int n, a[1000005], at[1000005];
long long int f[1000005], g[1000005], pref[1000005], suff[1000005], val[1000005];

void reset(){
	memset(val,0,sizeof(val));
}
void update(int x, int y){
	while (x<=n){
		val[x] += y;
		x += (x&-x);
	}
}
int getSum(int x){
	long long int res = 0;
	while (x>0){
		res += val[x];
		x -= (x&-x);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], at[a[i]] = i;
	
	reset();
	for (int i = 0; i < n; i++){
		f[i] = getSum(n)-getSum(a[i]);
		update(a[i],+1);
	}
	reset();
	for (int i = n-1; i >= 0; i--){
		g[i] = getSum(a[i]);
		update(a[i],+1);
	}
//	for (int i = 0; i  < n; i++){
//		c[i] = (i+1-f[i]+g[i])*f[i] + (n-i-g[i]+f[i])*g[i];
//	}
	suff[n+1] = pref[0] = 0;
	for (int i = n; i >= 1; i--) suff[i] = (suff[i+1]+f[at[i]]);
	for (int i = 1; i <= n; i++) pref[i] = (pref[i-1]+g[at[i]]);
	suff[0] = suff[1]; pref[n+1] = pref[n];
//	int mmax = -1e7, mmaxIndex = -1;
//	for (int i = 0; i < n; i++){
//		if (mmax < c[i]){
//			mmax = c[i];
//			mmaxIndex = i+1;
//		}
//	}
//	for (int i = 1; i <= n; i++) cout << i << " " << suff[i] << " " <<pref[i]<< endl; 
//	cout << mmaxIndex << " " <<  f[mmaxIndex-1];
	
//	reset();
//	int res = 0;
//	for (int i = 0; i < n; i++){
//		res += getSum(n)-getSum(a[i]);
//		update(a[i],+1);
//	}
//	cout << res;

	long long int res = 1e15; int resX = 1e7;
	for (int i = 0; i < n; i++){
		if (res>suff[a[i]+1]+pref[a[i]-1]){
			res = suff[a[i]+1]+pref[a[i]-1];
			resX = a[i];
		} else if (res==suff[a[i]+1]+pref[a[i]-1]){
			res = suff[a[i]+1]+pref[a[i]-1];
			resX = min(resX,a[i]);
		}
	}
	cout << resX<< " " <<suff[0] - res;
	
	return 0;
}
