#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans =0;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		if(s[2]==s[3]&&s[3]==s[4]&&s[4] == s[5])ans += 2000;
		else if(s[2]==s[3]&&s[4] == s[5])ans += 1500;
		else ans += 1000;
	}
	cout<<ans<<'\n';
}
