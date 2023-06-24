#include <bits/stdc++.h>

using namespace std;
int n, k;
string s;

int check(int x, int y){
	int dem =0;
	for (int i =x; i <= y; i++){
		if (s[i]!=s[i+(y-x+1)]) dem++;
	}	
	//cout << x<<" "<< y << "  " << dem << endl;
	return dem;
}

void solve(){
	cin >> k;
	int res = 0;
	for (int i = 0; i < s.length(); i++){
		for (int j = i; j+(j-i+1) < s.length(); j++){
			if (check(i,j)<=k) res = max(res, j-i+1);
		}
	}
	cout << res << endl;
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> s;
	while (n--) solve();

	return 0;
}
