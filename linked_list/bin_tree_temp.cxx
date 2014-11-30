#include <iostream>
using namespace std;

template <class T> class Tree;

template <class T> //linklist����
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

// Ʈ�� ����
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

//Ʈ���� ��ü ���
template <class T>
void Visit(TreeNode<T> *currentNode)
{
//�ش� ��带 �湮�ϰ� ���� ȭ�鿡 �����͸� ����ϴ� �Լ�
cout<<currentNode->data<<endl;
}

template <class T>
void Tree<T>::Postorder()
{
//��ü Ʈ���� ��ȸ�ϱ� ���ؼ� Driver �Լ��� workhorse�Լ��� ȣ���ϸ�
//Driver�� Tree Ŭ������ ���� ��� �Լ��� ����ȴ�.
Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T> *currentNode)
{
	if( currentNode == NULL ) return;

//workHorse�� CurrentNode�� Root�� �ϴ� ���� Ʈ���� ��ȸ�Ѵ�.
//�� workhorse�� TreeŬ������ ���� ��� �Լ��� ����ȴ�.
	Postorder(currentNode->leftChild); // L
	Postorder(currentNode->rightChild); // R
	Visit(currentNode); // V
}

template <class T>
void Tree<T>::Inorder()
{
//��ü Ʈ���� ��ȸ�ϱ� ���ؼ� Driver �Լ��� workhorse�Լ��� ȣ���ϸ�
//Driver�� Tree Ŭ������ ���� ��� �Լ��� ����ȴ�.
Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T> *currentNode)
{
	if( currentNode == NULL ) return;

//workHorse�� CurrentNode�� Root�� �ϴ� ���� Ʈ���� ��ȸ�Ѵ�.
//�� workhorse�� TreeŬ������ ���� ��� �Լ��� ����ȴ�.
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
