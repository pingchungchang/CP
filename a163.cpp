#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
int h;
int pr[10] = {};
void fh(){
	for(int i = 9;i>=0;i--){
		if(pr[i] != 0){
			h = i;
			return;
		}
	}
	h = -1;
	return;
}
void solve(){
	int n,m;
	cin>>n>>m;
	memset(pr,0,sizeof(pr));
	queue<pii> q;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		q.push(make_pair(k,i));
		pr[k]++;
	}
	fh();
	int t= 0;
	while(!q.empty()){
		fh();
		pii now = q.front();
		q.pop();
		if(h != now.f)q.push(now);
		else{
			t++;
			if(now.s == m){
				while(!q.empty())q.pop();
				cout<<t<<'\n';
				return;
			}
			else{
				pr[now.f]--;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
