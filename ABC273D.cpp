#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	map<ll,vector<ll>> row,col;
	int n;
	ll h,w;
	pll now;
	cin>>h>>w>>now.fs>>now.sc;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		row[a].push_back(b);
		col[b].push_back(a);
	}
	for(auto &i:row)sort(_all(i.sc));
	for(auto &i:col)sort(_all(i.sc));
	int q;
	cin>>q;
	while(q--){
		char dir;
		ll step;
		cin>>dir>>step;
		if(dir == 'L'){
			
			auto pos = lower_bound(_all(row[now.fs]),now.sc)-row[now.fs].begin();
			pos--;
			if(pos<0){
				now.sc -= step;
				now.sc = max(1LL,now.sc);
			}
			else{
				now.sc -= step;
				now.sc = max(now.sc,row[now.fs][pos]+1);
			}
		}
		else if(dir == 'R'){
			auto pos = upper_bound(_all(row[now.fs]),now.sc)-row[now.fs].begin();
			if(pos>=row[now.fs].size()){
				now.sc += step;
				now.sc = min(now.sc,w);
			}
			else{
				now.sc += step;
				now.sc = min(now.sc,row[now.fs][pos]-1);
			}
		}
		else if(dir == 'U'){
			auto pos = lower_bound(_all(col[now.sc]),now.fs)-col[now.sc].begin();
			pos--;
			if(pos<0){
				now.fs -= step;
				now.fs = max(now.fs,1LL);
			}
			else{
				now.fs -= step;
				now.fs = max(now.fs,col[now.sc][pos]+1);
			}
		}
		else{
			auto pos = lower_bound(_all(col[now.sc]),now.fs)-col[now.sc].begin();
			if(pos>=col[now.sc].size()){
				now.fs += step;
				now.fs = min(now.fs,h);
			}
			else{
				now.fs += step;
				now.fs = min(now.fs,col[now.sc][pos]-1);
			}
		}
		cout<<now.fs<<' '<<now.sc<<'\n';
	}
	return 0;
}

