#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1e6+10;
int n;
string s;
int cnt[26];

bool check(){
	for(auto &i:cnt)if(!i)return false;
	return true;
}

void solve(){
	if(!n)exit(0);
	memset(cnt,0,sizeof(cnt));
	cin>>s;
	s = "#"+s;
	int pt = 0;
	pii ans = {mxn,mxn*2+1};
	for(int i = 1;i<=n;i++){
		cnt[s[i]-'a']++;
		while(pt<i){
			cnt[s[pt+1]-'a']--;
			if(check())pt++;
			else{
				cnt[s[pt+1]-'a']++;
				break;
			}
		}
		if(check()){
			if(ans.sc-ans.fs+1>i-pt)ans = {pt+1,i};
		}
	}
	if(ans.fs>n)cout<<"not found\n";
	else cout<<s.substr(ans.fs,ans.sc-ans.fs+1)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
	return 0;
}
