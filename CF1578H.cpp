#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
stack<int> st;
void solve(vector<int> &tmp){
	int pre = tmp[0];
	for(int i = 0;i<tmp.size();i++){
		if(tmp[i] == -2){
			pre = max(pre,1+tmp[i+1]);
		}
	}
	st.push(pre);
}
int main(){
	io
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '(')st.push(-1);
		else if(s[i] == '-'){
			st.push(-2);
			i++;
		}
		else{
			vector<int> tmp;
			while(!st.empty()&&st.top() != -1){
				tmp.push_back(st.top());
				st.pop();
			}
			st.pop();
			if(tmp.empty())st.push(0);
			else{
				solve(tmp);
			}
		}
	}
	vector<int> v;
	while(!st.empty()){
		v.push_back(st.top());
		st.pop();
	}
//	reverse(v.begin(),v.end());
	solve(v);
	cout<<st.top();
//	for(auto it = v.rbegin();it != v.rend();it++)cout<<*it<<' ';
}

