#include <iostream>
using namespace std;
template <class T> class Chain;
template <class T>
class ChainNode {
friend class Chain<T>;
private:
 T data;
 ChainNode<T> *link;
public:
	ChainNode(const T& t) : data(t), link(NULL) { ; }
};
template <class T>
class Chain{
private:
 ChainNode<T> *first;
 ChainNode<T> *last;
public:
 Chain(){first = 0;last = 0;};
 ~Chain(){delete []first;delete []last;}
 void Insertfront(const T&);
 void InsertBack(const T&);
 void InsertAfter(const T& ,const T&);
 void DeleteNode(const T&);
 void FindNode(const T&);
 void ReverseNode();
 void Showlist();
};
template <class T>
void Chain<T>::Insertfront(const T& e)
{
 if(!first) {
  first = last =  new ChainNode<T>(e);
 }
 else {
  ChainNode<T> *tmp = first;
  first = new ChainNode<T>(e);
  first->link = tmp;
 }
}
template <class T>
void Chain<T>::InsertBack(const T& e)
{
 if(last){
  last->link = new ChainNode<T>(e);
  last = last->link;
 }
 else {
  first = last = new ChainNode<T>(e);
 }
}
template <class T>
void Chain<T>::InsertAfter(const T& c1,const T& c2)
{
 	ChainNode<T> *tmp = new ChainNode<T>(c2);

 if(first){
 	// Find Node
 	ChainNode<T> *cur = first;
 	while( cur ) {
 		if( cur->data == c1 ) {
 			tmp->link = cur->link;
 			cur->link = tmp;
 			break;
 		}
 	}
 	if( cur == NULL ) {		// Node not found
	  last->link = tmp;
	  last = tmp; 		
 	}
 }
 else {
 	first = last = tmp; 
 }
}
template <class T>
void Chain<T>::DeleteNode(const T&e)
{
 ChainNode<T> *current=first;
 ChainNode<T> *previous = 0;
 if(first){
  while(current){
   previous = current;
   current = current -> link;
   if( current -> data == e){
    previous -> link = current -> link;
    delete current;
   }
   else
    cout << "노드 안에 " << e << "가 없습니다." << endl;
  }
 }
 else cout << "Empty Node" << endl;
}
template <class T>
void Chain<T>::FindNode(const T&e)
{
 ChainNode<T> *current = first;
 int i = 0;
 if(first)
  while(current){
   current = current -> link;
   i++;
   if(current -> data == e)
    cout << i << "번째 Node에 "<< current -> data << "가 있습니다." << endl;
   else
    cout << "Node안에 " << current -> data << "가 없습니다." << endl;
  }
}
template <class T>
void Chain<T>::ReverseNode()
{
 ChainNode<T> *current = first;
 ChainNode<T> *previous = 0;
 while(current){
  ChainNode<T> *r = previous;
  previous = current;
  current = current -> link;
  previous -> link = r;
 }
 first = previous;
}
template <class T>
void Chain<T>::Showlist()
{
 ChainNode<T> *current;
 for(current = first; current != NULL;current = current -> link)
  cout << current -> data << " -> ";
 cout << endl;
}
int main()
{
 int num;
 Chain<char> chain;
 cout << "Welcome linked List World" << endl;
 do {

 cout << "0.help 1.Insertfront 2.InsertBack 3.InsertAfter 4.DeleteNode 5.FindNode 6.ReverseNode 7.ShowNode 8.Exit" << endl;
 cin >> num;
 switch(num){
  case 0:
   cout << "0.help 1.Insertfront 2.InsertBack 3.InsertAfter 4.DeleteNode 5.FindNode 6.ReverseNode 7.Showlist 8.Exit" << endl;
   break;
  case 1:
   cout << "앞에 들어갈 노드 값을 입력하세요:";
   char c;
   cin >> c;
   chain.Insertfront(c);
   break;
  case 2:
   cout << "뒤에 들어갈 노드 값을 입력하세요:";
   char c1;
   cin >> c1;
   chain.InsertBack(c1);
   break;
  case 3:
   cout << "어느 노드 뒤에 넣겠습니까:";
   char c2;
   cin >> c2;
   cout << "뒤에 들어갈 노드 값을 입력하세요:";
   char c3;
   cin >> c3;
   chain.InsertAfter(c2,c3);
   break;
  case 4:
   cout << "지울 노드 값을 입력하세요:";
   char c4;
   cin >> c4;
   chain.DeleteNode(c4);
   break;
  case 5:
   cout << "찾을 노드 값을 입력하세요:";
   char c5;
   cin >> c5;
   chain.FindNode(c5);
   break;
  case 6:
   cout << "노드를 뒤집습니다.";
   chain.ReverseNode();
   break;
  case 7:
   chain.Showlist();
   break;
  case 8:
   break;
 }
} while( num != 8 );
}
