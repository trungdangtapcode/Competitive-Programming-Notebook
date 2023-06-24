#include<bits/stdc++.h>

using namespace std;
int n, a[100005], p[100005], k;
int main(){
	ios::sync_with_stdio(0); 
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			cin >> p[i];
			a[p[i]] = i;
		}
		int res = 0;
		bool check = false;
//		for (int i = 1; i <= n;){
//			int j = i+1, cur = 1;
//			while (j<=n&&a[j]>a[j-1]) j++, cur++;
//			if (!check){
//				cur = 0;
//				check = true;
//			}
//			res += (cur+k-1)/k;
//			i = j;
//		}
		for (int i = 1; i < n; i++){
			if (a[i+1]<a[i]){
				res = (n-i+k-1)/k;
				break;
			}
		}
		cout << res << "\n";
//		cout << res << "\n";
	}
	
	return 0;
}
