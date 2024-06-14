#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

int phi[maxN], n, q, spf[maxN], c;

map<int,int> int_to_map(int x){
	if (x>=1e6){
		map<int,int> res;
		for (int i = 2; i*i <= x; i++) if (x%i==0){
			int cur = 0;
			while (x%i==0) x /= i, cur++;
			res[i] = cur;
		}
		if (x>1) res[x]++;
		return res;
	}
	map<int,int> res;
	while (x!=1){
		int y = spf[x],cur = 0;
		while (x%y==0) x /= y, cur++;
		res[y] = cur;
	}
	return res;
}
void mul(map<int,int>& x, int y){ //x *= y
	while (y>1){
		int tmp = spf[y], cnt = 0;
		int &me = x[tmp];
		while (y%tmp==0) y/=tmp, cnt++;
		c = c/(me+1)*(me+cnt+1);
		me += cnt;
	}
}
bool check(map<int,int>& x,map<int,int> y){ //check if x%y==0
	for (auto &a: y){
		if (!x.count(a.first)||x[a.first]<a.second) return 0;
	}
	return 1;
}
int cnt(int x){ //count divisor
	int res = 1;
	while (x>1){
		int tmp = spf[x], cnt = 0;
		while (x%tmp==0) x/=tmp, cnt++;
		res *= (cnt+1);
	}
	return res;	
}

void solve(){
	cin >> n >> q;
	map<int,int> mn = int_to_map(n);
	c = cnt(n);
	while (q--){
		int t, y;
		cin >> t;
//		t = 1, y = (q+1);
//		if (c>1e7) t = 2;
		if (t==2){
			mn = int_to_map(n);
			c = cnt(n);
			continue;
		}
		cin >> y;
		mul(mn,y);
		cout << (check(mn,int_to_map(c))?"YES":"NO") << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 1; i <= 1e6; i++) phi[i] = 1,spf[i] = i;
	for (int i = 2; i <= 1e6; i++) if (i==spf[i]){
		for (int j = i; j <= 1e6; j += i) spf[j] = i;
	}
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

/*
#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

int phi[maxN], n, q, spf[maxN];

map<int,int> f(int x){
	map<int,int> res;
	while (x!=1){
		int y = spf[x],cur = 0;
		while (x%y==0) x /= y, cur++;
		res[y] = cur;
	}
	return res;
}
void g(map<int,int>& x,map<int,int> y){
//	map<int,int> res;
//	for (auto a: x){
//		res[a.first] += a.second;
//	}
	for (auto &a: y){
		x[a.first] += a.second;
	}
//	return res;
}
void gg(map<int,int>& x, int y){
	while (y>1){
		int tmp = spf[y], cnt =0;
		while (y%tmp==0) y/=tmp, cnt++;
		x[tmp] += cnt;
	}
}
bool check(map<int,int>& x,map<int,int> y){
	for (auto &a: y){
		if (!x.count(a.first)||x[a.first]<a.second) return 0;
	}
	return 1;
}
void test(map<int,int>& x){
	int res = 1;
	for (auto &a: x){
		for (int i = 0; i< a.second; i++) res *= a.first;
	}
	cout << res << " .." << phi[res] << " <-\n";
}
int cnt(map<int,int>& x){
	int res = 1;
	for (auto &a: x) res *= (a.second+1);
	return res;	
}

void solve(){
	cin >> n >> q;
//	int d = phi[n];
	map<int,int> mn = f(n);
	while (q--){
		int t, y;
		cin >> t;
		if (t==2){
			mn = f(n);
//			d = phi[n];
			continue;
		}
		cin >> y;
//		d *= phi[y];
//		g(mn,f(y));
		gg(mn,y);
//		auto xx = f(y);
//		test(xx);
//		test(mn);
//		cout << d << "==\n";
		cout << (check(mn,f(cnt(mn)))?"YES":"NO") << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	
	for (int i = 1; i <= 1e6; i++) phi[i] = 1,spf[i] = i;
	for (int i = 2; i <= 1e6; i++) if (i==spf[i]){
		for (int j = i; j <= 1e6; j += i) spf[j] = i;
	}
//	for (int i = 2; i <= 1e6; i++){
//		for (int j = i; j <= 1e6; j += i) phi[j]++;
//	}
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
*/
