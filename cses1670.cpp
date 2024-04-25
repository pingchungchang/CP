#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int s;
unordered_map<int,int> mp;
vector<pii> mv;
queue<int> q;
int pw[10];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 0;i<3;i++){
		for(int j = 0;j<2;j++){
			mv.push_back({i*3+j,i*3+j+1});
			mv.push_back({j*3+i,j*3+i+3});
		}
	}
	pw[0] = 1;
	for(int i = 1;i<10;i++)pw[i] = pw[i-1]*10;
	for(int i = 0;i<9;i++){
		int c;
		cin>>c;
		s = s*10+c;
	}
	mp[s] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		int dis = mp[now];
		q.pop();
		for(auto &i:mv){
			int ta = now/pw[i.fs]%10,tb = now/pw[i.sc]%10;
			now -= ta*pw[i.fs]+tb*pw[i.sc];
			now += tb*pw[i.fs]+ta*pw[i.sc];
			if(mp.find(now) == mp.end()){
				mp[now] = dis+1;
				q.push(now);
			}
			now -= tb*pw[i.fs]+ta*pw[i.sc];
			now += ta*pw[i.fs]+tb*pw[i.sc];
		}
	}
	cout<<mp[123456789];
}
