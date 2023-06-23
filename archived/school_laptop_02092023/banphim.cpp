#include<bits/stdc++.h>
using namespace std;
int n, c[30][30]; //1 ky tu a bam duoc b thi moi ky tu a deu bam duoc b
string s, t;
int main(){
	cin >> n >> s >> t;
	s = s + s[0];
	if (s.find(t[0])==string::npos) return cout << "NO", 0;
	for (int i = 0; i < n; i++) c[s[i]-'a'][s[i+1]-'a'] = 1;
	for (int i = 0; i < t.length()-1; i++) if (c[t[i]-'a'][t[i+1]-'a']==0) return cout << "NO", 0;
	cout << "YES";
	return 0;
}
