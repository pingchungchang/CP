#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
int lpf[mxn];
int dist[mxn],pre[mxn];
vector<int> primes;
vector<int> paths[mxn];
int ans;

void BFS(int st){
	memset(dist,-1,sizeof(dist));
	memset(pre,-1,sizeof(pre));
	dist[st] = 0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(nxt == pre[now])continue;
			if(dist[nxt] == -1){
				dist[nxt] = dist[now]+1;
				pre[nxt] = now;
				q.push(nxt);
			}
			else{
				ans = min(ans,dist[now]+dist[nxt]+1);
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	primes.push_back(1);
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			primes.push_back(i);
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		vector<int> fac;
		while(k != 1){
			if(fac.empty()||fac.back() != lpf[k])fac.push_back(lpf[k]);
			else fac.pop_back();
			k /= lpf[k];
		}
		if(fac.empty()){
			cout<<"1\n";
			return 0;
		}
		if(fac.size() == 1)fac.push_back(1);
		for(auto &j:fac)j = lower_bound(primes.begin(),primes.end(),j)-primes.begin();
		paths[fac[0]].push_back(fac[1]);
		paths[fac[1]].push_back(fac[0]);
	}
	ans = mxn;
	for(int i = 0;i<primes.size()&&primes[i]<=mxn/primes[i];i++){
		BFS(i);
	}
	cout<<(ans<mxn?ans:-1);
}
