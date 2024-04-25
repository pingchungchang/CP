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
	ll n,m,q;
	cin>>n>>m>>q;
	vector<string> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	pii pos = {0,0};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(v[i][j] == '*')pos.fs++;
		}
	}
	int total = pos.fs;
	pos.sc = pos.fs/n;
	pos.fs %= n;
	int cnt = 0;
	bool flag = false;
	for(int i = 0;i<m;i++){
		if(flag)break;
		for(int j= 0;j<n;j++){
			if(pos.fs == j&&pos.sc == i){
				flag = true;
				break;
			}
			if(v[j][i] == '*')cnt++;
		}
	}
	while(q--){
//		cout<<cnt<<'\n';
		int r,c;
		cin>>r>>c;
		r--,c--;
		if(v[r][c] == '.'){
			total++;
			if(v[pos.fs][pos.sc] == '*')cnt++;
			pos.fs++;
			pos.sc += pos.fs/n;
			pos.fs %= n;
			if(pos.sc>c||(pos.sc == c&&pos.fs>r))cnt++;
			v[r][c] = '*';
		}
		else{
			total--;
			pos.fs--;
			if(pos.fs<0){
				pos.fs += n;
				pos.sc--;
			}
			if(v[pos.fs][pos.sc] == '*')cnt--;
			if(pos.sc>c||(pos.sc == c&&pos.fs>r))cnt--;
			v[r][c] = '.';
		}
		cout<<total-cnt<<'\n';
	}
	return 0;
}

