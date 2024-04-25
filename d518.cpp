#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int n;
void solve(){
	map<string,int> mp;
	while(n--){
		string s;
		cin>>s;
		if(mp.find(s) == mp.end()){
			cout<<"New! "<<mp.size()+1<<'\n';
			mp[s] = mp.size()+1;
		}
		else cout<<"Old! "<<mp[s]<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
