#include <iostream>
#include <vector>
#include<stack>
#include<queue>
using namespace std;

int main(){
    int k;
    cin >> k;
    for (int i = 0; i < k;i++){
        int m;
        cin >> m;
        int arr[m+1];
        int l;
        cin >> l;
        bool yes=false;
        arr[0] = 0;
        arr[1] = l;
        for (int j = 2; j <= m;j++){
            cin >> l;
            arr[j] = arr[j - 1] + l;
        }
        for (int j = 0; j < m;j++){
            if(arr[j]==arr[m]-arr[j+1]){
                cout << "YES"<<endl;
                yes = true;
            }
        }
        if(yes == false) cout << "NO"<<endl;
    }
}