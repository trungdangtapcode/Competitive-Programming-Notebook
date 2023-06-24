#include <bits/stdc++.h>

using namespace std;
int n;
long long int res;
vector<int> v1, v2;
string s1, s2;
char c;

int main(){
	
	cin >> s1 >> s2;
	if (s1.length()!=s2.length()){
		cout << -1;
		return 0;
	}
	n = s1.length();
	c = s1[0];
	for (int i = 0; i < n; i++){
		if (s1[i]==c) v1.push_back(i);
		if (s2[i]==c) v2.push_back(i);
	}
	if (v1.size()!=v2.size()){
		cout << -1;
		return 0;
	}
	n = v1.size();
	for (int i = 0; i < n; i++){
		res += abs(v1[i]-v2[i]);
	}
	cout << res;
	
	return 0;
}
