#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct whatever{
    string name;
    int c;
    int n;
    string details;
}whatever;
class Compare{
public:
    bool operator()(whatever a,whatever b){
        if(a.c == b.c)return a.n<b.n;
        else return a.c<b.c;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int times;
    cin>>times;
    whatever arr[times];
    for(int i =0;i<times;i++){
        int c,n;
        string name,details;
        cin>>name>>c>>n>>details;
        arr[i].name = name;
        arr[i].c = c;
        arr[i].n = n;
        arr[i].details = details;
    }
    sort(arr,arr+times,Compare());
    for(int i =0;i<times;i++){
        cout<<arr[i].c<<' '<<arr[i].n<<' '<<arr[i].name<<'\n'<<arr[i].details;
        if(i != times-1)cout<<'\n';
    }
}