// I forgot the condition contain at least 0,1,2.
// The solution should be shorter :D, it's just B
#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], s;
void solve(){
	cin >> n >> s;
	int sm = 0;
	int cnt[] = {0,0,0};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]]++;
		sm += a[i];
	}
	if (s<sm){
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	s -= sm;
	if (s==0){
		cout << -1 << "\n";
		return;
	}
	if (cnt[0]&&cnt[1]){
		if (!cnt[2]){
			cout << -1 << "\n";
			return;
		}
		if (s==1){
			for (int i = 0; i < cnt[0]; i++) cout << 0 << " ";
			for (int i = 0; i < cnt[2]; i++) cout << 2 << " ";
			for (int i = 0; i < cnt[1]; i++) cout << 1 << " ";
			cout << "\n";
			return;
		}
		cout << "-1\n";
		return;
	}
	if (s==1){
		for (int i = 0; i < cnt[0]; i++) cout << 0 << " ";
		for (int i = 0; i < cnt[2]; i++) cout << 2 << " ";
		for (int i = 0; i < cnt[1]; i++) cout << 1 << " ";
		cout << "\n";
		return;
	}
	if (cnt[0]==0&&cnt[1]){
		if (!cnt[2]){
			if (s%2==0){
				cout << -1 << "\n";
				return;
			}	
			for (int i = 0; i < cnt[1]; i++) cout << 1 << " ";
			cout << "\n";
			return;
		}
		if (abs(cnt[2]-cnt[1])<=1){
			if (s%3==0){
				cout << -1 << "\n";
				return;
			}
			int x = cnt[2]>cnt[1];
			for (int i = 0; i < n; i++){
				cout << (x?2:1) << " ";
				x ^= 1;
			}
			cout << "\n";
			return;
		}
		if (cnt[1]>cnt[2]){
			cout << -1 << "\n";
			return;
		}
		if (s==2){
			for (int i = 0; i < cnt[1]; i++){
				cout << 2 << " " << 1 << " ";
			}
			for (int i = 0; i < n-cnt[1]*2; i++){
				cout << 2 << " ";
			}
			cout << "\n";
			return;
		}
		return;	
	}
	if (cnt[1]==0&&cnt[0]){
		if (!cnt[2]){
			for (int i = 1; i <= n; i++) cout << a[i] << " ";
			cout << "\n";
			return;
		}
		if (s%2){
			for (int i = 1; i <= n; i++) cout << a[i] << " ";
			cout << "\n";
			return;
		}
		cout << -1 << "\n";
		return;
	}
	if (s%4){
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	cout << -1 << "\n";
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

