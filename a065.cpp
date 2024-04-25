#include <bits/stdc++.h>
using namespace std;


int main(){
	string s;
	cin>>s;
	int ans = 0;
	for(int i =0;i<s.size();i++){
		ans += (int)pow(-1,i%2)*(s[i]-'0');
	}
	cout<<abs(ans);
}
