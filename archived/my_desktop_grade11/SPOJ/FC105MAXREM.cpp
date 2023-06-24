#include <bits/stdc++.h>

using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int res = 0; //Greedy
	int maxEle = *max_element(a.begin(),a.end());
	for (int i = 0; i < n; i++){
		res = max(res,a[i]%maxEle);
	}
	cout << res;
	return 0;
}
