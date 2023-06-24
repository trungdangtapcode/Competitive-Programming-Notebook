#include <bits/stdc++.h>

using namespace std;

int n, x[100005], t[100005];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> t[i];
	sort(x,x+n);
	for (int i = 0; i < n; i++){
		int pos = upper_bound(x,x+n,t[i])-x-1;
		cout << pos-0+1 << '\n';
	}
	
	
	
	return 0;
}
