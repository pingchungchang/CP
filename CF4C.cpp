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
	map<string,int> mp;
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(!mp.count(s)){
			mp[s] = 1;
			cout<<"OK\n";
		}
		else{
			cout<<s<<mp[s]<<"\n";
			mp[s]++;
		}
	}
	return 0;
}

