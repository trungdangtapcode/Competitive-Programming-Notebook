#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		int cnt1 =0, res = 0;;
		for (int i =0 ,a ; i < n; i++){
			cin >> a;
			if (a==1) cnt1++;
			else res++;
		};
		cout << res+(cnt1+1)/2 << "\n";
	}
	
	return 0;
}
