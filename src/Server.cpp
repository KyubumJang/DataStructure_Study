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

	cout << "陛殮й ID蒂 殮溘ж褊衛螃 : ";
	cin >> id;

	for (int i = 0; i < memberList.size(); i++)
	{
		if (memberList.Get(i)->GetId() == id)
		{
			cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式式式忖" << endl;
			cout << "弛              檜嘐 襄營ж朝 ID殮棲棻.               弛" << endl;
			cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
			return;
		
		}
	}

	if (id == "0")
	{
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式式式忖" << endl;
		cout << "弛       п渡 嬴檜蛤朝 檜辨й 熱 橈蝗棲棻.            弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	}

	cout << "ぬ蝶錶萄蒂 殮溘ж褊衛螃 : ";
	cin >> pw;

	cout << endl;
	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛           鼻撮 薑爾蒂 殮溘ж褊衛螃.              弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cout << endl;

	cout << "檜葷: ";
	cin >> name;
	cout << "�瑒蹀��� 廓��: ";
	cin >> phoneNumber;
	cout << "儅橾(00001122): ";
	cin >> birth;
	cout << "Щ煎в 餌霞: ";
	cin >> profilePhoto;
	cout << "寡唳餌霞: ";
	cin >> backgroundPhoto;
	cout << "Щ煎в 詭衛雖 殮溘 : ";
	cin >> profileMessage;
	


	Member* Temp = new Member;
	Temp->SetRecord(id, pw, name, phoneNumber, birth, profilePhoto, backgroundPhoto, profileMessage);
	 memberList.Add(Temp);

	cout << endl;
	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛            �蛾� 陛殮縑 撩奢ц蝗棲棻.             弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cout << endl;
	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛            煎斜檣 �� 檜辨п輿褊衛螃.             弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cout << endl;
}

bool Server::leaveMember()
{
	int command;

	cout << endl;
	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛             �蛾� 驍黴蒂 ж衛啊蝗棲梱?            弛" << endl;
	cout << "弛                  1. 驍黴ж晦                     弛" << endl;
	cout << "弛                  0. 鏃模ж晦                     弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛            �蛾� 驍黴陛 諫猿腎歷蝗棲棻            弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;

		return true;
		break;
	case '0':
		cout << endl;
		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛                 詭景煎 給嬴骨棲棻                弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
		break;
	default:
		cout << endl;
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式式忖" << endl;
		cout << "弛               澀跤脹 貲滄橫殮棲棻!               弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
				this->curMember->getFriendList().Get(i)->addChatRoom(Temp2);	//鼻渠 嶸盪縑啪朝 釭曖 檜葷檜 ル衛腎嘎煎 ⑷營 煎斜檣и 嶸盪曖 檜葷戲煎 瓣た寞擊 機等檜おи棻.
				break;
			}
		}
	}
}

void Server::MakeGroupChatRoom(LinkedList<string> userId, string chatRoomName)
{
	//棻擠 Щ薛 陽 掘⑷
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
		nTemp->sendMessage(id, "瓣た寞縑憮 釭鬲蝗棲棻");	
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
		cout << "忙式式式式式式式式式式[憲葡]式式式式式式式式式式式式忖" << endl;
		cout << "弛             п渡 瓣た寞縑憮 釭鬲蝗棲棻           弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式式忖" << endl;
		cout << "弛        瓣た 跡煙縑 п渡 瓣た寞檜 橈蝗棲棻        弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
	}

}

void Server::deleteFriend(Member * data)
{
	if (this->curMember->getFriendList().Get(data))
	{
		this->curMember->deleteFriend(data);
		cout << endl;
		cout << "忙式式式式式式式式式式[憲葡]式式式式式式式式式式式式忖" << endl;
		cout << "弛        耀掘 跡煙縑憮 薯剪 腎歷蝗棲棻.            弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;

	}
	else
	{
		cout << endl;
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式式忖" << endl;
		cout << "弛         耀掘 跡煙縑 襄營ж雖 彊蝗棲棻.           弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
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
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式式忖" << endl;
		cout << "弛      п渡 嬴檜蛤蒂 陛霞 詹幗陛 橈蝗棲棻.         弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
		return NULL;
	}
}

bool Server::findMemberByName()
{
	bool found = false;	

	string name;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "詹幗曖 檜葷擊 殮溘ж褊衛螃: ";
	cin >> name;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;

	cout << "忙式式式式式式式式式<匐儀 唸婁>式式式式式式式式式式忖" << endl;
	for (int i = 0; i <  memberList.size(); i++)	
		if ( memberList.Get(i)->GetName() == name)	
		{
			memberList.Get(i)->displayMemberInfo();
			cout << "弛                                                  弛" << endl;
			found = true;
		}
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cout << endl;

	if (!found)
	{
		cout << "忙式式式式式式式式式式[縑楝]式式式式式式式式式式式式忖" << endl;
		cout << "弛       п渡 檜葷擊 陛霞 詹幗陛 橈蝗棲棻.          弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		cout << endl;
		return NULL;
	}
	else
		return true;
}
