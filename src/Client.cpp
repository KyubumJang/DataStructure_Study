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

	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "ID¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
	cin >> id;
	cout << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "Password¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
	cin >> pw;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢         ·Î±×ÀÎÀÌ ¼º°øÀûÀ¸·Î µÇ¾ú½À´Ï´Ù.          ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢             È¸¿ø°¡ÀÔÀÌ ÇÊ¿äÇÕ´Ï´Ù.               ¦¢" << endl;
		cout << "¦¢                       ¶Ç´Â                       ¦¢" << endl;
		cout << "¦¢          ¾ÆÀÌµð ºñ¹Ð¹øÈ£¸¦ È®ÀÎÇØ ÁÖ½Ê½Ã¿À.      ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢       ·Î±×¾Æ¿ôÀÌ ¼º°øÀûÀ¸·Î µÇ¾ú½À´Ï´Ù.          ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << endl;

	return true;
}

Message * Client::MakeMessage()
{
	Message* nTemp = new Message;	

	string content;	

	cout << "¦¢                                             (³ª) ¦¢" << endl;
	cout << "¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢" << endl;
	cout << "¦¢¦¢";
	cin >> content;
	cout << "¦¢¦¢" << setw(50) << "¦¢¦¢" << endl;
	cout << "¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢" << endl;
	cout << "¦¢" << setw(52) << "¦¢" << endl;
	cout << "¦¢" << setw(52) << "¦¢" << endl;

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
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "Ä£±¸ Ãß°¡ÇÒ Ä£±¸ÀÇ ¾ÆÀÌµð¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> id;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << endl;
		m_user->addFriend(findMemberbyId(id));
	}
}

void Client::printFriendList()
{
	if (m_user->getFriendList().size() == 0)
	{
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¾Ë¸²]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢            Ä£±¸¸ñ·ÏÀÌ ºñ¾ú½À´Ï´Ù.              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
	}

	cout << endl;
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[Ä£±¸¸ñ·Ï]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	for (int i = 0; i < m_user->getFriendList().size(); i++)
	{
		m_user->getFriendList().Get(i)->displayMemberInfo();
		cout << "¦¢                                                      ¦¢" << endl;
	}
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;

}

bool Client::MakeChatRoom()
{
	int command;

	cout << endl;
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡[Ã¤ÆÃ¹æ ¸¸µé±â ¸Þ´º]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢           1.  °³ÀÎ Ã¤ÆÃ¹æ ¸¸µé±â                 ¦¢" << endl;
	cout << "¦¢           2.  ´ÜÃ¼ Ã¤ÆÃ¹æ ¸¸µé±â                 ¦¢" << endl;
	cout << "¦¢           0.  Ãë¼Ò                               ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << endl;

	while (true)
	{
		cin >> command;

		if (command == 1)
		{
			string userId;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			cout << "°³ÀÎ Ã¤ÆÃÀ» ÇÒ À¯ÀúÀÇ ¾ÆÀÌµð¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
			cin >> userId;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
				cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¾Ë¸²]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
				cout << "¦¢           Ã¤ÆÃ¹æÀÌ »ý¼º µÇ¾ú½À´Ï´Ù.            ¦¢" << endl;
				cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
				return true;
			}
			else
			{
				cout << endl;
				cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
				cout << "¦¢    Ä£±¸ ¸ñ·Ï¿¡ Á¸ÀçÇÏÁö ¾Ê´Â ¾ÆÀÌµð ÀÔ´Ï´Ù.    ¦¢" << endl;
				cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
				cout << endl;
				return false;
			}
			break;
		}
		else if (command == 2)
		{
			//´ÙÀ½ ÇÁÁ§¿¡ ±¸Çö
		}

		else if (command == 0)
		{
			cout << endl;
			cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¾Ë¸²]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
			cout << "¦¢                µÚ·Î µ¹¾Æ°©´Ï´Ù.              ¦¢" << endl;
			cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
			cout << endl;
			return false;
			break;
		}

		else
		{
			cout << endl;
			cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
			cout << "¦¢               ´Ù½Ã ÀÔ·ÂÇÏ½Ê½Ã¿À.               ¦¢" << endl;
			cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
			cout << endl;
			cin >> command;
		}
	}
}

