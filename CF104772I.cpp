#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

vector<int> gray[11];
int re;

int n;

inline void ask(int l,int r){
	cout<<l+1<<' '<<r+1<<endl;
	cin>>re;
	if(re == n)exit(0);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	gray[0].push_back(0);
	gray[0].push_back(1);
	for(int i = 1;i<=10;i++){
		auto tmp = gray[i-1];
		gray[i] = gray[i-1];
		for(auto &j:tmp)j ^= (1<<i);
		while(!tmp.empty()){
			gray[i].push_back(tmp.back());
			tmp.pop_back();
		}
	}
	for(int i = 0;i<=10;i++){
		//cout<<i<<":";for(auto &j:gray[i])cout<<j<<',';cout<<endl;
	}
	cin>>n;
	cin>>re;
	if(re == n)exit(0);
	for(int i = 0;i<n;i++){
		pii big = {re,0};
		for(int j = 1;j<gray[n-1-i].size();j++){
			int b = gray[n-1-i][j]^gray[n-1-i][j-1];
			//cout<<gray[n-1-i][j]<<endl;
			ask(i,i+__lg(b));
			big = max(big,make_pair(re,gray[n-1-i][j]));
		}
		int now = gray[n-1-i].back();
		//cout<<i<<":"<<big.fs<<' '<<big.sc<<' '<<now<<endl;
		for(int j = 0;j<n;j++){
			if(((1<<j)&now) != ((1<<j)&big.sc))ask(i,i+j);
		}
	}
	exit(0);
}
