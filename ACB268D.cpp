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

int total = 0;
int n,m;
int spare = 0;
vector<string> v;
bool flag;
set<string> st;
void dfs(int nn,string now,int nowspare){
	if(flag)return;
	now += v[nn];
	if(nn == n-1){
		if(now.size()>16||now.size()<3)return;
		if(st.find(now) == st.end()){
			cout<<now;
			flag = true;
		}
		return;
	}
	now += '_';
	dfs(nn+1,now,nowspare);
	while(nowspare>0){
		nowspare--;
		now += '_';
		dfs(nn+1,now,nowspare);
	}
	return;
}
int main(){
	flag = false;
	cin>>n>>m;
	v = vector<string>(n);
	for(auto &i:v){
		cin>>i;
		total += i.size();
	}
	sort(_all(v));
	for(int i = 0;i<m;i++){
		string in;
		cin>>in;
		st.insert(in);
	}
	spare = 16-total-n+1;
	dfs(0,"",spare);
	while(!flag&&next_permutation(_all(v))){
		dfs(0,"",spare);
	}
	if(!flag)cout<<"-1";
	return 0;
}

