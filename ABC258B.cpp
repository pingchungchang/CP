#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

string ans = "";
vector<vector<char>> v;
int n;
pii dir[] = {{1,0},{1,1},{-1,0},{-1,-1},{0,-1},{0,1},{1,-1},{-1,1}};

void f(int r,int c){
	pii now = make_pair(r,c);
	for(auto i:dir){
		string tmp;
		now.fs += i.fs;
		now.sc += i.sc;
		if(now.fs>=n)now.fs -= n;
		if(now.fs<0)now.fs += n;
		if(now.sc>=n)now.sc -= n;
		if(now.sc<0)now.sc += n;
		tmp += v[now.fs][now.sc];
		while(now.fs != r||now.sc != c){
			now.fs += i.fs;
			now.sc += i.sc;
			if(now.fs>=n)now.fs -= n;
			if(now.fs<0)now.fs += n;
			if(now.sc>=n)now.sc -= n;
			if(now.sc<0)now.sc += n;
			tmp += v[now.fs][now.sc];
		}
		ans  = max(ans,tmp);
	}
	return;
}
int main(){
	cin>>n;
	v = vector<vector<char>>(n,vector<char>(n,'('));
	for(int i= 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>v[i][j];
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			f(i,j);
		}
	}
	cout<<ans;
}

