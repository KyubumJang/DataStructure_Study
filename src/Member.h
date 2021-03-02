#pragma once
#include"GroupChatRoom.h"
#include"PersonalChatRoom.h"
/**
*	ȸ�� ������ ���ϴ� Ŭ����
*	@author	��Թ�
*	@date	20171027
*/
class Member
{
public:
	/**
	*	�⺻ ������.
	*/
	Member();

	/**
	*	�Ҹ���.
	*/
	~Member();

	/**
	*	@brief	ȸ�� ���̵� �������� �Լ�.
	*	@pre	ȸ�� ���̵� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	���̵� ����.
	*/
	string GetId() { return m_Id; };

	/**
	*	@brief	ȸ�� ��й�ȣ �������� �Լ�.
	*	@pre	ȸ�� ��й�ȣ�� �����Ǿ� �־�� �Ѵ�.
	*	@post	����
	*	@return	��й�ȣ ����.
	*/
	string GetPw() { return m_pw; };

	/**
	*	@brief	ȸ�� �̸� �������� �Լ�
	*	@pre	ȸ�� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	�̸� ����.
	*/
	string GetName() { return m_Name; };

	/**
	*	@brief	ȸ�� ��ȭ��ȣ �������� �Լ�.
	*	@pre	ȸ�� ��ȭ��ȣ�� �����Ǿ� �־�� �Ѵ�.
	*	@post	����
	*	@return	��ȭ��ȣ ����.
	*/
	string GetPhoneNum() { return m_phoneNum; };

	/**
	*	@brief	ȸ�� ������� �������� �Լ�.
	*	@pre	ȸ�� ��������� �����Ǿ� �־�� �Ѵ�.
	*	@post	����
	*	@return	���� ����.
	*/
	string GetBirth() { return m_birth; };

	/**
	*	@brief	ȸ�� ������ ���� �������� �Լ�.
	*	@pre	ȸ�� ������ ������ �����Ǿ� �־�� �Ѵ�.
	*	@post	����
	*	@return	������ ���� ����.
	*/
	string GetProfilePhoto() { return m_profilePhoto; };

	/**
	*	@brief	ȸ�� ��� ���� �������� �Լ�.
	*	@pre	ȸ�� ��� ������ �����Ǿ� �־�� �Ѵ�.
	*	@post	����
	*	@return	��� ���� ����.
	*/
	string GetBackgroundPhoto() { return m_backgroundPhoto; };

	/**
	*	@brief	ȸ�� ������ �޽����� �������� �Լ�
	*	@pre	ȸ�� ������ �޽����� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	������ �޽���.
	*/
	string GetProfileMessage() { return m_profileMessage; };

	/**
	*	@brief	ȸ�� ���̵� �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ���̵� �����ȴ�.
	*	@param	���̵�	���̵�.
	*/
	void SetId(string inId) { m_Id = inId; };

	/**
	*	@brief	ȸ�� ��й�ȣ �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ��й�ȣ�� �����ȴ�.
	*	@param	��й�ȣ	ȸ�� ��й�ȣ.
	*/
	void SetPw(string inPw) { m_pw = inPw; };

	/**
	*	@brief	ȸ�� �̸� �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� �̸��� �����ȴ�.
	*	@param	�̸�	ȸ�� �̸�.
	*/
	void SetName(string inName) { m_Name = inName; };

	/**
	*	@brief	ȸ�� ��ȭ��ȣ �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ��ȭ��ȣ�� �����ȴ�.
	*	@param	��ȭ��ȣ	ȸ�� ��ȭ��ȣ.
	*/
	void SetPhoneNum(string inPhoneNUm) { m_phoneNum = inPhoneNUm; };

	/**
	*	@brief	ȸ�� ������� �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ��������� �����ȴ�.
	*	@param	�������	ȸ�� �������.
	*/
	void SetBirth(string inBirth) { m_birth = inBirth; };

