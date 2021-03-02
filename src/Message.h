#pragma once
#include<string>
#include<iomanip>
#include"QueueType.h"
#include"LinkedList.h"
#include<string>
#include<iomanip>
/**
*	īī���忡�� �޽����� �����ϴ� Ŭ����
*	@author	��Թ�
*	@date	20171027
*/
class Message
{
public:
	/**
	*	@brief	������
	*	@pre	����.
	*	@post	����.
	*/
	Message();

	/**
	*	@brief	�Ҹ���
	*	@pre	����.
	*	@post	����.
	*/
	~Message();

	/**
	*	@brief	�޽����� sendID�� ����
	*	@return	m_sendId
	*/
	string getSendId();

	/**
	*	@brief	�޽����� content�� ����
	*	@return	m_content
	*/
	string getContent();

	/**
	*	@brief	�޽����� ������
	*	@pre	����.
	*	@post	����.
	*	@return	�޽���
	*/
	Message GetMessage();

	/**
	*	@brief	�޽����� ����
	*	@pre	����.
	*	@post	����.
	*	@param	�߽��� ID, �޽��� ����
	*/
	void sendMessage(string sendID, string content);


	/**
	*	@brief	�޽����� ������ ����Ѵ�
	*/
	void printMessage();
private:
	string m_sendId;	//������ ��� ���̵�
	string m_content;	//�޽��� ����
};

