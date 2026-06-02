#include<iostream>
using namespace std;

// advance patterns problems to solve

void pattern1(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=rows-i;j++){
            cout<<" ";
        }
        for (int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    };
};


void pattern2(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        
        for (int j=1;j<=rows-i;j++){
            cout<<" ";
        }
        for (int j=1;j<=i;j++){
            char c = 'A' + (j-1);
            cout<<c;
        }
        cout<<endl;
    };
};

void pattern3(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        
        for (int j=1;j<=rows-i;j++){
            cout<<" ";
        }
        for (int j=i;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    };
};

void pattern4(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        
        for (int j=1;j<=rows-i;j++){
            cout<<" ";
        }
        for (int j=1;j<=2*i-1;j++){
            cout<<"*";
        }

        cout<<endl;
    };
};


void pattern5(){

    int n=5;
    for (int i = 1; i <= n; i++) {

        // 1. spaces triangle
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // 2. left stars triangle
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // 3. right stars triangle
        for (int j = 1; j <= i - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }
};

void pattern6(){

    int n=5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * (n - i) + 1; j++) {
            cout << "*";
        }


        cout << endl;
    }
};




int main(){

    pattern1();
    cout<<endl;
    pattern2();
    cout<<endl;
    pattern3();
    cout<<endl;
    pattern4();
    cout<<endl;
    pattern5();
    cout<<endl;
    pattern6();


};