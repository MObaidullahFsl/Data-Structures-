#include<iostream>
using namespace std;


class node {
	public:
	int data;
	node* next;
	node(int a): data(a) {

	}
	void insert(node*&);
	void endInsert(node*&);
	void randomInsert(node*&, int);
	void print();
};

void node::insert(node*& head) {
	
	node* temp = head;
	head = this;
	this->next = temp;

}

void node::endInsert(node*& head) {
	node* temp = head;
	while (temp -> next != nullptr) {
		temp = temp->next;
	} 
	temp->next = this;
	this->next = nullptr;
}

void node::randomInsert(node*& head, int pos) {
	node* temp = head; int i = 0; int j = 0;
	node* temp2 = head;
	while (true)
	{
		if (temp->next == nullptr) { // reached end
			temp->next = this;
			this->next = nullptr;
			
			break;
			}
		else if (i == pos)
		{
			if (i == 0)
			{
				this->next = head;
				head = this;
				break;

			}
			else {
				
				while (j != (i-1)) {
					j++;
					temp2 = temp->next;

				}
				this->next = temp;
				temp2->next = this;

				break;

			}

		}
		else {
			i++;
			temp = temp->next;
		}
	}
}

void node::print() {
	node* temp = this;
	while (temp->next != nullptr) {
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << temp->data;
}


int main() {
	node* head= nullptr;
	node *a = new node(5);
	node* b = new node(7);
	node* c = new node(1);
	node* d = new node(2);
	node* e = new node(9);


	a->insert( head);
	b->insert( head);
	c->insert( head);
	d->endInsert(head);
	e->randomInsert(head,0);
	head->print();

}