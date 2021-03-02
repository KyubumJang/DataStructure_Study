#include "Client.h"



Client::Client()
{
	m_user = NULL;
	m_isLogin = false;
}


Client::~Client()
{
}

bool Client::GetIsLogin()
{
	return m_isLogin;
}

void Client::SetUser(Member * Temp)
{
	m_user = Temp;
}

void Client::SetIsLogin()
{
	if (m_isLogin == true)
	{
		m_isLogin = false;
	}
	else
	{
		m_isLogin = true;
	}
}

bool Client::Login()
{
	string id, pw;

	cout << "������������������������������������������������������" << endl;
	cout << "ID�� �Է��Ͻʽÿ�: ";
	cin >> id;
	cout << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "Password�� �Է��Ͻʽÿ�: ";
	cin >> pw;
	cout << "������������������������������������������������������" << endl;
	cout << endl << endl;

	for (int i = 0; i < memberList.size(); i++)
	{
		if (memberList.Get(i)->GetId() == id)
		{
			if (memberList.Get(i)->GetPw() == pw)
			{
				curMember = memberList.Get(i);
				m_isLogin = true;
				break;
			}
		}
	}
	if (m_isLogin == true)
	{
		cout << endl;
		cout << "������������������������������������������������������" << endl;
		cout << "��         �α����� ���������� �Ǿ����ϴ�.          ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "������������������������[����]������������������������" << endl;
		cout << "��             ȸ�������� �ʿ��մϴ�.               ��" << endl;
		cout << "��                       �Ǵ�                       ��" << endl;
		cout << "��          ���̵� ��й�ȣ�� Ȯ���� �ֽʽÿ�.      ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl << endl;
	}
	SetUser(curMember);	


	if (m_isLogin == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Client::Logout()
{
	m_isLogin = false;
	SetUser(NULL);	
	cout << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "��       �α׾ƿ��� ���������� �Ǿ����ϴ�.          ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << endl;

	return true;
}

Message * Client::MakeMessage()
{
	Message* nTemp = new Message;	

	string content;	

	cout << "��                                             (��) ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "����";
	cin >> content;
	cout << "����" << setw(50) << "����" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "��" << setw(52) << "��" << endl;
	cout << "��" << setw(52) << "��" << endl;

	if (content != "0")	
	{
		nTemp->sendMessage(curMember->GetId(), content);
	}
	else
	{
		nTemp = NULL;
	}

	return nTemp;
}

Message * Client::RecieveMessageFromServer()
{
	Message* nTemp = new Message;	
	messageQ.Dequeue(nTemp);	
	return nTemp;	
}

Message * Client::SendMessageToServer()
{
	Message* Temp = new Message;
	Temp = MakeMessage();
	EnqueueMessage(Temp);
	return Temp;
}

void Client::AddFriend()
{
	if (findMemberByName())
	{
		string id;	
		cout << endl;
		cout << "��������������������������������������������������������" << endl;
		cout << "ģ�� �߰��� ģ���� ���̵� �Է��Ͻʽÿ�: ";
		cin >> id;
		cout << "��������������������������������������������������������" << endl;
		cout << endl;
		m_user->addFriend(findMemberbyId(id));
	}
}

void Client::printFriendList()
{
	if (m_user->getFriendList().size() == 0)
	{
		cout << endl;
		cout << "����������������������[�˸�]������������������������" << endl;
		cout << "��            ģ������� ������ϴ�.              ��" << endl;
		cout << "����������������������������������������������������" << endl;
		cout << endl;
	}

	cout << endl;
	cout << "����������������������[ģ�����]��������������������������" << endl;
	for (int i = 0; i < m_user->getFriendList().size(); i++)
	{
		m_user->getFriendList().Get(i)->displayMemberInfo();
		cout << "��                                                      ��" << endl;
	}
	cout << "����������������������������������������������������������" << endl;

}

bool Client::MakeChatRoom()
{
	int command;

	cout << endl;
	cout << "����������������[ä�ù� ����� �޴�]������������������" << endl;
	cout << "��           1.  ���� ä�ù� �����                 ��" << endl;
	cout << "��           2.  ��ü ä�ù� �����                 ��" << endl;
	cout << "��           0.  ���                               ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << endl;

	while (true)
	{
		cin >> command;

		if (command == 1)
		{
			string userId;
			cout << "������������������������������������������������������" << endl;
			cout << "���� ä���� �� ������ ���̵� �Է��Ͻʽÿ�: ";
			cin >> userId;
			cout << "������������������������������������������������������" << endl;
			cout << endl;
			bool found = false;

			for (int i = 0; i < m_user->getFriendList().size(); i++)
				if (m_user->getFriendList().Get(i)->GetId() == userId)
				{
					found = true;
					MakePersonalChatRoom(userId);
					break;
				}
			if (found == true)
			{
				cout << endl;
				cout << "����������������������[�˸�]������������������������" << endl;
				cout << "��           ä�ù��� ���� �Ǿ����ϴ�.            ��" << endl;
				cout << "����������������������������������������������������" << endl;
				return true;
			}
			else
			{
				cout << endl;
				cout << "����������������������[����]������������������������" << endl;
				cout << "��    ģ�� ��Ͽ� �������� �ʴ� ���̵� �Դϴ�.    ��" << endl;
				cout << "����������������������������������������������������" << endl;
				cout << endl;
				return false;
			}
			break;
		}
		else if (command == 2)
		{
			//���� ������ ����
		}

		else if (command == 0)
		{
			cout << endl;
			cout << "����������������������[�˸�]����������������������" << endl;
			cout << "��                �ڷ� ���ư��ϴ�.              ��" << endl;
			cout << "��������������������������������������������������" << endl;
			cout << endl;
			return false;
			break;
		}

		else
		{
			cout << endl;
			cout << "����������������������[����]������������������������" << endl;
			cout << "��               �ٽ� �Է��Ͻʽÿ�.               ��" << endl;
			cout << "����������������������������������������������������" << endl;
			cout << endl;
			cin >> command;
		}
	}
}

void Client::ExitsChatRoom()
{
	int chatRoomId;

	cout << "������������������������������������������������������������" << endl;
	cout << "������ ä�ù��� ID�� �Է��ϼ���(0�� ������ �ڷ� ���ư��ϴ�.) ";
	cin >> chatRoomId;
	cout << "������������������������������������������������������������" << endl;
	cout << endl;

	if (!chatRoomId)
	{
		cout << endl;
		cout << "����������������������[�˸�]������������������������" << endl;
		cout << "��                 �ڷ� ���ư��ϴ�                ��" << endl;
		cout << "����������������������������������������������������" << endl;
		cout << endl;
	}
	else
	{
		ExitChatRoom(chatRoomId);
	}
}

void Client::SendMessageToUser()
{
	string userId;
	cout << "����������������������������������������������������������" << endl;
	cout << "�޽����� ���� ������ ID�� �Է��ϼ��� : ";
	cin >> userId;
	cout << "����������������������������������������������������������" << endl;
	cout << endl;

	Member* Temp = new Member;	
	bool found = false;	
	for (int i = 0; i < m_user->getFriendList().size(); i++)
	{
		if (m_user->getFriendList().Get(i)->GetId() == userId)
		{
			Temp = m_user->getFriendList().Get(i);	
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << endl;
		cout << "����������������������[����]������������������������" << endl;
		cout << "��    ģ�� ��Ͽ� �������� �ʴ� ���̵� �Դϴ�.    ��" << endl;
		cout << "����������������������������������������������������" << endl;
		cout << endl;
	}
	else
	{
		int chatRoomId;	
		if (SendMessageToServer() != NULL)
		{
			chatRoomId = SendMessageToReceiver(Temp);
		}
		printMessageInChatRoom(chatRoomId);	

		while (true)
		{
			if (SendMessageToServer() != NULL)
			{
				chatRoomId = SendMessageToReceiver(Temp);
			}
			else
			{
				DequeueMessageQ();
				break;
			}
		}
	}
}

void Client::sendMessageToChatRoom()
{
	int chatRoomId;	

	cout << "������������������������������������������������������" << endl;
	cout << "�޽����� ���� ä�ù��� ���̵� �Է��ϼ���: ";
	cin >> chatRoomId;
	cout << "������������������������������������������������������" << endl;

	ChatRoom* Temp = this->printMessageInChatRoom(chatRoomId);	

	if (Temp != NULL)
	{
		while (true)
		{
			if (this->SendMessageToServer() != NULL)
			{
				this->SendMessageToChatRoom(Temp);	
			}
			else
			{
				this->DequeueMessageQ();
				break;
			}
		}
	}
}

void Client::DisplayChat()
{
	m_user->printChatRoom();
	int command;

	cout << endl;
	cout << "������������������<ä�ù�  �޴�>����������������������" << endl;
	cout << "��              1.  ä�ù� �߰�                     ��" << endl;
	cout << "��              2.  ä�ù� ������                   ��" << endl;
	cout << "��              3.  ä�ù� ����                     ��" << endl;
	cout << "��              4.  ä�ù� �̸� �ٲٱ�              ��" << endl;
	cout << "��              0.  �ڷΰ���                        ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cin >> command;
	cout << endl;

	switch (command)
	{
	case 1:
		MakeChatRoom();
		break;
	case 2:
		ExitsChatRoom();
		break;
	case 3:
		sendMessageToChatRoom();
		break;
	case 4:
		ChangeChatRoomName();
		break;
	case 0:
		return;
		break;
	default:
		cout << endl;
		cout << "������������������������[����]������������������������" << endl;
		cout << "��              �ٽ� �õ��� ���ʽÿ�.               ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
		break;
	}

}

ChatRoom * Client::printMessageInChatRoom(int chatRoomId)
{
	bool found = false;	

	for (int i = 0; i < m_user->getChatRoomList().size(); i++)
	{
		if (m_user->getChatRoomList().Get(i)->getChatRoomID() == chatRoomId)
		{
			found = true;
			m_user->getChatRoomList().Get(i)->PrintMessageList();
			return m_user->getChatRoomList().Get(i);
			break;
		}
	}

	if (!found)
	{
		cout << endl;
		cout << "����������������������[����]������������������������" << endl;
		cout << "��             �ش� ä�ù��� �����ϴ�             ��" << endl;
		cout << "����������������������������������������������������" << endl;
		cout << endl;
	}

	return NULL;
}

void Client::ChangeUserInfo()
{
	int command;

	cout << endl;
	cout << "������������������<ȸ������ ���� �޴�>����������������������" << endl;
	cout << "��              1.  ��й�ȣ                              ��" << endl;
	cout << "��              2.  �̸�                                  ��" << endl;
	cout << "��              3.  ��ȭ��ȣ                              ��" << endl;
	cout << "��              4.  ������ ����                           ��" << endl;
	cout << "��              5.  ��� ����                             ��" << endl;
	cout << "��              6.  ������ �޽���                         ��" << endl;
	cout << "��              0.  �ڷΰ���                              ��" << endl;
	cout << "������������������������������������������������������������" << endl;
	cin >> command;
	cout << endl;

	string temp;
	switch (command)
	{
	case 1:
		cout << "����������������������������������������������������������" << endl;
		cout << "�ٲ� ��й�ȣ�� �Է��Ͻʽÿ�: ";
		cin >> temp;
		cout << "����������������������������������������������������������" << endl;
		m_user->SetPw(temp);
		cout << "���� �Ǿ����ϴ�." << endl;
		cout << "����������������������������������������������������������" << endl;
		break;
	case 2:
		cout << "����������������������������������������������������������" << endl;
		cout << "�ٲ� �̸��� �Է��Ͻʽÿ�: ";
		cin >> temp;
		cout << "����������������������������������������������������������" << endl;
		m_user->SetName(temp);
		cout << "���� �Ǿ����ϴ�." << endl;
		cout << "����������������������������������������������������������" << endl;
		break;
	case 3:
		cout << "����������������������������������������������������������" << endl;
		cout << "�ٲ� ��ȭ��ȣ�� �Է��Ͻʽÿ�: ";
		cin >> temp;
		cout << "����������������������������������������������������������" << endl;
		m_user->SetPhoneNum(temp);
		cout << "���� �Ǿ����ϴ�." << endl;
		cout << "����������������������������������������������������������" << endl;
		break;
	case 4:
		cout << "����������������������������������������������������������" << endl;
		cout << "�ٲ� ������ ������ �Է��Ͻʽÿ�: ";
		cin >> temp;
		cout << "����������������������������������������������������������" << endl;
		m_user->SetProfilePhoto(temp);
		cout << "���� �Ǿ����ϴ�." << endl;
		cout << "����������������������������������������������������������" << endl;
		break;
	case 5:
		cout << "����������������������������������������������������������" << endl;
		cout << "�ٲ� �������� �Է��Ͻʽÿ�: ";
		cin >> temp;
		cout << "����������������������������������������������������������" << endl;
		m_user->SetBackgroundPhoto(temp);
		cout << "���� �Ǿ����ϴ�." << endl;
		cout << "����������������������������������������������������������" << endl;
		break;

	case 6:
		cout << "����������������������������������������������������������" << endl;
		cout << "�ٲ� ������ �޽����� �Է��Ͻʽÿ�: ";
		cin >> temp;
		cout << "����������������������������������������������������������" << endl;
		m_user->SetProfileMessage(temp);
		cout << "���� �Ǿ����ϴ�." << endl;
		cout << "����������������������������������������������������������" << endl;
		break;
	case 0:
		return;
		break;
	default:
		cout << endl;
		cout << "����������������������[����]������������������������" << endl;
		cout << "��               �ٽ� �Է� �Ͻʽÿ�.              ��" << endl;
		cout << "����������������������������������������������������" << endl;
		cout << endl;
		break;
	}

}

void Client::ChangeChatRoomName()
{
	int chatRoomId;
	cout << "��������������������������������������������������������" << endl;
	cout << "�̸��� ������ ä�ù��� ���̵� �Է��ϼ��� : ";
	cin >> chatRoomId;
	cout << "��������������������������������������������������������" << endl;
	cout << endl;

	bool found = false;	 
	for (int i = 0; i < m_user->getChatRoomList().size(); i++)
	{
		if (m_user->getChatRoomList().Get(i)->getChatRoomID() == chatRoomId)
		{
			found = true;	
			string ChatRoomName;	
			cout << "������������������������������������������������������" << endl;
			cout << "���� �� ä�ù��� �̸��� �Է��ϼ��� : ";
			cin >> ChatRoomName;
			cout << "������������������������������������������������������" << endl;
			cout << endl;

			m_user->getChatRoomList().Get(i)->SetChatRoomByName(ChatRoomName);
			cout << endl;
			cout << "����������������������[�˸�]������������������������" << endl;
			cout << "��          ä�ù� �̸��� ����Ǿ����ϴ�.         ��" << endl;
			cout << "����������������������������������������������������" << endl;
			cout << endl;
			break;
		}
	}
	if (!found)
	{
		cout << endl;
		cout << "����������������������[����]������������������������" << endl;
		cout << "��             �ش� ä�ù��� �����ϴ�             ��" << endl;
		cout << "����������������������������������������������������" << endl;
		cout << endl;
	}
}

void Client::deleteFriends()
{
	string friendId;
	cout << "����������������������������������������������������������" << endl;
	cout << "������ ģ���� ID�� �Է��ϼ��� : ";
	cin >> friendId;
	cout << "����������������������������������������������������������" << endl;
	cout << endl;

	this->deleteFriend(this->findMemberbyId(friendId));	

}
