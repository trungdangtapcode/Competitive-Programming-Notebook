#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n;
int l[maxN];
vector<int> a[maxN], res[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j  <= l[i]; j++){
			int x; cin >> x;
			a[i].push_back(x);
			res[i].push_back(0);
		}
		reverse(a[i].begin(),a[i].end());
	}
	for (int i = 1; i<= n; i++){
		int cnt; cin >> cnt;
		int sum = 0;
		for (int j = 0, p = 0; j < l[i]; j++){
			sum += a[i][j];
			while (p<=j&&sum>10) sum -= a[i][p], p++;
//			cout << i << ": " << p << ".." << j << " = " << sum << "\n";
			if (sum==10&&cnt>0){
				cnt--;
				for (int x = p; x <= j; x++) res[i][x] = 1;
				p = j+1;
				sum = 0;
			} 
			
		}
		int check = 0;
		for (int j = l[i]-1; j >= 0; j--){
//			cout << res[i][j] << " "; cout << "\n";
			if (!res[i][j]) cout << a[i][j] << " ";
			if (!res[i][j]) check = 1;
		}
		if (check==0) cout << 0;
		cout << "\n";
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

