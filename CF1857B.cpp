#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	s = "0"+s;
	int mv = s.size();
	string ans = s;
	for(int i = s.size()-1;i>=1;i--){
		if(s[i]>='5'){
			mv = i;
			if(s[i-1] != '9')s[i-1]++;
			else{
				for(int j = i-1;j>=0;j--){
					if(s[j] == '9')s[j] = '0';
					else{
						s[j]++;
						break;
					}
				}
			}
		}
		s[i] = '0';
	}
	s = ans;
	for(int i = s.size()-1;i>=mv;i--){
		if(s[i]>='5'){
			if(s[i-1] != '9')s[i-1]++;
			else{
				for(int j = i-1;j>=0;j--){
					if(s[j] == '9')s[j] = '0';
					else{
						s[j]++;
						break;
					}
				}
			}
		}
		s[i] = '0';
	}
	if(s[0] == '0')s = s.substr(1,s.size()-1);
	cout<<s<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
