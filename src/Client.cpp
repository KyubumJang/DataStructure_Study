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

	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "ID蒂 殮溘ж褊衛螃: ";
	cin >> id;
	cout << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "Password蒂 殮溘ж褊衛螃: ";
	cin >> pw;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
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
		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛         煎斜檣檜 撩奢瞳戲煎 腎歷蝗棲棻.          弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "忙式式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
		cout << "弛             �蛾灠㊣埬� в蹂м棲棻.               弛" << endl;
		cout << "弛                       傳朝                       弛" << endl;
		cout << "弛          嬴檜蛤 綠塵廓�ㄧ� �挫恉� 輿褊衛螃.      弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛       煎斜嬴醒檜 撩奢瞳戲煎 腎歷蝗棲棻.          弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cout << endl;

	return true;
}

Message * Client::MakeMessage()
{
	Message* nTemp = new Message;	

	string content;	

	cout << "弛                                             (釭) 弛" << endl;
	cout << "弛忙式式式式式式式式式式式式式式式式式式式式式式式忖弛" << endl;
	cout << "弛弛";
	cin >> content;
	cout << "弛弛" << setw(50) << "弛弛" << endl;
	cout << "弛戌式式式式式式式式式式式式式式式式式式式式式式式戎弛" << endl;
	cout << "弛" << setw(52) << "弛" << endl;
	cout << "弛" << setw(52) << "弛" << endl;

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
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "耀掘 蹺陛й 耀掘曖 嬴檜蛤蒂 殮溘ж褊衛螃: ";
		cin >> id;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << endl;
		m_user->addFriend(findMemberbyId(id));
	}
}

void Client::printFriendList()
{
	if (m_user->getFriendList().size() == 0)
	{
		cout << endl;
		cout << "忙式式式式式式式式式式[憲葡]式式式式式式式式式式式忖" << endl;
		cout << "弛            耀掘跡煙檜 綠歷蝗棲棻.              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
	}

	cout << endl;
	cout << "忙式式式式式式式式式式[耀掘跡煙]式式式式式式式式式式式式忖" << endl;
	for (int i = 0; i < m_user->getFriendList().size(); i++)
	{
		m_user->getFriendList().Get(i)->displayMemberInfo();
		cout << "弛                                                      弛" << endl;
	}
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;

}

bool Client::MakeChatRoom()
{
	int command;

	cout << endl;
	cout << "忙式式式式式式式[瓣た寞 虜菟晦 詭景]式式式式式式式式忖" << endl;
	cout << "弛           1.  偃檣 瓣た寞 虜菟晦                 弛" << endl;
	cout << "弛           2.  欽羹 瓣た寞 虜菟晦                 弛" << endl;
	cout << "弛           0.  鏃模                               弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cout << endl;

	while (true)
	{
		cin >> command;

		if (command == 1)
		{
			string userId;
			cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "偃檣 瓣た擊 й 嶸盪曖 嬴檜蛤蒂 殮溘ж褊衛螃: ";
			cin >> userId;
			cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
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
				cout << "忙式式式式式式式式式式[憲葡]式式式式式式式式式式式忖" << endl;
				cout << "弛           瓣た寞檜 儅撩 腎歷蝗棲棻.            弛" << endl;
				cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
				return true;
			}
			else
			{
				cout << endl;
				cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
				cout << "弛    耀掘 跡煙縑 襄營ж雖 彊朝 嬴檜蛤 殮棲棻.    弛" << endl;
				cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
				cout << endl;
				return false;
			}
			break;
		}
		else if (command == 2)
		{
			//棻擠 Щ薛縑 掘⑷
		}

		else if (command == 0)
		{
			cout << endl;
			cout << "忙式式式式式式式式式式[憲葡]式式式式式式式式式式忖" << endl;
			cout << "弛                菴煎 給嬴骨棲棻.              弛" << endl;
			cout << "戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
			cout << endl;
			return false;
			break;
		}

		else
		{
			cout << endl;
			cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
			cout << "弛               棻衛 殮溘ж褊衛螃.               弛" << endl;
			cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
			cout << endl;
			cin >> command;
		}
	}
}

