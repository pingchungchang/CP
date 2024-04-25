#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int N;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	N--;
	int M = __lg(N)+1;
	vector<vector<int>> v;
	for(int i = 0;i<M;i++){
		v.push_back(vector<int>());
		for(int j = 0;j<=N;j++){
			if(j&(1<<i))v.back().push_back(j);
		}
	}
	cout<<M<<endl;
	for(auto &i:v){
		cout<<i.size()<<' ';
		for(auto &j:i)cout<<j+1<<' ';cout<<endl;
	}
	string s;
	cin>>s;
	int ans = 0;
	for(int i = 0;i<M;i++){
		if(s[i]=='1')ans|=1<<i;
	}
	cout<<ans+1<<endl;
}
