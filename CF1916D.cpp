#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	if(n == 1){
		cout<<"1\n";
		return;
	}
	vector<string> v;
	v.push_back("196"s+string(n-3,'0'));
	for(int i = 0;i*2+3<=n;i++){
		string tmp = "9"s+string(i,'0')+"6"+string(i,'0')+"1"+string(n-i*2-3,'0');
		v.push_back(tmp);
		tmp = "1"s+string(i,'0')+"6"+string(i,'0')+"9"+string(n-i*2-3,'0');
		v.push_back(tmp);
	}
	for(auto &i:v)cout<<i<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
