#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	int n = s.size();
	sort(s.begin(),s.end());
	deque<char>pre,suf;
	for(int i = 0;i<s.size();i+=2){
		if(i+1 == s.size()){
			pre.push_back(s[i]);
			break;
		}
		if(s[i] == s[i+1]){
			pre.push_back(s[i]);
			suf.push_front(s[i]);
		}
		else{
			bool flag = false;
			int len = 0;
			for(int j = i+1;j<s.size();j++)len++,flag = (s[j] != s[i+1]?true:flag);
			if(!flag){
				for(int j = 0;j<(len+1)/2;j++)pre.push_back(s[i+1]);
				pre.push_back(s[i]);
				for(int j = (len+1)/2;j<len;j++)pre.push_back(s[i+1]);
				break;
			}
			else{
				for(int j = i+1;j<n;j++)pre.push_back(s[j]);
				pre.push_back(s[i]);
				break;
			}
		}
	}
	while(!suf.empty())pre.push_back(suf.front()),suf.pop_front();
	s = "";
	for(auto &i:pre)s+=i;
	/*
	string t = s;
	reverse(t.begin(),t.end());
	*/
	cout<<s;
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
