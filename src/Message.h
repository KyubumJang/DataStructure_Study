#pragma once
#include<string>
#include<iomanip>
#include"QueueType.h"
#include"LinkedList.h"
#include<string>
#include<iomanip>
/**
*	카카오톡에서 메시지를 관리하는 클래스
*	@author	장규범
*	@date	20171027
*/
class Message
{
public:
	/**
	*	@brief	생성자
	*	@pre	없음.
	*	@post	없음.
	*/
	Message();

	/**
	*	@brief	소멸자
	*	@pre	없음.
	*	@post	없음.
	*/
	~Message();

	/**
	*	@brief	메시지의 sendID를 리턴
	*	@return	m_sendId
	*/
	string getSendId();

	/**
	*	@brief	메시지의 content를 리턴
	*	@return	m_content
	*/
	string getContent();

	/**
	*	@brief	메시지를 리턴함
	*	@pre	없음.
	*	@post	없음.
	*	@return	메시지
	*/
	Message GetMessage();

	/**
	*	@brief	메시지를 보냄
	*	@pre	없음.
	*	@post	없음.
	*	@param	발신자 ID, 메시지 내용
	*/
	void sendMessage(string sendID, string content);


	/**
	*	@brief	메시지의 내용을 출력한다
	*/
	void printMessage();
private:
	string m_sendId;	//보내는 사람 아이디
	string m_content;	//메시지 내용
};

