#include "Server.h"



Server::Server()
{
	 curMember = NULL;
	 chatRoomId = 0;
}


Server::~Server()
{
}

void Server::JoinMember()
{

	string  id ,pw, name, phoneNumber, birth, profilePhoto, backgroundPhoto, profileMessage;

	cout << "������ ID�� �Է��Ͻʽÿ� : ";
	cin >> id;

	for (int i = 0; i < memberList.size(); i++)
	{
		if (memberList.Get(i)->GetId() == id)
		{
			cout << "����������������������[����]����������������������������" << endl;
			cout << "��              �̹� �����ϴ� ID�Դϴ�.               ��" << endl;
			cout << "��������������������������������������������������������" << endl;
			return;
		
		}
	}

	if (id == "0")
	{
		cout << "����������������������[����]����������������������������" << endl;
		cout << "��       �ش� ���̵�� �̿��� �� �����ϴ�.            ��" << endl;
		cout << "��������������������������������������������������������" << endl;
	}

	cout << "�н����带 �Է��Ͻʽÿ� : ";
	cin >> pw;

	cout << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "��           �� ������ �Է��Ͻʽÿ�.              ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << endl;

	cout << "�̸�: ";
	cin >> name;
	cout << "�޴���ȭ ��ȣ: ";
	cin >> phoneNumber;
	cout << "����(00001122): ";
	cin >> birth;
	cout << "������ ����: ";
	cin >> profilePhoto;
	cout << "������: ";
	cin >> backgroundPhoto;
	cout << "������ �޽��� �Է� : ";
	cin >> profileMessage;
	


	Member* Temp = new Member;
	Temp->SetRecord(id, pw, name, phoneNumber, birth, profilePhoto, backgroundPhoto, profileMessage);
	 memberList.Add(Temp);

	cout << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "��            ȸ�� ���Կ� �����߽��ϴ�.             ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "��            �α��� �� �̿����ֽʽÿ�.             ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << endl;
}

