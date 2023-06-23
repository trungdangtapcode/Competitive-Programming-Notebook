#include<bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
string s[1005];
int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = "#" + s[i] + "#";
	}
	s[0].assign(m+2,'#');
	s[n+1].assign(m+2,'#');
	int res = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (s[i][j]=='C'){
		int cntA = 0, cntM = 0;
		for (int k = 0; k < 4; k++){
			int ii = i + dx[k] , jj = j + dy[k];
			if (s[ii][jj] == 'A') cntA++;
			if (s[ii][jj] == 'M') cntM++;
		}
		res += cntA*cntM;
	}
	cout << res;
	
	return 0;
}
