#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int n;
	cin>>n;
	map<string,ll>  mp;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		if(mp.count(s) != 0){
			cout<<"NIE"<<' '<<mp[s]<<'\n';
		}
		else {
			cout<<"TAK"<<' '<<++cnt<<'\n';
			mp[s] = cnt;	
		}
	}
}