bool Server::leaveMember()
{
	int command;

	cout << endl;
	cout << "������������������������������������������������������" << endl;
	cout << "��             ȸ�� Ż�� �Ͻðڽ��ϱ�?            ��" << endl;
	cout << "��                  1. Ż���ϱ�                     ��" << endl;
	cout << "��                  0. ����ϱ�                     ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cin >> command;
	cout << endl;
	switch (command)
	{
	case '1':
		for (int i = 0; i <  memberList.size(); i++)	
			if ( memberList.Get(i)->getFriendList().Get( curMember))
			{
				 memberList.Get(i)->deleteFriend( findMemberbyId( curMember->GetId()));
			}

		for (int i = 1; i <=  chatRoomId; i++)
			for (int j = 0; j <  curMember->getChatRoomList().size(); j++)
				if ( curMember->getChatRoomList().Get(j)->getChatRoomID() == i)
				{
					 ExitChatRoom(i);
				}

		 memberList.Delete( curMember);

		cout << endl;
		cout << "������������������������������������������������������" << endl;
		cout << "��            ȸ�� Ż�� �Ϸ�Ǿ����ϴ�            ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;

		return true;
		break;
	case '0':
		cout << endl;
		cout << "������������������������������������������������������" << endl;
		cout << "��                 �޴��� ���ư��ϴ�                ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
		break;
	default:
		cout << endl;
		cout << "����������������������[����]��������������������������" << endl;
		cout << "��               �߸��� ��ɾ��Դϴ�!               ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}

	return false;
}

void Server::DequeueMessageQ()
{
	Message* data = new Message;
	 messageQ.Dequeue(data);
	data = NULL;
}

void Server::EnqueueMessage(Message * data)
{
	 messageQ.Enqueue(data);
}

int Server::SendMessageToReceiver(Member * Temp)
{

	ChatRoom* nTemp = new PersonalChatRoom;	

	if ( curMember->getChatRoomList().size() == 0)	
	{
		MakePersonalChatRoom(Temp->GetId());	
		nTemp = curMember->getChatRoomList().Get(0);
		SendMessageToChatRoom(nTemp);
	}
	else
	{
		bool found = false;
		for (int i = 0; i <  curMember->getChatRoomList().size(); i++)
		{
			if ( curMember->getChatRoomList().Get(i)->GetReceiverId() == Temp->GetId())
			{
				nTemp = curMember->getChatRoomList().Get(i);
				found = true;
				SendMessageToChatRoom(nTemp);
				break;
			}
		}

		if (!found)
		{
			 MakePersonalChatRoom(Temp->GetId());	
			for (int i = 0; i < curMember->getChatRoomList().size(); i++)
			{
				if ( curMember->getChatRoomList().Get(i)->GetReceiverId() == Temp->GetId())
				{
					nTemp =  curMember->getChatRoomList().Get(i);
					 SendMessageToChatRoom(nTemp);
					break;
				}
			}
		}
	}

	return nTemp->getChatRoomID();
}

void Server::SendMessageToChatRoom(ChatRoom * chat)
{
	Message* nMessageTemp = new Message;	
	 messageQ.Dequeue(nMessageTemp);	
	for (int i = 0; i <  memberList.size(); i++)	
		for (int j = 0; j <  memberList.Get(i)->getChatRoomList().size(); j++)	
		{
			if ( memberList.Get(i)->getChatRoomList().Get(j)->getChatRoomID() == chat->getChatRoomID())	
			{
				 memberList.Get(i)->getChatRoomList().Get(j)->addChatRoom(nMessageTemp);
			}
		}
}

void Server::MakePersonalChatRoom(string userId)
{
	bool found = false;

	for (int i = 0; i < curMember->getChatRoomList().size(); i++)
	{
		if (curMember->getChatRoomList().Get(i)->GetReceiverId() == userId)
		{
			found = true;
			break;
		}

	}

	string userName;	
	for (int i = 0; i <  memberList.size(); i++)
	{
		if ( memberList.Get(i)->GetId() == userId)
		{
			userName =  memberList.Get(i)->GetName();
			break;
		}
	}

	
	if (found)
	{
	}
	else
	{
		ChatRoom* Temp = new PersonalChatRoom;	
		chatRoomId++;	

		Temp->SetReceiverId(userId, userName);
		Temp->updateChatRoomID(chatRoomId);
		curMember->addChatRoom(Temp);

		for (int i = 0; i < curMember->getFriendList().size(); i++)	
		{
			if (curMember->getFriendList().Get(i)->GetId() == userId)
			{
				ChatRoom* Temp2 = new PersonalChatRoom;
				Temp2->SetReceiverId(curMember->GetId(), curMember->GetName());	
				Temp2->updateChatRoomID(chatRoomId);
				this->curMember->getFriendList().Get(i)->addChatRoom(Temp2);	//��� �������Դ� ���� �̸��� ǥ�õǹǷ� ���� �α����� ������ �̸����� ä�ù��� ������Ʈ�Ѵ�.
				break;
			}
		}
	}
}

void Server::MakeGroupChatRoom(LinkedList<string> userId, string chatRoomName)
{
	//���� ���� �� ����
}

void Server::ExitChatRoom(int chatRoomId)
{
	bool found = false;	

	ChatRoom* Temp = NULL;	

	for (int i = 0; i < curMember->getChatRoomList().size(); i++)
		if ( curMember->getChatRoomList().Get(i)->getChatRoomID() == chatRoomId)
		{
			found = true;
			Temp =  curMember->getChatRoomList().Get(i);	
			curMember->deleteChatRoom(curMember->getChatRoomList().Get(i));
			break;
		}

	if (found)
	{
		Message* nTemp = new Message;
		string id =  curMember->GetId();
		nTemp->sendMessage(id, "ä�ù濡�� �������ϴ�");	
		for (int i = 0; i < memberList.size(); i++)	
		{
			for (int j = 0; j < memberList.Get(i)->getChatRoomList().size(); j++)	
				if (memberList.Get(i)->getChatRoomList().Get(j)->getChatRoomID() == chatRoomId)	
				{
					memberList.Get(i)->deleteChatRoomInMember(curMember->GetId(), chatRoomId);
					memberList.Get(i)->getChatRoomList().Get(j)->addChatRoom(nTemp);
					if (memberList.Get(i)->getChatRoomList().Get(j)->GetBasicChatRoomName())
					{
						memberList.Get(i)->getChatRoomList().Get(j)->SetChatRoomNameByID();
					}
					break;
				}
		}


		cout << endl;
		cout << "����������������������[�˸�]��������������������������" << endl;
		cout << "��             �ش� ä�ù濡�� �������ϴ�           ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "����������������������[����]��������������������������" << endl;
		cout << "��        ä�� ��Ͽ� �ش� ä�ù��� �����ϴ�        ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}

}

void Server::deleteFriend(Member * data)
{
	if (this->curMember->getFriendList().Get(data))
	{
		this->curMember->deleteFriend(data);
		cout << endl;
		cout << "����������������������[�˸�]��������������������������" << endl;
		cout << "��        ģ�� ��Ͽ��� ���� �Ǿ����ϴ�.            ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;

	}
	else
	{
		cout << endl;
		cout << "����������������������[����]��������������������������" << endl;
		cout << "��         ģ�� ��Ͽ� �������� �ʽ��ϴ�.           ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}

}



Member * Server::findMemberbyId(string userId)
{
	bool found = false;	
	for (int i = 0; i <  memberList.size(); i++)
	{
		if ( memberList.Get(i)->GetId() == userId)
		{
			found = true;
			return  memberList.Get(i);
			break;
		}
	}
	if (!found)
	{
		cout << "����������������������[����]��������������������������" << endl;
		cout << "��      �ش� ���̵� ���� ����� �����ϴ�.         ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
		return NULL;
	}
}

bool Server::findMemberByName()
{
	bool found = false;	

	string name;
	cout << "����������������������������������������������������������" << endl;
	cout << "����� �̸��� �Է��Ͻʽÿ�: ";
	cin >> name;
	cout << "����������������������������������������������������������" << endl;

	cout << "��������������������<�˻� ���>����������������������" << endl;
	for (int i = 0; i <  memberList.size(); i++)	
		if ( memberList.Get(i)->GetName() == name)	
		{
			memberList.Get(i)->displayMemberInfo();
			cout << "��                                                  ��" << endl;
			found = true;
		}
	cout << "������������������������������������������������������" << endl;
	cout << endl;

	if (!found)
	{
		cout << "����������������������[����]��������������������������" << endl;
		cout << "��       �ش� �̸��� ���� ����� �����ϴ�.          ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
		return NULL;
	}
	else
		return true;
}
