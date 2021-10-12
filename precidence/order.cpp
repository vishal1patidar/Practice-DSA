#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    //   int a = 34; 
    //   cout<<"The value of a was: "<<a;
    //   a = 45; 
    //   cout<<"The value of a is: "<<a;
    //   Constants in C++
    //   const int a = 3;
    //  cout<<"The value of a was: "<<a<<endl;
    //   a = 45; 
    //   cout<<"The value of a is: "<<a<<endl;

    //   Manipulators in C++
    // endl" is used for the next line.
// "setw" is used to specify the width of the output.
    //   int a =3, b=78, c=1233;
    // cout<<"The value of a without setw is: "<<a<<endl;
    // cout<<"The value of b without setw is: "<<b<<endl;
    // cout<<"The value of c without setw is: "<<c<<endl;

    // cout<<"The value of a is: "<<setw(4)<<a<<endl;
    // cout<<"The value of b is: "<<setw(4)<<b<<endl;
    // cout<<"The value of c is: "<<setw(4)<<c<<endl;


    // Operator Precedence
    int a =3, b=4;
    // int c = (a*5)+b;
     int c = ((((a*5)+b)-45)+87);
     cout<<c;
    return 0;
}
