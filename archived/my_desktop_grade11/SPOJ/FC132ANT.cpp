#include <bits/stdc++.h>
int n,q;
long long int a[300005];
using namespace std;int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i] ;
	for (int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		cout << a[(r+l+1)/2]-a[(r+l)/2]+1 <<"\n";
	}
	
	return 0;
}
