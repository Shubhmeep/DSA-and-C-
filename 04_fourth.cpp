#include<iostream>
using namespace std;

// beginner patterns problems to solve

void pattern1(){

           int rows = 5;
    int col = 5;
    int c = 1;
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=col;j++){
            cout<<j<<" ";
            c+=1;
        }
        cout<<endl;
    };
};


void pattern2(){

    int rows = 5;
    int col = 5;
    int c = 1;
    for (int i=1;i<=rows;i++){
        for (int j=col;j>0;j--){
            cout<<j<<" ";
            c+=1;
        }
        cout<<endl;
    };
};

void pattern3(){

    int rows = 5;
    int col = 5;
    int c = 1;
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=col;j++){
            cout<<c<<" ";
            c+=1;
        }
        cout<<endl;
    };
};

void pattern4(){

    int rows = 5;
    int col = 5;
    
    for (int i=1;i<=rows;i++){
        char c = 'a' + (i-1);
        for (int j=1;j<=col;j++){
            cout<<c<<" ";
        }
        cout<<endl;
    };
};

void pattern5(){

    int rows = 6;
    int col = 6;
    
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=col;j++){
            cout<<j*j*j<<" ";
        }
        cout<<endl;
    };
};


void pattern6(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    };
};

void pattern7(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    };
};


void pattern8(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        for (int j=i;j>0;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    };
};

void pattern9(){

    int rows = 5;
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=rows-(i-1);j++){
            cout<<j<<" ";
        }
        cout<<endl;
    };
};



int main(){

    pattern1();
    cout << endl;
    pattern2();
    cout << endl;
    pattern3();
    cout << endl;
    pattern4();
    cout << endl;
    pattern5();
    cout << endl;
    pattern6();
    cout << endl;
    pattern7();
    cout << endl;
    pattern8();
    cout << endl;
    pattern9();

    return 0;
};