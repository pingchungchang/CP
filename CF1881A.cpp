#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

bool check(string &a,string &b){
	for(int i = 0;i+b.size()<=a.size();i++){
		if(a.substr(i,b.size()) == b)return true;
	}
	return false;
}

void solve(){
	int n,m;
	string a,b;
	cin>>n>>m;
	cin>>a>>b;
	int ans = 0;
	while(!check(a,b)&&a.size()<200)a+=a,ans++;
	if(!check(a,b)){
		cout<<"-1\n";
	}
	else cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
