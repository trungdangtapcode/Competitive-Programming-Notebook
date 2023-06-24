#include <bits/stdc++.h>

using namespace std;
int n, cnt;

bool check(int x){
	int res = 0;
	while (x){
		res += x%10;
		x /= 10;
	}
	return (res%10==0);
}

int main(){
	
	cin >> n;
	cnt = 0;
	for (int i = 1; ; i++){
		if (check(i)){
			cnt++;
		}
		if (cnt==n){
			cout << i;
			break;
		}
	}
	
	return 0;
}
