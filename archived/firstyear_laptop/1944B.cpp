#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int a[maxN], n, k, cnt[maxN], p[maxN][2];
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i <= 2*n; i++){
		cin >> a[i];
		p[a[i]][cnt[a[i]]++] = i;
	}
	vector<int> res1, res2, single;
	for (int i = 1; i <= n; i++){
		if (p[i][0]<=n&&p[i][1]>n){
			single.push_back(i);
		} else {
			if (p[i][0]<=n){
				if (res1.size()>=2*k) continue;
				res1.push_back(i);
				res1.push_back(i);
			} else {
				if (res2.size()>=2*k) continue;
				res2.push_back(i);
				res2.push_back(i);
			}
		}
	}
//	if (res1.length()<res2.length()) swap(res1,res2);
	assert(res1.size()==res2.size());
	while (res1.size()<2*k){
		res1.push_back(single.back());
		res2.push_back(single.back());
		single.pop_back();
	}
	for (int x: res1) cout << x << " "; cout << '\n';
	for (int x: res2) cout << x << " "; cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
