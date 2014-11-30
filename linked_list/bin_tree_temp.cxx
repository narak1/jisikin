#include <iostream>
using namespace std;

template <class T> class Tree;

template <class T> //linklist구현
class TreeNode
{
	friend class Tree<T>;
public:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};

template <class T>
class Tree
{
public:
	Tree(){ root = NULL; };
	void insert(T);
	void add_node(TreeNode<T>* &node, TreeNode<T> *t);
	bool IsEmpty() const { return root==NULL; };
	void Inorder();
	void Inorder(TreeNode<T> *currentNode);
	void Postorder();
	void Postorder(TreeNode<T> *currentNode);
private:
	TreeNode<T> *root;
};

// 트리 삽입
template <class T>
void Tree<T>::insert(T d)
{
	TreeNode<T> *t = new TreeNode<T>;
	t->data = d;
	t->leftChild = NULL;
	t->rightChild = NULL;

	add_node(root, t);
}

template <class T>
void Tree<T>::add_node(TreeNode<T>* &curr, TreeNode<T> *t)
{
	if( curr == NULL ) {
		curr = t;
		return;
	}

	if(t->data > curr->data) add_node(curr->rightChild, t);
	else add_node(curr->leftChild, t);
}

//트리의 전체 출력
template <class T>
void Visit(TreeNode<T> *currentNode)
{
//해당 노드를 방문하고 나서 화면에 데이터를 출력하는 함수
cout<<currentNode->data<<endl;
}

template <class T>
void Tree<T>::Postorder()
{
//전체 트리를 순회하기 위해서 Driver 함수는 workhorse함수를 호출하며
//Driver는 Tree 클래스의 공용 멤버 함수로 선언된다.
Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T> *currentNode)
{
	if( currentNode == NULL ) return;

//workHorse는 CurrentNode를 Root로 하는 서브 트리를 순회한다.
//이 workhorse는 Tree클래스의 전용 멤버 함수로 선언된다.
	Postorder(currentNode->leftChild); // L
	Postorder(currentNode->rightChild); // R
	Visit(currentNode); // V
}

template <class T>
void Tree<T>::Inorder()
{
//전체 트리를 순회하기 위해서 Driver 함수는 workhorse함수를 호출하며
//Driver는 Tree 클래스의 공용 멤버 함수로 선언된다.
Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T> *currentNode)
{
	if( currentNode == NULL ) return;

//workHorse는 CurrentNode를 Root로 하는 서브 트리를 순회한다.
//이 workhorse는 Tree클래스의 전용 멤버 함수로 선언된다.
	Inorder(currentNode->leftChild); // L
	Visit(currentNode); // V
	Inorder(currentNode->rightChild); // R
}

int main()
{
	Tree<int> b;
	int tmp;
	while(1) {
		cout<<" Enter data to be inserted (0 for finish) : ";
		cin>>tmp;
		if( tmp == 0 ) break;
		b.insert(tmp);
	}
	cout<<" In-Order Traversal "<<endl;
	cout<<" -------------------"<<endl;
	b.Inorder();
	cout<<" Post-Order Traversal "<<endl;
	cout<<" -------------------"<<endl;
	b.Postorder();
}
