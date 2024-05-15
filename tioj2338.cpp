#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


vector<pii> ans;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N,M;
	cin>>N>>M;
	if((N+M-1)%2 == 1){
		for(int i = 1;i<=N;i++){
			for(int j = 1;j<=M;j++)ans.push_back(pii(i,j));
		}
	}
	else if(N&1){
		for(int i = 1;i<=N;i++){
			for(int j = 2;j<=M;j++)ans.push_back(pii(i,j));
		}
	}
	else if(M&1){
		for(int i = 2;i<=N;i++){
			for(int j = 1;j<=M;j++)ans.push_back(pii(i,j));
		}
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y]:ans)cout<<x<<' '<<y<<'\n';
	return 0;
}
