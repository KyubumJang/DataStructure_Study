#include "Message.h"



Message::Message()
{
}


Message::~Message()
{
}

string Message::getSendId()
{
	return m_sendId;
}

string Message::getContent()
{
	return m_content;
}

Message Message::GetMessage()
{
	return *this;
}

void Message::sendMessage(string sendId, string content)
{
	m_sendId = sendId;
	m_content = content;
}

void Message::printMessage()
{
	cout << "弛忙式式式式式式式式式式式式式式式式式式式式式式式忖弛" << endl;
	cout << "弛弛" << m_content << setw(50 - m_content.size()) << "弛弛" << endl;
	cout << "弛戌式式式式式式式式式式式式式式式式式式式式式式式戎弛" << endl;
}
