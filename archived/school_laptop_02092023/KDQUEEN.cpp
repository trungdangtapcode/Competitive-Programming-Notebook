#include<bits/stdc++.h>

using namespace std;
#define int long long
int pow2[100005], n, f[100005], a[100005], x[100005], mmax = 1e9;
vector<int> duyet;
const int p = 1e9+7;

main(){
	pow2[0] = 1;
	for (int i = 1; i<=1e5; i++) pow2[i] =2ll*pow2[i-1]%p;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int res = 0;
	for (int i= 0; i < n;i++){
		cin >> x[i];
		res = (res+a[i]-1)%p;
	}
	for (int i = 0; i < n; i++){
		int tmp = a[i]-x[i];
		mmax = min(mmax,max(tmp,x[i]-1));
		f[i] = min(tmp,x[i]-1);
//		cout << f[i] << " ";
	}
	sort(f,f+n);
	duyet.push_back(0);
	duyet.push_back(min(1ll,mmax));
	duyet.push_back(mmax); //3 pos co dinh quan trong
	for (int i = 0; i < n; i++){
		duyet.push_back(min(f[i],mmax));
	}
	sort(duyet.begin(),duyet.end());
	duyet.erase(unique(duyet.begin(),duyet.end()),duyet.end());
//	for (int i = n-1; i >= 0; i--) if (f[i]<=mmax){
//		if (f[i]<1) break;
//		sum = 2*sum+;
//	}
	for (int i = 1; i < duyet.size(); i++){
		int cnt = (duyet[i]-duyet[i-1])%p;
		int pos = lower_bound(f,f+n,duyet[i])-f;
		res = (res+1ll*pow2[n-1-pos+1]*cnt%p)%p;
	}
//	for (int l = 1; l <= mmax; l++){
//		int pos = lower_bound(f,f+n,l)-f;
//		res = (res+1ll*pow2[n-1-pos+1])%p;
//	}
	cout << res;
	
	return 0;
}
