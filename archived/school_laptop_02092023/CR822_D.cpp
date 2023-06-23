#include<bits/stdc++.h>

using namespace std;
int n, p;
vector<int> a;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> p;
		a.assign(n+1,0);
		for (int i = 1; i <= n; i++) cin >> a[i];
		int l = p, r = p;
		long long int hp = a[p];
		for (;;){
			int ml = l, fl = l;
			long long int tmpl = hp, mhl = hp;
			while (fl>1&&tmpl+a[fl-1]>=0){
				tmpl+=a[fl-1];
				fl--;
				if (tmpl>=mhl) mhl = tmpl, ml = fl;
			}
			int mr = r, fr = r;
			long long int tmpr = hp, mhr = hp;
			while (fr<n&&tmpr+a[fr+1]>=0){
				tmpr+=a[fr+1];
				fr++;
				if (tmpr>=mhr) mhr = tmpr, mr = fr;
			}  
			if (fl==1||fr==n){
				cout << "YES\n";
				break;
			}
			if (max(mhl,mhr)==hp){
				cout << "NO\n";
				break;
			}
			if (mhl>mhr) hp = mhl, l = ml;
			else hp = mhr, r = mr;
		}
	}
	
	return 0;
}
