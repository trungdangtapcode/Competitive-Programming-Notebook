#include<bits/stdc++.h>

using namespace std;
long long n, m1, m2;
int memo[1000005];
vector<long long> d;
int& dp(long long x){
	return memo[lower_bound(d.begin(),d.end(),x)-d.begin()];
}

void solve(){
	cin >> n >> m1 >> m2;
	vector<int> d1, d2;
	d.clear();
//	vector<long long> d;
//	map<long long, int> dp; 
	for (int i = 1; i*i <= m1; i++) if (m1%i==0){
		d1.push_back(i);
		d1.push_back(m1/i);
	}
	for (int i = 1; i*i <= m2; i++) if (m2%i==0){
		d2.push_back(i);
		d2.push_back(m2/i);
	}
	for (int x: d1) for (int y: d2) d.push_back(1ll*x*y);
	sort(d.begin(),d.end());
	d.erase(unique(d.begin(),d.end()),d.end());
	fill(memo,memo+d.size(),0);
	vector<int> p;
	for (int i = 2; i*i <= m1; i++) if (m1%i==0){
		while (m1%i==0) m1 /= i;
		p.push_back(i);
	}
	if (m1>1) p.push_back(m1);
	for (int i = 2; i*i <= m2; i++) if (m2%i==0){
		while (m2%i==0) m2 /= i;
		p.push_back(i);
	}
	if (m2>1) p.push_back(m2);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	int total_xor = 0, positive = 0;
	for (long long x: d){
		int &ref = dp(x);
		if (x<=n) ref = x;
		for (long long prime: p){
			if (x%prime==0) ref = max(ref,dp(x/prime));
			if (prime>x) break;
		};
		long long res = x/ref;
		if (res>n) res = 0;
		else positive++;
		total_xor ^= res;
	}
	cout << positive << " " << total_xor << "\n";
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
