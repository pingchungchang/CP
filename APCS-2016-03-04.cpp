#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    Node* parent;
    vector<Node*> childs;
} Node;
int finddepth(int& ans,Node* nowroot,int nowdepth){
    if(nowroot->childs.size()==1){
        int x = finddepth(ans,nowroot->childs[0],nowdepth+1);
        ans = max(x-nowdepth,ans);
        return x;
    }
    else if(nowroot->childs.size()==0){
        return nowdepth;
    }
    else{
        int k = 0;
        vector<int> depths;
        for(int i = 0;i<nowroot->childs.size();i++){
            depths.push_back(finddepth(ans,nowroot->childs[i],nowdepth+1));
        }
        sort(depths.begin(),depths.end());
        ans = max(ans,depths[depths.size()-1]+depths[depths.size()-2]-2*nowdepth);
        return depths[depths.size()-1];
    }
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        scanf("\n");
        Node* root;
        unordered_map<int,Node*> used;
        for(int i = 0;i<n-1;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(i != n-2)scanf("\n");
            Node* p = new Node;
            p->parent = nullptr;
            Node* c = new Node;
            if(used.count(a) != 0){
                p = used[a];
            }
            else used[a] = p;
            if(used.count(b)!=0){
                c = used[b];
            }
            else used[b] = c;
            p->childs.push_back(c);
            c->parent = p;
            if(p->parent == nullptr){
                root = p;
            }
        }
        while(root->parent != nullptr)root = root->parent;
        int ans = 0;
        finddepth(ans,root,0);
        printf("%d\n",ans);
        scanf("\n");
    }
}