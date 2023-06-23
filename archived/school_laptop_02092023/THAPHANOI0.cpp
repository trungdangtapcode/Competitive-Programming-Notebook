#include<bits/stdc++.h>

using namespace std;
int n;
void build(int k, int s, int t, int tmp){
	if (k==1){
		if (s==3&&t==2) cout << "CA";
		else if (s==1&&t==3) cout << "AB";
		else if (s==2&&t==1) cout << "BC";
		else cout << (char)(s - 1 + 'A'); 
		return;
	}
	if (s==1&&t==3){
		build(k-1,1,3,2);
		build(1,1,2,3);
		build(k-1,3,1,2);
		build(1,2,3,1);
		build(k-1,1,3,2);
	} else if (s==3&&t==2){
		build(k-1,3,2,1);
		build(1,3,1,2);
		build(k-1,2,3,1);
		build(1,1,2,3);
		build(k-1,3,2,1);
	} else if (s==2&&t==1) {
		build(k-1,2,1,3);
		build(1,2,3,1);
		build(k-1,1,2,3);
		build(1,3,1,2);
		build(k-1,2,1,3);
	} else {
		build(k-1,s,tmp,t);
		build(1,s,t,tmp);
		build(k-1,tmp,t,s);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	build(n,1,3,2);
}
