#include<bits/stdc++.h>

using namespace std;
long long int n, m, w, h;
int catdoi(long long int a, long long int b){ 
	int res = 0;
	while (a<b){
		a *= 2;
		res++;
	}
	return res;
}

int main(){
	cin >> n >> m >> h >> w;
	cout << min(catdoi(h,n)+catdoi(w,m),catdoi(h,m)+catdoi(w,n));
	
	
	return 0;
}
