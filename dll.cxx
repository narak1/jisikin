//#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
private:
Node *prevNode;
Node *nextNode;
string str;
public:
void setString(string str)
{
this->str = str;
}
void setNextNode(Node* node)
{
this->nextNode = node;
}
void setPrevNode(Node* node)
{
this->prevNode = node;
}
string getString()
{
return this->str;
}
Node* getNextNode()
{
return nextNode;
}
};


class List
{
protected:
Node *header;
Node *tailer;
public:
List()
{
initList();
}
void add(string str)
{
	Node *tmp = new Node();
	tmp->setString(str);

	Node *next = header->getNextNode();
	tmp->setNextNode(next);
	tmp->setPrevNode(header);
	
	header->setNextNode(tmp);
	next->setPrevNode(tmp);
}
virtual void printAll()
{
Node *temp = header->getNextNode();
while (temp != tailer)
{
cout << temp->getString() << endl;
temp = temp->getNextNode();
}
}
void fileSave()
{
}
void fileLoad()
{
}
void initList()
{
header = new Node();
tailer = new Node();
(*header).setNextNode(tailer);
tailer->setPrevNode(header);
}
};


int main(void)
{
	List list;
	
	list.add("11");
	list.add("12");
	list.add("13");
	list.add("14");
	
	list.printAll();
	return 0;
}
