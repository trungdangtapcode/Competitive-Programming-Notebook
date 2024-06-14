#include <bits/stdc++.h>
using namespace std;
string s;
deque<char> d;
int main(){
    cin >> s;
    for (char c: s){
        d.push_back(c);
        d.push_back(d.front());
        d.pop_front();
    }
    while (d.size()){
        cout << d.front();
        d.pop_front();
    }

    return 0;
}

