#include <iostream>
#include <string>
using namespace std;

// Divide with long division logic (string-based)
string divideWithPrecision(int numerator, int denominator, int precision) {
    if (denominator == 0) {
        return "Cannot divide by zero";
    }

    string result = "";

    // Integer part
    int intPart = numerator / denominator;
    result += to_string(intPart) + ".";

    // Initial remainder
    int remainder = numerator % denominator;

    for (int i = 0; i < precision; ++i) {
        remainder *= 10;
        int digit = remainder / denominator;
        result += to_string(digit);
        remainder %= denominator;

        // Optional: Stop early if remainder becomes 0
        if (remainder == 0) {
            result += string(precision - i - 1, '0'); // Fill remaining with 0
            break;
        }
    }

    return result;
}

// Input helpers
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
    int operation = getOperation();
    double num1 = getNumber("Enter first number: ");
    double num2 = getNumber("Enter second number: ");
    int precision;

    cout << "Enter number of digits after decimal: ";
    cin >> precision;

    if (operation == 4) {
        // Use integers for exact digit extraction
        int intNum1 = static_cast<int>(num1);
        int intNum2 = static_cast<int>(num2);

        string result = divideWithPrecision(intNum1, intNum2, precision);
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

        // Convert to string manually
        int intPart = static_cast<int>(result);
        double fracPart = result - intPart;

        string resultStr = to_string(intPart) + ".";

        for (int i = 0; i < precision; ++i) {
            fracPart *= 10;
            int digit = static_cast<int>(fracPart);
            resultStr += to_string(digit);
            fracPart -= digit;
        }

        cout << "Result: " << resultStr << endl;
    }

    return 0;
}
