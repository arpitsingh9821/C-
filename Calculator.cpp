#include <iostream>
#include <string>
using namespace std;

class Calculator {
public:
   
    string divideWithPrecision(int numerator, int denominator, int precision) {
        if (denominator == 0) {
            return "Cannot divide by zero";
        }

        string result = "";
        int intPart = numerator / denominator;
        result += to_string(intPart) + ".";

        int remainder = numerator % denominator;

        for (int i = 0; i < precision; ++i) {
            remainder *= 10;
            int digit = remainder / denominator;
            result += to_string(digit);
            remainder %= denominator;

            if (remainder == 0) {
                result += string(precision - i - 1, '0');
                break;
            }
        }

        return result;
    }

    // Method for addition, subtraction, and multiplication with precision
    string formatWithPrecision(double result, int precision) {
        int intPart = static_cast<int>(result);
        double fracPart = result - intPart;

        string resultStr = to_string(intPart) + ".";

        for (int i = 0; i < precision; ++i) {
            fracPart *= 10;
            int digit = static_cast<int>(fracPart);
            resultStr += to_string(digit);
            fracPart -= digit;
        }

        return resultStr;
    }
};

int getOperation() {
    int op;
    cout << "Select operation:\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n";
    cout << "Enter operation number: ";
    cin >> op;
    return op;
}

double getNumber(const string& prompt) {
    double num;
    cout << prompt;
    cin >> num;
    return num;
}

int main() {
    Calculator calc;

    int operation = getOperation();
    double num1 = getNumber("Enter first number: ");
    double num2 = getNumber("Enter second number: ");
    int precision;

    cout << "Enter number of digits after decimal: ";
    cin >> precision;

    if (operation == 4) {
        int intNum1 = static_cast<int>(num1);
        int intNum2 = static_cast<int>(num2);
        string result = calc.divideWithPrecision(intNum1, intNum2, precision);
        cout << "Result: " << result << endl;
    } else {
        double result;
        if (operation == 1) result = num1 + num2;
        else if (operation == 2) result = num1 - num2;
        else if (operation == 3) result = num1 * num2;
        else {
            cout << "Invalid operation\n";
            return 1;
        }

        cout << "Result: " << calc.formatWithPrecision(result, precision) << endl;
    }

    return 0;
}
