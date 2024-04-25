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
	string s;
	cin>>s;
	string tmp = "#";
	for(auto &i:s){
		tmp += i;
		tmp += '#';
	}
	pii ans = make_pair(0,0);
	int len = 0;
	int n = tmp.size();
	for(int i = 1;i<tmp.size();i++){
		int pt = 0;
		while(i+pt<n&&i-pt>=0&&tmp[i+pt] == tmp[i-pt])pt++;
		pt--;
		int cnt = 0;
		for(int j = i-pt;j<=i+pt;j++){
			if(tmp[j] != '#')cnt++;
		}
		if(cnt>len){
			len = cnt;
			cnt = 0;
			for(int j = 0;j<=i-pt;j++)if(tmp[j] != '#')cnt++;
			ans.fs = cnt;
			cnt = 0;
			for(int j = 0;j<=i+pt;j++)if(tmp[j] != '#')cnt++;
			ans.sc = cnt;
			if(tmp[i-pt] == '#')ans.fs++;
		}
	}
	cout<<len<<'\n'<<ans.fs<<' '<<ans.sc<<'\n';
	return 0;
}

