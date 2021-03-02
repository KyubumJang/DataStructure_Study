#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}

void Application::Run()
{
	int command;
	while (true)
	{
		cout << "����������������������<īī����>����������������������" << endl;
		cout << "��                 1. �α���                        ��" << endl;
		cout << "��                 2. ȸ�� ����                     ��" << endl;
		cout << "��                 0. ����                          ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			if (Login())
			{
				LoginMenu();
			}
			break;
		case 2:
			JoinMember();
			break;
		case 0:
			return;
		default:
			ErrorMessage();
		}
	}
}

void Application::LoginMenu()
{
	int command;
	while (true)
	{
		if (!GetIsLogin())
		{
			break;
		}

		cout << endl;
		cout << "����������������<(" << curMember->GetName() << setw(36 - curMember->GetName().size()) << ")�� �޴��Դϴ�.>������������" << endl;
		cout << "��              1.  ģ��                            ��" << endl;
		cout << "��              2.  ä�ù�                          ��" << endl;
		cout << "��              3.  �� ����                         ��" << endl;
		cout << "��              0.  �α׾ƿ�                        ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			FriendMenu();
			break;
		case 2:
			ChatRoomMenu();
			break;
		case 3:
			UserMenu();
			break;
		case 0:
			if (Logout())
			{
				return;
			}
			break;
		default:
			ErrorMessage();
		}
	}
}

void Application::FriendMenu()
{
	int command;
	while (true)
	{
		cout << endl;
		cout << "��������������<īī���� ģ�� �޴��Դϴ�>��������������" << endl;
		cout << "��              1.  ģ�� ���                       ��" << endl;
		cout << "��              2.  �޽��� ������                   ��" << endl;
		cout << "��              3.  ģ�� �߰�                       ��" << endl;
		cout << "��              4.  ģ�� ����                       ��" << endl;
		cout << "��              0.  �ڷΰ���                        ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			printFriendList();
			break;
		case 2:
			SendMessageToUser();
			break;
		case 3:
			AddFriend();
			break;
		case 4:
			deleteFriends();
			break;
		case 0:
			return;
			break;
		default:
			ErrorMessage();
		}
	}
}

void Application::ChatRoomMenu()
{
	int command;
	while (true)
	{
		cout << endl;
		cout << "����������������<ä�ù� �޴� �Դϴ�>������������������" << endl;
		cout << "��              1.  ä�ù� ���                     ��" << endl;
		cout << "��              0.  �����޴�                        ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			DisplayChat();
			break;
		case 0:
			return;
			break;
		default:
			ErrorMessage();
		}
	}
}

void Application::UserMenu()
{
	int command;
	while (true)
	{
		cout << endl;
		cout << "��������������<���ϴ� ����� �����ϼ���>��������������" << endl;
		cout << "��              1.  ����� ���� ���                ��" << endl;
		cout << "��              2.  ����� ���� ����                ��" << endl;
		cout << "��              3.  ȸ�� Ż��                       ��" << endl;
		cout << "��              0.  �ڷΰ���                        ��" << endl;
		cout << "����������������s��������������������������������������" << endl;
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			cout << "��������������������<���������>����������������������" << endl;
			curMember->displayMemberInfo();
			cout << "������������������������������������������������������" << endl;
			break;
		case 2:
			ChangeUserInfo();
			break;
		case 3:
			if (leaveMember())
			{
				SetIsLogin();
			}
			return;
		case 0:
			return;
			break;
		default:
			ErrorMessage();
		}
	}
}

void Application::ErrorMessage()
{
	cout << endl;
	cout << "����������������������[ERROR!]������������������������" << endl;
	cout << "��               �߸��� ��ɾ��Դϴ�!               ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << endl;
}
