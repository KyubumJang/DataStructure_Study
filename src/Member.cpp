#include "Member.h"

#include "Member.h"



Member::Member()
{
	m_Id = -1;
	m_pw = "";
	m_Name = "";
	m_phoneNum = "01000000000";
	m_birth = "00001122";
	m_profilePhoto = "";
	m_backgroundPhoto = "";
	m_profileMessage = "";
};


Member::~Member()
{
}

//����Ʈ�� ���ڵ� ���� �Լ�
void Member::SetRecord(string inId, string inPw, string inName, string inPhoneNum, string inBirth, string inProfilePhoto, string inBackgroundPhoto, string inProfileMessage)
{
	m_Id = inId;
	m_pw = inPw;
	m_Name = inName;
	m_phoneNum = inPhoneNum;
	m_birth = inBirth;
	m_profilePhoto = inProfilePhoto;
	m_backgroundPhoto = inBackgroundPhoto;
	m_profileMessage = inProfileMessage;
}

//ȭ�鿡 ȸ�� ���̵� ��� �Լ�
void Member::displayId()
{
	cout << m_Id << endl;
}
//ȭ�鿡 ȸ�� ��й�ȣ�� ȭ�鿡 ����Ѵ�.
void Member::displayPw()
{
	cout << m_pw << endl;
}

//ȭ�鿡 ȸ�� �̸� ��� �Լ�
void Member::DisplayNameOnScreen()
{
	cout << m_Name << endl;
}

//ȭ�鿡 ȸ�� ��ȭ��ȣ ��� �Լ�
void Member::DisplayPhoneNumOnScreen()
{
	cout << m_phoneNum << endl;
}

//ȭ�鿡 ȸ�� ��������� ȭ�鿡 ����Ѵ�.
void Member::DisplayBirthOnScreen()
{
	cout << m_birth << endl;
}

//ȭ�鿡 ȸ�� ������ ������ ȭ�鿡 ����Ѵ�.
void Member::DisplayProfilePhotoOnScreen()
{
	cout << m_profilePhoto << endl;
}

//ȭ�鿡 ȸ�� ��� ������ ȭ�鿡 ����Ѵ�.
void Member::DisplayBackgroundPhotoOnScreen()
{
	cout << m_backgroundPhoto << endl;
}

//ȭ�鿡 ȸ�� ������ �޽����� ȭ�鿡 ����Ѵ�.
void Member::DisplayProfileMessageOnScreen()
{
	cout << m_profileMessage << endl;
}

//ȭ�鿡 ȸ�� ���� ��� �Լ�
void Member::displayMemberInfo()
{
	cout << "�� ID : " << m_Id << endl;
	cout << "�� �̸� : " << m_Name << endl;
	cout << "�� ��ȭ��ȣ : " << m_phoneNum << endl;
	cout << "�� ������� : " << m_birth << endl;
	cout << "�� �����ʻ��� : " << m_profilePhoto  << endl;
	cout << "�� ������ : " << m_backgroundPhoto << endl;
	cout << "�� ������ �޽��� : " << m_profileMessage  << endl;

}

//Ű����� �Է� �޾� ȸ�� ���̵� �����ϴ� �Լ�
void Member::ReadID()
{
	int id;
	cout << "���̵� �Է��Ͻʽÿ�: " << endl;
	cin >> id;
	m_Id = id;
}

//Ű����� �Է� �޾� ȸ�� ��й�ȣ�� �����ϴ� �Լ�
void Member::ReadPW()
{
	string pw;
	cout << "��й�ȣ�� �Է��Ͻʽÿ�: " << endl;
	cin >> pw;
	m_pw = pw;
}

//Ű����� �Է� �޾� ȸ�� �̸� �����ϴ� �Լ�
void Member::SetNameFromKB()
{
	string name;
	cout << "�̸��� �Է��Ͻʽÿ�: " << endl;
	cin >> name;
	m_Name = name;
}

//Ű����� �Է� �޾� ȸ�� ��ȭ��ȣ �����ϴ� �Լ�
void Member::SetPhoneNumFromKB()
{
	string phoneNumber;
	cout << "��ȭ��ȣ�� �Է��Ͻʽÿ�: " << endl;
	cin >> phoneNumber;
	m_phoneNum = phoneNumber;
}

//Ű����� �Է� �޾� ȸ�� ������� �����ϴ� �Լ�
void Member::SetBirthFromKB()
{
	string birth;
	cout << "��������� �Է��Ͻʽÿ�: " << endl;
	cin >> birth;
	m_birth = birth;
}

//Ű����� �Է� �޾� ȸ�� ������ ������ �����ϴ� �Լ�
void Member::SetProfilPhotoFromKB()
{
	string profilePhoto;
	cout << "������ ������ �Է��Ͻʽÿ�: " << endl;
	cin >> profilePhoto;
	m_profilePhoto = profilePhoto;
}

