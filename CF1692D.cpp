#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int ans[1440];
void solve(){
	string s;
	int t;
	cin>>s>>t;
	int now = stoi(s.substr(0,2))*60+stoi(s.substr(3,2));
	set<int> st;
	int returns= 0;
	while(st.find(now) == st.end()){
		returns += ans[now];
		st.insert(now);
		now += t;
		now %= 1440;
	}
	cout<<returns<<'\n';
	return;
}
int main(){
	io
	for(int i = 0;i<1440;i++){
		int h = i/60;
		int m = i%60;
		string sh = to_string(h);
		string sm = to_string(m);
		if(sh.size() != 2)sh = "0"+sh;
		if(sm.size() != 2)sm = "0"+sm;
		string now = sh+sm;
		string tmp = now;
		reverse(tmp.begin(),tmp.end());
		if(now == tmp)ans[i] = 1;
	}
	int t;
	cin>>t;
	while(t--)solve();
}

