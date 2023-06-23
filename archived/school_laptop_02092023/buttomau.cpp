#include<bits/stdc++.h>

using namespace std;

int vox[] = {1,0,-1,0}, voy[] = {0,1,0,-1}, vxx[] = {0,1,1,-1,-1}, vxy[] = {0,-1,1,1,-1};
string s[1005];
int n, m, ii, jj;

int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = "#" + s[i] + "#";
	}	
	s[0].assign(m+2,'#');
	s[n+1].assign(m+2,'#');
	//but O
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			bool ok = true;
			for (int k = 0; k < 4; k++){
				ii = i+vox[k];
				jj = j+voy[k];
				if (s[ii][jj]=='.') ok = false;
			}
			if (ok) for (int k = 0; k < 4; k++){
				ii = i+vox[k];
				jj = j+voy[k];
				s[ii][jj] = '#';
			} 
		}
	}
	//but X
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			bool ok = true;
			for (int k = 0; k < 5; k++){
				ii = i+vxx[k];
				jj = j+vxy[k];
				if (s[ii][jj]=='.') ok = false;
			}
			if (ok) for (int k = 0; k < 5; k++){
				ii = i+vxx[k];
				jj = j+vxy[k];
				s[ii][jj] = '#';
			} 
		}
	}
	for (int i = 0; i <= n+1; i++){
		cout << s[i] << "\n";
	}
	bool res = true;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) if (s[i][j]=='*') res = false;
	}	
	cout << (res?"YES":"NO");
	
	
	return 0;
}
