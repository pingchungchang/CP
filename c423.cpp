#include <bits/stdc++.h>
using namespace std;

int root(string s){
	int returns = 0;
	for(auto i:s){
		returns += i-'0';
	}
	if(returns<10)return returns;
	else return root(to_string(returns));
}
int main(){
	int n,r;
	cin>>n>>r;
	string s;
	cin>>s;
	set<string> ans;
	for(int i = 0;i<=n-1;i++){
		for(char j = '0';j<='9';j++){
			string now  = s.substr(0,i);
			now += j;
			now += s.substr(i,n-1-i);
			if(root(now) == r)ans.insert(now);
//			cout<<now<<endl;
		}
	}
	auto l = --ans.end();
	for(auto it = ++ans.begin();it != l;it++){
		cout<<*it<<'\n';
	}
}
