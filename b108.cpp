#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int parent;
	vector<int> childs;
	node(){
		parent = -1;
	}
}node;
typedef struct container{
	int val;
	int dest;
	container(int d,int v){
		val = v;
		dest = d;
	}
}container;

vector<node> tree;
int n;
int bfs(int root,int& dist){
	int ans=0;
	int goneto[n];
	memset(goneto,-1,n*sizeof(int));
	queue<container> q;
	q.push(container(root,0));
	while(!q.empty()){
		container now = q.front();
//		cout<<now.dest<<'c';
//		for(int i =0;i<n;i++)cout<<goneto[i]<<' ';
//		cout<<endl;
		q.pop();
		goneto[now.dest] = now.val;
		ans = max(ans,now.val);
		for(int i =0;i<tree[now.dest].childs.size();i++){
			int next = tree[now.dest].childs[i];
			if(goneto[next] == -1){
				q.push(container(next,now.val+1));
				goneto[next] = now.val+1;
			}
		}
	}
//	cout<<ans<<endl<<endl;
	dist = ans;
	for(int i =0;i<n;i++){
		if(goneto[i] == ans) return i;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		tree = vector<node>(n,node());
		for(int i =0;i<n;i++){
			int c;
			while(cin>>c){
				if(c == -1)break;
				tree[i].childs.push_back(c);
				tree[c].parent = i;
			}
			if(tree[i].parent !=-1)tree[i].childs.push_back(tree[i].parent);
		}
//		for(int i =0;i<n;i++){
//			for(int j =0;j<tree[i].childs.size();j++){
//				cout<<tree[i].childs[j]<<' ';
//			}
//			cout<<endl;
//		}
		int dist =0;
		int r = bfs(0,dist);
//		cout<<r<<endl;
		bfs(r,dist);
		cout<<dist<<'\n';
	}
}

/*
5
1 2 -1
3 -1
4 -1
-1
-1
*/
