#include<bits/stdc++.h>

using namespace std;
int n, cnt[2], res;
long long int c, cur;
string s;
int main(){
	cin >> n >> c >> s;
	s = s + "#";
	for (int i = 0, j = -1; i < n; i++){
		while (j<n&&cur<=c){
			j++;
			if (s[j]=='a') cnt[0]++;
			if (s[j]=='b') cur += cnt[0], cnt[1]++;
		}
		if (s[j]=='a') cnt[0]--;
		if (s[j]=='b') cur -= cnt[0], cnt[1]--;
		j--;
		if (cur<=c){
			res = max(res,j-i+1);
		}
		if (s[i]=='a') cur -= cnt[1], cnt[0]--;
		if (s[i]=='b') cnt[1]--;
	}
	cout << res;
	
	return 0;
}
