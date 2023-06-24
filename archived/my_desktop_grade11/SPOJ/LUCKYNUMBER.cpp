#include <bits/stdc++.h>
#define fix cout<<"fix"<<endl;
using namespace std;


int main(){
	long int n;
	cin >> n;
	queue<string> q;
	q.push("6");
	q.push("8");
	long int i = 1;
	while (i <= n){
		string s = q.front();
		q.pop();
		if (i==n){
			cout << s;
			return 0;
		};
		i++;
		
		if (s[s.length()-1]=='6'){
			q.push(s+"6");
		} else if (s[s.length()-1]=='8'){
			q.push(s+"6");
			q.push(s+"8");
		}
	}
	
	return 0;
	//memset(dp,-1,sizeof(dp));
	//cout << dp_set(0,n-1,0) - dp_set(0,n-1,1);
}	
