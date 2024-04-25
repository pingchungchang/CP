#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	if(t.substr(0,n) == s&&t.substr(m-n,n) == s)cout<<0;
	else if(t.substr(0,n) == s)cout<<1;
	else if(t.substr(m-n,n) == s)cout<<2;
	else cout<<3;
}
