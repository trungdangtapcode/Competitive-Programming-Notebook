#include<bits/stdc++.h>

using namespace std;
int n, m, a[100005][35], cnt[35];
string s, t;

bool check(int x, int y){
	for (int i = 'a'; i <= 'z'; i++) if (a[y][i-'a']-a[x-1][i-'a']>cnt[i-'a']) return false;
	return true;
}

int main(){
	cin >> n >> m >> s >> t;
	s = "#" + s + "a";
	for (char c: t) cnt[c-'a']++;
	for (int i = 1; i <= n; i++) for (int j = 'a'; j <= 'z'; j++){
		if (s[i]==j) a[i][j-'a'] = a[i-1][j-'a'] + 1;
		else a[i][j-'a'] = a[i-1][j-'a'];
	}
	long long int res = 0;
	for (int i = 1, j = 1; i <= n; i++){
		while (j<=n&&check(i,j)) j++;
		j--;
		if (check(i,j)){
			res += j-i+1;
		}
	}
	cout << res;
	
	
	return 0;
}
