#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, p[200005], pt[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> p[i];
			pt[p[i]] = i;
		}
		int l = (n+1)/2, r = n/2+1;
		vector<ii> v;
		for (; l>=1&&r<=n; l--,r++){
			v.push_back({pt[l],pt[r]});
		}
		int res = 0;
		for (int i = 0; i < v.size(); i++){
			int l = v[i].first, r = v[i].second;
			if (l>r||i&&(l>v[i-1].first||r<v[i-1].second)){
				res =  v.size() - i;
				break;	
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}
