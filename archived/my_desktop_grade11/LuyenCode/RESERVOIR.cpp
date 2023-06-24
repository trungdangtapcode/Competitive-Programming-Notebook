#include <bits/stdc++.h>
using namespace std;
long long int l[100005], h[100005], n, prv[100005], q, k, t; //phai long long moi chiu
long long int sum[100005], g[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> l[i], l[i]++; l[0] = 0;
		for (int i = 1; i <= n; i++) cin >> h[i]; h[0] = 1e5+5;
		for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + h[i];
		stack<int> sta;
		for (int i = n; i >= 0; i--){
			while (!sta.empty()&&h[sta.top()]<=h[i]){
				prv[sta.top()] = i;
				sta.pop();
			}
			sta.push(i);
		}
		g[0] = 0;
		for (int i = 1; i <= n; i++){
			g[i] = g[prv[i]] + (l[i]-l[prv[i]])*h[i] - (sum[i]-sum[prv[i]]);
		}
		
		cin >> q;
		while (q--){
			cin >> k;
			cout << lower_bound(g,g+n+1,k)-g-1 << '\n';
		}
	}
	//for (int i = 1; i <= n; i++) cout << g[i] << " ";
//	cin >> k;
	
	
	return 0;
}
