// better time complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
//long long int a[100005], prefMax[100005], suffMax[100005];
//int l[100005], r[100005], d[100005];
int n, m;
const long long int INF = 1e15;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	vector <long long int> a(n+2), prefMax(n+2), suffMax(n+2), l(m), r(m), d(m);
	for (int i = 0; i < m; i++){
		cin >> l[i] >> r[i] >> d[i];
		a[l[i]] += d[i]; a[r[i]+1] -= d[i];
	}
	for (int i = 1; i <= n; i++) a[i] += a[i-1]; //[lazy?] to norm a[]
	prefMax[0] = -INF; for (int i = 1; i <= n; i++) prefMax[i] = max(prefMax[i-1],a[i]);
	suffMax[n+1] = -INF; for (int i = n; i >= 1; i--) suffMax[i] = max(suffMax[i+1],a[i]);
	long long int res = INF, maxA = prefMax[n]; //= suffMax[1]
	for (int i = 0; i < m; i++) res = min(res,max({prefMax[l[i]-1],suffMax[r[i]+1],maxA-d[i]}));
	cout << res;
	return 0;
}
