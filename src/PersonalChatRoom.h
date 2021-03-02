#pragma once
#include "ChatRoom.h"
/**
*	���� ä�ù� Ŭ���� : ChatRoom�� ��ӹ���.
*	@author	��Թ�
*	@date	20171027
*/
class PersonalChatRoom: public ChatRoom
{
public:
	/**
	*	@brief	������
	*	@pre	����.
	*	@post	����.
	*/
	PersonalChatRoom();
	/**
	*	@brief	�Ҹ���
	*	@pre	����.
	*	@post	����.
	*/
	~PersonalChatRoom();

	//ä�ù� �Լ�

	/**
	*	@brief	ä�ù� ����� �Լ�
	*	@pre	����.
	*	@post	�޽��� �߰�
	*	@param	ä�ù� �޽��� ����Ʈ�� �߰��� Message* data
	*/
	void addChatRoom(Message* data);

	/**
	*	@brief	ä�ù� ���̵� ������Ʈ �ϴ� �Լ�
	*	@pre	����.
	*	@post	ä�ù� ���̵� ����
	*	@param	ä�ù� ���̵�
	*/
	void updateChatRoomID(int chatRoomID);

	/**
	*	@brief	�޽����� �޴� �������� ID�� �߰��ϴ� �Լ�
	*	@pre	�̹� ������ ����ó��
	*	@post	�޴� ��� ���̵� �߰�
	*	@param	int id, string name
	*/
	void AddReceiverId(string id, string name);

	/**
	*	@brief	ä�ù濡���� ��ȭ ������ ����ϴ� �Լ�
	*	@pre	ä�ù��� ����
	*	@post	��ȭ ���� ���
	*/
	void PrintMessageList();

	/**
	*	@brief	ä�ù濡�� �ش� ���̵� ���� ������ �����Ѵ�
	*	@pre	�ش� ���̵� ���� ������ ����.
	*	@post	�ش� ���̵�
	*	@param	int userId
	*	@return	���� �� true ����
	*/
	bool DeleteReceiver(string userId);

	//Get �Լ�

	/**
	*	@brief	ä�ù� ���̵� �����ϴ� �Լ�
	*	@pre	id ������
	*	@post	����
	*	@return	ä�ù� ���̵�
	*/
	int getChatRoomID();

	/**
	*	@brief	1:1 ä���� �� ������ ID�� �����ϴ� �Լ�
	*	@pre	���ù� ���̵� ������
	*	@post	�޴� ����� ���̵� ����
	*	@return	�޴� ����� ���̵�
	*/
	string GetReceiverId();

	/**
	*	@brief	�޽����� �޴� �������� ID�� �������� �Լ�
	*	@pre	�޴� ������� ���̵� ������
	*	@post	�޴� ������� ���̵� ������
	*	@return	�޴� ������� ���̵�
	*/
	LinkedList<string> GetReceiversId();

	/**
	*	@brief	ä�ù��� �޽��� ����Ʈ�� �������� �Լ�
	*	@pre	����
	*	@post	����.
	*	@return	LinkedList<Message*>
	*/
	LinkedList<Message*> GetMessageList();

	/**
	*	@brief	ä�ù��� �̸��� �����ϴ� ���� ���� �Լ� ����
	*	@pre	����
	*	@post	����
	*	@return	string
	*/
	string GetChatRoomName();

	/**
	*	@brief	ä�ù� �⺻ �̸� ����
	*	@pre	�̸��� �����Ǿ� �־�� ��.
	*	@post	�⺻ �̸� ����
	*	@return	ä�ù� �⺻ �̸�
	*/
	bool GetBasicChatRoomName();

	//Set �Լ�

	/**
	*	@brief	1:1 ä���� �� ������ Id�� ���ϴ� ���� ���� �Լ�
	*	@pre	����
	*	@post	�޴� ��� ���̵� ����
	*	@param	int id, string name
	*/
	void SetReceiverId(string id, string name);

	/**
	*	@brief	ä�ù��� �̸� ����, �⺻���� �������� ID�� ����.
	*	@pre	����.
	*	@post	����.
	*	@return	ä�ù� �̸�
	*/
	string SetChatRoomNameByID();

	/**
	*	@brief	ä�ù��� �̸��� �����ϴ� �Լ�(ä�ù��� �⺻ �̸��� ä�ù��� �������� �̸�.)
	*	@pre	����.
	*	@post	ä�ù� �̸� ������.
	*	@param	string name
	*/
	void SetChatRoomByName(string name);

private:
	int m_chatRoomId;	//ä�ù��� Id
	string m_chatRoomName;	//ä�ù� �̸�
	bool m_IsBasicName;	//�̸��� �⺻ �������� Ȯ���ϴ� ����

	string m_chatMemberId;	//���� ä�� ����� ID
	string m_chatMemberList;	//���� ä�� ����� �̸�
	LinkedList<Message*> messageList;	//ä�� ����� �����ϴ� ����Ʈ

	
};

