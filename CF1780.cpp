#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> odd,ev;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(k&1)odd.push_back(i+1);
		else ev.push_back(i+1);
	}
	if(ev.size() >=2&&odd.size()>=1)cout<<"YES\n"<<odd[0]<<' '<<ev[0]<<' '<<ev[1]<<'\n';
	else if(odd.size()>=3)cout<<"YES\n"<<odd[0]<<' '<<odd[1]<<' '<<odd[2]<<'\n';
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
