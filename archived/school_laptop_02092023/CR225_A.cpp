#include<bits/stdc++.h>

using namespace std;
int n, cur;
long long res;
int main(){
	cin >> n;
    for (int i = 0, a; i < n; i++){
        cin >> a;
        if (a) cur++;
        else res += cur;
    }
    cout << res;
	
	return 0;	
}
