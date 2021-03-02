#pragma once

#define MAXSIZE_Q 1000
/**
*	ťŸ���� ���ø� Ŭ����
*	@author	��Թ�
*	@date	20171027
*/
template<typename T>
class QueueType
{
private:
	T* item;	// Q�� ������ TŸ�� ���� : �����Ҵ� �迭
	int front;	// ������ �Ͼ�� ��
	int rear;	// ������ �Ͼ�� ��
	int maxQue;	// �ִ� ť ������
public:

	/**
	*	@brief	������
	*	@pre	����.
	*	@post	����.
	*/
	QueueType();

	/**
	*	@brief	������ : intŸ���� ����
	*	@pre	����.
	*	@post	����.
	*	@param	int max
	*/
	QueueType(int max);

	/**
	*	@brief	�Ҹ���
	*	@pre	����.
	*	@post	����
	*/
	~QueueType();


	/**
	*	@brief	Queue�� ������� Ȯ��
	*	@pre	����.
	*	@post	����.
	*	@return	������� 1 ����, �ƴҽ� 0 ����
	*/
	bool IsEmpty();

	/**
	*	@brief	Queue�� ���� á���� Ȯ���ϴ� �Լ�
	*	@pre	����.
	*	@post	����.
	*	@return	�� á���� 1 ����, �ƴҽ� 0 ����
	*/
	bool IsFull();

	/**
	*	@brief	Queue�� ������ �߰�
	*	@pre	����.
	*	@post	Queue�� ������ �߰�
	*	@param	T Ÿ�� item
	*/
	void Enqueue(T item);

	/**
	*	@brief	Queue���� ������ ����
	*	@pre	Queue�� ������ ����
	*	@post	����.
	*	@param	T& Ÿ�� item
	*/
	void Dequeue(T &item);
};

template<typename T>
QueueType<T>::QueueType()
{
	this->maxQue = MAXSIZE_Q;
	this->front = 0;
	this->rear = 0;
	this->item = new T[this->maxQue];
}

template<typename T>
QueueType<T>::QueueType(int max)
{
	this->maxQue = max + 1;
	this->front = max;
	this->rear = max;
	this->item = new T[maxQue]; // T���� ���� �Ҵ�
}

template<typename T>
QueueType<T>::~QueueType()
{
	delete[] this->item;
}

template<typename T>
bool QueueType<T>::IsEmpty()
{
	return (this->rear == this->front);
}

template<typename T>
bool QueueType<T>::IsFull()
{
	return ((this->rear + 1) % this->maxQue == this->front);
}

template<typename T>
void QueueType<T>::Enqueue(T item)
{
	if (!this->IsFull())
	{
		this->rear = (this->rear + 1) % this->maxQue;
		this->item[this->rear] = item;
	}
}

template<typename T>
void QueueType<T>::Dequeue(T &item)
{
	if (!this->IsEmpty())
	{
		this->front = (this->front + 1) % this->maxQue;
		item = this->item[front];
	}
}