void Client::ExitsChatRoom()
{
	int chatRoomId;

	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "³ª°¡´Â Ã¤ÆÃ¹æÀÇ ID¸¦ ÀÔ·ÂÇÏ¼¼¿ä(0À» ´©¸£¸é µÚ·Î µ¹¾Æ°©´Ï´Ù.) ";
	cin >> chatRoomId;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << endl;

	if (!chatRoomId)
	{
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¾Ë¸²]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢                 µÚ·Î µ¹¾Æ°©´Ï´Ù                ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "¸Þ½ÃÁö¸¦ º¸³¾ À¯ÀúÀÇ ID¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ";
	cin >> userId;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢    Ä£±¸ ¸ñ·Ï¿¡ Á¸ÀçÇÏÁö ¾Ê´Â ¾ÆÀÌµð ÀÔ´Ï´Ù.    ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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

	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "¸Þ½ÃÁö¸¦ º¸³¾ Ã¤ÆÃ¹æÀÇ ¾ÆÀÌµð¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ";
	cin >> chatRoomId;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;

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
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡<Ã¤ÆÃ¹æ  ¸Þ´º>¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢              1.  Ã¤ÆÃ¹æ Ãß°¡                     ¦¢" << endl;
	cout << "¦¢              2.  Ã¤ÆÃ¹æ ³ª°¡±â                   ¦¢" << endl;
	cout << "¦¢              3.  Ã¤ÆÃ¹æ ÀÔÀå                     ¦¢" << endl;
	cout << "¦¢              4.  Ã¤ÆÃ¹æ ÀÌ¸§ ¹Ù²Ù±â              ¦¢" << endl;
	cout << "¦¢              0.  µÚ·Î°¡±â                        ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢              ´Ù½Ã ½ÃµµÇØ º¸½Ê½Ã¿À.               ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢             ÇØ´ç Ã¤ÆÃ¹æÀÌ ¾ø½À´Ï´Ù             ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
	}

	return NULL;
}

void Client::ChangeUserInfo()
{
	int command;

	cout << endl;
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡<È¸¿øÁ¤º¸ ¼öÁ¤ ¸Þ´º>¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢              1.  ºñ¹Ð¹øÈ£                              ¦¢" << endl;
	cout << "¦¢              2.  ÀÌ¸§                                  ¦¢" << endl;
	cout << "¦¢              3.  ÀüÈ­¹øÈ£                              ¦¢" << endl;
	cout << "¦¢              4.  ÇÁ·ÎÇÊ »çÁø                           ¦¢" << endl;
	cout << "¦¢              5.  ¹è°æ »çÁø                             ¦¢" << endl;
	cout << "¦¢              6.  ÇÁ·ÎÇÊ ¸Þ½ÃÁö                         ¦¢" << endl;
	cout << "¦¢              0.  µÚ·Î°¡±â                              ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cin >> command;
	cout << endl;

	string temp;
	switch (command)
	{
	case 1:
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "¹Ù²Ü ºñ¹Ð¹øÈ£¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> temp;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		m_user->SetPw(temp);
		cout << "º¯°æ µÇ¾ú½À´Ï´Ù." << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		break;
	case 2:
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "¹Ù²Ü ÀÌ¸§À» ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> temp;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		m_user->SetName(temp);
		cout << "º¯°æ µÇ¾ú½À´Ï´Ù." << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		break;
	case 3:
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "¹Ù²Ü ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> temp;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		m_user->SetPhoneNum(temp);
		cout << "º¯°æ µÇ¾ú½À´Ï´Ù." << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		break;
	case 4:
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "¹Ù²Ü ÇÁ·ÎÇÊ »çÁøÀ» ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> temp;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		m_user->SetProfilePhoto(temp);
		cout << "º¯°æ µÇ¾ú½À´Ï´Ù." << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		break;
	case 5:
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "¹Ù²Ü ¹è°æ»çÁøÀ» ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> temp;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		m_user->SetBackgroundPhoto(temp);
		cout << "º¯°æ µÇ¾ú½À´Ï´Ù." << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		break;

	case 6:
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "¹Ù²Ü ÇÁ·ÎÇÊ ¸Þ½ÃÁö¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
		cin >> temp;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		m_user->SetProfileMessage(temp);
		cout << "º¯°æ µÇ¾ú½À´Ï´Ù." << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		break;
	case 0:
		return;
		break;
	default:
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢               ´Ù½Ã ÀÔ·Â ÇÏ½Ê½Ã¿À.              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
		break;
	}

}

void Client::ChangeChatRoomName()
{
	int chatRoomId;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "ÀÌ¸§À» º¯°æÇÒ Ã¤ÆÃ¹æÀÇ ¾ÆÀÌµð¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ";
	cin >> chatRoomId;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << endl;

	bool found = false;	 
	for (int i = 0; i < m_user->getChatRoomList().size(); i++)
	{
		if (m_user->getChatRoomList().Get(i)->getChatRoomID() == chatRoomId)
		{
			found = true;	
			string ChatRoomName;	
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			cout << "º¯°æ ÇÒ Ã¤ÆÃ¹æÀÇ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä : ";
			cin >> ChatRoomName;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
			cout << endl;

			m_user->getChatRoomList().Get(i)->SetChatRoomByName(ChatRoomName);
			cout << endl;
			cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¾Ë¸²]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
			cout << "¦¢          Ã¤ÆÃ¹æ ÀÌ¸§ÀÌ º¯°æµÇ¾ú½À´Ï´Ù.         ¦¢" << endl;
			cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
			cout << endl;
			break;
		}
	}
	if (!found)
	{
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢             ÇØ´ç Ã¤ÆÃ¹æÀÌ ¾ø½À´Ï´Ù             ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
	}
}

void Client::deleteFriends()
{
	string friendId;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "»èÁ¦ÇÒ Ä£±¸ÀÇ ID¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ";
	cin >> friendId;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << endl;

	this->deleteFriend(this->findMemberbyId(friendId));	

}
