

#include <bits/stdc++.h>

using namespace std;

int n, s;
int b[100005], f[100005];
int main(){
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> b[i];
	//sort(b,b+n);
	
	memset(f,1,sizeof(f));
	f[0] = -100000; 
	
	int res = 0;
	for (int i = 0; i < n; i++) {
    	int k = lower_bound(f, f+n, b[i]) - f;
    	f[k] = b[i];
    	res = max(res, k);
	}
	cout << res;
	
	
	return 0;
}
