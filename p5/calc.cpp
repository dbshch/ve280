#include<iostream>
#include"dlist.h"
#include"dlist.cpp"
#include<string>
using namespace std;
void err2() {
	cout << "Not enough operands\n";
}
int main() {
	Dlist<int> stk;
	string cmd;
	string ii;
	int* i;
	int *a, *b;
	int flg = 0;
	while (cmd != "q") {
		flg = 0;
		cin >> cmd;
		for (auto elt : cmd) {
			if (!(elt - '0'<10 && elt - '0'>-1)) ++flg;
		}
		if ((!flg)||(flg==1&&cmd[0]=='-')) {
			stk.insertFront(new int(atoi(cmd.c_str())));
		}
		else if (cmd == "+") {
			if (!stk.isEmpty()) {
				a = stk.removeFront();
			}
			else{
				err2(); continue;
			}
			if (!stk.isEmpty())
				b = stk.removeFront();
			else {
				stk.insertFront(a);
				err2(); continue;
			}
			*a = *a + *b;
			delete b;
			stk.insertFront(a);
		}
		else if (cmd == "-") {
			if (!stk.isEmpty()) {
				a = stk.removeFront();
			}
			else {
				err2(); continue;
			}
			if (!stk.isEmpty())
				b = stk.removeFront();
			else {
				stk.insertFront(a);
				err2(); continue;
			}
			*a = *b - *a;
			delete b;
			stk.insertFront(a);
		}
		else if (cmd == "*") {
			if (!stk.isEmpty()) {
				a = stk.removeFront();
			}
			else {
				err2(); continue;
			}
			if (!stk.isEmpty())
				b = stk.removeFront();
			else {
				stk.insertFront(a);
				err2(); continue;
			}
			*a = *a * *b;
			delete b;
			stk.insertFront(a);
		}
		else if (cmd == "/") {
			if (!stk.isEmpty()) {
				a = stk.removeFront();
				if (*a == 0) {
					cout << "Divide by zero\n";
					stk.insertFront(a);
					continue;
				}
			}
			else {
				err2(); continue;
			}
			if (!stk.isEmpty())
				b = stk.removeFront();
			else {
				stk.insertFront(a);
				err2(); continue;
			}
			*a = *b / *a;
			delete b;
			stk.insertFront(a);
		}
		else if (cmd == "n") {
			if (stk.isEmpty()) {
				err2();
			}
			else {
				a = stk.removeFront();
				*a = -*a;
				stk.insertFront(a);
			}
		}
		else if(cmd=="d"){
			a = stk.removeFront();
			int* t = new int;
			*t = *a;
			stk.insertFront(t);
			stk.insertFront(a);
		}
		else if (cmd == "r") {
			if (!stk.isEmpty()) {
				a = stk.removeFront();
				if (*a == 0) {
					cout << "Divide by zero\n";
					stk.insertFront(a);
					continue;
				}
			}
			else {
				err2(); continue;
			}
			if (!stk.isEmpty())
				b = stk.removeFront();
			else {
				stk.insertFront(a);
				err2(); continue;
			}
			stk.insertFront(a);
			stk.insertFront(b);
		}
		else if (cmd == "p") {
			if (stk.isEmpty())
				err2();
			else {
				a = stk.removeFront();
				cout << *a << endl;
				stk.insertFront(a);
			}
		}
		else if (cmd == "c") {
			while (!stk.isEmpty()) {
				a = stk.removeFront();
				delete a;
			}
		}
		else if (cmd == "a") {
			Dlist<int> tp;
			if (stk.isEmpty())
				cout << endl;
			else {
				a = stk.removeFront();
				cout << *a;
				tp.insertBack(a);
				while (!stk.isEmpty()) {
					a = stk.removeFront();
					cout << ' ' << *a;
					tp.insertBack(a);
				}
				cout << endl;
				stk = tp;
			}
		}
		else if (cmd == "q") {
			while (!stk.isEmpty()) {
				a = stk.removeFront();
				delete a;
			}
		}
		else {
			cout << "Bad input\n";
		}
	}
	return 0;
}