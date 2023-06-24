#include <bits/stdc++.h>

using namespace std;
long long int x;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> x;
		vector <long long int> v;
		long long int y = 0;
		while (x!=0){
			if (x%2) v.push_back(y);
			x /= 2;	
			y++;
		}
		cout << v.size() << '\n';
		y = 0;
		for (auto& it: v){
			cout << (1ll<<(it-(y++))) << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
