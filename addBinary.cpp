#include <iostream>

using namespace std;

// Function to reverse a number
int reverse(int res) {
    int tot = 0;

    // Loop to fetch the last digit
    while (res > 0)
    {
        int last = res%10;

        tot = tot*10 + last;

        res = res/10;
    }

    return tot;
    
}

int addingBinary(int num1, int num2) {
    // Variable to store the result
    int ans = 0;

    // Variable to keep track of the previous carry generated. Initially there is no carry so it is initialized with 0.
    int prevCarry = 0;

    /* There will be 3 cases to for adding two binary numbers
        case 1. If both the digits are 0 then there exist are two subcases:
                a) if previous carry is 1 then sum will be 1, and previous carry will set to 0.
                b) if previous carry is 0 then sum will be 0, and previous carry will set to 0.
        case 2. If one of the digit is 0 & other is 1 then there exist two subcases:
                a) if previous carry is 1 then sum will be 0, and previous carry will set to 1.
                b) if previous carry is 0 then sum will be 1, and previous carry will set to 0.
        case 3. If both the digits are 1 then there exist two subcases:
                a) if previous carry is 1 then sum will be 1, and previous carry will set to 1.
                b) if previous carry is 0 then sum will be 0, and previous carry will set to 1.
    */

   // Loop till the number is not fully traversed
    while (num1 > 0 && num2 > 0){

        // Case 1
        if (num1%2 == 0 && num2%2 == 0) {
            // both 1.a & 1.b is checked as previous carry will always set to 0.
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }
        // Case 2
        else if ((num1%2 == 0 && num2%2 == 1) || (num1%2 == 1 && num2%2 == 0)) {

            // 2.a
            if (prevCarry == 1) {
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            // 2.b
            else {
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        // Case 3 both 3.a & 3.b is checked & previous carry will always set to 1
        else {
            ans = ans*10 + prevCarry;
            prevCarry = 1;
        }

        // Updating the input numbers by removing the last digit
        num1 = num1/10;
        num2 = num2/10;
    }

    /* Checking if any of the number has more digits than the other then add the previous carry to the remaining digit.
        Case 1: If Number 1 has more digits & there exist two subcases:
                a) if previous carry is 1 & existing digit is 1 then sum is 0 & previous carry is set to 1.
                b) if previous carry is 0 & existing digit is 1 then sum is 1 & previous carry is set to 0.
        Case 2: If Number 2 has more digits & there exist two subcases:
                a) if previous carry is 1 & existing digit is 1 then sum is 0 & previous carry is set to 1.
                b) if previous carry is 0 & existing digit is 1 then sum is 1 & previous carry is set to 0.
    */

   // Case 1
    while (num1 > 0) {
        // 1.a
        if (prevCarry == 1) {
            if (num1 % 2 == 1) {
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            // 1.b
            else {
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        // Here it is checked for if there is no carry but still digit exist then it is fetched & added to the result.
        else {
            ans = ans*10 + (num1%2);
        }

        // Here again the number is updated by removing the digits.
        num1 = num1/10;
    }

    // Case 2
    while (num2 > 0) {
        // 2.a
        if (prevCarry == 1) {
            if (num2 % 2 == 1) {
                ans = ans*10 + 0;
                prevCarry = 1;
            }
            // 2.b
            else {
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        // Here it is checked for if there is no carry but still digit exist then it is fetched & added to the result.
        else {
            ans = ans*10 + (num2%2);
        }

        // Here again the number is updated by removing the digits.
        num2 = num2/10;
    }

    // Here it checked if previous carry is 1 & there is no digits left in both the numbers.
    if (prevCarry == 1)
    {
        ans = ans*10 + 1;
    }
    
    // The answer has to be reversed as the result is saved from last digits.
    ans = reverse(ans);
    
    return ans;
            
}

int main() {
    int num1, num2;

    cout<<"Enter two binary number: ";
    cin>>num1>>num2;

    cout<<addingBinary(num1, num2)<<endl;

    return 0;
}