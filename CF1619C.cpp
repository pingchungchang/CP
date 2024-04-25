#include <bits/stdc++.h>
using namespace std;


void solve(){
	string a,s;
	cin>>a>>s;
	if(a.size()>s.size()){
		cout<<-1<<'\n';
		return;
	}
	int p = s.size()-1;
	string ans;
	for(int i = a.size()-1;i>=0;i--){
		if(p<0){
			cout<<-1<<'\n';
			return;
		}
		if(a[i]<=s[p]){
			ans = (char)(s[p]-a[i]+'0')+ans;
			p--;
		}
		else{
			if(p>=1&&s[p-1] == '1'){
				ans = (char)(-(int)(a[i]-s[p])+10+'0')+ans;
				p-=2;				
			}
			else{
				cout<<-1<<'\n';
				return;
			}
		}
	}
	if(p >=0){
		ans = s.substr(0,p+1)+ans;
	}
	cout<<stoll(ans)<<'\n';
	
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
	return 0;
} 


