#pragma once
#include"Message.h"
/**
*	채팅방을 만드는 클래스 : 채팅방은 메시지 목록을 가짐.
*	@author	장규범
*	@date	20171027
*/
class ChatRoom
{
public:
	/**
	*	@brief	생성자
	*	@pre	없음.
	*	@post	없음.
	*/
	ChatRoom();
	/**
	*	@brief	소멸자
	*	@pre	없음.
	*	@post	없음.
	*/
	~ChatRoom();

	//채팅방 함수

	/**
	*	@brief	채팅방 만드는 순수 가상 함수
	*	@pre	없음.
	*	@post	메시지 추가
	*	@param	채팅방 메시지 리스트에 추가할 Message* data
	*/
	virtual void addChatRoom(Message* data) = 0;

	/**
	*	@brief	채팅방 아이디를 업데이트 하는 순수 가상 함수
	*	@pre	없음.
	*	@post	채팅방 아이디 설정
	*	@param	채팅방 아이디
	*/
	virtual void updateChatRoomID(int chatRoomID) = 0;

	/**
	*	@brief	메시지를 받는 유저들의 ID를 추가하는 순수 가상 함수
	*	@pre	이미 있으면 예외처리
	*	@post	받는 사람 아이디 추가
	*	@param	int id, string name
	*/
	virtual void AddReceiverId(string id, string name) = 0;

	/**
	*	@brief	채팅방에서의 대화 내역을 출력하는 순수 가상 함수
	*	@pre	채팅방이 설정
	*	@post	대화 내용 출력
	*/
	virtual void PrintMessageList() = 0;

	/**
	*	@brief	채팅방에서 해당 아이디를 가진 유저를 제거한다(순수 가상 함수)
	*	@pre	해당 아이디를 가진 유저가 있음.
	*	@post	해당 아이디
	*	@param	int userId
	*	@return	제거 시 true 리턴
	*/
	virtual bool DeleteReceiver(string userId) = 0;

	//Get 함수

	/**
	*	@brief	채팅방 아이디를 리턴하는 순수 가상 함수
	*	@pre	id 설정됨
	*	@post	없음
	*	@return	채팅방 아이디
	*/
	virtual int getChatRoomID() = 0;

	/**
	*	@brief	1:1 채팅을 할 유저의 ID를 리턴하는 순수 가상 함수
	*	@pre	리시버 아이디 설정됨
	*	@post	받는 사람의 아이디 리턴
	*	@return	받는 사람의 아이디
	*/
	virtual string GetReceiverId() = 0;

	/**
	*	@brief	메시지를 받는 유저들의 ID를 가져오는 순수 가상 함수
	*	@pre	받는 사람들의 아이디 설정됨
	*	@post	받는 사람들의 아이디 가져옴
	*	@return	받는 사람들의 아이디
	*/
	virtual LinkedList<string> GetReceiversId() = 0;

	/**
	*	@brief	채팅방의 메시지 리스트들 가져오는 순수 가상 함수
	*	@pre
	*	@post
	*	@return	LinkedList<Message*>
	*/
	virtual LinkedList<Message*> GetMessageList() = 0;

	/**
	*	@brief	채팅방의 이름을 리턴하는 순수 가상 함수
	*	@pre	없음
	*	@post	없음
	*	@return	string
	*/
	virtual string GetChatRoomName() = 0;

	/**
	*	@brief	채팅방 기본 이름인지 확인 하는 함수
	*	@pre	이름이 설정되어 있어야 함.
	*	@post	없음.
	*	@return	채팅방 기본 이름이면 true
	*/
	virtual bool GetBasicChatRoomName() = 0;

	//Set 함수

	/**
	*	@brief	1:1 채팅을 할 유저의 Id를 셋하는 순수 가상 함수
	*	@pre	없음
	*	@post	받는 사람 아이디 설정
	*	@param	int id, string name
	*/
	virtual void SetReceiverId(string id, string name) = 0;

	/**
	*	@brief	채팅방의 이름 설정, 기본으로 유저들의 ID로 구성. 순수 가상 함수
	*	@pre	없음.
	*	@post	없음.
	*	@return	채팅방 이름
	*/
	virtual string SetChatRoomNameByID() = 0;

	/**
	*	@brief	채팅방의 이름을 설정하는 순수 가상 함수(채팅방의 기본 이름은 채팅방의 유저들의 이름.)
	*	@pre	없음.
	*	@post	채팅방 이름 설정됨.
	*	@param	string name
	*/
	virtual void SetChatRoomByName(string name) = 0;

};

