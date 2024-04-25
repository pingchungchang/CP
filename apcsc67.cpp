#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int m;
	cin>>m;
	queue<int> q;
	while(m--){
		int t;
		cin>>t;
		if(t == 1){
			int n;
			cin>>n;
			q.push(n);
		}
		else if(t == 2){
			if(q.empty()){
				cout<<"QQ\n";
			}
			else q.pop();
		}
		else if(t == 3){
			if(q.empty())cout<<"QQ\n";
			else cout<<q.front()<<'\n';
		}
		else cout<<q.size()<<'\n';
	}
	return 0;
}

