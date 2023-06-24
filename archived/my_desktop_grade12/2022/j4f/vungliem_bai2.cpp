#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	int a1 = (n+2)/3;
	int a2 = (n+1)/3;
	int a3 = (n+0)/3;
	int b1 = (n+1)/2;
	int b2 = (n+0)/2;
	
	int fishA = a1*2 + 3*a1*(a1-1)/2 + a2*4 + 3*a2*(a2-1)/2 + a3*3 + 3*a3*(a3-1)/2;
	int fishB = b1*3 + 2*b1*(b1-1)/2 + b2*2 + 2*b2*(b2-1)/2;
	if (fishA>fishB){
		cout << "A " << fishA - fishB;
		return 0; 
	} 
	if (fishA<fishB){
		cout << "B " << fishB - fishA;
		return 0;
	}
	cout << "C " << fishA;
	
	
	
	return 0;
}
