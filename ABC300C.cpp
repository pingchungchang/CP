#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

pii dir[] = {{1,1},{1,-1},{-1,1},{-1,-1}};

void solve(){
	int h,w;
	cin>>h>>w;
	int n = min(h,w);
	int ans[n+1] = {};
	vector<string> v;
	v.push_back(string(w+3,'.'));
	for(int i = 0;i<h;i++){
		string in;
		cin>>in;
		in = "."+in+".";
		v.push_back(in);
	}
	v.push_back(v[0]);
	for(int i = 1;i<=h;i++){
		for(int j = 1;j<=w;j++){
			int c = 0;
			for(auto &k:dir){
				if(v[k.fs+i][k.sc+j] == '#')c++;
			}
			if(c != 4)continue;
			c = 0;
			pii now = {i,j};
			while(v[now.fs][now.sc] == '#')c++,now.fs++,now.sc++;
			ans[c-1]++;
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=  1;
	while(t--)solve();
}
