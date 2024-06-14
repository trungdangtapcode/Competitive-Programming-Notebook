#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], k;
//int f(int c, int a, int b){
//	if (c) swap(a,b);
//	int tmp = min(a,b);
//	if (k>=2*tmp){
//		k -= 2*tmp;
//		return 3;
//	} else {
//		if (a==0) return 1;
//		if (b==0)
//	}
//}
void solve(){
	deque<int> d;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int a; cin >> a;
		d.push_back(a);
	} 
	int c = 0;
	while (k>0){
		if (d.size()<2) break;
		int tmp = min(d.front(),d.back());
		int &a = d.front(), &b = d.back();
//		cout << k << "\n";
		if (k>=2*tmp){
			d.back()-= tmp, d.front()-= tmp;
			if (d.back()==0) d.pop_back();
			if (d.front()==0) d.pop_front();
			k -= 2*tmp; 
		} else {
//			k %= 2;
			d.front() -= k/2, d.back()-= k/2;
			k %= 2;
			if (d.back()==0) d.pop_back();
			if (d.front()==0) d.pop_front();
			if (k==1){
				if (a==1) d.pop_front();
				k = 0;
			}
		}
	}
	if (d.size()==1){
		if (k>=d.front()) d.pop_front();
	}
	cout << n - d.size() << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

