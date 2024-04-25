#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


bool check(string &s,string &t){
	if(s.size() == t.size()){
		int d = 0;
		for(int i = 0;i<s.size();i++)if(s[i] != t[i])d++;
		return d<=1;
	}
	if(max(s.size(),t.size()) != min(s.size(),t.size())+1)return false;
	if(s.size()>t.size()){
		int pt = 0;
		for(int i = 0;i<s.size();i++){
			if(pt<t.size()&&t[pt] == s[i])pt++;
		}
		if(pt == t.size()&&s.size() == t.size()+1)return true;
		else return false;
	}
	else{
		int pt = 0;
		for(int i = 0;i<t.size();i++){
			if(pt<s.size()&&s[pt] == t[i])pt++;
		}
		if(pt == s.size()&&t.size() == s.size()+1)return true;
		else return false;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string t;
	cin>>n>>t;
	string arr[n];
	for(auto &i:arr)cin>>i;
	vector<int> ans;
	for(int i = 0;i<n;i++){
		if(check(t,arr[i]))ans.push_back(i+1);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
}
