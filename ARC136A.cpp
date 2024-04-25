#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int n;
	cin>>n;
	for(int i= 0;i<n;i++){
		char c;
		cin>>c;
		if(c == 'A')s += "BB";
		else s += c;
	}
	deque<char> dq;
	for(int i = 0;i<s.size();i++){
		if(!dq.empty()&&dq.back() == 'B'&&s[i] == 'B'){
			dq.pop_back();
			dq.push_back('A');
		}
		else dq.push_back(s[i]);
	}
	while(!dq.empty()){
		cout<<dq.front();
		dq.pop_front();
	}
}
