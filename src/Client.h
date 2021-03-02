#pragma once
#include"Server.h"
/**
*	클라이언트는 채팅방과 친구를 관리.
*	로그인 한 유저가 친구 목록, 채팅방 리스트를 관리.
*	로그인 한 유저가 채팅함.
*	@author	장규범
*	@date	20171027
*/
class Client : public Server
{
public:
	/**
	*	@brief	생성자
	*	@pre	없음.
	*	@post	없음.
	*/
	Client();
	/**
	*	@brief	소멸자
	*	@pre	없음.
	*	@post	없음.
	*/
	~Client();
	
	//get함수

	/**
	*	@brief	m_isLogin을 리턴
	*	@pre	없음
	*	@post	m_isLogin 리턴
	*/
	bool GetIsLogin();
	
	//set 함수

	/**
	*	@brief	멤버변수 m_user를 설정함
	*	@pre	m_user가 설정안됨
	*	@post	m_user 설정됨
	*	@param	Member* Temp
	*/
	void SetUser(Member *Temp);

	/**
	*	@brief	m_isLogin의 상태 설정
	*	@pre	없음
	*	@post	로그인이 되어 있으면 m_isLogin false, 안되어 있으면 m_isLogin true
	*/
	void SetIsLogin();

	//일반 함수

	/**
	*	@brief	로그인 하는 함수
	*	@pre	로그인이 안되어 있어야 함
	*	@post	로그인을 함.
	*	@return	로그인 성공 시 true 리턴, 아니면 false 리턴
	*/
	bool Login();

	/**
	*	@brief	로그아웃 하는 함수
	*	@pre	로그인이 되어 있어야 함
	*	@post	로그아웃을 함.
	*	@return	로그아웃 성공 시 true 리턴, 아니면 false 리턴
	*/
	bool Logout();

	/**
	*	@brief	보낼 메시지 생성함
	*	@pre	없음.
	*	@post	메시지가 생성됨
	*	@return	Message*
	*/
	Message* MakeMessage();

	/**
	*	@brief	서버에서 호출하는 함수이다. 호출 될 때 메시지가 파라미터로 전달
	*	@pre	메시지가 존재해야 함.
	*	@post	메시지 호출함.
	*	@return	Message*
	*/
	Message* RecieveMessageFromServer();

	/**
	*	@brief	MakeMessage()로 생성된 메시지를 messageQ에 저장한다.
	*	@pre	MakeMessage()로 메시지 생성함.
	*	@post	messageQ에 Enqueue
	*	@return	전송한 Message*
	*/
	Message* SendMessageToServer();

	/**
	*	@brief	멤버의 친구 리스트에 친구 추가한다.
	*	@pre	친구가 이미 친구 리스트에 추가되어 있으면 안됨.
	*	@post	친구 리스트에 추가됨
	*/
	void AddFriend();

	/**
	*	@brief	친구 목록 출력하는 함수
	*	@pre	없음.
	*	@post	친구 목록이 출력됨.
	*/
	void printFriendList();
	
	/**
	*	@brief	채팅 방 만드는 함수.
	*	@pre	없음
	*	@post	유저는 개인 채팅방과 단체 채팅방 중 하나를 만든다.
	*	@return	채팅방이 만들어지면 true 리턴, 채팅방을 안만들면 false 리턴
	*/
	bool MakeChatRoom();

	/**
	*	@brief	채팅방 아이디를 입력받아 해당 하는 채팅방에서 나간다
	*	@pre	없음.
	*	@post	채팅방에서 나간다.
	*/
	void ExitsChatRoom();

	/**
	*	@brief	메시지를 유저의 아이디를 통해 전송한다. 
	*	@pre	없음.
	*	@post	메시지가 전송됨.
	*/
	void SendMessageToUser();

	/**
	*	@brief	메시지를 채팅방으로 메시지 전송한다.
	*	@pre	없음.
	*	@post	메시지가 전송됨.
	*/
	void sendMessageToChatRoom();

	/**
	*	@brief	chatRoomList에 chatRoomList를 화면에 출력
	*	@pre	chatRoomList != empty
	*	@post	화면에 chatRoomList 출력
	*/
	void DisplayChat();

	/**
	*	@brief	채팅방 아이디를 입력받아, 해당 채팅방의 메시지를 출력하는 함수
	*	@pre	없음
	*	@post	메시지가 출력됨
	*	@param	채팅방 아이디
	*	@return	해당 채팅방이 리턴됨
	*/
	ChatRoom* printMessageInChatRoom(int chatRoomId);

	/**
	*	@brief	현재 로그인한 멤버의 정보를 수정하는 함수
	*	@pre	없음
	*	@post	멤버의 정보 수정.
	*/
	void ChangeUserInfo();

	/**
	*	@brief	채팅방 ID를 검색하여 채팅방의 이름을 수정(현재 로그인 한 사용자에게만 적용)
	*	@pre	없음.
	*	@post	채팅방 이름이 변경됨.
	*/
	void ChangeChatRoomName();

	/**
	*	@brief	친구 삭제를 하는 함수
	*	@pre	없음.
	*	@post	m_user의 친구 목록에서 해당 친구를 삭제한다
	*/
	void deleteFriends();

private:
	Member* m_user; // 유저 정보 저장 Member
	bool m_isLogin; // 로그인 되있으면 true 리턴, 로그아웃이 되있으면 false 리턴
};

