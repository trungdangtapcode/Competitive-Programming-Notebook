#include <bits/stdc++.h>

using namespace std;
int h[1005], p[1005], a, b, res = 0, n;
bool used[1005];

int main(){
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) if (!used[i]){
		vector <pair<int,int>> v;
		for (int j = i; j < n; j++) if (!used[j]) v.push_back({h[j],j}); //
		sort(v.begin(),v.end());
		int cur = -1;
		//for (auto& it: v) cout << it.first << " "; cout << endl;
		//if (p[i]<n-i)
		if (p[i]<v.size()) if (v[p[i]].first>h[i]) cur = v[p[i]].second; //p[i]-1: bao gom ca a[i] (bo)
		if (cur!=-1) { //moi h[i] doi 1 khac nhau nen khoi lo i cap voi i
			res += b;
			used[cur] = true;
		} else res += a;
		//cout << i << " " << cur << "    res = " << res << endl;
	}
	cout << res;
	
	return 0;
}
