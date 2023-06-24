//#include <bits/stdc++.h>
//#include <string>
#include <stack>
#include <cstdio>
//#include <iostream>

using namespace std;
int n, q;
char str[100005]; //string
stack <int> sta;

int main(){
	
	//cin >> n >> q;
	//scanf("%d %d", &n, &q);
	scanf("%d", &n);
	scanf("%d", &q);
	//memset(str,'#',sizeof(str[0])*n);
	for (int i = 0; i < n; i++) str[i] = '#';
	for (int i = 0; i < n; i++){
		int x;
		if (sta.empty()){
			sta.push(i);
			continue;
		}
		//cout << "? " << sta.top()+1 << " " << i+1 << '\n';
		//cin >> x;
		printf("? %u %d\n", sta.top()+1, i+1);
		fflush(stdout);
		//cout << '?' << ' ' << sta.top()+1 << ' ' << i+1 << '\n';
		scanf("%d", &x);
		if (x){
			str[sta.top()] = '(';
			str[i] = ')';
			sta.pop();
		} else sta.push(i);
	}
	
	if (!sta.empty()){
		int stackSize = sta.size();
		for (int i = 0; i < stackSize/2; i++) {
			str[sta.top()] = '(';
			sta.pop();
		} 
		for (int i = 0; i < stackSize/2; i++){
			str[sta.top()] = ')';
			sta.pop();	
		}		
	}
	//cout << "! "; // << str;
	//for (int i = 0; i < n; i++) cout << str[i]; 
	//cout << '!' <<' ';
	printf("! %s\n", str);
	fflush(stdout);
	
	return 0;
}
