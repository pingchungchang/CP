#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	map<string,int> mp;
	while(n--){
		string s;
		cin>>s;
		mp[s]++;
	}
	string ans = mp.begin()->fs;
	for(auto &i:mp){
		if(i.sc>mp[ans])ans = i.fs;
	}
	cout<<ans;
}
