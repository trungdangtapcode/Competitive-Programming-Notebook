#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], k;
string s;
void solve(){
	cin >> n >> k >> s;
	s = " " + s;
	int cntO = 0;
	for (int i = 1; i <= n; i++) a[i] = s[i]=='K';
	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= k; j++) 
		for (int last = 0; last < 2; last++) 
		for (int yet = 0; yet < 2; yet++){
			int tmp = f[i-1][j][last][yet];
			int cntK = i-1-cntO;
			int freeK = cntK-tmp;
			int freeK2 = cntK-tmp*2;
			int freeO = cntO-tmp;
			
			if (last==0&&a[i]==1){ //01 = OK
				f[i][j][1][yet] = max(f[i][j][1][yet],tmp+1);
			}
			if (last==0&&a[i]==0){ //OO
				f[i][j][0][yet] = max(f[i][j][0][yet], tmp);
				if (freeK>0) f[i][j+1][1][yet] = max(f[i][j+1][1][yet],tmp+2);
			}
			if (yet==0&&a[i]==0){
				f[i][j+1][1][1] = max(f[i][j+1][1][1],tmp);
			}
			
		}
		cntO += (s[i]=='O');
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

