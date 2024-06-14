#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int a[maxN], n, cnt[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[i-1] = 0;
	}
	for (int i = 1; i <= n; i++){
		cnt[a[i]] = 1;
	}
	int mex = 0;
	for (int i = 0; i <= n; i++){
		mex = i;
		if (cnt[i]==0) break;
	}
	for (int i = 0; i < n; i++) cnt[i] = 0;
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (a[i]<mex){
			if (cnt[a[i]]==0){
				res++;
			} 
			cnt[a[i]] = 1;
		}
		if (mex==res){
			for (int j = i+1; j <= n; j++){
				if (a[j]<mex){
					if (cnt[a[j]]==1) res--;
					cnt[a[j]] = 0;
				}
			}
			if (res!=0){
				cout << -1 << "\n";
			} else {
				cout << "2\n1 " << i << "\n" << i+1 << " " << n << "\n";
			}
			return;
		}
	}
	cout << "?\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
