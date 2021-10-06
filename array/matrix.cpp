#include<bits/stdc++.h>
using namespace std;
int main(){

    const int n_row=4;
    const int n_col=4;
    const int m [n_row] [n_col]={

        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {14,15,16,17},

    }; 

for(int y=0;y<n_row;y++){
    for( int x=0;x<n_col;x++){
        cout<<m[y][x];
    }
    cout<<"\n";
}
return 0;
}