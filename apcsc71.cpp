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
	stack<int> st;
	while(m--){
		int t;
		cin>>t;
		if(t == 1){
			int k;
			cin>>k;
			st.push(k);
		}
		else if(t == 2){
			if(st.empty())cout<<"QQ\n";
			else st.pop();
		}
		else if(t == 3){
			if(st.empty())cout<<"QQ\n";
			else cout<<st.top()<<'\n';
		}
		else cout<<st.size()<<'\n';
	}
	return 0;
}

