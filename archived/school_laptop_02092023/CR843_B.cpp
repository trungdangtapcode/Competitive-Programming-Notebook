#include<bits/stdc++.h>

using namespace std;
int n, k[100005], cnt[200005];
vector<int> p[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> k[i];
			p[i].assign(k[i],0);
			for (int j = 0; j < k[i]; j++){
				cin >> p[i][j];
				cnt[p[i][j]]++;
			} 
		}
		bool res = 0;
		for (int i = 0; i < n; i++){
			bool cur = true;
			for (int j = 0; j < k[i]; j++){
				if (cnt[p[i][j]]==1) cur = false;
			}
			if (cur) res = true;
		}
		cout << (res?"Yes\n":"No\n");
		for (int i = 0; i < n; i++){
			for (int j = 0; j < k[i]; j++) cnt[p[i][j]] = 0;
		}
	}
	
	return 0;
}
