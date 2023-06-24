#include <bits/stdc++.h>

using namespace std;

int minpos, maxpos, pos, needspace, n, m, k, res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1, x; i <= m; i++){
		cin >> x;
		pos += (x==1?-1:1);
		minpos = min(minpos,pos);
		maxpos = max(maxpos,pos);
	}
	needspace = maxpos-minpos+1;
	
	vector<int> v(k+2);
	v[0] = 0; v[k+1] = n+1;
	for (int i = 1; i <= k; i++) cin >> v[i];
	for (int i = 0, space; i <= k; i++){
		space = v[i+1]-v[i]-1;
		res += max(space-needspace+1,0);
	}
	cout << res;
	return 0;
}
