#include<bits/stdc++.h>

using namespace std;
int n1, n2;
string s1, s2;

int main(){
	freopen("bai2vungliem.inp","r",stdin);
	freopen("bai2vungliem.out","w",stdout);
	int res = 0;
	cin >> s1 >> s2;
	n1 = s1.length();
	n2 = s2.length();
	for (int i = 0; i < n1; i++) s1[i] = toupper(s1[i]);
	for (int i = 0; i < n2; i++) s2[i] = toupper(s2[i]);
	for (int i = 0; i < n2-n1+1; i++){
		res += (s1==s2.substr(i,n1));
	}
	cout << res;
	return 0;
}
