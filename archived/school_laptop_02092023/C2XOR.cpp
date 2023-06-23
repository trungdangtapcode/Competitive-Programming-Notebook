#include<bits/stdc++.h>

using namespace std;
typedef pair<long long,int> ii;
int n, a[100005];
map<int,ii> mp;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i-1];
	} 
	mp[0] = {1,1};
	long long res = 0;
	for (int i = 1; i <= n; i++){
		if (mp.count(a[i])){
//			cout << mp[a[i]].second << ".. " << i;
			res += 1ll*mp[a[i]].second*i-mp[a[i]].first;
		}
		mp[a[i]].first += i+1;
		mp[a[i]].second++;
	}
	cout << res;
	
	return 0;
}
