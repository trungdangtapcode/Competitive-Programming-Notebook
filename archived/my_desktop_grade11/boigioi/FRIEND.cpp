#include <bits/stdc++.h>

using namespace std;

int n, s, b[100005];
bool f[100005];
int main(){
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(b,b+n);
	
	memset(f,false,sizeof(f));
	int res = 0;
	for (int i = 0; i < n; i++) if (binary_search(b,b+n,s-b[i])){
		int pos1 = lower_bound(b,b+n,s-b[i])-b;
		int pos2 = upper_bound(b,b+n,s-b[i])-b-1;
			res += pos2 - pos1 + 1;
			if (2*b[i]==s) res--;
	}
	cout << res/2;
	
	
	return 0;
}
