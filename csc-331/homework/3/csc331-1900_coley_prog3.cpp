/*
 * CSC331-1900
 * Natalie Coley
 * csc331-1900_coley_prog3.cpp
 *
 * Assignment #3 - Due 10/30/2019
 *
 * This program should implement a stack data structure in C++. Use of the C++ STL is permitted, as is a user defined stack.
 *
 * The full purpose of the assignment is to process user given expressions in postfix notation using a stack and return the result.
 *
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
 * PostfixNotationEvaluator class handles evaluating postfix notation expressions using a stack, and returning the results of those expressions
 */

class PostfixNotationEvaluator {
    stack<float> transaction_stack;
    int operand;
    char op; //operator
    float first;
    float second;
    bool process_transaction(char op);
    void clear_transaction_stack();

public:
    string evaluate_expression(string expression);
};

/*
 * ~~ PostfixNotationEvaluator - Public Methods ~~
 */

string PostfixNotationEvaluator::evaluate_expression(string expression) {
    string result;
    bool transaction_succeeded;

    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            operand = expression[i] - '0';
            transaction_stack.push(operand);
        }
        else {
            op = expression[i];
            transaction_succeeded = process_transaction(op);
            if (!transaction_succeeded) { clear_transaction_stack(); break; }
        }
    }

    if (transaction_stack.empty()) {
        result = "Error: Divide By Zero";
    }
    else {
        result = to_string(transaction_stack.top());
        result.erase( result.find_last_not_of('0') + 1, string::npos);
        result.erase(result.find_last_not_of(".") + 1, string::npos);
        clear_transaction_stack();
    }

    return result;
}

/*
 * ~~ PostfixNotationEvaluator -- Private Methods ~~
 *        return value is whether or not the transaction was successfully processed
 */

bool PostfixNotationEvaluator::process_transaction(char op) {
    float result;
    bool divide_by_zero = false;

    second = transaction_stack.top();
    transaction_stack.pop();
    first = transaction_stack.top();
    transaction_stack.pop();

    switch(op) {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            if (second != 0) {
                result = first / second;
            }
            else { divide_by_zero = true; }
            break;
    }

    if (!divide_by_zero) {
        transaction_stack.push(result);
        return 1;
    }
    else {
        return 0;
    }
}

void PostfixNotationEvaluator::clear_transaction_stack() {
    while (!transaction_stack.empty()) {
        transaction_stack.pop();
    }
}

/*
 * UserInputManager class handles determining what actions to take based on user input
 */

class UserInputManager {
    string input;
    void get_next_input();
    void handle_user_input();

public:
    void request_and_handle_user_instruction();
};

/*
 * ~~ UserInputManager - Public Methods ~~
 */

void UserInputManager::request_and_handle_user_instruction() {
    get_next_input();
    handle_user_input();
}

/*
 * ~~ UserInputManager -- Private Methods ~~
 */

void UserInputManager::get_next_input() {
    cout << "Please enter an expression in post-fix notation: " << endl;
    getline(cin, input);
}

void UserInputManager::handle_user_input() {
    PostfixNotationEvaluator expressionEvaluator;

    while(input.find("end-of-file") == string::npos) {
        cout << "result = " << expressionEvaluator.evaluate_expression(input) << endl;
        get_next_input();
    }
}


int main() {
    UserInputManager input_manager;
    input_manager.request_and_handle_user_instruction();

    return 0;
}