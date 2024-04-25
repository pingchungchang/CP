#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tiii tuple<int,int,int>


const int mxn = 2e5+10;
int n,K;
string s;
string ans;
bitset<mxn> done;

inline int add(int p,int d){
	p += d;
	if(p<0)p += n;
	if(p>=n)p -= n;
	return p;
}

bool check(char tar,int pos,int t){
	if(t&1)return s[pos] != tar;
	else return s[pos] == tar;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>K;
	cin>>s;
	ans = s;
	queue<tiii> q;
	for(int i = 1;i<n;i++){
		if(s[i] == s[i-1]){
			q.push(make_tuple(i-1,-1,0));
			q.push(make_tuple(i,1,0));
			done[i] = done[i-1] = 1;
		}
	}
	if(s[n-1] == s[0]){
		q.push(make_tuple(0,1,0));
		q.push(make_tuple(n-1,-1,0));
		done[0] = done[n-1] = 1;
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		int p = get<0>(now),d = get<1>(now),t = get<2>(now);
		if(t == K)continue;
		int pre = p;
		p = add(p,d);
		while(!done[p]&&check(ans[pre],p,t))p = add(p,d);
		if(done[p])continue;
		done[p] = true;
		ans[p] = ans[pre];
		q.push(make_tuple(p,d,t+1));
	}
	for(int i = 0;i<n;i++){
		if(!done[i]){
			if(K&1)ans[i] = (ans[i] == 'W'?'B':'W');
		}
	}
	cout<<ans;
}
