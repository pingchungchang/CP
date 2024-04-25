#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	vector<int> childs;
	node(){
		val = -1;
	}
};

vector<node> treee;
void dfs(int now){
//	cout<<now<<' ';
	if(treee[now].val != -1) return;
	if(treee[now].childs.size()==0){
		treee[now].val = 0;
		return;
	}
	treee[now].val = 0;
	for(int i = 0;i<treee[now].childs.size();i++){
		dfs(treee[now].childs[i]);
		int c= treee[now].childs[i];
		treee[now].val += treee[c].val+1;
	}
	return;
}
int main(){
	int n;
	cin>>n;
	treee = vector<node>(n);
	for(int i = 1;i<n;i++){
		int k;
		cin>>k;
		k--;
		treee[k].childs.push_back(i);
	}
	for(int i = 0;i<n;i++){
		if(treee[i].val == -1){
			dfs(i);
//			cout<<endl;
		}
	}
	for(int i = 0;i<n;i++)cout<<treee[i].val<<' ';
}
