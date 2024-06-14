#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
//	int res = 0, pos = 0, cnt = 0, last = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i]>0){
		} else {
			cnt++;
		}
	}
	int res = 1;
	for (int i = 2; i <= cnt; i++) if (abs(a[i])>abs(a[i-1])) res = 0;
	for (int i = cnt+2; i <= n; i++) if (abs(a[i])<abs(a[i-1])) res = 0;
	cout << (res?"YES\n":"NO\n");
//	cout << (res>1||pos==0&&pos==cnt+1?"NO\n":"YES\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

