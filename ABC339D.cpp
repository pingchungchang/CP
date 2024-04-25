#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int dist[66][66][66][66];
queue<pair<pii,pii>> q;
pii dir[] = {{-1,0},{0,1},{1,0},{0,-1}};
string arr[66];
int N;

pii mv(pii now,pii d){
	if(arr[now.fs+d.fs][now.sc+d.sc] != '#')return {now.fs+d.fs,now.sc+d.sc};
	else return now;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dist,-1,sizeof(dist));
	vector<pii> v;
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>arr[i];
		arr[i] = "#"+arr[i]+"#";
	}
	arr[0] = arr[N+1] = string(N+2,'#');
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			if(arr[i][j] == 'P'){
				v.push_back({i,j});
				arr[i][j] = '.';
			}
		}
	}
	q.push(make_pair(v[0],v[1]));
	dist[v[0].fs][v[0].sc][v[1].fs][v[1].sc] = 0;
	while(!q.empty()){
		auto tmp = q.front();
		q.pop();
		auto pa = tmp.fs,pb = tmp.sc;
		for(auto &i:dir){
			auto ta = mv(pa,i),tb = mv(pb,i);
			if(dist[ta.fs][ta.sc][tb.fs][tb.sc] == -1){
				dist[ta.fs][ta.sc][tb.fs][tb.sc] = dist[pa.fs][pa.sc][pb.fs][pb.sc]+1;
				q.push(make_pair(ta,tb));
			}
		}
	}
	int ans = 1e9;
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			if(dist[i][j][i][j] != -1)ans = min(ans,dist[i][j][i][j]);
		}
	}
	cout<<(ans>=1e8?-1:ans);
}
