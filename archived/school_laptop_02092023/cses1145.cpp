#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> lis;
int main(){
	
	cin >> n;
	lis.assign(n+1,1e9);
	lis[0] = -1e9;
	int res = 0;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		int pos = lower_bound(lis.begin(),lis.end(),a)-lis.begin();
		res = max(res,pos);
		lis[pos] = a;
	}
	cout << res;
	
	return 0;	
}
