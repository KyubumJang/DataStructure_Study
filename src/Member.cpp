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

//리스트의 레코드 설정 함수
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

//화면에 회원 아이디 출력 함수
void Member::displayId()
{
	cout << m_Id << endl;
}
//화면에 회원 비밀번호를 화면에 출력한다.
void Member::displayPw()
{
	cout << m_pw << endl;
}

//화면에 회원 이름 출력 함수
void Member::DisplayNameOnScreen()
{
	cout << m_Name << endl;
}

//화면에 회원 전화번호 출력 함수
void Member::DisplayPhoneNumOnScreen()
{
	cout << m_phoneNum << endl;
}

//화면에 회원 생년월일을 화면에 출력한다.
void Member::DisplayBirthOnScreen()
{
	cout << m_birth << endl;
}

//화면에 회원 프로필 사진을 화면에 출력한다.
void Member::DisplayProfilePhotoOnScreen()
{
	cout << m_profilePhoto << endl;
}

//화면에 회원 배경 사진을 화면에 출력한다.
void Member::DisplayBackgroundPhotoOnScreen()
{
	cout << m_backgroundPhoto << endl;
}

//화면에 회원 프로필 메시지를 화면에 출력한다.
void Member::DisplayProfileMessageOnScreen()
{
	cout << m_profileMessage << endl;
}

//화면에 회원 정보 출력 함수
void Member::displayMemberInfo()
{
	cout << "│ ID : " << m_Id << endl;
	cout << "│ 이름 : " << m_Name << endl;
	cout << "│ 전화번호 : " << m_phoneNum << endl;
	cout << "│ 생년월일 : " << m_birth << endl;
	cout << "│ 프로필사진 : " << m_profilePhoto  << endl;
	cout << "│ 배경사진 : " << m_backgroundPhoto << endl;
	cout << "│ 프로필 메시지 : " << m_profileMessage  << endl;

}

//키보드로 입력 받아 회원 아이디 설정하는 함수
void Member::ReadID()
{
	int id;
	cout << "아이디를 입력하십시오: " << endl;
	cin >> id;
	m_Id = id;
}

//키보드로 입력 받아 회원 비밀번호를 설정하는 함수
void Member::ReadPW()
{
	string pw;
	cout << "비밀번호를 입력하십시오: " << endl;
	cin >> pw;
	m_pw = pw;
}

//키보드로 입력 받아 회원 이름 설정하는 함수
void Member::SetNameFromKB()
{
	string name;
	cout << "이름을 입력하십시오: " << endl;
	cin >> name;
	m_Name = name;
}

//키보드로 입력 받아 회원 전화번호 설정하는 함수
void Member::SetPhoneNumFromKB()
{
	string phoneNumber;
	cout << "전화번호를 입력하십시오: " << endl;
	cin >> phoneNumber;
	m_phoneNum = phoneNumber;
}

//키보드로 입력 받아 회원 생년월일 설정하는 함수
void Member::SetBirthFromKB()
{
	string birth;
	cout << "생년월일을 입력하십시오: " << endl;
	cin >> birth;
	m_birth = birth;
}

//키보드로 입력 받아 회원 프로필 사진을 설정하는 함수
void Member::SetProfilPhotoFromKB()
{
	string profilePhoto;
	cout << "프로필 사진을 입력하십시오: " << endl;
	cin >> profilePhoto;
	m_profilePhoto = profilePhoto;
}

//키보드로 입력 받아 회원 프로필 사진을 설정하는 함수
void Member::SetBackgroundPhotoFromKB()
{
	string backgroundPhoto;
	cout << "배경 사진을 입력하십시오: " << endl;
	cin >> backgroundPhoto;
	m_backgroundPhoto = backgroundPhoto;
}

//키보드로 입력 받아 회원 프로필 메시지를 설정하는 함수
void Member::SetProfileMessageFromKB()
{
	string profileMessage;
	cout << "프로필 메시지를 입력하십시오: " << endl;
	cin >> profileMessage;
	m_profileMessage = profileMessage;
}

//키보드로 입력 받아 회원 정보 설정하는 함수
void Member::ReadMemberInfo()
{
	int id;
	cout << "아이디를 입력하십시오: " << endl;
	cin >> id;
	m_Id = id;

	string pw;
	cout << "비밀번호를 입력하십시오: " << endl;
	cin >> pw;
	m_pw = pw;

	string name;
	cout << "이름을 입력하십시오: " << endl;
	cin >> name;
	m_Name = name;

	string phoneNumber;
	cout << "전화번호를 입력하십시오: " << endl;
	cin >> phoneNumber;
	m_phoneNum = phoneNumber;

	string birth;
	cout << "생년월일을 입력하십시오: " << endl;
	cin >> birth;
	m_birth = birth;

	string profilePhoto;
	cout << "프로필 사진을 입력하십시오: " << endl;
	cin >> profilePhoto;
	m_profilePhoto = profilePhoto;

	string backgroundPhoto;
	cout << "배경 사진을 입력하십시오: " << endl;
	cin >> backgroundPhoto;
	m_backgroundPhoto = backgroundPhoto;

	string profileMessage;
	cout << "프로필 메시지를 입력하십시오: " << endl;
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
		cout << "│         친구 목록에 이미 존재하는 유저입니다         │" << endl;
	}
	else if (Temp == NULL)
	{
		"│         해당하는 사람을 찾을 수 없습니다         │";
	}
	else if (this == Temp)
	{
		cout << "│     자기 자신은 친구 목록에 추가할 수 없습니다   │" << endl;
	}

	friendList.Add(Temp);

	cout << endl;
	cout << "┌──────────[알림]────────────┐" << endl;
	cout << "│       친구 추가가 성공적으로 되었습니다.         │" << endl;
	cout << "└─────────────────────────┘" << endl;
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
		cout << "┌──────────[알림]────────────┐" << endl;
		cout << "│                 채팅방이 없습니다.               │" << endl;
		cout << "└─────────────────────────┘" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "┌─────────[채팅방 목록]──────────┐" << endl;
		for (int i = 0; i < chatRoomList.size(); i++)
		{
			cout << "│채팅방 아이디 : " << chatRoomList.Get(i)->getChatRoomID() << setw(39) << "│" << endl;
			cout << "│채팅방 이름 : ";
			cout << chatRoomList.Get(i)->GetChatRoomName() << setw(38 - chatRoomList.Get(i)->GetChatRoomName().size()) << "│" << endl;
			cout << "│                                                  │" << endl;
		}
		cout << "└─────────────────────────┘" << endl;
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





