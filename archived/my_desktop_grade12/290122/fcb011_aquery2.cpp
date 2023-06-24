#include<bits/stdc++.h>

using namespace std;
#define int long long
int q, k, a, b;
map<int,int> mp;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> q;
	while (q--){
		cin >> a >> b;
		mp[a]+=b;
	}
	cin >> k;
	for (auto it: mp){
		if (k<=it.second){
			cout << it.first;
			return 0;
		}
		k -= it.second;
	}
		
	return 0;
}
