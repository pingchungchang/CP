#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;
stack<int> st;
queue<int> ans;

void solve(){
	int t;
	while(1){
		for(int i =0;i<n;i++){
			cin>>t;
			if(t == 0){
				cout<<'\n';
				while(!ans.empty())ans.pop();
				return;
			}
			ans.push(t);
		}
		for(int i = 1;i<=n;i++)q.push(i);
		while(!q.empty()){
			if(q.front() == ans.front()){
				ans.pop();
				q.pop();
			}
			else if(!st.empty()&&st.top() == ans.front()){
				ans.pop();
				st.pop();
			}
			else{
				st.push(q.front());
				q.pop();
			}
		}
		while(!st.empty()&&!ans.empty()&&st.top() == ans.front()){
			st.pop();
			ans.pop();
		}
		if(ans.empty())cout<<"Yes\n";
		else cout<<"No\n";
		while(!st.empty())st.pop();
		while(!q.empty())q.pop();
		while(!ans.empty())ans.pop();
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		if(!n)return 0;
		solve();
	}
}
