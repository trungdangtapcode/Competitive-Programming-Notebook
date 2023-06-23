#include<bits/stdc++.h>

using namespace std;
int n, cnt1, cnt2;
vector<int> a,b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		b.assign(n,0);
		cnt1 = cnt2 = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		int res = 0;
		for (int i = 0; i < n; i++){
			if (a[i]!=b[i]) res++;
			if (a[i]) cnt1++;
			if (b[i]) cnt2++;
		}	
		cout << min(res,abs(cnt1-cnt2)+1) << "\n";
	}
	return 0;
}
