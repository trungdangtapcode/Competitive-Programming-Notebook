#include <bits/stdc++.h>
using namespace std;
std::vector<int> solve(std::vector<std::vector<int>> T){
	int test = T.size();
	vector<int> res(test);
	for (int i = 0; i < test; i++){
		int n = T[i][0], k = T[i][1];
		int x = n, y = k-1;
		if (x>y) swap(x,y);
		res[i] = (2019201913ll*x+2019201949ll*y)%2019201997ll; 
		//this increase if 7x+4y decrease and vice versa
		//so we need smallest (x,y)
		//but they alway choose biggest (x,y) so we must arrange
		//all big cows now in a group, all small remaining in (k-1) groups
	}
	return res;
}
int main(){
	int t;
	cin >> t;
	vector<vector<int>> a(t,vector<int>(2));
	for (int i = 0; i < t; i++) cin >> a[i][0] >> a[i][1];
	auto res = solve(a);
	for (auto it: res) cout << it << " ";
	return 0;
}
