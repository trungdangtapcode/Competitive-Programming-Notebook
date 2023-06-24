#include<bits/stdc++.h>

using namespace std;
int a[3];
typedef pair<int,int> ii;
int main(){
	for (int i = 0; i < 3; i++) cin >> a[i];

	map<int, int> mp;
	for (int i = 0; i < 3; i++){
		map<int, int> cur;
		for (int j = 2; j*j <= a[i]; j++) if (a[i]%j==0){
			while (a[i]%j==0) cur[j]++, a[i] /= j;
		}
		if (a[i]>1) cur[a[i]]++;
		for (ii it: cur) mp[it.first] = max(mp[it.first],it.second);
	}
	unsigned long long res = 1;
	for (ii it: mp){
		for (int i = 0; i < (it.second+1)/2; i++) res *= it.first;
	}
	cout << res;
	
	
	return 0;
}
