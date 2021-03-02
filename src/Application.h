#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"Client.h"
using namespace std;

#define FILENAMESIZE 1024

/**
*	īī���� �����ϴ� Ŭ����
*	@author	��Թ�
*	@date	20171027
*/
class Application: public Client
{
public:
	/**
	*	�⺻ ������
	*/
	Application();

	/**
	*	�Ҹ���
	*/
	~Application();

	/**
	*	@brief	���α׷� ����
	*	@pre	���α׷��� ���۵ȴ�.
	*	@post	���α׷��� ������.
	*/
	void Run();

	/**
	*	@brief	�α��� �� ������ �̿� ������ �޴� ���
	*	@pre	�α����� �Ǿ� �־�� �Ѵ�.
	*	@post	�α����� �� ä�ð� ģ�� �˻��� ����
	*/
	void LoginMenu();


	/**
	*	@brief	ģ�� ��� �����ϴ� �޴�(ģ�� ��� ���, ģ�� �˻�, ģ�� �߰�, ģ�� ����, �޽��� ����)
	*	@pre	������ ģ�� �޴��� ���� �Ѵ�
	*	@post	ģ�� �޴� ���
	*/
	void FriendMenu();

	/**
	*	@brief	ä�ù� �޴�(���� ä�ù� ���, ä�ù� ���̵�� ���� �� ä�� ����)
	*	@pre	ä�ù� ��� �Լ��� �ϼ�
	*	@post	ä�ù� �޴� ���
	*/
	void ChatRoomMenu();

	/**
	*	@brief	���� �α��� �� ������ ���� Ȯ�� �� ���� �޴�(���� ������ ���� ��� �� ����)
	*	@pre	�α����� ������ ���� ���, �����ϴ� �Լ� ����
	*	@post	���� �޴� ���
	*/
	void UserMenu();

	/**
	*	@brief	���� �޽��� ����ϴ� �Լ�
	*	@pre	����.
	*	@post	���� �޽��� ���
	*/
	void ErrorMessage();
};

