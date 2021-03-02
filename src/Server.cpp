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

	cout << "°¡ÀÔÇÒ ID¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À : ";
	cin >> id;

	for (int i = 0; i < memberList.size(); i++)
	{
		if (memberList.Get(i)->GetId() == id)
		{
			cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
			cout << "¦¢              ÀÌ¹Ì Á¸ÀçÇÏ´Â IDÀÔ´Ï´Ù.               ¦¢" << endl;
			cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
			return;
		
		}
	}

	if (id == "0")
	{
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢       ÇØ´ç ¾ÆÀÌµð´Â ÀÌ¿ëÇÒ ¼ö ¾ø½À´Ï´Ù.            ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	}

	cout << "ÆÐ½º¿öµå¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À : ";
	cin >> pw;

	cout << endl;
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢           »ó¼¼ Á¤º¸¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À.              ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << endl;

	cout << "ÀÌ¸§: ";
	cin >> name;
	cout << "ÈÞ´ëÀüÈ­ ¹øÈ£: ";
	cin >> phoneNumber;
	cout << "»ýÀÏ(00001122): ";
	cin >> birth;
	cout << "ÇÁ·ÎÇÊ »çÁø: ";
	cin >> profilePhoto;
	cout << "¹è°æ»çÁø: ";
	cin >> backgroundPhoto;
	cout << "ÇÁ·ÎÇÊ ¸Þ½ÃÁö ÀÔ·Â : ";
	cin >> profileMessage;
	


	Member* Temp = new Member;
	Temp->SetRecord(id, pw, name, phoneNumber, birth, profilePhoto, backgroundPhoto, profileMessage);
	 memberList.Add(Temp);

	cout << endl;
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢            È¸¿ø °¡ÀÔ¿¡ ¼º°øÇß½À´Ï´Ù.             ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << endl;
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢            ·Î±×ÀÎ ÈÄ ÀÌ¿ëÇØÁÖ½Ê½Ã¿À.             ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << endl;
}

bool Server::leaveMember()
{
	int command;

	cout << endl;
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢             È¸¿ø Å»Åð¸¦ ÇÏ½Ã°Ú½À´Ï±î?            ¦¢" << endl;
	cout << "¦¢                  1. Å»ÅðÇÏ±â                     ¦¢" << endl;
	cout << "¦¢                  0. Ãë¼ÒÇÏ±â                     ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢            È¸¿ø Å»Åð°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù            ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;

		return true;
		break;
	case '0':
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢                 ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù                ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
		break;
	default:
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢               Àß¸øµÈ ¸í·É¾îÀÔ´Ï´Ù!               ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
				this->curMember->getFriendList().Get(i)->addChatRoom(Temp2);	//»ó´ë À¯Àú¿¡°Ô´Â ³ªÀÇ ÀÌ¸§ÀÌ Ç¥½ÃµÇ¹Ç·Î ÇöÀç ·Î±×ÀÎÇÑ À¯ÀúÀÇ ÀÌ¸§À¸·Î Ã¤ÆÃ¹æÀ» ¾÷µ¥ÀÌÆ®ÇÑ´Ù.
				break;
			}
		}
	}
}

void Server::MakeGroupChatRoom(LinkedList<string> userId, string chatRoomName)
{
	//´ÙÀ½ ÇÁÁ§ ¶§ ±¸Çö
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
		nTemp->sendMessage(id, "Ã¤ÆÃ¹æ¿¡¼­ ³ª°¬½À´Ï´Ù");	
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¾Ë¸²]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢             ÇØ´ç Ã¤ÆÃ¹æ¿¡¼­ ³ª°¬½À´Ï´Ù           ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢        Ã¤ÆÃ ¸ñ·Ï¿¡ ÇØ´ç Ã¤ÆÃ¹æÀÌ ¾ø½À´Ï´Ù        ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
	}

}

void Server::deleteFriend(Member * data)
{
	if (this->curMember->getFriendList().Get(data))
	{
		this->curMember->deleteFriend(data);
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¾Ë¸²]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢        Ä£±¸ ¸ñ·Ï¿¡¼­ Á¦°Å µÇ¾ú½À´Ï´Ù.            ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;

	}
	else
	{
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢         Ä£±¸ ¸ñ·Ï¿¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.           ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢      ÇØ´ç ¾ÆÀÌµð¸¦ °¡Áø ¸â¹ö°¡ ¾ø½À´Ï´Ù.         ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
		return NULL;
	}
}

bool Server::findMemberByName()
{
	bool found = false;	

	string name;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "¸â¹öÀÇ ÀÌ¸§À» ÀÔ·ÂÇÏ½Ê½Ã¿À: ";
	cin >> name;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;

	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡<°Ë»ö °á°ú>¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	for (int i = 0; i <  memberList.size(); i++)	
		if ( memberList.Get(i)->GetName() == name)	
		{
			memberList.Get(i)->displayMemberInfo();
			cout << "¦¢                                                  ¦¢" << endl;
			found = true;
		}
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << endl;

	if (!found)
	{
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡[¿¡·¯]¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢       ÇØ´ç ÀÌ¸§À» °¡Áø ¸â¹ö°¡ ¾ø½À´Ï´Ù.          ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << endl;
		return NULL;
	}
	else
		return true;
}
