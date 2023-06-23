#include<bits/stdc++.h>

using namespace std;
int n, a[2505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1, l = 1, h = n*n; i <= n*n; i++){
			if (i&1) a[i] = l++;
			else a[i] = h--;
		}
//		for (int i = 1; i <= n*n; i++) cout << a[i] << " "; cout << endl;
		for (int i = 1; i <= n; i++){
			if (i&1) for (int j = (i-1)*n+1; j <= i*n; j++) cout << a[j] << " ";
			else for (int j = i*n; j > (i-1)*n; j--) cout << a[j] << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
