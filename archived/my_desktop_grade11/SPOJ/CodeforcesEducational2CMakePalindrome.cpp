#include <bits/stdc++.h>

using namespace std;
int n, cnt[26];
string s;

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) cnt[s[i]-'a']++;
	for (int i = 0, j = 25;;){
		while (i<26&&cnt[i]%2==0) i++; //tim nho le
		while (j>=0&&cnt[j]%2==0) j--; //tim lon le
//		cout << (char)(i+'a') << " " << (char)(j+'a') << endl;
		if (i>=j) break; //end or that's odd
		cnt[j]--; //giam
		cnt[i]++; //tang. uu tien vi thu tu tu dien
	}
	deque<char> res;
	for (int i = 25; i >= 0; i--) if (cnt[i]%2==1) res.push_back(i+'a');
	for (int i = 25; i >= 0; i--) {
		while (cnt[i]>1) res.push_back(i+'a'), res.push_front(i+'a'), cnt[i] -= 2;
	}
	s = "";
	while (!res.empty()) s.push_back(res.front()), res.pop_front();
	cout << s;
		
	return 0;
}
