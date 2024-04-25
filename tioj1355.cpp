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

int cnt = 0;
void dfs(int n,int s,int e){
	if(n == 0)return;
	dfs(n-1,s,6-s-e);
	cout<<"#"<<++cnt<<" : move the dish from #"<<s<<" to #"<<e<<"\n";
	dfs(n-1,6-s-e,e);
	return;
}
int main(){
	io
	int n;
	cin>>n;
	dfs(n,1,3);
}

