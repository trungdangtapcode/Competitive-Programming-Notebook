#include <bits/stdc++.h>

using namespace std;
int n, cnt[2000005];
long long int res;
vector<int> sdb;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	//init sdb
	for (int i = 1; i <= 9; i++){
		for (int sum = i; sum <= 2e6; sum = sum*10 + i){
			sdb.push_back(sum);
		}
	}
//	for (auto it: sdb) cout << it << " "; cout << endl;
	
	cin >> n;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		for (auto num: sdb) if (num>=a)res += cnt[num-a];
		cnt[a]++;
	}
	cout << res;
}
