#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


void solve(){
	int n,m,h,k;
	cin>>n>>m>>h>>k;
	pii now = {0,0};
	set<pii> st;
	string s;
	cin>>s;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		st.insert({a,b});
	}
	for(auto &i:s){
		if(!h){
			cout<<"No";
			return;
		}
		if(i == 'R')now.fs++;
		else if(i == 'L')now.fs--;
		else if(i == 'U')now.sc++;
		else now.sc--;
		h--;
		if(st.find(now) !=st.end()&&h<k)h = max(h,k),st.erase(now);
	}
	cout<<"Yes";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
