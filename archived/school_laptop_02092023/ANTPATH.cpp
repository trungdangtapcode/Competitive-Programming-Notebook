#include<bits/stdc++.h>

using namespace std;
long long int a[4], b[4], tmp, res;
int main(){
	cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
	//a[3]
	tmp = min(a[3],b[3]);
	res += 9*tmp;
	a[3] -= tmp;
	b[3] -= tmp;
	tmp = min(a[3],min(b[1],b[2]));
	res += 9*tmp;
	a[3] -= tmp;
	b[2] -= tmp;
	b[1] -= tmp;
	tmp = min(a[3],min(a[1],b[2]/2));
	res += 12*tmp;
	a[3] -= tmp;
	a[1] -= tmp;
	b[2] -= tmp*2;
	tmp = min(a[3],b[1]/3);
	res += 9*tmp;
	a[3] -= tmp;
	b[1] -= tmp*3;
	tmp = min(a[3]/2,b[2]/3);
	res += 24*tmp;
	a[3] -= tmp*2;
	b[2] -= tmp*3;
	//b[3]
	tmp = min(b[3],a[3]);
	res += 9*tmp;
	b[3] -= tmp;
	a[3] -= tmp;
	tmp = min(b[3],min(a[1],a[2]));
	res += 9*tmp;
	b[3] -= tmp;
	a[2] -= tmp;
	a[1] -= tmp;
	tmp = min(b[3],min(b[1],a[2]/2));
	res += 12*tmp;
	b[3] -= tmp;
	b[1] -= tmp;
	a[2] -= tmp*2;
	tmp = min(b[3],a[1]/3);
	res += 9*tmp;
	b[3] -= tmp;
	a[1] -= tmp*3;
	tmp = min(b[3]/2,a[2]/3);
	res += 24*tmp;
	b[3] -= tmp*2;
	a[2] -= tmp*3;
	//a[2]
	tmp = min(a[2],b[2]);
	res += 4*tmp;
	a[2] -= tmp;
	b[2] -= tmp;
	tmp = min(a[2],b[1]/2);
	res += 4*tmp;
	a[2] -= tmp;
	b[1] -= tmp*2;
	//b[2]
	tmp = min(b[2],a[2]);
	res += 4*tmp;
	b[2] -= tmp;
	a[2] -= tmp;
	tmp = min(b[2],a[1]/2);
	res += 4*tmp;
	b[2] -= tmp;
	a[1] -= tmp*2;
	
	cout << res+a[1];
	
	
	return 0;
}
