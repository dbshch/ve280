#include<iostream>
#include<string>
#include"dlist.h"
#include"dlist.cpp"
using namespace std;

struct usr
{
	int tm, dur;
	string name, stat;
	friend ostream& operator<<(ostream& out, usr* &t) {
		out << "Call from " << t->name << " a " << t->stat << " member";
		return out;
	}
};
int main() {
	string name, stat;
	int n, tm, dur, tck = 0, busy = 0;
	usr *tmp;
	Dlist<usr> re, si, go, pt, que;
	cin >> n;
	while (n--)
	{
		cin >> tm >> name >> stat >> dur;
		tmp = new usr{ tm, dur, name, stat };
		que.insertBack(tmp);
		if (stat == "regular") {
			re.insertBack(tmp);
		}
		else if (stat == "silver") {
			si.insertBack(tmp);
		}
		else if (stat == "gold") {
			go.insertBack(tmp);
		}
		else {
			pt.insertBack(tmp);
		}
	}
	n = -1;
	while (true)
	{
		if (busy<0 && si.isEmpty() && go.isEmpty() && pt.isEmpty() && re.isEmpty()) {
			break;
		}
		cout << "Starting tick #" << n+1 << endl;
		if(busy>=0) --busy;
		++n;
		while (!que.isEmpty())
		{
			tmp = que.removeFront();
			if (tmp->tm == n) {
				cout << tmp << endl;
			}
			else
			{
				que.insertFront(tmp);
				break;
			}
		}
		if (busy<0) {
			if (!pt.isEmpty()) {
				tmp = pt.removeFront();
				if (tmp->tm <= n) {
					busy += tmp->dur;
					cout << "Answering call from " << tmp->name << endl;
					delete tmp;
					continue;
				}
				else
				{
					pt.insertFront(tmp);
				}
			}
			if (!go.isEmpty()) {
				tmp = go.removeFront();
				if (tmp->tm <= n) {
					busy += tmp->dur;
					cout << "Answering call from " << tmp->name << endl;
					delete tmp;
					continue;
				}
				else
				{
					go.insertFront(tmp);
				}
			}
			if (!si.isEmpty()) {
				tmp = si.removeFront();
				if (tmp->tm <= n) {
					busy += tmp->dur;
					cout << "Answering call from " << tmp->name << endl;
					delete tmp;
					continue;
				}
				else
				{
					si.insertFront(tmp);
				}
			}
			if (!re.isEmpty()) {
				tmp = re.removeFront();
				if (tmp->tm <= n) {
					busy += tmp->dur;
					cout << "Answering call from " << tmp->name << endl;
					delete tmp;
					continue;
				}
				else
				{
					re.insertFront(tmp);
				}
			}
		}
	}
	return 0;
}