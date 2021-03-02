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
	cout << "������������������������������������������������������" << endl;
	cout << "����" << m_content << setw(50 - m_content.size()) << "����" << endl;
	cout << "������������������������������������������������������" << endl;
}
