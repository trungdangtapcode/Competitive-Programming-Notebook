#include <bits/stdc++.h>

using namespace std;
int n, k, cnt =0;
long long int a;
bool b[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(b,false,sizeof(b));
	
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (!b[a%k]) cnt++;
		b[a%k] = true; 
	}
	cout << cnt;
	
	return 0;
}
