#pragma once
#include"Member.h"

/**
*	������ application Ŭ������ �����϶�� ������ ���� Ŭ���� ���� ������.
*	������ īī������ �̿��ϴ� ��� �������� ������ ����.
*	�޽����� �� ������ �����Ѵ�.
*	@author	��Թ�
*	@date	20171027
*/
class Server
{
public:
	/**
	*	@brief	������
	*	@pre	����.
	*	@post	����.
	*/
	Server();
	/**
	*	@brief	�Ҹ���
	*	@pre	����.
	*	@post	����.
	*/
	~Server();

	/**
	*	@brief	ȸ������ �ϴ� �Լ�
	*	@pre	ȸ�� ������ �Ǿ� ������ �ȵ�
	*	@post	ȸ������ ��
	*/
	void JoinMember();

	/**
	*	@brief	ȸ�� Ż�� �ϴ��Լ�
	*	@pre	�α���
	*	@post	ȸ�� Ż��
	*	@return	Ż�� �� true ����
	*/
	bool leaveMember();

	/**
	*	@brief	messageQ�� ���� �ֽ� �޽����� Dequeue�ϴ� �Լ�
	*	@pre	����.
	*	@post	����.
	*/
	void DequeueMessageQ();


	/**
	*	@brief	messageQ�� (Message*)�� Enqueue
	*	@pre	����
	*	@post	ť�� �޽��� ����
	*	@param	Message* data
	*/
	void EnqueueMessage(Message* data);

	/**
	*	@brief	ť�� ����� �޽����� �޽��� �޴� ģ������ ����
	*	@pre	ť�� �޽����� ����Ǿ� ����.
	*	@post	�޽����� Temp�� ����
	*	@param	�޽����� ���� ���� Member *Temp
	*	@return	chatRoomId(ä�ù� ���̵�)
	*/
	int SendMessageToReceiver(Member* Temp);

	/**
	*	@brief	ť�� ����� �޽����� ä�ù濡 ����
	*	@pre	ä�ù��� �����Ǿ� ����, messageQ�� �޽��� ����
	*	@post	�ش� ä�ù濡 �޽��� ����
	*	@param	ä�ù� ChatRoom* chat
	*/
	void SendMessageToChatRoom(ChatRoom* chat);

	/**
	*	@brief	���� ä�ù��� ����� �Լ�
	*	@pre	����
	*	@post	���� ä�ù� ����
	*	@param	string userId
	*/
	void MakePersonalChatRoom(string userId);

	/**
	*	@brief	��ü ä�ù��� ����� �Լ�
	*	@pre	����
	*	@post	��ü ä�ù� ����
	*	@parma	LinkedList<string> userId, string chatRoomName
	*/
	void MakeGroupChatRoom(LinkedList<string> userId, string chatRoomName);

	/**
	*	@brief	���� ������ �Ķ���ͷ� ���� �ش� chatRoomId�� ���� ä�ù濡�� ������
	*	@pre	chatRoomId�� ä�ù��� ����
	*	@post	chatRoomId�� ���� ������� ä�ù濡�� ���� ������ ������.
	*	@param	int chatRoomId
	*/
	void ExitChatRoom(int chatRoomId);

	/**
	*	@brief	���� ������� ģ�� ��Ͽ��� ģ�� ������.
	*	@pre	����.
	*	@post	���� ������� ģ�� ��Ͽ��� ģ�� ������
	*	@param	������ ģ�� Member* data
	*/
	void deleteFriend(Member* data);

	/**
	*	@brief	��� ���̵�� ��� ã�Ƽ� ȸ������ ã��
	*	@pre	ID�� ��ġ�ϴ� ��� ������.
	*	@post	�ش� ���̵��� ��� ����
	*	@param	string userId
	*	@return	Member*
	*/
	Member* findMemberbyId(string userId);

	/**
	*	@brief	�̸����� ģ�� �˻�
	*	@pre	����.
	*	@post	����.
	*	@return	�ش��ϴ� ����� ������ 1 ����, ������ 0 ����.
	*/
	bool findMemberByName();

protected:
	int chatRoomId;	//ä�ù� ���� ���̵�
	QueueType<Message*> messageQ; // Client class���� �޽����� �������� �� ���� �� messageQ�� ������ �����Ѵ�.(ť���� ���� �ֽ��� �޽����� ���� ����� chatList�� ����)
	LinkedList<Member*> memberList; // �޽��� ����ϴ� ��� �����ϴ� ����Ʈ(ȸ�� ���� �� �������Ʈ�� �߰�)
	Member* curMember;	//������ �α��� �� ��� ����

};

