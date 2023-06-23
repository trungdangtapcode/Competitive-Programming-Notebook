#include<bits/stdc++.h>

using namespace std;
string s0, s;
int n, p[2000050];
long long int res;

int main(){
	cin >> s0;
	for (char c: s0){
		s.push_back('#');
		s.push_back(c);
	}
	s += "#";
	n = s.length();
//	cout << s << endl;
	s = "$" + s + "^";
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++){
		p[i] = max(0,min(r-i,p[l+(r-i)]));
		while (s[i-p[i]]==s[i+p[i]]) p[i]++;
		if (i+p[i]>r) l = i-p[i], r = i+p[i];
//		cout << (s[i]=='#'?(p[i]-1)/2:p[i]/2) << " ";
		res += (s[i]=='#'?(p[i]-1)/2:p[i]/2);
	}
	cout << res;
	
	return 0;
}
