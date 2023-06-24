#include <bits/stdc++.h>

using namespace std;
vector<int> b, g;
int pos1, pos2, n, k;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		if (x>0) b.push_back(x);
		else g.push_back(-x);
	}
	sort(b.begin(),b.end());
	sort(g.begin(),g.end());
	long long int res = 0;
	for (auto it: b){
		pos1 = lower_bound(g.begin(),g.end(),it-k)-g.begin();
		pos2 = upper_bound(g.begin(),g.end(),it)-g.begin()-1;
		res += pos2 - pos1 + 1;
	}
	cout << res;	
}
