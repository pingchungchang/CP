#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	set<string> ss;
	ss.insert(s);
	while(next_permutation(s.begin(),s.end())){
		if(ss.find(s) == ss.end()){
			ss.insert(s);
		}
	}
	cout<<ss.size()<<'\n';
	for(auto it = ss.begin();it != ss.end();it++){
		cout<<*it<<'\n';
	}
	return 0;
}
