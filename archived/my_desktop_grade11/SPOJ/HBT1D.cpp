#include <bits/stdc++.h>

using namespace std;

long long int p = 1e18;
string f[3000005];
map <string, bool> m;

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++){
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++){
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	f[1] = "1";
	f[2] = "1";
	m["1"] = true; 
	for (int i = 3; i <= 10000; i++) f[i] =  findSum(f[i-1],f[i-2]), m[f[i]] = true;// cout << i << endl;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << (m[s]?"Yes":"No") << endl;
	}
	
	return 0;
}
