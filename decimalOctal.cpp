#include <iostream>

using namespace std;

int decimalToOctal(int num){
    // Defining an answer varible for storing the converted answer
    int ans = 0;
    // Defining a variable to set the state position
    int dec = 1;

    // Looping for setting the state
    while (dec <= num) {
        // Setting the state with multiplicative of 8
        dec *= 8;
    }

    // Decrementing the set variable if set variable is greater than the user input number.
    dec /= 8;

    // Looping till the set variable is greater than zero
    while (dec > 0) {
        // Saving the quotient by dividing the number by set variable
        int last = num/dec;

        // Now subtracting the quotient * the set variable from the original number
        num -= last * dec;

        // Again decrementing the set variable
        dec /= 8;
        // Now increasing the answer variable by 10 times so that last value can be added. 
        ans = ans*10 + last;
    }

    // Returning the answer variable.
    return ans;
}

int main() {
    int num;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<decimalToOctal(num);

    return 0;
}