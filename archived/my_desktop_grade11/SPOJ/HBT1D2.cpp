#include <bits/stdc++.h>

using namespace std;

long long int p = 1e18;
long long int f[6000005];
//map<long long int, bool> m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	f[1] = f[2] = 1;
	//m[1] = true;
	for (int i = 3; i < 6000000; i++) f[i] = (f[i-1]+f[i-2])%p;// m[f[i]] = true;
	//cout << f[20];
	
	//cin.ignore();
	sort(f,f+6000000);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		int delta = min(18,(int)s.length());
		//cout << delta << endl;
		//cout << stoll(s.substr(s.length()-delta,delta)) << endl;
		//printf("%s\n",(m[stoll(s.substr(s.length()-delta,delta))]?"Yes":"No"));
		printf("%s\n",(binary_search(f,f+6000000,stoll(s.substr(s.length()-delta,delta)))?"Yes":"No"));
	}
	
	
	return 0;
}
