#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define int long long
int n, q, pref[800005], s[800005], f[800005], x[400005], y[400005], z[400005], l[400005], r[400005], k[400005], a1, a2, a3, b1, b2, b3, c1, c2, c3, m1, m2, m3;
const int p = 1e9+7;
vector<int> vec;
void read(){
	cin >> n >> q;
	cin >> x[1] >> x[2] >> a1 >> b1 >> c1 >> m1;
	cin >> y[1] >> y[2] >> a2 >> b2 >> c2 >> m2;
	cin >> z[1] >> z[2] >> a3 >> b3 >> c3 >> m3;
	for (int i = 3; i <= n; i++) x[i] = (a1*x[i-1]+b1*x[i-2]+c1)%m1, y[i] = (a2*y[i-1]+b2*y[i-2]+c2)%m2;
	for (int i = 3; i <= q; i++) z[i] = (a3*z[i-1]+b3*z[i-2]+c3)%m3;
	for (int i = 1; i <= n; i++) l[i] = min(x[i],y[i])+1, r[i] = max(x[i],y[i])+1;
	for (int i = 1; i <= q; i++) k[i] = z[i] + 1;
}

inline int ff(int x){
	int pos = upper_bound(vec.begin(),vec.end(),x)-vec.begin()-1, res = 0;
	if (pos>0) res += pref[pos-1];
	if (pos>=0) res += (x-vec[pos]+1)*f[pos];
	return res; 
}
inline int findRank(int x){
	return ff(*vec.rbegin())-ff(x)+1;
}

main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		vec.clear();
		read();
//		if (n==5&&q==1&&k[1]==5){
//			cout << 7 << "\n";
//			continue;
//		}
		for (int i = 1; i <= n; i++) vec.push_back(l[i]), vec.push_back(r[i]+1);
		vec.push_back(1e10);
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		int sz = vec.size();
	//	for (auto x: vec) cout << x << " "; cout << endl;
		memset(f,0,sizeof(f));
		for (int i = 1; i <= n; i++){
	//		cout << l[i] << ".." << r[i] << " => ";
			l[i] = lower_bound(vec.begin(),vec.end(),l[i])-vec.begin();
			r[i] = lower_bound(vec.begin(),vec.end(),r[i]+1)-vec.begin();
	//		cout << l[i] << "..." << r[i] << endl;
			f[l[i]]++;
			f[r[i]]--;
		}
		for (int i = 1; i < sz; i++) f[i] += f[i-1];
		for (int i = 0; i < sz-1; i++){
			s[i] = f[i]*(vec[i+1]-vec[i]);
		}
		s[sz-1] = 0;
	//	int tmp = k[1];
		pref[0] = s[0];
		for (int i =1; i < sz; i++){
			pref[i] = pref[i-1] + s[i];
		}
	//	for (int i = 0; i < sz; i++){
	//		cout << vec[i] << " " << f[i] << " " << pref[i] << "\n";
	//	}
	//	cout << findRank(5) << " " << k[1]<< endl;
		int ans = 0;
		for (int i = 1; i <= q; i++){
			int l = 0, h = *vec.rbegin(), m, res;
			while (l<=h){
				m = (l+h)/2;
				if (findRank(m)<=k[i]){
					h = m-1;
					res = m;
				} else l = m+1;
			}
			ans += res*i;
		}
		cout << ans << "\n";
	}
//	int pos = upper_bound(pref,pref+sz,tmp)-pref-1;
//	tmp -= pref[pos];
//	cout << vec[pos+1]+(tmp/f[pos+1]+(bool)(tmp%f[pos+1]));
		
//	for (int i = 1; i < sz; i++) pref[i] += pref[i-1];
//	for (int i = 0; i < sz; i++){
//		
//	}
	
	return 0;
}
