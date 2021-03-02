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
		cout << "┌──────────<카카오톡>──────────┐" << endl;
		cout << "│                 1. 로그인                        │" << endl;
		cout << "│                 2. 회원 가입                     │" << endl;
		cout << "│                 0. 종료                          │" << endl;
		cout << "└─────────────────────────┘" << endl;
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
		cout << "┌───────<(" << curMember->GetName() << setw(36 - curMember->GetName().size()) << ")님 메뉴입니다.>─────┐" << endl;
		cout << "│              1.  친구                            │" << endl;
		cout << "│              2.  채팅방                          │" << endl;
		cout << "│              3.  내 정보                         │" << endl;
		cout << "│              0.  로그아웃                        │" << endl;
		cout << "└─────────────────────────┘" << endl;
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
		cout << "┌──────<카카오톡 친구 메뉴입니다>──────┐" << endl;
		cout << "│              1.  친구 목록                       │" << endl;
		cout << "│              2.  메시지 보내기                   │" << endl;
		cout << "│              3.  친구 추가                       │" << endl;
		cout << "│              4.  친구 삭제                       │" << endl;
		cout << "│              0.  뒤로가기                        │" << endl;
		cout << "└─────────────────────────┘" << endl;
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
		cout << "┌───────<채팅방 메뉴 입니다>────────┐" << endl;
		cout << "│              1.  채팅방 목록                     │" << endl;
		cout << "│              0.  이전메뉴                        │" << endl;
		cout << "└─────────────────────────┘" << endl;
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
		cout << "┌──────<원하는 기능을 선택하세요>──────┐" << endl;
		cout << "│              1.  사용자 정보 출력                │" << endl;
		cout << "│              2.  사용자 정보 수정                │" << endl;
		cout << "│              3.  회원 탈퇴                       │" << endl;
		cout << "│              0.  뒤로가기                        │" << endl;
		cout << "└───────s──────────────────┘" << endl;
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			cout << "┌─────────<사용자정보>──────────┐" << endl;
			curMember->displayMemberInfo();
			cout << "└─────────────────────────┘" << endl;
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
	cout << "┌──────────[ERROR!]───────────┐" << endl;
	cout << "│               잘못된 명령어입니다!               │" << endl;
	cout << "└─────────────────────────┘" << endl;
	cout << endl;
}
