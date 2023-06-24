#include <bits/stdc++.h>

using namespace std;
int n, k;
long long int a[100005], x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k;
	n = 0;
	while (cin >> x){ a[n++] = x;	};
	sort(a,a+n);
	//for (int i = 0; i < n; i++) cout << a[i] << " ";
	//n = (unique(a,a+n)-a);
	//for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	cout << a[n-1-k+1];// << " " << n;
	
	return 0;
}


//	string s;
//	cin.ignore();
//	getline(cin,s);
//	s = s + ' ';
//	n = 0;
//	int lastBlank = -1;
//	for (int i = 0; i < s.length(); i++) if (s[i]==' '){
//		a[n++] = stoll(s.substr(lastBlank+1,i-lastBlank-1));
//		lastBlank = i;
//	}



