#include<bits/stdc++.h>

using namespace std;
int s, a[55][55], cnt[55];
int main(){
	cin >> s; cin.ignore();
	for (int i = 0; i < s; i++){
		string x;
		getline(cin,x);
		stringstream ss(x);
		while (ss>>a[i+1][++cnt[i+1]]);
		--cnt[i+1];
	}
//	for (int i = 1; i <= s; i++){
//		for (int j = 1; j <= cnt[i]; j++) cout << a[i][j] << " ";
//		cout << endl;
//	}
//	int res = 0;
//	for (int i = 1; i <= s; i++) for (int j = 1; j <= s; j++){
//		res = max(res,a[i][j]);
//		for (int l = 2; i+l-1<=s&&j+l-1<=s; l++) res = max(res,a[i][j]+a[i+l-1][j]+a[i][j+l-1]+a[i+l-1][j+l-1]);
//	}
//	cout << res;
	cout << a[1][1] + (s>1?a[1][s]+a[s][1]+a[s][s]:0); 	
	
	return 0;
}
