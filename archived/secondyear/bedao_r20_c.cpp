#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, c1, c2, a[maxN], mx;

long long solve1(){
	long long res = 0;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) pq.push(mx-a[i]);
	while (pq.size()>1){
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		res += min(1ll*y*c2,2ll*y*c1);
		if (x!=y) pq.push(x-y);
	}
	if (pq.size()) res += 1ll*c1*pq.top();
	return res;
}
long long solve2(){
	long long sum = 0, res = 1e15;
	int pivot = 0;
	for (int i = 1; i <= n; i++) sum += (mx-a[i]), pivot = max(pivot,mx-a[i]);
	for (int i = mx; i <= 2*mx; i++){
		long long sum2 = sum-pivot;
		if (sum2<=pivot){
			res = min(res,sum2*c2+(pivot-sum2)*c1);
		} else {
			res = min(res,1ll*pivot*c2+(sum2-pivot)/2*c2+(sum2%2!=pivot%2)*c1);
		}
		sum += n;
		pivot++;
	}
	return res;
}

void solve(){
	cin >> n >> c1 >> c2;
	for (int i = 1; i <= n; i++) cin >> a[i];
	mx = *max_element(a+1,a+n+1);
	if (c2>c1){
		cout << solve1() << '\n';
		return;
	}
	cout << solve2() << "\n";
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

