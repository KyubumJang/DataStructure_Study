#pragma once
#include"Member.h"

/**
*	서버는 application 클래스로 간주하라고 했지만 서버 클래스 새로 생성함.
*	서버는 카카오톡을 이용하는 모든 유저들의 정보를 저장.
*	메시지도 이 서버에 저장한다.
*	@author	장규범
*	@date	20171027
*/
class Server
{
public:
	/**
	*	@brief	생성자
	*	@pre	없음.
	*	@post	없음.
	*/
	Server();
	/**
	*	@brief	소멸자
	*	@pre	없음.
	*	@post	없음.
	*/
	~Server();

	/**
	*	@brief	회원가입 하는 함수
	*	@pre	회원 가입이 되어 있으면 안됨
	*	@post	회원가입 됨
	*/
	void JoinMember();

	/**
	*	@brief	회원 탈퇴 하는함수
	*	@pre	로그인
	*	@post	회원 탈퇴
	*	@return	탈퇴 시 true 리턴
	*/
	bool leaveMember();

	/**
	*	@brief	messageQ의 가장 최신 메시지를 Dequeue하는 함수
	*	@pre	없음.
	*	@post	없음.
	*/
	void DequeueMessageQ();


	/**
	*	@brief	messageQ에 (Message*)를 Enqueue
	*	@pre	없음
	*	@post	큐에 메시지 저장
	*	@param	Message* data
	*/
	void EnqueueMessage(Message* data);

	/**
	*	@brief	큐에 저장된 메시지를 메시지 받는 친구에게 보냄
	*	@pre	큐에 메시지가 저장되어 있음.
	*	@post	메시지를 Temp에 저장
	*	@param	메시지를 받을 유저 Member *Temp
	*	@return	chatRoomId(채팅방 아이디)
	*/
	int SendMessageToReceiver(Member* Temp);

	/**
	*	@brief	큐에 저장된 메시지를 채팅방에 보냄
	*	@pre	채팅방이 설정되어 있음, messageQ에 메시지 있음
	*	@post	해당 채팅방에 메시지 전송
	*	@param	채팅방 ChatRoom* chat
	*/
	void SendMessageToChatRoom(ChatRoom* chat);

	/**
	*	@brief	개인 채팅방을 만드는 함수
	*	@pre	없음
	*	@post	개인 채팅방 생성
	*	@param	string userId
	*/
	void MakePersonalChatRoom(string userId);

	/**
	*	@brief	단체 채팅방을 만드는 함수
	*	@pre	없음
	*	@post	단체 채팅방 생성
	*	@parma	LinkedList<string> userId, string chatRoomName
	*/
	void MakeGroupChatRoom(LinkedList<string> userId, string chatRoomName);

	/**
	*	@brief	현재 유저가 파라미터로 받은 해당 chatRoomId를 가진 채팅방에서 나간다
	*	@pre	chatRoomId의 채팅방이 존재
	*	@post	chatRoomId를 가진 멤버들의 채팅방에서 현재 유저가 없어짐.
	*	@param	int chatRoomId
	*/
	void ExitChatRoom(int chatRoomId);

	/**
	*	@brief	현재 사용자의 친구 목록에서 친구 삭제함.
	*	@pre	없음.
	*	@post	현재 사용자의 친구 목록에서 친구 삭제됨
	*	@param	삭제할 친구 Member* data
	*/
	void deleteFriend(Member* data);

	/**
	*	@brief	멤버 아이디로 멤버 찾아서 회원정보 찾음
	*	@pre	ID가 일치하는 멤버 존재함.
	*	@post	해당 아이디의 멤버 리턴
	*	@param	string userId
	*	@return	Member*
	*/
	Member* findMemberbyId(string userId);

	/**
	*	@brief	이름으로 친구 검색
	*	@pre	없음.
	*	@post	없음.
	*	@return	해당하는 멤버가 있으면 1 리턴, 없으면 0 리턴.
	*/
	bool findMemberByName();

protected:
	int chatRoomId;	//채팅방 고유 아이디
	QueueType<Message*> messageQ; // Client class에서 메시지를 보내고자 할 때는 이 messageQ에 내용을 전달한다.(큐에서 가장 최신의 메시지를 현재 멤버의 chatList에 전달)
	LinkedList<Member*> memberList; // 메신저 사용하는 멤버 저장하는 리스트(회원 가입 때 멤버리스트에 추가)
	Member* curMember;	//서버에 로그인 한 멤버 변수

};

