#include<bits/stdc++.h>

using namespace std; 
map<int,bool> mp;
int main(){
	int n; cin >> n;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		cout << mp[x] << " ";
		mp[x] = true;
	}
	
	return 0;
}
