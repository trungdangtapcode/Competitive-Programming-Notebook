#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> a;

int main(){
	cin >> n >> m;
	a.assign(n,0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	long long int res = 0;
	for (int i = 0; i < n; i++){
		int pos = upper_bound(a.begin(),a.begin()+i,m-a[i])-a.begin();
		res += pos;
	}
	cout << res;
	
	return 0;
}