void Client::ExitsChatRoom()
{
	int chatRoomId;

	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "釭陛朝 瓣た寞曖 ID蒂 殮溘ж撮蹂(0擊 援腦賊 菴煎 給嬴骨棲棻.) ";
	cin >> chatRoomId;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << endl;

	if (!chatRoomId)
	{
		cout << endl;
		cout << "忙式式式式式式式式式式[憲葡]式式式式式式式式式式式忖" << endl;
		cout << "弛                 菴煎 給嬴骨棲棻                弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "詭衛雖蒂 爾鳥 嶸盪曖 ID蒂 殮溘ж撮蹂 : ";
	cin >> userId;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
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
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
		cout << "弛    耀掘 跡煙縑 襄營ж雖 彊朝 嬴檜蛤 殮棲棻.    弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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

	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "詭衛雖蒂 爾鳥 瓣た寞曖 嬴檜蛤蒂 殮溘ж撮蹂: ";
	cin >> chatRoomId;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;

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
	cout << "忙式式式式式式式式<瓣た寞  詭景>式式式式式式式式式式忖" << endl;
	cout << "弛              1.  瓣た寞 蹺陛                     弛" << endl;
	cout << "弛              2.  瓣た寞 釭陛晦                   弛" << endl;
	cout << "弛              3.  瓣た寞 殮濰                     弛" << endl;
	cout << "弛              4.  瓣た寞 檜葷 夥紱晦              弛" << endl;
	cout << "弛              0.  菴煎陛晦                        弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
		cout << "忙式式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
		cout << "弛              棻衛 衛紫п 爾褊衛螃.               弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
		cout << "弛             п渡 瓣た寞檜 橈蝗棲棻             弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
	}

	return NULL;
}

void Client::ChangeUserInfo()
{
	int command;

	cout << endl;
	cout << "忙式式式式式式式式<�蛾讔內� 熱薑 詭景>式式式式式式式式式式忖" << endl;
	cout << "弛              1.  綠塵廓��                              弛" << endl;
	cout << "弛              2.  檜葷                                  弛" << endl;
	cout << "弛              3.  瞪�食醽�                              弛" << endl;
	cout << "弛              4.  Щ煎в 餌霞                           弛" << endl;
	cout << "弛              5.  寡唳 餌霞                             弛" << endl;
	cout << "弛              6.  Щ煎в 詭衛雖                         弛" << endl;
	cout << "弛              0.  菴煎陛晦                              弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cin >> command;
	cout << endl;

	string temp;
	switch (command)
	{
	case 1:
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "夥羚 綠塵廓�ㄧ� 殮溘ж褊衛螃: ";
		cin >> temp;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		m_user->SetPw(temp);
		cout << "滲唳 腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	case 2:
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "夥羚 檜葷擊 殮溘ж褊衛螃: ";
		cin >> temp;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		m_user->SetName(temp);
		cout << "滲唳 腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	case 3:
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "夥羚 瞪�食醽ㄧ� 殮溘ж褊衛螃: ";
		cin >> temp;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		m_user->SetPhoneNum(temp);
		cout << "滲唳 腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	case 4:
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "夥羚 Щ煎в 餌霞擊 殮溘ж褊衛螃: ";
		cin >> temp;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		m_user->SetProfilePhoto(temp);
		cout << "滲唳 腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	case 5:
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "夥羚 寡唳餌霞擊 殮溘ж褊衛螃: ";
		cin >> temp;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		m_user->SetBackgroundPhoto(temp);
		cout << "滲唳 腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		break;

	case 6:
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "夥羚 Щ煎в 詭衛雖蒂 殮溘ж褊衛螃: ";
		cin >> temp;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		m_user->SetProfileMessage(temp);
		cout << "滲唳 腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	case 0:
		return;
		break;
	default:
		cout << endl;
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
		cout << "弛               棻衛 殮溘 ж褊衛螃.              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
		break;
	}

}

void Client::ChangeChatRoomName()
{
	int chatRoomId;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "檜葷擊 滲唳й 瓣た寞曖 嬴檜蛤蒂 殮溘ж撮蹂 : ";
	cin >> chatRoomId;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << endl;

	bool found = false;	 
	for (int i = 0; i < m_user->getChatRoomList().size(); i++)
	{
		if (m_user->getChatRoomList().Get(i)->getChatRoomID() == chatRoomId)
		{
			found = true;	
			string ChatRoomName;	
			cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "滲唳 й 瓣た寞曖 檜葷擊 殮溘ж撮蹂 : ";
			cin >> ChatRoomName;
			cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
			cout << endl;

			m_user->getChatRoomList().Get(i)->SetChatRoomByName(ChatRoomName);
			cout << endl;
			cout << "忙式式式式式式式式式式[憲葡]式式式式式式式式式式式忖" << endl;
			cout << "弛          瓣た寞 檜葷檜 滲唳腎歷蝗棲棻.         弛" << endl;
			cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
			cout << endl;
			break;
		}
	}
	if (!found)
	{
		cout << endl;
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式忖" << endl;
		cout << "弛             п渡 瓣た寞檜 橈蝗棲棻             弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
	}
}

void Client::deleteFriends()
{
	string friendId;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "餉薯й 耀掘曖 ID蒂 殮溘ж撮蹂 : ";
	cin >> friendId;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << endl;

	this->deleteFriend(this->findMemberbyId(friendId));	

}