	/**
	*	@brief	ȸ�� ������ ���� �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ������ ������ �����ȴ�.
	*	@param	������ ����	ȸ�� ������ ����.
	*/
	void SetProfilePhoto(string inProfilePhoto) { m_profilePhoto = inProfilePhoto; };
	/**
	*	@brief	ȸ�� ���ȭ�� �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ���ȭ���� �����ȴ�.
	*	@param	������ ���ȭ��	ȸ�� ���ȭ�� �޽���.
	*/
	void SetBackgroundPhoto(string inBackgroundPhoto) { m_backgroundPhoto = inBackgroundPhoto; };

	/**
	*	@brief	ȸ�� ������ �޽��� �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ������ �޽����� �����ȴ�.
	*	@param	������ �޽���	ȸ�� ������ �޽���.
	*/
	void SetProfileMessage(string inProfileMessage) { m_profileMessage = inProfileMessage; };

	/**
	*	@brief	ȸ�� ���� �����ϴ� �Լ�.
	*	@pre	����.
	*	@post	ȸ�� ������ �����ȴ�.
	*	@param	���̵�	ȸ�� ���̵�.
	*	@param	��й�ȣ	ȸ�� ��й�ȣ.
	*	@param	�̸�	ȸ�� �̸�.
	*	@param	�������	ȸ�� �������.
	*	@param	������ �޽���	ȸ�� ������ �޽���.
	*/
	void SetRecord(string inId, string inPw, string inName, string inPhoneNum, string inBirth, string inProfilePhoto, string inBackgroundPhoto, string inProfileMessage);

	/**
	*	@brief	ȸ�� ���̵� ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� ���̵� �����Ǿ� ����.
	*	@post	ȸ�� ���̵� ȭ�鿡 ��µ�.
	*/
	void displayId();

	/**
	*	@brief	ȸ�� ��й�ȣ�� ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� ��й�ȣ�� �����Ǿ� ����.
	*	@post	ȸ�� ��й�ȣ�� ȭ�鿡 ��µ�.
	*/
	void displayPw();

	/**
	*	@brief	ȸ�� �̸��� ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� �̸��� �����Ǿ� ����.
	*	@post	ȸ�� �̸��� ȭ�鿡 ��µ�.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	ȸ�� ��ȭ��ȣ�� ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� ��ȭ��ȣ�� �����Ǿ� ����.
	*	@post	ȸ�� ��ȭ��ȣ�� ȭ�鿡 ��µ�.
	*/
	void DisplayPhoneNumOnScreen();

	/**
	*	@brief	ȸ�� ��������� ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� ��������� �����Ǿ� ����.
	*	@post	ȸ�� ��������� ȭ�鿡 ��µ�.
	*/
	void DisplayBirthOnScreen();

	/**
	*	@brief	ȸ�� ������ ������ ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� ������ ������ �����Ǿ� ����.
	*	@post	ȸ�� ������ ������ ȭ�鿡 ��µ�.
	*/
	void DisplayProfilePhotoOnScreen();

	/**
	*	@brief	ȸ�� �������� ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� �������� �����Ǿ� ����.
	*	@post	ȸ�� �������� ȭ�鿡 ��µ�.
	*/
	void DisplayBackgroundPhotoOnScreen();

	/**
	*	@brief	ȸ�� ������ �޽����� ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� ������ �޽����� �����Ǿ� ����.
	*	@post	ȸ�� ������ �޽����� ȭ�鿡 ��µ�.
	*/
	void DisplayProfileMessageOnScreen();

	/**
	*	@brief	ȸ�� ������ ȭ�鿡 ����Ѵ�.
	*	@pre	ȸ�� ������ �����Ǿ� ����.
	*	@post	ȸ�� ������ ȭ�鿡 ��µ�.
	*/
	void displayMemberInfo();

	/**
	*	@brief	Ű����� ȸ�� ���̵� ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ���̵� ������.
	*/
	void ReadID();

	/**
	*	@brief	Ű����� ȸ�� ��й�ȣ ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ��й�ȣ�� ������.
	*/
	void ReadPW();

