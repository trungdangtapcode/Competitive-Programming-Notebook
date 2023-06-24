#include<bits/stdc++.h>

using namespace std;
int q, x, cnt[100005], p;
bool solve(){
	memset(cnt,0,sizeof(cnt));
	cin >> q;
	bool ok = true;
	while (q--){
		cin >> p >> x;
		if (p==1){
			cnt[x]++;
		} else {
			if (cnt[x]>0) cnt[x]--;
			else if (cnt[0]>0) cnt[0]--;
			else ok = false;	
		}
	}
	return ok;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cout << (solve()?"YES\n":"NO\n");
	}
	
	return 0;
}
