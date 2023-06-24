#include <bits/stdc++.h>

using namespace std;
int n, m, k;
long long int x;
string S0;
string s[505];
int pos[505], demBaseK[505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k >> x >> S0; x--; //vi tri trong toan hoc bat dau tu 0
	int index_S0 = 0;
	for (int i = 0; i < S0.length(); i++) if (S0[i]=='#'){
		pos[index_S0] = i;
		index_S0++;
	}
	for (int i = 0; i< m; i++){
		cin >> s[i];
		sort(s[i].begin(),s[i].end());
	}
	for (int i = 0; i <m; i++){
		demBaseK[m-i-1] = x%k;
		x /= k;
	}
	//for (int i = 0; i <m; i++) cout << s[i] <<" "; cout << endl;
	for (int i = 0; i <m; i++){
		S0[pos[i]] = s[i][demBaseK[i]];
	}
	cout << S0;
	
	return 0;
}
