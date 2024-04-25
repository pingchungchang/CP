#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int ans = INT_MAX;
	
	int ev = 0,od = 0,tmp = 0;
	for(int i = 0;i<n;i++){
		if(a[i] == b[i]){
			tmp++;
			if(a[i] == '0')ev++;
			else od++;
		}
	}//moved odd times
	if((tmp&1)==1&&od-ev>=0&&od-ev<2)ans = tmp;
	
	tmp = 0,od = 0,ev =0;
	for(int i = 0;i<n;i++){
		if(a[i] != b[i]){
			tmp++;
			if(a[i] != '0')od++;
			else ev++;
		}
	}
	if((tmp&1) == 0&&od-ev>=0&&od-ev<2)ans = min(ans,tmp);
	
	if(ans == INT_MAX)cout<<-1<<'\n';
	else cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
