#include <bits/stdc++.h>

using namespace std;

int n, s;
pair <int, int> b[100005];
int f[100005];
int bf[100005];
int main(){
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> b[i].first, b[i].second = i;
	sort(b,b+n);
	
	memset(f,-1,sizeof(f));
	f[n-1] = b[n-1].second;
	for (int i = n-2; i >= 0; i--) f[i] = max(f[i+1],b[i].second);
	for (int i = 0; i < n; i++) bf[i] = b[i].first;
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		int pos2 = upper_bound(bf,bf+n,bf[i]+s)-bf;
		if (pos2>-1) if (bf[pos2-1]-bf[i]>=s) pos2--;
		res = max(res,f[pos2]-b[i].second);
	}
	cout << res;
	
	
	return 0;
}
