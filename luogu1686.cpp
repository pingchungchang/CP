#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 250005;
int lans,sans,eans;
set<pii> row[mxn*2],col[mxn*2];
int n;
string s;
char dir;

inline bool check(pii p,int id){
	auto it = row[p.fs].lower_bound(make_pair(p.sc,-1));
	if(it != row[p.fs].end()){
		int len = it->fs-p.sc;
		if(len < lans){
			lans = len;
			sans = it->sc;
			eans = id;
		}
		else if(len == lans){
			if(sans == it->sc)eans = min(eans,id);
		}
	}
	if(it != st.begin()){
		it--;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	s = "#"+s;
	pii now = {0,0};
	add(now,0);
	lans = 1e9;
	for(int i = 1;i<=n;i++){
		if(s[i] == 'E')now.fs++;
		else if(s[i] == 'W')now.fs--;
		else if(s[i] == 'N')now.sc++;
		else now.sc--;
		check(now,i);
		add(now,i);
	}
	cout<<lans<<' '<<sans<<' '<<eans<<' '<<dir;
}
