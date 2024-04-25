#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int f(string s,char c){
	int p1 = 0,p2 = s.size()-1;
	int ans = 0;
	while(p1 < p2){
		if(s[p1] == s[p2]){
			p1++;
			p2--;
		}
		else if(s[p1] == c){
			p1++;
			ans++;
		}
		else if(s[p2] == c){
			p2--;
			ans++;
		}
		else{
			return INT_MAX;
		}
	}
	return ans;
}
void solve(){
	int n;
	string s;
	cin>>n>>s;
	int ans = INT_MAX;
	for(int i = 0;i<26;i++){
		ans = min(ans,f(s,'a'+i));
	}
	if(ans == INT_MAX){
		cout<<-1<<'\n';
	}
	else cout<<ans<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

