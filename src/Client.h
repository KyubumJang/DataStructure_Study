#pragma once
#include"Server.h"
/**
*	Ŭ���̾�Ʈ�� ä�ù�� ģ���� ����.
*	�α��� �� ������ ģ�� ���, ä�ù� ����Ʈ�� ����.
*	�α��� �� ������ ä����.
*	@author	��Թ�
*	@date	20171027
*/
class Client : public Server
{
public:
	/**
	*	@brief	������
	*	@pre	����.
	*	@post	����.
	*/
	Client();
	/**
	*	@brief	�Ҹ���
	*	@pre	����.
	*	@post	����.
	*/
	~Client();
	
	//get�Լ�

	/**
	*	@brief	m_isLogin�� ����
	*	@pre	����
	*	@post	m_isLogin ����
	*/
	bool GetIsLogin();
	
	//set �Լ�

	/**
	*	@brief	������� m_user�� ������
	*	@pre	m_user�� �����ȵ�
	*	@post	m_user ������
	*	@param	Member* Temp
	*/
	void SetUser(Member *Temp);

	/**
	*	@brief	m_isLogin�� ���� ����
	*	@pre	����
	*	@post	�α����� �Ǿ� ������ m_isLogin false, �ȵǾ� ������ m_isLogin true
	*/
	void SetIsLogin();

	//�Ϲ� �Լ�

	/**
	*	@brief	�α��� �ϴ� �Լ�
	*	@pre	�α����� �ȵǾ� �־�� ��
	*	@post	�α����� ��.
	*	@return	�α��� ���� �� true ����, �ƴϸ� false ����
	*/
	bool Login();

	/**
	*	@brief	�α׾ƿ� �ϴ� �Լ�
	*	@pre	�α����� �Ǿ� �־�� ��
	*	@post	�α׾ƿ��� ��.
	*	@return	�α׾ƿ� ���� �� true ����, �ƴϸ� false ����
	*/
	bool Logout();

	/**
	*	@brief	���� �޽��� ������
	*	@pre	����.
	*	@post	�޽����� ������
	*	@return	Message*
	*/
	Message* MakeMessage();

	/**
	*	@brief	�������� ȣ���ϴ� �Լ��̴�. ȣ�� �� �� �޽����� �Ķ���ͷ� ����
	*	@pre	�޽����� �����ؾ� ��.
	*	@post	�޽��� ȣ����.
	*	@return	Message*
	*/
	Message* RecieveMessageFromServer();

	/**
	*	@brief	MakeMessage()�� ������ �޽����� messageQ�� �����Ѵ�.
	*	@pre	MakeMessage()�� �޽��� ������.
	*	@post	messageQ�� Enqueue
	*	@return	������ Message*
	*/
	Message* SendMessageToServer();

	/**
	*	@brief	����� ģ�� ����Ʈ�� ģ�� �߰��Ѵ�.
	*	@pre	ģ���� �̹� ģ�� ����Ʈ�� �߰��Ǿ� ������ �ȵ�.
	*	@post	ģ�� ����Ʈ�� �߰���
	*/
	void AddFriend();

	/**
	*	@brief	ģ�� ��� ����ϴ� �Լ�
	*	@pre	����.
	*	@post	ģ�� ����� ��µ�.
	*/
	void printFriendList();
	
	/**
	*	@brief	ä�� �� ����� �Լ�.
	*	@pre	����
	*	@post	������ ���� ä�ù�� ��ü ä�ù� �� �ϳ��� �����.
	*	@return	ä�ù��� ��������� true ����, ä�ù��� �ȸ���� false ����
	*/
	bool MakeChatRoom();

	/**
	*	@brief	ä�ù� ���̵� �Է¹޾� �ش� �ϴ� ä�ù濡�� ������
	*	@pre	����.
	*	@post	ä�ù濡�� ������.
	*/
	void ExitsChatRoom();

	/**
	*	@brief	�޽����� ������ ���̵� ���� �����Ѵ�. 
	*	@pre	����.
	*	@post	�޽����� ���۵�.
	*/
	void SendMessageToUser();

	/**
	*	@brief	�޽����� ä�ù����� �޽��� �����Ѵ�.
	*	@pre	����.
	*	@post	�޽����� ���۵�.
	*/
	void sendMessageToChatRoom();

	/**
	*	@brief	chatRoomList�� chatRoomList�� ȭ�鿡 ���
	*	@pre	chatRoomList != empty
	*	@post	ȭ�鿡 chatRoomList ���
	*/
	void DisplayChat();

	/**
	*	@brief	ä�ù� ���̵� �Է¹޾�, �ش� ä�ù��� �޽����� ����ϴ� �Լ�
	*	@pre	����
	*	@post	�޽����� ��µ�
	*	@param	ä�ù� ���̵�
	*	@return	�ش� ä�ù��� ���ϵ�
	*/
	ChatRoom* printMessageInChatRoom(int chatRoomId);

	/**
	*	@brief	���� �α����� ����� ������ �����ϴ� �Լ�
	*	@pre	����
	*	@post	����� ���� ����.
	*/
	void ChangeUserInfo();

	/**
	*	@brief	ä�ù� ID�� �˻��Ͽ� ä�ù��� �̸��� ����(���� �α��� �� ����ڿ��Ը� ����)
	*	@pre	����.
	*	@post	ä�ù� �̸��� �����.
	*/
	void ChangeChatRoomName();

	/**
	*	@brief	ģ�� ������ �ϴ� �Լ�
	*	@pre	����.
	*	@post	m_user�� ģ�� ��Ͽ��� �ش� ģ���� �����Ѵ�
	*/
	void deleteFriends();

private:
	Member* m_user; // ���� ���� ���� Member
	bool m_isLogin; // �α��� �������� true ����, �α׾ƿ��� �������� false ����
};

