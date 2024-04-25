#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	while(cin>>n>>k){
		queue<string> q;
		for(int i =0;i<n;i++){
			string s;
			cin>>s;
			q.push(s);
			if(q.size()>k)q.pop();
		}
		cout<<q.front()<<'\n';
	}
}