	/**
	*	@brief	Ű����� ȸ�� �̸� ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� �̸� ������.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Ű����� ȸ�� ��ȭ��ȣ ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ��ȭ��ȣ ������.
	*/
	void SetPhoneNumFromKB();

	/**
	*	@brief	Ű����� ȸ�� ������� ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ������� ������.
	*/
	void SetBirthFromKB();
	/**
	*	@brief	Ű����� ȸ�� ������ ���� ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ������ ���� ������.
	*/
	void SetProfilPhotoFromKB();

	/**
	*	@brief	Ű����� ȸ�� ��� ���� ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ��� ���� ������.
	*/
	void SetBackgroundPhotoFromKB();

	/**
	*	@brief	Ű����� ȸ�� ������ �޽��� ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ������ �޽��� ������.
	*/
	void SetProfileMessageFromKB();

	/**
	*	@brief	Ű����� ȸ�� ���� ����.
	*	@pre	����.
	*	@post	Ű����� ȸ�� ���� ������.
	*/
	void ReadMemberInfo();

	/**
	*	@brief	����� ģ�� ����Ʈ�� Temp �߰�
	*	@pre	ģ�� ����Ʈ�� Temp�� ����� ��
	*	@post	ģ�� ����Ʈ�� �߰���
	*	@param	Member* Temp
	*/
	void addFriend(Member* Temp);
	
	/**
	*	@biref	����� ģ�� ����Ʈ���� Temp ����
	*	@pre	�ش��ϴ� ģ���� ģ������Ʈ�� ����
	*	@post	ģ�� ����Ʈ���� ����
	*	@param	Member* Temp
	*/
	void deleteFriend(Member *Temp);

	/**
	*	@brief	����� ģ�� ����Ʈ�� ������
	*	@pre	����� ģ�� ����Ʈ�� ������
	*	@post	����.
	*	@return	LinkedList<Member*>
	*/
	LinkedList<Member*> getFriendList();

	/**
	*	@brief	ä�ù濡 Temp �߰�
	*	@pre	����.
	*	@post	ä�ù� ����Ʈ�� �߰���
	*	@param	ChatRoom* Temp
	*/
	void addChatRoom(ChatRoom* Temp);

	/**
	*	@brief	��� ä�ù� ����Ʈ���� Temp ����
	*	@pre	����.
	*	@post	ä�ù� ����Ʈ���� Temp ������
	*	@param	ChatRoom* Temp
	*/
	void deleteChatRoom(ChatRoom *Temp);

	/**
	*	@brief	����� ä�ù� ����Ʈ�� ������
	*	@pre	����� ä�ù� ����Ʈ ������
	*	@post	����.
	*	@return	LinkedList<ChatRoom*>
	*/
	LinkedList<ChatRoom*> getChatRoomList();

	/**
	*	@brief	������ ä�ù� ��� �����.
	*	@pre	����.
	*	@post	ä�ù� ��µ�.
	*/
	void printChatRoom();

	/**
	*	@brief	ä�ù濡�� userId�� ����
	*	@pre	����
	*	@post	ä�ù� ����Ʈ���� ����� ������
	*	@param	userId, int chatRoomId
	*/
	void deleteChatRoomInMember(string userId, int chatRoomId);

protected:
	string m_Id;			///< īī���� ���̵�.
	string m_pw;		///< īī���� ��й�ȣ
	string m_Name;		///< �̸�.
	string m_phoneNum;	///< ��ȭ��ȣ
	string m_birth;		///< ���� ���� 
	string m_profilePhoto;	///< ������ ����
	string m_backgroundPhoto;	///< ������
	string m_profileMessage;	///< ������ �޽���.

	LinkedList<Member*> friendList; // ������ ģ�� ��� ����Ʈ
	LinkedList<ChatRoom*> chatRoomList; // ä�ù��� �����ϴ� ����Ʈ (ģ�� ��Ͽ��� ������ ģ������ ä�ù� ����Ʈ�� �����)
};

