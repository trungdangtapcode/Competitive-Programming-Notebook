#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main(){
	cin >> n;
	a.assign(n,0);
	for (auto &i: a) cin >> i;
	sort(a.begin(),a.end());
	int res = 1;
	for (int i = 1, cl = a[0]&1; i < a.size(); i++){
		if ((a[i]&1)!=cl) res++, cl^=1;
	}
	cout << res;
	
	return 0;
}
