#include<bits/stdc++.h>

using namespace std;

int spf[1020006], n;
vector<int> uoc;
vector<pair<int,int>> v;
void backtrack(int k, int p){
	if (k==v.size()){
		uoc.push_back(k);
	}
	for (int i = 0, pp = 1; i <= v[k].second; i++){
		backtrack(k+1,pp*p);
		pp *= v[k].first;
	}	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 1e6+2e4; i++) spf[i] = i;
	for (int i = 2; i*i <= 1e6+2e4; i++) if (spf[i]==i) for (int j = i*i; j <= 1e6+2e4; j+=i) spf[j] = i; 
		
	int q; cin >> q;
	while (q--){
		cin >> n;
		int t = n*(n+1)*(n+2);
		map<int,int> mp;
		v.clear();
		int n0 = n;
		while (n>1){
			mp[spf[n]]++;
			n /= spf[n];
		}
		n = n0+1;
		while (n>1){
			mp[spf[n]]++;
			n /= spf[n];
		}
		n = n0+2;
		while (n>1){
			mp[spf[n]]++;
			n /= spf[n];
		}
	//	for (auto it: mp) v.push_back(it);
	//	for (auto it: mp) cout << it.first << " " <<it.second << endl;
		int cnt1 = 1, cnt2 = 1;
		for (auto it: mp) cnt1 *= (it.second+1), cnt2 *= (it.second*2+1);
		cout << (cnt2-1)/2+1-cnt1 << "\n";
	}
	return 0;
}
