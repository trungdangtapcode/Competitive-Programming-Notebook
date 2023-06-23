#include<bits/stdc++.h>

using namespace std;

int s[10005], n;
int res, mmin = 1e9, cnt[4];
int diff[105][3];
void backtrack(int k){	
	if (k>=n){
//		for (int i = 0; i < n; i++) cout << (char)(s[i]+'A') << " "; cout << "\n";
//		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
		if (mmin>cnt[2]) mmin = cnt[2], res = 1;
		else if (mmin==cnt[2]) res++;
		return;
	}
	for (int x = 0; x < 3; x++){
		bool check = true;
		s[k] = x;
		for (int i = k; i > k/2; i--){
			int l = k-i+1, st = k-l-l+1;
			bool ok = true;
			for (int j = 0; j < l; j++) if (s[st+j]!=s[k-l+1+j]){
				ok = false;
				break;
			};
			if (ok){
				check = false;
				break;
			}
		}
		cnt[x]++;
		if (check&&cnt[2]<mmin){
			backtrack(k+1);	
		}
		s[k] = -1;
		cnt[x]--;
	}
}

int main(){
	cin >> n;
	backtrack(0);
	cout << res << " " << mmin << "\n";
	
	
	return 0;
}
