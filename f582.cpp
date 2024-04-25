#include <bits/stdc++.h>
using namespace std;
struct node{
	string s;
	vector<int> child;
	node(string k){
		s = k;
	}
};
int n,m;
vector<node> tree;
int main(){
	cin>>n>>m;
	int root = -1;
	tree = vector<node>(n,node(""));
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		if(a == b){
			root = a;
			continue;
		}
		tree[b].child.push_back(a)
	}
}
