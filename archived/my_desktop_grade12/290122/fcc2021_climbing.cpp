#include<bits/stdc++.h>

using namespace std;

int n, m, c, a[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	deque<int> dmax, dmin;
	bool res = false;
	for (int i = 1, j = 0; i+m-1 <= n; i++){
		while (j-i+1<m){
			j++;
			while (dmax.size()&&a[dmax.back()]<=a[j]) dmax.pop_back();
			dmax.push_back(j);
			while (dmin.size()&&a[dmin.back()]>=a[j]) dmin.pop_back();
			dmin.push_back(j);
		}
		if (a[dmax.front()]-a[dmin.front()]<=c){
			cout << i << "\n";
			res = true;
		};
		if (dmax.front()<=i) dmax.pop_front();
		if (dmin.front()<=i) dmin.pop_front();
	}
	if (!res) cout << "NONE";
	
	
	return 0;
}
