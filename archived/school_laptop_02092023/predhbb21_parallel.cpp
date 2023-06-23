#include<bits/stdc++.h>

using namespace std;
int n, a[13];
map<int,int> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (true){
		for (int i = 1; i <= 12; i++) cin >> a[i];
		for (int i = 1; i <= 12; i++) mp[a[i]]++;
		if (mp.count(0)&&mp[0]==12) break;
		int res = 1;
		for (auto it: mp) if (it.second%4!=0) res = 0;
		cout << (res?"yes\n":"no\n"); 
		mp.clear();
	}
	
	return 0;
}
