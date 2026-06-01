#include <iostream>
#include <utility>
using namespace std;


//calc x**y
int problem_1(){

    int num = 4;
    int pow = 4;
    double ans = 1;

    for (int i = 1; i <= pow; i++) {
        ans = ans*num;
    }

    return ans;
};

int sumOfNaturalNumber(){

    int first = 3;
    int sum = 0;

    for(int i=1;i<=first;i++){

        sum = sum + i;
    };

    return sum;
};

int factorial(){
    
    int num = 5;
    int ans = 1;
    for(int i=num;i>0;i--){
        ans = ans*i;
    };

    return ans;
};


int reverse(){

    int num = 12345;
    int ans = 0;
    while (num!=0){
        int digit = num%10;
        ans = ans*10 + digit;
        num = num/10;
    };

    return ans;

};


pair<int, int> sum_count_digit(){
    int num = 12345;
    int count = 0;
    int sum = 0;
    for (int i=num;i>0;i=i/10){
        int digit = i%10;
        sum += digit;
        count += 1;
    };

    return {sum, count};
};

int main() {
    
    cout << problem_1() << endl;
    cout << sumOfNaturalNumber() << endl;
    cout << factorial() << endl;  
    cout << reverse() << endl;  
    pair<int, int> result = sum_count_digit();
    cout << result.first << endl;   // sum
    cout << result.second << endl;  // count

    return 0;
}