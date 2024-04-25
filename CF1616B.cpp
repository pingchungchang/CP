#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	int p = -1;
	cin>>n>>s;
	for(int i = 0;i<n-1;i++){
		if(s[i]<=s[i+1]){
			p = i;
			break;
		}
	}
	string ans;
	if(p>=0){
		ans += s.substr(0,p+1);
		cout<<ans;
		reverse(ans.begin(),ans.end());
		cout<<ans<<'\n';
	}
	else{
		cout<<s;
		reverse(s.begin(),s.end());
		cout<<s<<'\n';
	}
	
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
