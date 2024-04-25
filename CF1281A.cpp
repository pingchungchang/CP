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
	while(s.size()<10)s = "#"+s;
	if(s.substr(s.size()-2,2) == "po")cout<<"FILIPINO\n";
	else if(s.substr(s.size()-5,5) == "mnida")cout<<"KOREAN\n";
	else cout<<"JAPANESE\n";
	return;
}
int main(){
	//wwwwwwwww
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
