#include<bits/stdc++.h>

using namespace std;
typedef pair<int,string> is;
string s;

is formatString(vector<string>& v){
	string res;
	for (int i = 1; i < v.size(); i++){
		string cur = " " + v[i];
		cur[1] = toupper(cur[1]);
		res.append(cur);
	}
	return {stoll(v[0]),res};
}

int main(){
	ifstream fi("input.txt");
	
	vector<is> v;
	while (!fi.eof()){
		getline(fi,s);
		stringstream ss(s);
		string st;
		vector<string> cur;
		while (ss >> st){
			cur.push_back(st);
		}
		v.push_back(formatString(cur));
	}
	sort(v.begin(),v.end());
	for (is it: v){
		cout << it.first << " " << it.second << "\n";
	}
	
	return 0;
}
