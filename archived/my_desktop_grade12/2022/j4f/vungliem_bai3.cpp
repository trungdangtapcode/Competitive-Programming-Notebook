#include<bits/stdc++.h>

using namespace std;
string s;

string formatName(string s){
	string res = s;
	for (int i = 0; i < s.length(); i++) res[i] = tolower(s[i]);
	res[0] = toupper(s[0]);
	return res;
}

int main(){
	freopen("output.txt","w",stdout);
	ifstream is("input.txt");
	vector<vector<string>> name;
	while (!is.eof()){
		deque<string> vs;
		getline(is,s);
		stringstream ss(s);
		while (ss >> s){
			vs.push_back(formatName(s));
		}
		vs.push_front(vs.back());
		vs.pop_back();
		vector<string> vss;
		for (string s: vs){
			vss.push_back(s);
		}
		name.push_back(vss);
	}
	sort(name.begin(),name.end());
	for (auto it: name){
		for (auto s: it) cout << s << " ";
		cout << "\n";
	}
	
	
	return 0;
}
