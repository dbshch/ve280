#include<iostream>
#include<string>
#include"dlist.h"
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
	n = 0;
	while (true)
	{
		if (busy<0 && si.isEmpty() && go.isEmpty() && pt.isEmpty() && re.isEmpty()) {
			break;
		}
		cout << "Starting tick #" << n << endl;
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
		if (!busy) {
			if (!pt.isEmpty()) {
				tmp = pt.removeFront();
				busy = tmp->dur;
				cout << "Answering call from " << tmp->name << endl;
				delete tmp;
			}
			else if (!go.isEmpty()) {
				tmp = go.removeFront();
				busy = tmp->dur;
				cout << "Answering call from " << tmp->name << endl;
				delete tmp;
			}
			else if (!si.isEmpty()) {
				tmp = si.removeFront();
				busy = tmp->dur;
				cout << "Answering call from " << tmp->name << endl;
				delete tmp;
			}
			else if (!re.isEmpty()) {
				tmp = re.removeFront();
				busy = tmp->dur;
				cout << "Answering call from " << tmp->name << endl;
				delete tmp;
			}
		}
		--busy;
		++n;
	}
	return 0;
}