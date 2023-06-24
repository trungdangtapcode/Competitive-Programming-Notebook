#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int t[100005];

long long int p = 1e9+3, base = 31, hashS[100005], powBase[100005];

long long int getHashS(int i, int j){
	return (hashS[j]-hashS[i-1]*powBase[j-i+1]+p*p)%p;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	
	//ifstream fi("input.inp");
	
	
	cin >> s;
	n = s.length();
	s = " " + s;
	
	hashS[0] = 0; powBase[0] = 1;
	for (int i = 1; i <= n; i++){
		powBase[i] = (powBase[i-1]*base)%p;
		hashS[i] = (hashS[i-1]*base+s[i]-'a'+1)%p;
	}
		
	//cout << getHashS(1,3) << " " << getHashS(4,6);
	//cout << getHashS(1,1) << " " << getHashS(3,3) << endl;
	memset(t,0,sizeof(t));
	//t[n] = 1;
	for (int i = 1; i <= n; i++){
		//if (getHashS(1,i)==getHashS(n-i+1,n)) t[i] = t[i+1] + 1; else t[i] = t[i+1];
		int l = 1, h = n, m, res = 0;
		while (l<=h){
			m = (l+h)/2;
			//cout << "   " << l << " " << h << " " << m << endl;
			if (getHashS(1,m)==getHashS(i,i+m-1)){
				res = m;
				l = m+1;
			} else {
				h = m-1;
			}
		}
		//cout << i << " " <<res << endl;
		t[res]++;
	}
	t[n+1] = 0;
	for (int i = n; i >= 1; i--) t[i] += t[i+1]; 
	
	for (int i = 1; i <= n; i++) cout << t[i] << " ";
	//for (int i = 1; i <= n; i++) cout << i << " ->"<< t[i] << endl;
	
	return 0;
}
