#ifndef __DLIST_CPP__
#define __DLIST_CPP__


#include"dlist.h"

template<class T>
bool Dlist<T>::isEmpty() {
	if (first == nullptr) return true;
	return false;
}

template<class T>
void Dlist<T>::insertFront(T* op) {
	node *tmp = new node;
	if (first == nullptr) {
		tmp->next = nullptr;
		tmp->prev = nullptr;
		tmp->op = op;
		first = tmp;
		last = tmp;
	}
	else {
		tmp->next = this->first;
		tmp->prev = nullptr;
		tmp->op = op;
		first->prev = tmp;
		first = tmp;
	}
}

template<class T>
void Dlist<T>::insertBack(T *op) {
	node *tmp = new node;
	if (last == nullptr) {
		tmp->next = nullptr;
		tmp->prev = nullptr;
		tmp->op = op;
		first = tmp;
		last = tmp;
	}
	else {
		tmp->next = nullptr;
		tmp->prev = last;
		tmp->op = op;
		last->next = tmp;
		last = tmp;
	}
}

template<class T>
T *Dlist<T>::removeFront() {
	emptyList a;
	if (this->isEmpty()) throw a;
	T* tmp = this->first->op;
	node* nxt = first->next;
	if(nxt!=nullptr) nxt->prev = nullptr;
	else last = nxt;
	delete first;
	first = nxt;
	if(first!=nullptr) first->prev = nullptr;
	return tmp;
}

template<class T>
T *Dlist<T>::removeBack() {
	emptyList a;
	if (this->isEmpty()) throw a;
	T* tmp = this->last->op;
	node* nxt = last->prev;
	if (nxt != nullptr) nxt->next = nullptr;
	else first = nxt;
	delete last;
	last = nxt;
	if (first != nullptr) last->next = nullptr;
	return tmp;
}

template<class T>
Dlist<T>::Dlist() {
	first = nullptr;
	last = nullptr;
}

template<class T>
Dlist<T>::Dlist(const Dlist &l){
	copyAll(l);
}

template<class T>
Dlist<T>& Dlist<T>::operator=(const Dlist &l) {
	copyAll(l);
	return *this;
}

template<class T>
Dlist<T>::~Dlist() {
	removeAll();
}

template<class T>
void Dlist<T>::removeAll() {
	node* tmp;
	if (!this->isEmpty()) {
		while (first->next != nullptr) {
			tmp = first->next;
			delete first;
			first = tmp;
		}
		delete first;
		first = nullptr;
		last = nullptr;
	}
}

template<class T>
void Dlist<T>::copyAll(const Dlist &l) {
	removeAll();
	node* tmp=l.first;
	if (l.first!=nullptr) {
		node *elem = new node;
		node *pre;
		first = elem;
		elem->op = tmp->op;
		elem->prev = tmp->prev;
		elem->next = nullptr;
		pre = elem;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
			elem = new node;
			pre->next = elem;
			elem->op = tmp->op;
			elem->prev = pre;
			elem->next = tmp->next;
			pre = elem;
		}
		last = elem;
	}
}
#endif // __DLIST_CPP__