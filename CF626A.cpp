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
	string s;
	cin>>n>>s;
	map<pii,int> mp;
	mp[make_pair(0,0)] = 1;
	int ans = 0;
	pii now = {0,0};
	for(auto &i:s){
		if(i == 'U')now.fs++;
		else if(i == 'D')now.fs--;
		else if(i == 'L')now.sc--;
		else now.sc++;
		ans += mp[now];
		mp[now]++;
	}
	cout<<ans;
}
