#include<iostream>
using namespace std;

/**
*	�̱۸� ��ũ�� ����Ʈ�� �����ϱ� ���� NodeType
*	@author	��Թ�
*	@date	20171027
*/
template<typename T>
struct NodeType
{
	T data;		///< ������ ��忡 ���� ������
	NodeType* next;	///< ���� ��带 ����Ű�� ���� ��� ������
};

/**
*	�̱۸� ��ũ�� ����Ʈ Ŭ����(Sorted-Linked-list)
*	@author	��Թ�
*	@date	20171027
*/
template<typename T>
class LinkedList
{
public:
	/**
	*	@brief	�⺻ ������
	*/
	LinkedList();

	/**
	*	@brief	�⺻ �Ҹ���
	*/
	~LinkedList();


	/**
	*	@brief	LinkedList�� ���.
	*	@pre	����.
	*	@post	LinkedList�� �����.
	*/
	void Empty();


	/**
	*	@brief	����Ʈ �ʱ�ȭ
	*	@pre	����.
	*	@post	m_pCurPoiner �ʱ�ȭ;
	*/
	void ResetList();

	/**
	*	@brief	LinkedList�� T�� �߰��ϴ� �Լ�
	*	@pre	����.
	*	@post	LinkedList�� T �߰�.
	*	@param	T Temp
	*/
	void Add(T Temp);

	/**
	*	@brief	LinkedList�� index ���� ���� �Լ�
	*	@pre	this->length >= index
	*	@post	����Ʈ�� index��° T ����
	*	@param	T data
	*/
	void Delete(T data);

	/**
	*	@brief	LinkedList�� T ���Ҹ� ��ȯ
	*	@pre	this->length >= index
	*	@post	����
	*	@param	T& data
	*	@return	���� ������ ã���� 1 ����, ��ã���� 0 ����
	*/
	bool Get(T& data);

	/**
	*	@brief	LinkedList�� index��° ���Ҹ� ��ȯ
	*	@pre	this->length >= index
	*	@post	����
	*	@param	int index
	*	@return	T
	*/
	T Get(int index);

	/**
	*	@brief	LinkedList�� ���̸� ����.
	*	@pre	����.
	*	@post	����
	*	@return	this->length
	*/
	int size();

	/**
	*	@brief	���� ���Ҹ� ����Ŵ = this->m_pCurPointer ++;
	*	@pre	����.
	*	@post	����.
	*	@param	T& Temp
	*/
	void GetNextItem(T& Temp);
private:
	NodeType<T> *m_pList;	//LinkedList�� ù��° ��带 ����Ű�� ������
	NodeType<T> *m_pCurPointer;	//LinkedList�� ���� ��Ʈ�� ����Ű�� ������
	int length;	//LinkedList�� ����
};

template<typename T>
LinkedList<T>::LinkedList()
{
	this->length = 0;
	this->m_pList = NULL;
	this->m_pCurPointer = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
}

template<typename T>
void LinkedList<T>::Empty()
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (this->m_pList != NULL)
	{
		tempPtr = m_pList;
		this->m_pList = m_pList->next;
		delete tempPtr;
	}

	this->length = 0;
}

template<typename T>
void LinkedList<T>::ResetList()
{
	this->m_pCurPointer = NULL;
}

template<typename T>
void LinkedList<T>::Add(T Temp)
{
	this->ResetList();	// ���� curpointer�� �ʱ�ȭ

	NodeType<T> *node = new NodeType<T>;	// ����Ʈ�� �߰��� ���ο� ���
	NodeType<T> *pre;		// ���� ��带 ����ų ������
	T temp;	// �ӽ��� T ����

					// *node ����
	node->data = Temp;
	node->next = NULL;

	//	list���� node�� ���� ��� = this->length = 0;
	if (this->length == 0)
		this->m_pList = node;

	// list���� node�� �ϳ� �̻� ���� = this->length > 0;
	else
	{
		while (1)
		{
			pre = this->m_pCurPointer;	// pre ����

			this->GetNextItem(temp);	// GetNextItem �Լ� �̿��� node ������ ����

			if (this->m_pCurPointer->next == NULL)	// this->m_pCurPointer = NULL, �� ��� ���� ��� ���⿡ node�� �߰�
			{
				this->m_pCurPointer->next = node;
				break;
			}
		}
	}

	this->length++;
}

template<typename T>
void LinkedList<T>::Delete(T data)
{
	this->ResetList();	//this->m_pCurPointer�� �ʱ�ȭ

	T dummy;	//�ӽ� ����

	bool found = false;	//data�� ������ true
	for (int i = 0; i < this->length; i++)
	{
		this->GetNextItem(dummy);

		if (this->m_pCurPointer->data == data)
		{
			found = true;
			break;
		}
	}

	if (found)	//���� data�� LinkedList���� �����Ѵٸ�
	{
		this->length--;
		this->ResetList();

		this->GetNextItem(dummy);
		while (1)
		{
			if (this->m_pCurPointer->next == NULL)
			{
				this->m_pCurPointer = NULL;
				break;
			}
			else if (this->m_pList->data == data)
			{
				NodeType<T> *newNode = this->m_pList;
				this->m_pList = this->m_pList->next;

				newNode->next = NULL;
				newNode = NULL;

				break;
			}
			else if (this->m_pCurPointer->next->data == data)
			{
				NodeType<T> *newNode = this->m_pCurPointer->next;
				this->m_pCurPointer->next = this->m_pCurPointer->next->next;

				newNode->next = NULL;
				newNode = NULL;

				break;
			}
			this->GetNextItem(dummy);
		}
	}
}

template<typename T>
bool LinkedList<T>::Get(T &data)	//���� Get�� �����ϸ� false ����
{
	this->ResetList();

	NodeType<T> *temp;
	T dummy;
	bool found = false;	// item�� ����Ʈ ���� ������ true

	temp = this->m_pList;

	for (int i = 0; i < this->length; i++)	// ����Ʈ�� ���̸�ŭ �ݺ��Ѵ�
	{
		this->GetNextItem(dummy);	//	dummy�� �����͸� ����Ʈ�� T���� ����

		if (dummy == data)	//	�ݺ� ���� ����Ʈ ������ item�� ��ġ�ϴ� �����Ͱ� ������ �ݺ� ����
		{
			found = true;
			break;
		}
	}

	// ����
	if (found)
		return true;
	else
		return false;

}

template<typename T>
T LinkedList<T>::Get(int index)
{
	this->ResetList();

	T temp;

	this->GetNextItem(temp);
	for (int i = 0; i < index; i++)
		this->GetNextItem(temp);

	return temp;
}

template<typename T>
int LinkedList<T>::size()
{
	return this->length;
}

template<typename T>
void LinkedList<T>::GetNextItem(T& Temp)
{
	if (this->m_pCurPointer == NULL)	// ���� �����Ͱ� NULL�̸� ���� �����ʹ� ù��° ���
		this->m_pCurPointer = this->m_pList;
	else
		this->m_pCurPointer = this->m_pCurPointer->next;

	Temp = this->m_pCurPointer->data;	// Temp�� ���� �����Ͱ� ����Ű�� ������ ����
}