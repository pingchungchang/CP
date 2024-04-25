#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bool isp(int k){
	for(int i = 2;1LL*i*i<=k;i++){
		if(k%i == 0)return false;
	}
	return true;
}

void solve(string s = ""){
	if(s.empty())cin>>s;
	for(int i = 1;i<=9;i++)s += '0'+i;
	for(int i = 0;i<s.size();i++){
		for(int j = i+1;j<s.size();j++){
			int tmp = (s[i]-'0')*10+s[j]-'0';
			if(isp(tmp)){
				cout<<tmp<<'\n';
				return;
			}
		}
	}
	assert(false);
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
