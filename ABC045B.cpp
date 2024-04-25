#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<queue<char>> v(3);
	for(int i = 0;i<3;i++){
		string s;
		cin>>s;
		for(char c:s)v[i].push(c-'a');
	}
	int now = 0;
	while(!v[now].empty()){
		int nxt = v[now].front();
		v[now].pop();
		now = nxt;
	}
	cout<<(char)(now+'A');
	return 0;
}
