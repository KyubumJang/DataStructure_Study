#pragma once
#include"Message.h"
/**
*	ä�ù��� ����� Ŭ���� : ä�ù��� �޽��� ����� ����.
*	@author	��Թ�
*	@date	20171027
*/
class ChatRoom
{
public:
	/**
	*	@brief	������
	*	@pre	����.
	*	@post	����.
	*/
	ChatRoom();
	/**
	*	@brief	�Ҹ���
	*	@pre	����.
	*	@post	����.
	*/
	~ChatRoom();

	//ä�ù� �Լ�

	/**
	*	@brief	ä�ù� ����� ���� ���� �Լ�
	*	@pre	����.
	*	@post	�޽��� �߰�
	*	@param	ä�ù� �޽��� ����Ʈ�� �߰��� Message* data
	*/
	virtual void addChatRoom(Message* data) = 0;

	/**
	*	@brief	ä�ù� ���̵� ������Ʈ �ϴ� ���� ���� �Լ�
	*	@pre	����.
	*	@post	ä�ù� ���̵� ����
	*	@param	ä�ù� ���̵�
	*/
	virtual void updateChatRoomID(int chatRoomID) = 0;

	/**
	*	@brief	�޽����� �޴� �������� ID�� �߰��ϴ� ���� ���� �Լ�
	*	@pre	�̹� ������ ����ó��
	*	@post	�޴� ��� ���̵� �߰�
	*	@param	int id, string name
	*/
	virtual void AddReceiverId(string id, string name) = 0;

	/**
	*	@brief	ä�ù濡���� ��ȭ ������ ����ϴ� ���� ���� �Լ�
	*	@pre	ä�ù��� ����
	*	@post	��ȭ ���� ���
	*/
	virtual void PrintMessageList() = 0;

	/**
	*	@brief	ä�ù濡�� �ش� ���̵� ���� ������ �����Ѵ�(���� ���� �Լ�)
	*	@pre	�ش� ���̵� ���� ������ ����.
	*	@post	�ش� ���̵�
	*	@param	int userId
	*	@return	���� �� true ����
	*/
	virtual bool DeleteReceiver(string userId) = 0;

	//Get �Լ�

	/**
	*	@brief	ä�ù� ���̵� �����ϴ� ���� ���� �Լ�
	*	@pre	id ������
	*	@post	����
	*	@return	ä�ù� ���̵�
	*/
	virtual int getChatRoomID() = 0;

	/**
	*	@brief	1:1 ä���� �� ������ ID�� �����ϴ� ���� ���� �Լ�
	*	@pre	���ù� ���̵� ������
	*	@post	�޴� ����� ���̵� ����
	*	@return	�޴� ����� ���̵�
	*/
	virtual string GetReceiverId() = 0;

	/**
	*	@brief	�޽����� �޴� �������� ID�� �������� ���� ���� �Լ�
	*	@pre	�޴� ������� ���̵� ������
	*	@post	�޴� ������� ���̵� ������
	*	@return	�޴� ������� ���̵�
	*/
	virtual LinkedList<string> GetReceiversId() = 0;

	/**
	*	@brief	ä�ù��� �޽��� ����Ʈ�� �������� ���� ���� �Լ�
	*	@pre
	*	@post
	*	@return	LinkedList<Message*>
	*/
	virtual LinkedList<Message*> GetMessageList() = 0;

	/**
	*	@brief	ä�ù��� �̸��� �����ϴ� ���� ���� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	string
	*/
	virtual string GetChatRoomName() = 0;

	/**
	*	@brief	ä�ù� �⺻ �̸����� Ȯ�� �ϴ� �Լ�
	*	@pre	�̸��� �����Ǿ� �־�� ��.
	*	@post	����.
	*	@return	ä�ù� �⺻ �̸��̸� true
	*/
	virtual bool GetBasicChatRoomName() = 0;

	//Set �Լ�

	/**
	*	@brief	1:1 ä���� �� ������ Id�� ���ϴ� ���� ���� �Լ�
	*	@pre	����
	*	@post	�޴� ��� ���̵� ����
	*	@param	int id, string name
	*/
	virtual void SetReceiverId(string id, string name) = 0;

	/**
	*	@brief	ä�ù��� �̸� ����, �⺻���� �������� ID�� ����. ���� ���� �Լ�
	*	@pre	����.
	*	@post	����.
	*	@return	ä�ù� �̸�
	*/
	virtual string SetChatRoomNameByID() = 0;

	/**
	*	@brief	ä�ù��� �̸��� �����ϴ� ���� ���� �Լ�(ä�ù��� �⺻ �̸��� ä�ù��� �������� �̸�.)
	*	@pre	����.
	*	@post	ä�ù� �̸� ������.
	*	@param	string name
	*/
	virtual void SetChatRoomByName(string name) = 0;

};

