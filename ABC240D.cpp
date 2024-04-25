#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int total = 0;
	stack<pair<int,int>> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(st.empty()||st.top().first != k){
			st.push(make_pair(k,1));
		}
		else{
			st.top().second++;
		}
		total ++;
		if(!st.empty()&&st.top().second == st.top().first){
			total -= st.top().second;
			st.pop();
		}
		cout<<total<<'\n';
	}
	
}
