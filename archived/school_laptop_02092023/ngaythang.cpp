#include<bits/stdc++.h>

using namespace std;

int n, m;
int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> m;
	cout << (n>=8?n-7:m+7);	
	return 0;
}
