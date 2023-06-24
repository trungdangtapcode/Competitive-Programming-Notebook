#include <bits/stdc++.h>

using namespace std;
int n, m, q;
string s[105], t;
int vx[8] = {0,1,1,1,0,-1,-1,-1}; //theo [][] => x la doc
int vy[8] = {1,1,0,-1,-1,-1,0,1};

bool check(int x, int y){
	
	int l = t.length();
	bool ch[8];
	memset(ch,true,sizeof(ch));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < l; j++){
			if (x+vx[i]*j<0||x+vx[i]*j>=n||y+vy[i]*j<0||y+vy[i]*j>=m) {ch[i] = false; break;}
			if (t[j]!=s[x+vx[i]*j][y+vy[i]*j]) {ch[i] = false; break;}
		}
	}
	
	for (int i = 0; i < 8; i++) if (ch[i]) return true;
	return false;
}

bool search(){
	for (int i =0; i < n; i++) for (int j = 0; j < m; j++) if (check(i,j)) return true;
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	for (int i = 0; i < q; i++){
		cin >> t;
		cout << (search()?"YES":"NO") << endl;
	}
	
	return 0;
}
