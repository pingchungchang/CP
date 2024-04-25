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
	map<char,int> mp;
	for(int i = 0;i<3;i++){
		char c;
		cin>>c;
		mp[c]++;
	}
	for(auto i:mp){
		if(i.sc == 1){
			cout<<i.fs;
			return 0;
		}
	}
	cout<<-1;;
}

