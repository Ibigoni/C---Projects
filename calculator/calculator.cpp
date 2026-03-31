#include <iostream>
using namespace std;

//Calculator implementation
double add (double a, double b) {
    return a + b;
}

double subtract (double a, double b){
    return a - b;
}

double multiply (double a, double b){
    return a * b;
}

double divide (double a, double b){
  return b != 0 ? a / b: 0; //using a ternary operator (short way to write and if else) for safety check if dividing by 0.
}

int main() {
  double num1, num2;
  char op;

  cout <<"Enter first number: ";
  cin >> num1;

  cout <<"Enter operator (+, -, *, /): ";
  cin >> op;

  cout <<"Enter second number: ";
  cin >> num2;

  //check statement for division by 0
   if (op == '/' && num2 == 0) {
        cout << "Error: Cannot by zero." << endl;
        return 1;
    }

    double result;

    //Using switch for each operation
    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            cout << "Invalid operator!" << endl;
            return 1;
    }

    //Result
    cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << endl;

    return 0;
}