//Ű����� �Է� �޾� ȸ�� ������ ������ �����ϴ� �Լ�
void Member::SetBackgroundPhotoFromKB()
{
	string backgroundPhoto;
	cout << "��� ������ �Է��Ͻʽÿ�: " << endl;
	cin >> backgroundPhoto;
	m_backgroundPhoto = backgroundPhoto;
}

//Ű����� �Է� �޾� ȸ�� ������ �޽����� �����ϴ� �Լ�
void Member::SetProfileMessageFromKB()
{
	string profileMessage;
	cout << "������ �޽����� �Է��Ͻʽÿ�: " << endl;
	cin >> profileMessage;
	m_profileMessage = profileMessage;
}

//Ű����� �Է� �޾� ȸ�� ���� �����ϴ� �Լ�
void Member::ReadMemberInfo()
{
	int id;
	cout << "���̵� �Է��Ͻʽÿ�: " << endl;
	cin >> id;
	m_Id = id;

	string pw;
	cout << "��й�ȣ�� �Է��Ͻʽÿ�: " << endl;
	cin >> pw;
	m_pw = pw;

	string name;
	cout << "�̸��� �Է��Ͻʽÿ�: " << endl;
	cin >> name;
	m_Name = name;

	string phoneNumber;
	cout << "��ȭ��ȣ�� �Է��Ͻʽÿ�: " << endl;
	cin >> phoneNumber;
	m_phoneNum = phoneNumber;

	string birth;
	cout << "��������� �Է��Ͻʽÿ�: " << endl;
	cin >> birth;
	m_birth = birth;

	string profilePhoto;
	cout << "������ ������ �Է��Ͻʽÿ�: " << endl;
	cin >> profilePhoto;
	m_profilePhoto = profilePhoto;

	string backgroundPhoto;
	cout << "��� ������ �Է��Ͻʽÿ�: " << endl;
	cin >> backgroundPhoto;
	m_backgroundPhoto = backgroundPhoto;

	string profileMessage;
	cout << "������ �޽����� �Է��Ͻʽÿ�: " << endl;
	cin >> profileMessage;
	m_profileMessage = profileMessage;
}

void Member::addFriend(Member * Temp)
{
	bool found = false;	

	for (int i = 0; i < friendList.size(); i++)
	{
		if (friendList.Get(i) == Temp)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		cout << "��         ģ�� ��Ͽ� �̹� �����ϴ� �����Դϴ�         ��" << endl;
	}
	else if (Temp == NULL)
	{
		"��         �ش��ϴ� ����� ã�� �� �����ϴ�         ��";
	}
	else if (this == Temp)
	{
		cout << "��     �ڱ� �ڽ��� ģ�� ��Ͽ� �߰��� �� �����ϴ�   ��" << endl;
	}

	friendList.Add(Temp);

	cout << endl;
	cout << "����������������������[�˸�]��������������������������" << endl;
	cout << "��       ģ�� �߰��� ���������� �Ǿ����ϴ�.         ��" << endl;
	cout << "������������������������������������������������������" << endl;
	cout << endl;
}

void Member::deleteFriend(Member * Temp)
{
	friendList.Delete(Temp);
}

LinkedList<Member*> Member::getFriendList()
{
	return friendList;
}

void Member::addChatRoom(ChatRoom * Temp)
{
	chatRoomList.Add(Temp);
}

void Member::deleteChatRoom(ChatRoom * Temp)
{
	if (chatRoomList.Get(Temp))
	{
		chatRoomList.Delete(Temp);
	}
}

LinkedList<ChatRoom*> Member::getChatRoomList()
{
	return chatRoomList;
}

void Member::printChatRoom()
{
	if (chatRoomList.size() == 0)
	{
		cout << endl;
		cout << "����������������������[�˸�]��������������������������" << endl;
		cout << "��                 ä�ù��� �����ϴ�.               ��" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "��������������������[ä�ù� ���]����������������������" << endl;
		for (int i = 0; i < chatRoomList.size(); i++)
		{
			cout << "��ä�ù� ���̵� : " << chatRoomList.Get(i)->getChatRoomID() << setw(39) << "��" << endl;
			cout << "��ä�ù� �̸� : ";
			cout << chatRoomList.Get(i)->GetChatRoomName() << setw(38 - chatRoomList.Get(i)->GetChatRoomName().size()) << "��" << endl;
			cout << "��                                                  ��" << endl;
		}
		cout << "������������������������������������������������������" << endl;
		cout << endl;
	}
}

void Member::deleteChatRoomInMember(string userId, int chatRoomId)
{
	for (int i = 0; i < chatRoomList.size(); i++)
	{
		if (chatRoomList.Get(i)->getChatRoomID() == chatRoomId)
		{
			if (chatRoomList.Get(i)->GetReceiverId() == userId)
			{
				chatRoomList.Get(i)->DeleteReceiver(userId);
			}
			else if (chatRoomList.Get(i)->GetReceiversId().Get(userId))
			{
				chatRoomList.Get(i)->DeleteReceiver(userId);
			}
			break;
		}
	}
}





