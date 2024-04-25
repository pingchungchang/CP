#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	cin>>m>>n;
	queue<string> q;
	set<string> s;
	int ans = 0;
	for(int i = 0;i<n;i++){
		string k;
		cin>>k;
		q.push(k);
		if(s.find(k) == s.end())s.insert(k);
		else{
			while(q.front()!= k){
				s.erase(q.front());
				q.pop();
			}
			q.pop();
		}
		if(s.size()>=m)ans++;
	}
	cout<<ans;
}
