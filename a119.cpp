#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	queue<int> q;
	int ans = 0;
	for(auto c:s){
		if(c == '('){
			q.push('(');
		}
		else{
			if(q.empty()){
				cout<<0;
				return 0;
			}
			else{
				ans++;
				q.pop();
			}
		}
	}
	if(q.empty())cout<<ans;
	else cout<<0;
	return 0;
}
