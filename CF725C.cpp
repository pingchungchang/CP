#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
pair<int,int> dir[4] = {make_pair(0,-1),make_pair(1,0),make_pair(0,1),make_pair(-1,0)};
int main(){
	string s;
	cin>>s;
	vector<string> ans(2,string(13,'#'));
	map<char,int> mp;
	pair<int,int> use;
	for(int i = 0;i<27;i++){
		char now = s[i];
		if(mp.count(now) == 0)mp[now] = i;
		else use = make_pair(mp[now],i);
	}
	s += s;
	int dif = use.sc-use.fs-1;
	if(dif == 0){
		cout<<"Impossible\n";
		return 0;
	}
	ans[0][dif/2] = s[use.fs];
	pair<int,int> pos = make_pair(0,dif/2);
	for(int i = use.fs+1;i<use.fs+27;i++){
		if(s[i] == s[use.fs])continue;
		for(auto p:dir){
			if(pos.fs+p.fs>=0&&pos.fs+p.fs<=1&&pos.sc+p.sc<13&&pos.sc+p.sc>=0&&ans[p.fs+pos.fs][p.sc+pos.sc] == '#'){
				pos.fs += p.fs;
				pos.sc += p.sc;
				break;
			}
		}
		ans[pos.fs][pos.sc] = s[i];
	}
	cout<<ans[0]<<'\n'<<ans[1];
	return 0;
}

