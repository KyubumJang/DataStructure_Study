#pragma once
#include"ChatRoom.h"
/**
*	그룹 채팅방 클래스 : ChatRoom을 상속받음.
*	@author	장규범
*	@date	20171027
*/
class GroupChatRoom: public ChatRoom
{
public:
	/**
	*	@brief	생성자
	*	@pre	없음.
	*	@post	없음.
	*/
	GroupChatRoom();
	/**
	*	@brief	소멸자
	*	@pre	없음.
	*	@post	없음.
	*/
	~GroupChatRoom();

	//채팅방 함수

	/**
	*	@brief	채팅방 만드는 함수
	*	@pre	없음.
	*	@post	메시지 추가
	*	@param	채팅방 메시지 리스트에 추가할 Message* data
	*/
	void addChatRoom(Message* data);

	/**
	*	@brief	채팅방 아이디를 업데이트 하는 함수
	*	@pre	없음.
	*	@post	채팅방 아이디 설정
	*	@param	채팅방 아이디
	*/
	void updateChatRoomID(int chatRoomID);

	/**
	*	@brief	메시지를 받는 유저들의 ID를 추가하는 함수
	*	@pre	이미 있으면 예외처리
	*	@post	받는 사람 아이디 추가
	*	@param	int id, string name
	*/
	void AddReceiverId(string id, string name);

	/**
	*	@brief	채팅방에서의 대화 내역을 출력하는 함수
	*	@pre	채팅방이 설정
	*	@post	대화 내용 출력
	*/
	void PrintMessageList();

	/**
	*	@brief	채팅방에서 해당 아이디를 가진 유저를 제거한다
	*	@pre	해당 아이디를 가진 유저가 있음.
	*	@post	해당 아이디
	*	@param	int userId
	*	@return	제거 시 true 리턴
	*/
	bool DeleteReceiver(string userId);

	//Get 함수

	/**
	*	@brief	채팅방 아이디를 리턴하는 함수
	*	@pre	id 설정됨
	*	@post	없음
	*	@return	채팅방 아이디
	*/
	int getChatRoomID();

	/**
	*	@brief	1:1 채팅을 할 유저의 ID를 리턴하는 함수
	*	@pre	리시버 아이디 설정됨
	*	@post	받는 사람의 아이디 리턴
	*	@return	받는 사람의 아이디
	*/
	string GetReceiverId();

	/**
	*	@brief	메시지를 받는 유저들의 ID를 가져오는 함수
	*	@pre	받는 사람들의 아이디 설정됨
	*	@post	받는 사람들의 아이디 가져옴
	*	@return	받는 사람들의 아이디
	*/
	LinkedList<string> GetReceiversId();

	/**
	*	@brief	채팅방의 메시지 리스트들 가져오는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	LinkedList<Message*>
	*/
	LinkedList<Message*> GetMessageList();

	/**
	*	@brief	채팅방의 이름을 리턴하는 순수 가상 함수 구현
	*	@pre	없음
	*	@post	없음
	*	@return	string
	*/
	string GetChatRoomName();

	/**
	*	@brief	채팅방 기본 이름인지 확인 하는 함수
	*	@pre	이름이 설정되어 있어야 함.
	*	@post	없음.
	*	@return	채팅방 기본 이름이면 true
	*/
	bool GetBasicChatRoomName();

	//Set 함수

	/**
	*	@brief	1:1 채팅을 할 유저의 Id를 셋하는 순수 가상 함수
	*	@pre	없음
	*	@post	받는 사람 아이디 설정
	*	@param	int id, string name
	*/
	void SetReceiverId(string id, string name);

	/**
	*	@brief	채팅방의 이름 설정, 기본으로 유저들의 ID로 구성. 
	*	@pre	없음.
	*	@post	없음.
	*	@return	채팅방 이름
	*/
	string SetChatRoomNameByID();

	/**
	*	@brief	채팅방의 이름을 설정하는 함수(채팅방의 기본 이름은 채팅방의 유저들의 이름.)
	*	@pre	없음.
	*	@post	채팅방 이름 설정됨.
	*	@param	string name
	*/
	void SetChatRoomByName(string name);

private:
	int m_chatRoomId;	//채팅방의 Id
	string m_chatRoomName;	//채팅방 이름
	bool m_IsBasicName;	//이름이 기본 설정인지 확인하는 변수

	LinkedList<string> chatMembersId;	//채팅에 참가한 유저 아이디 목록
	LinkedList<string> chatMembersList;	//채팅에 참가한 유저 이름 목록
	LinkedList<Message*> messageList;	//채팅 목록을 저장하는 리스트

	

};

