#include <bits/stdc++.h>

using namespace std;
int n , a[1005], b[1005], c[1005];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	
	sort(c,c+n);
	
	int res = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int pos1 = upper_bound(c,c+n,abs(a[i]-b[j]))-c;
			int pos2 = lower_bound(c,c+n,a[i]+b[j])-c-1;
			if (pos1<0) res += pos2; else res += (pos2) - (pos1) + 1;
			//cout << pos1 << " " << pos2 << endl;
		}
	}
	cout << res;
	
	return 0;
}
