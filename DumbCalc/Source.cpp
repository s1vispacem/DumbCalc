//dumb calc v228 p1 by Igor Lesyuk
// fixed entering operands
// fixed entering operations

#include <iostream>
#include <cmath>
using  std::cin;			// забрати namespace std
using  std::cout;			
using  std::atof;			
using  std::endl;			

const int b8 = 256;

bool operation_check(char operation[]) {
	char arr[] = "+-/*%^r";

	for (int i = 0; i < b8; i++) {			//при вводі значень в чар, після останнього символу ставится 0 => перевіряємо чи оп[1]==0
		if (operation[1] != 0) {
			cout << "only one symbol, dummy\n";
			return false;
		}
	}

	for (int i = 0; i < 7; ++i) {
		if (operation[0] == arr[i]) {
			return true;
		}
	}
	return false;
}

bool word_check(char word[], char comp[], int size) {
	for (int i = 0; i < size; i++) {
		if (word[i] != comp[i]) { return false; };
	}
	return true;
}


bool operand_check(char operand[]) {
	int i = 0;
	while (operand[i] != static_cast<char>(0))
	{
		if (operand[i] == '-' or operand[i] == '.')
		{
			i++;
			continue;
		}
		if(!isdigit(operand[i]))
		{
			return false;
		}
		i++;
	}
	return true;
}



int main(int argc, char* argv[]) {
	cout << "dumb calc v228 p1 by Igor Lesyuk\n";

	bool flag_global = true;
	while (flag_global) {

		bool flag1 = true;
		char operation[b8];


		while (flag1) {				//entering operation

			cout << " enter operation \n suported : + , -, /, *, %, ^, r for root\n only one sym\n";
			cin >> operation;
			
			if (operation_check(operation)) {
				flag1 = false;
			}
			else {
				cout << "try again\n";
			}
		}
		double num1;

		bool flag2 = true;
		while (flag2) {											// 1-st operand
			char operand1[b8];									//operand fixed
			
			cout << "enter first operand\n";
			cin >> operand1;
			
			if (!operand_check(operand1)) 
			{
				cout << "input fail\nenter only nums\n ";								
			}
			else 
			{
				num1 = atof(operand1);
				cout << "fin. \n";
				flag2 = false;
			}

			
		}

		double num2;
		bool flag3 = true;

		while (flag3) {												//2-nd operand

			char operand2[b8];

			cout << "enter second operand\n";
			cin >> operand2;

			if(!operand_check(operand2))
			{
				cout << "input fail\nenter only nums\n";
			}
			else
			{
				num2 = atof(operand2); 
					cout << "fin.\n";
					flag3 = false;
			}
		}

		cout << "gud\n";
		double result;
		switch (operation[0]) {
		case '+': {result = num1 + num2; break; }
		case '-': {result = num1 - num2; break; }
		case '/': {result = num1 / num2; break; }
		case '*': {result = num1 * num2; break; }
		case '^': {result = pow(num1, num2); break; }
		case 'r': {result = pow(num1, 1 / num2); break; }
				 
		case '%': {result = static_cast<int>(num1) % static_cast<int>(num2); break; }
		}
		cout << "result = " << result << endl;

		char check[b8];
		char reset_w[] = "reset";
		char exit_w[] = "exit";
		bool flag4 = true;
		cout << "now u can leave me alone\n";

		while (flag4) {
			cout << " write exit to set me free \n write reset and will calc again \n ";
			cin >> check;
			
			if (word_check(check, exit_w, 4)) {
				cout << "finnaly, i`m free\n";
				flag_global = false;
				flag4 = false;
			}
			
			else if (word_check(check, reset_w, 5)) {
				cout << "ah shit, here we go again\n";
				flag4 = false;
			}
			else {
				cout << "incorrect, try again:\n ";
			}
		}
	}


	return 0;
}