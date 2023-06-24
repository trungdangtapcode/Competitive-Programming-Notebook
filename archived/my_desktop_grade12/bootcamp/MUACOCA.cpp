#include<bits/stdc++.h>

using namespace std;
string s;
string catdoan(string x){
	string res = "";
	for (char c: x){
		if (c==x.back()) return res;
		res.push_back(c);
	}
}

int main(){
	cin >> s;
	int res = 0;
	while (s.size()!=0&&s.front()!=s.back()){
		s = catdoan(s);
		res++;
	}
	cout << (res%2?"Win":"Lose");
	
	return 0;
}
