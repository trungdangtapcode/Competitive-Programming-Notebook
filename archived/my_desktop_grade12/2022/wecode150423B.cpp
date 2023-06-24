#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		cout << (((k%3&&n%3)||k%3==0&&(n%(k+1)==k||n%(k+1)%3))?"Alice\n":"Bob\n");
//		vector<bool> f(100);
//		for (int i = 1; i <= n; i++){
//			f[i] = f[i]||!f[i-1];
//			if (i>=2) f[i] = f[i]||!f[i-2];
//			if (i>=k) f[i] = f[i]||!f[i-k];
//			cout << f[i] << " ";
//		}
		
	}
	
	return 0;
}
