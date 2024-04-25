#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e7;

int a,N;
string s;
int dist[mxn];

ll f(ll now){
	string s = to_string(now);
	if(s.back() == '0')return now;
	s.insert(s.begin(),s.back());
	s.pop_back();
	return stoll(s);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>N;
	queue<ll> q;
	memset(dist,-1,sizeof(dist));
	dist[1] = 0;
	q.push(1);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(now*a<mxn&&dist[now*a] == -1){
			dist[now*a] = dist[now]+1;
			q.push(now*a);
		}
		if(dist[f(now)] == -1){
			dist[f(now)] = dist[now]+1;
			q.push(f(now));
		}
	}
	cout<<dist[N];
}
