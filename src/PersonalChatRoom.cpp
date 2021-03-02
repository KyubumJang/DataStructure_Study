#include "PersonalChatRoom.h"



PersonalChatRoom::PersonalChatRoom()
{
}


PersonalChatRoom::~PersonalChatRoom()
{
}

void PersonalChatRoom::addChatRoom(Message * data)
{
	messageList.Add(data);
}

void PersonalChatRoom::updateChatRoomID(int chatRoomID)
{
	m_chatRoomId = chatRoomID;
}

void PersonalChatRoom::AddReceiverId(string id, string name)
{
}

void PersonalChatRoom::PrintMessageList()
{
	cout << endl;
	if (messageList.size() == 0)
	{
		cout << endl;
		cout << "����������������������[�˸�]��������������������������" << endl;
		cout << "��               ��ȭ ������ �����ϴ�.              ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}

	cout << m_chatRoomName << endl;
	for (int i = 0; i < messageList.size(); i++)
	{
		if (messageList.Get(i)->getSendId() != m_chatMemberId)
		{
			cout << "��                                             (��) ��" << endl;
			messageList.Get(i)->printMessage();
		}
		else
		{
			cout << "��(" << m_chatMemberList << ")" << setw(50 - m_chatMemberList.size()) << "��" << endl;
			messageList.Get(i)->printMessage();
		}
	}
}

bool PersonalChatRoom::DeleteReceiver(string userId)
{
	if (m_chatMemberId == userId)
	{
		return true;
	}

	return false;
}


void PersonalChatRoom::SetReceiverId(string id, string name)
{
	m_chatMemberId = id;
	m_chatMemberList = name;
}

//���̵� int�� ���� string���� �ؾ����� ����..
string PersonalChatRoom::SetChatRoomNameByID()
{
	m_chatRoomName = string();
	m_chatRoomName = m_chatMemberId;
	m_IsBasicName = true;

	return m_chatRoomName;
}

void PersonalChatRoom::SetChatRoomByName(string name)
{
	m_IsBasicName = false;

	m_chatRoomName = name;
}

int PersonalChatRoom::getChatRoomID()
{
	return m_chatRoomId;
}

string PersonalChatRoom::GetReceiverId()
{
	return m_chatMemberId;
}

LinkedList<string> PersonalChatRoom::GetReceiversId()
{
	return LinkedList<string>();
}

LinkedList<Message*> PersonalChatRoom::GetMessageList()
{
	return messageList;
}

string PersonalChatRoom::GetChatRoomName()
{
	if (m_chatRoomName.size() == 0)
	{
		SetChatRoomNameByID();
	}

	return m_chatRoomName;
}

bool PersonalChatRoom::GetBasicChatRoomName()
{
	return m_IsBasicName;
}
