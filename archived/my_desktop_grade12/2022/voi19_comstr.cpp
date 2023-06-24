#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<int> v;
int m, m1, m2, r, m12, ptr, p[100005], cnt[100005][26];
string s;
int main(){
	cin >> m >> m1 >> m2 >> r >> s;
	s = "#" + s;
	m12 = m1 + m2;
	ptr = m2; //last string to add
	for (int i = 1; i <= m12; i++){
		p[i] = i;
	}
	for (int i = m12+1, j; i <= m;){
		for (j = i; j < i+ptr; j++){
			if (j>m) break;
			p[j] = p[(j-i+1)];
		}
		if (j>m) break;
		ptr = i-1;
		i = j;
	}
	for (int i = m12+1; i <= m; i++){
		cnt[p[i]][s[i]-'A']++;
	}
	int res = 0;
	for (int i = 1; i <= m12; i++){
		int cur = 0;
		for (int j = 0; j < 26; j++){
			if (cnt[i][j]) cur = max(cur,cnt[i][j]-cnt[i][s[i]-'A']);
			if (j!=s[i]-'A') res += cnt[i][j];
		}
		if (cur!=0) v.push_back(cur);
	}
//	for (auto it: v){
//		cout << it.first << " " << it.second << "\n";
//	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for (int it: v){
		if (r<=0) break;
		res -= it;
		r--;
	}
	cout << res << "\n";
	
	return 0;
}
