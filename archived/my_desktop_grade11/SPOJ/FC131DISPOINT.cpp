#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[200005];
int tmp[200005];
int n, maxX = -1e7, maxY = -1e7, minX = 1e7, minY = 1e7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> tmp[i];
	for (int i = 0; i < n; i++){
		int x = tmp[i], y;
		cin >> y;
		a[i] = {x+y,x-y};
		maxX = max(maxX,a[i].first);
		maxY = max(maxY,a[i].second);
		minX = min(minX,a[i].first);
		minY = min(minY,a[i].second);
	}
	for (int i = 0; i < n; i++) 
		cout << max({abs(maxX-a[i].first),abs(maxY-a[i].second),abs(minX-a[i].first),abs(minY-a[i].second)}) << " ";
	
	
	return 0;
}
