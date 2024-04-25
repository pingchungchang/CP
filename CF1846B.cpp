#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<vector<pii>> win;

void solve(){
	string s[3];
	for(auto &i:s)cin>>i;
	for(auto &i:win){
		if(s[i[0].fs][i[0].sc] == s[i[1].fs][i[1].sc] && s[i[1].fs][i[1].sc] == s[i[2].fs][i[2].sc]){
			if(s[i[0].fs][i[0].sc] == '.')continue;
			cout<<s[i[0].fs][i[0].sc]<<'\n';
			return;
		}
	}
	cout<<"DRAW\n";
	return;

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 0;i<3;i++){
		win.push_back({make_pair(i,0),make_pair(i,1),make_pair(i,2)});
		win.push_back({make_pair(0,i),make_pair(1,i),make_pair(2,i)});
	}
	win.push_back({make_pair(0,0),make_pair(1,1),make_pair(2,2)});
	win.push_back({make_pair(2,0),make_pair(1,1),make_pair(0,2)});
	int t;cin>>t;
	while(t--)solve();
}
