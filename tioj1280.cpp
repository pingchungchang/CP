#include <bits/stdc++.h>
using namespace std;

struct node{
	pair<int,int> dir;
	pair<int,int> pos;
	node(pair<int,int> a,pair<int,int> b){
		dir = b;
		pos = a;
	}
};
int cross(pair<int,int> a,pair<int,int> b){
	return a.first*b.second-a.second*b.first;
}
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	if(n == 0){
		cout<<0<<'\n';
		return 0;
	}
	for(int i = 0;i<n;i++)cin>>v[i].first>>v[i].second;
	stack<node> st;
	sort(v.begin(),v.end());
	st.push(node(v[0],make_pair(0,0)));
	for(int i = 0;i<v.size();i++){
		node now = st.top();
		pair<int,int> d = make_pair(v[i].first-now.pos.first,v[i].second-now.pos.second);
		while(st.size()>1&&cross(d,now.dir)<0){
			st.pop();
			now = st.top();
			d = make_pair(v[i].first-now.pos.first,v[i].second-now.pos.second);
		}
		st.push(node(v[i],make_pair(-d.first,-d.second)));
	}
	stack<node> s2;
	s2.push(node(v[n-1],make_pair(0,0)));
	for(int i = n-1;i>=0;i--){
		node now = s2.top();
		pair<int,int> d = make_pair(v[i].first-now.pos.first,v[i].second-now.pos.second);
		while(s2.size()>1&&cross(d,now.dir)<0){
			s2.pop();
			now = s2.top();
			d = make_pair(v[i].first-now.pos.first,v[i].second-now.pos.second);
		}
		s2.push(node(v[i],make_pair(-d.first,-d.second)));		
	}
	int ans = 0;
	pair<int,int> p= st.top().pos;
	st.pop();
	while(!st.empty()){
//		cout<<st.top().pos.first<<' '<<st.top().pos.second<<'\n';
		ans += p.first*st.top().pos.second-p.second*st.top().pos.first;
		p = st.top().pos;
		st.pop();
	}
//	cout<<endl;
	while(!s2.empty()){
//		cout<<s2.top().pos.first<<' '<<s2.top().pos.second<<'\n';
		ans += p.first*s2.top().pos.second-p.second*s2.top().pos.first;
		p = s2.top().pos;
		s2.pop();
	}
	cout<<(abs(ans)+1)/2;
}
