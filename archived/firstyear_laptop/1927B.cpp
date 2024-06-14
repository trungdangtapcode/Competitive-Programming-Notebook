#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, cnt[30], a[maxN];
char res[maxN];
string s;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 0; j < 26; j++) cnt[j] = -1;
	for (int i = n; i >= 1; i--){
		int mmin = 1e9, cur = -1;
		for (int j = 0; j < 26; j++) if (a[i]==cnt[j]-1&&cnt[j]<mmin){
			mmin = cnt[j];
			cur = j;
		} 
		if (cur!=-1){
			res[i]= (char)(cur+'a');
			cnt[cur]--;
			continue;
		}
		for (int j = 0; j < 26; j++) if (cnt[j]==-1){
			res[i] = (char)(j+'a');
			cnt[j] = a[i];
			break;
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i];
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
