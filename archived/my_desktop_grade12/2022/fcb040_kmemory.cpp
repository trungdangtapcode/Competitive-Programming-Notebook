#include<bits/stdc++.h>

using namespace std;

int n, k, a[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	deque<int> dmax, dmin;
	long long int res = 0;
	for (int i = 1, j = 1; i <= n; i++){
		while (dmax.size()&&a[dmax.back()]<=a[i]) dmax.pop_back();
		dmax.push_back(i);
		while (dmin.size()&&a[dmin.back()]>=a[i]) dmin.pop_back();
		dmin.push_back(i);
		while (j<i&&a[dmax.front()]-a[dmin.front()]>k){
			if (dmax.front()<=j) dmax.pop_front();
			if (dmin.front()<=j) dmin.pop_front();
			j++;
		}
		if (a[dmax.front()]-a[dmin.front()]<=k){
			res += (i-j+1);
		};
	}
	cout << res;
	
	
	return 0;
}
