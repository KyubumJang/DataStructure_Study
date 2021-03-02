#pragma once

#define MAXSIZE_Q 1000
/**
*	큐타입의 템플릿 클래스
*	@author	장규범
*	@date	20171027
*/
template<typename T>
class QueueType
{
private:
	T* item;	// Q에 저장할 T타입 변수 : 동적할당 배열
	int front;	// 삭제가 일어나는 곳
	int rear;	// 삽입이 일어나는 곳
	int maxQue;	// 최대 큐 사이즈
public:

	/**
	*	@brief	생성자
	*	@pre	없음.
	*	@post	없음.
	*/
	QueueType();

	/**
	*	@brief	생성자 : int타입을 받음
	*	@pre	없음.
	*	@post	없음.
	*	@param	int max
	*/
	QueueType(int max);

	/**
	*	@brief	소멸자
	*	@pre	없음.
	*	@post	없음
	*/
	~QueueType();


	/**
	*	@brief	Queue가 비었는지 확인
	*	@pre	없음.
	*	@post	없음.
	*	@return	비었으면 1 리턴, 아닐시 0 리턴
	*/
	bool IsEmpty();

	/**
	*	@brief	Queue가 가득 찼는지 확인하는 함수
	*	@pre	없음.
	*	@post	없음.
	*	@return	다 찼을시 1 리턴, 아닐시 0 리턴
	*/
	bool IsFull();

	/**
	*	@brief	Queue에 아이템 추가
	*	@pre	없음.
	*	@post	Queue에 아이템 추가
	*	@param	T 타입 item
	*/
	void Enqueue(T item);

	/**
	*	@brief	Queue에서 아이템 삭제
	*	@pre	Queue에 아이템 존재
	*	@post	없음.
	*	@param	T& 타입 item
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
	this->item = new T[maxQue]; // T으로 동적 할당
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