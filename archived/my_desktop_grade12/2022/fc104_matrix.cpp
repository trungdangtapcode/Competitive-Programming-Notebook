#include<bits/stdc++.h>

using namespace std;

int main(){
	for (int i = 0, x; i < 5; i++) for (int j = 0; j < 5; j++){
		cin >> x;
		if (x){
			cout << abs(i-2)+abs(j-2);
			return 0;
		}
	}
	
	return 0;
}
