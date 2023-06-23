#include<bits/stdc++.h>

using namespace std;
int n, a[100005];
int main(){
	cin >> n;
	for (int i = 2, cur = 0; i <= n; i++) if (a[i]==0){
		++cur;
		for (int j = i; j <= n; j+=i) if (a[j]==0) a[j] = cur;
	}
	for (int i = 2; i <= n; i++) cout << a[i] << " ";
	
	return 0;
}
