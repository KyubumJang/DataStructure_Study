#include "GroupChatRoom.h"



GroupChatRoom::GroupChatRoom()
{
}


GroupChatRoom::~GroupChatRoom()
{
}

void GroupChatRoom::addChatRoom(Message * data)
{
}

void GroupChatRoom::updateChatRoomID(int chatRoomID)
{
}

void GroupChatRoom::AddReceiverId(string id, string name)
{
}

void GroupChatRoom::PrintMessageList()
{
}

bool GroupChatRoom::DeleteReceiver(string userId)
{
	return false;
}

int GroupChatRoom::getChatRoomID()
{
	return 0;
}

string GroupChatRoom::GetReceiverId()
{
	return string();
}

LinkedList<string> GroupChatRoom::GetReceiversId()
{
	return LinkedList<string>();
}

LinkedList<Message*> GroupChatRoom::GetMessageList()
{
	return LinkedList<Message*>();
}

string GroupChatRoom::GetChatRoomName()
{
	return string();
}

bool GroupChatRoom::GetBasicChatRoomName()
{
	return false;
}

void GroupChatRoom::SetReceiverId(string id, string name)
{
}

string GroupChatRoom::SetChatRoomNameByID()
{
	return string();
}

void GroupChatRoom::SetChatRoomByName(string name)
{
}
