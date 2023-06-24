#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> cnt;
int n;
const int p = 1e9+7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		cnt[a]++;
	}
	int res = 1;
	for (auto it: cnt){
		res = (1ll*res*(it.second+1))%p;
	}
	cout << res;
	
	return 0;
}
