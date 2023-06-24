#include<bits/stdc++.h>

using namespace std;
typedef pair<char,int> ci;
vector<ci> v;
string s;
int main(){
	cin >> s;
	char last = s[0];
	for (int i = 1, cnt = 1; i < s.length(); i++){
		if (s[i]!=last){
			v.push_back({last,cnt});
			last = s[i];
			cnt = 0;
		}
		cnt++;
		if (i==s.length()-1){
			v.push_back({last,cnt});
		}
	}
	for (auto it: v){
		cout << it.first << it.second;
	}
	return 0;
}
