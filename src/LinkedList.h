#include<iostream>
using namespace std;

/**
*	싱글리 링크드 리스트를 구현하기 위한 NodeType
*	@author	장규범
*	@date	20171027
*/
template<typename T>
struct NodeType
{
	T data;		///< 각각의 노드에 대한 데이터
	NodeType* next;	///< 다음 노드를 가리키기 위한 노드 포인터
};

/**
*	싱글리 링크드 리스트 클래스(Sorted-Linked-list)
*	@author	장규범
*	@date	20171027
*/
template<typename T>
class LinkedList
{
public:
	/**
	*	@brief	기본 생성자
	*/
	LinkedList();

	/**
	*	@brief	기본 소멸자
	*/
	~LinkedList();


	/**
	*	@brief	LinkedList를 비움.
	*	@pre	없음.
	*	@post	LinkedList가 비워짐.
	*/
	void Empty();


	/**
	*	@brief	리스트 초기화
	*	@pre	없음.
	*	@post	m_pCurPoiner 초기화;
	*/
	void ResetList();

	/**
	*	@brief	LinkedList에 T를 추가하는 함수
	*	@pre	없음.
	*	@post	LinkedList에 T 추가.
	*	@param	T Temp
	*/
	void Add(T Temp);

	/**
	*	@brief	LinkedList의 index 원소 삭제 함수
	*	@pre	this->length >= index
	*	@post	리스트의 index번째 T 삭제
	*	@param	T data
	*/
	void Delete(T data);

	/**
	*	@brief	LinkedList의 T 원소를 반환
	*	@pre	this->length >= index
	*	@post	없음
	*	@param	T& data
	*	@return	만약 데이터 찾으면 1 리턴, 못찾으면 0 리턴
	*/
	bool Get(T& data);

	/**
	*	@brief	LinkedList의 index번째 원소를 반환
	*	@pre	this->length >= index
	*	@post	없음
	*	@param	int index
	*	@return	T
	*/
	T Get(int index);

	/**
	*	@brief	LinkedList의 길이를 리턴.
	*	@pre	없음.
	*	@post	없음
	*	@return	this->length
	*/
	int size();

	/**
	*	@brief	다음 원소를 가리킴 = this->m_pCurPointer ++;
	*	@pre	없음.
	*	@post	없음.
	*	@param	T& Temp
	*/
	void GetNextItem(T& Temp);
private:
	NodeType<T> *m_pList;	//LinkedList의 첫번째 노드를 가리키는 포인터
	NodeType<T> *m_pCurPointer;	//LinkedList의 현재 노트를 가리키는 포인터
	int length;	//LinkedList의 길이
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
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	this->ResetList();	// 현재 curpointer를 초기화

	NodeType<T> *node = new NodeType<T>;	// 리스트에 추가할 새로운 노드
	NodeType<T> *pre;		// 이전 노드를 가리킬 포인터
	T temp;	// 임시형 T 변수

					// *node 갱신
	node->data = Temp;
	node->next = NULL;

	//	list내에 node가 없을 경우 = this->length = 0;
	if (this->length == 0)
		this->m_pList = node;

	// list내에 node가 하나 이상 존재 = this->length > 0;
	else
	{
		while (1)
		{
			pre = this->m_pCurPointer;	// pre 갱신

			this->GetNextItem(temp);	// GetNextItem 함수 이용해 node 포인터 갱신

			if (this->m_pCurPointer->next == NULL)	// this->m_pCurPointer = NULL, 즉 비어 있을 경우 여기에 node를 추가
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
	this->ResetList();	//this->m_pCurPointer를 초기화

	T dummy;	//임시 파일

	bool found = false;	//data가 있으면 true
	for (int i = 0; i < this->length; i++)
	{
		this->GetNextItem(dummy);

		if (this->m_pCurPointer->data == data)
		{
			found = true;
			break;
		}
	}

	if (found)	//만약 data가 LinkedList내에 존재한다면
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
bool LinkedList<T>::Get(T &data)	//만약 Get에 실패하면 false 리턴
{
	this->ResetList();

	NodeType<T> *temp;
	T dummy;
	bool found = false;	// item이 리스트 내에 있으면 true

	temp = this->m_pList;

	for (int i = 0; i < this->length; i++)	// 리스트의 길이만큼 반복한다
	{
		this->GetNextItem(dummy);	//	dummy의 데이터를 리스트의 T으로 갱신

		if (dummy == data)	//	반복 도중 리스트 내에서 item과 일치하는 데이터가 나오면 반복 중지
		{
			found = true;
			break;
		}
	}

	// 리턴
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
	if (this->m_pCurPointer == NULL)	// 현재 포인터가 NULL이면 현재 포인터는 첫번째 노드
		this->m_pCurPointer = this->m_pList;
	else
		this->m_pCurPointer = this->m_pCurPointer->next;

	Temp = this->m_pCurPointer->data;	// Temp에 현재 포인터가 가리키는 데이터 대입
}