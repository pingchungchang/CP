#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,less<int>> high;
priority_queue<int,vector<int>,greater<int>> low;
multiset<int> st;
void makehigh(){
	while(!high.empty()&&st.find(high.top()) == st.end())high.pop();
	if(!high.empty()){
		st.erase(st.find(high.top()));
		cout<<high.top()<<' ';
		high.pop();
	}
	return;
}
void makelow(){
	while(!low.empty()&&st.find(low.top()) == st.end())low.pop();
	if(!low.empty()){
		st.erase(st.find(low.top()));
		cout<<low.top()<<' ';
		low.pop();
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	while(cin>>t){
		if(t == 0)return 0;
		if(t>0){
			high.push(t);
			low.push(t);
			st.insert(t);
		}
		else if(t == -1){
			makelow();
		}
		else makehigh();
	}
}
