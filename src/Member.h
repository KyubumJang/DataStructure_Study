#pragma once
#include"GroupChatRoom.h"
#include"PersonalChatRoom.h"
/**
*	회원 정보를 정하는 클래스
*	@author	장규범
*	@date	20171027
*/
class Member
{
public:
	/**
	*	기본 생성자.
	*/
	Member();

	/**
	*	소멸자.
	*/
	~Member();

	/**
	*	@brief	회원 아이디 가져오는 함수.
	*	@pre	회원 아이디가 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	아이디 리턴.
	*/
	string GetId() { return m_Id; };

	/**
	*	@brief	회원 비밀번호 가져오는 함수.
	*	@pre	회원 비밀번호가 설정되어 있어야 한다.
	*	@post	없음
	*	@return	비밀번호 리턴.
	*/
	string GetPw() { return m_pw; };

	/**
	*	@brief	회원 이름 가져오는 함수
	*	@pre	회원 이름이 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	이름 리턴.
	*/
	string GetName() { return m_Name; };

	/**
	*	@brief	회원 전화번호 가져오는 함수.
	*	@pre	회원 전화번호가 설정되어 있어야 한다.
	*	@post	없음
	*	@return	전화번호 리턴.
	*/
	string GetPhoneNum() { return m_phoneNum; };

	/**
	*	@brief	회원 생년월일 가져오는 함수.
	*	@pre	회원 생년월일이 설정되어 있어야 한다.
	*	@post	없음
	*	@return	생일 리턴.
	*/
	string GetBirth() { return m_birth; };

	/**
	*	@brief	회원 프로필 사진 가져오는 함수.
	*	@pre	회원 프로필 사진이 설정되어 있어야 한다.
	*	@post	없음
	*	@return	프로필 사진 리턴.
	*/
	string GetProfilePhoto() { return m_profilePhoto; };

	/**
	*	@brief	회원 배경 사진 가져오는 함수.
	*	@pre	회원 배경 사진이 설정되어 있어야 한다.
	*	@post	없음
	*	@return	배경 사진 리턴.
	*/
	string GetBackgroundPhoto() { return m_backgroundPhoto; };

	/**
	*	@brief	회원 프로필 메시지를 가져오는 함수
	*	@pre	회원 프로필 메시지가 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	프로필 메시지.
	*/
	string GetProfileMessage() { return m_profileMessage; };

	/**
	*	@brief	회원 아이디 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 아이디가 설정된다.
	*	@param	아이디	아이디.
	*/
	void SetId(string inId) { m_Id = inId; };

	/**
	*	@brief	회원 비밀번호 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 비밀번호가 설정된다.
	*	@param	비밀번호	회원 비밀번호.
	*/
	void SetPw(string inPw) { m_pw = inPw; };

	/**
	*	@brief	회원 이름 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 이름이 설정된다.
	*	@param	이름	회원 이름.
	*/
	void SetName(string inName) { m_Name = inName; };

	/**
	*	@brief	회원 전화번호 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 전화번호가 설정된다.
	*	@param	전화번호	회원 전화번호.
	*/
	void SetPhoneNum(string inPhoneNUm) { m_phoneNum = inPhoneNUm; };

	/**
	*	@brief	회원 생년월일 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 생년월일이 설정된다.
	*	@param	생년월일	회원 생년월일.
	*/
	void SetBirth(string inBirth) { m_birth = inBirth; };

	/**
	*	@brief	회원 프로필 사진 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 프로필 사진이 설정된다.
	*	@param	프로필 사진	회원 프로필 사진.
	*/
	void SetProfilePhoto(string inProfilePhoto) { m_profilePhoto = inProfilePhoto; };
	/**
	*	@brief	회원 배경화면 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 배경화면이 설정된다.
	*	@param	프로필 배경화면	회원 배경화면 메시지.
	*/
	void SetBackgroundPhoto(string inBackgroundPhoto) { m_backgroundPhoto = inBackgroundPhoto; };

	/**
	*	@brief	회원 프로필 메시지 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 프로필 메시지가 설정된다.
	*	@param	프로필 메시지	회원 프로필 메시지.
	*/
	void SetProfileMessage(string inProfileMessage) { m_profileMessage = inProfileMessage; };

	/**
	*	@brief	회원 정보 설정하는 함수.
	*	@pre	없음.
	*	@post	회원 정보가 설정된다.
	*	@param	아이디	회원 아이디.
	*	@param	비밀번호	회원 비밀번호.
	*	@param	이름	회원 이름.
	*	@param	생년월일	회원 생년월일.
	*	@param	프로필 메시지	회원 프로필 메시지.
	*/
	void SetRecord(string inId, string inPw, string inName, string inPhoneNum, string inBirth, string inProfilePhoto, string inBackgroundPhoto, string inProfileMessage);

	/**
	*	@brief	회원 아이디를 화면에 출력한다.
	*	@pre	회원 아이디가 설정되어 있음.
	*	@post	회원 아이디가 화면에 출력됨.
	*/
	void displayId();

	/**
	*	@brief	회원 비밀번호를 화면에 출력한다.
	*	@pre	회원 비밀번호가 설정되어 있음.
	*	@post	회원 비밀번호가 화면에 출력됨.
	*/
	void displayPw();

	/**
	*	@brief	회원 이름를 화면에 출력한다.
	*	@pre	회원 이름이 설정되어 있음.
	*	@post	회원 이름이 화면에 출력됨.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	회원 전화번호를 화면에 출력한다.
	*	@pre	회원 전화번호가 설정되어 있음.
	*	@post	회원 전화번호가 화면에 출력됨.
	*/
	void DisplayPhoneNumOnScreen();

	/**
	*	@brief	회원 생년월일을 화면에 출력한다.
	*	@pre	회원 생년월일이 설정되어 있음.
	*	@post	회원 생년월일이 화면에 출력됨.
	*/
	void DisplayBirthOnScreen();

	/**
	*	@brief	회원 프로필 사진을 화면에 출력한다.
	*	@pre	회원 프로필 사진이 설정되어 있음.
	*	@post	회원 프로필 사진이 화면에 출력됨.
	*/
	void DisplayProfilePhotoOnScreen();

	/**
	*	@brief	회원 배경사진을 화면에 출력한다.
	*	@pre	회원 배경사진이 설정되어 있음.
	*	@post	회원 배경사진이 화면에 출력됨.
	*/
	void DisplayBackgroundPhotoOnScreen();

	/**
	*	@brief	회원 프로필 메시지를 화면에 출력한다.
	*	@pre	회원 프로필 메시지가 설정되어 있음.
	*	@post	회원 프로필 메시지가 화면에 출력됨.
	*/
	void DisplayProfileMessageOnScreen();

	/**
	*	@brief	회원 정보를 화면에 출력한다.
	*	@pre	회원 정보가 설정되어 있음.
	*	@post	회원 정보가 화면에 출력됨.
	*/
	void displayMemberInfo();

	/**
	*	@brief	키보드로 회원 아이디 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 아이디가 설정됨.
	*/
	void ReadID();

	/**
	*	@brief	키보드로 회원 비밀번호 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 비밀번호가 설정됨.
	*/
	void ReadPW();

	/**
	*	@brief	키보드로 회원 이름 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 이름 설정됨.
	*/
	void SetNameFromKB();

	/**
	*	@brief	키보드로 회원 전화번호 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 전화번호 설정됨.
	*/
	void SetPhoneNumFromKB();

	/**
	*	@brief	키보드로 회원 생년월일 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 생년월일 설정됨.
	*/
	void SetBirthFromKB();
	/**
	*	@brief	키보드로 회원 프로필 사진 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 프로필 사진 설정됨.
	*/
	void SetProfilPhotoFromKB();

	/**
	*	@brief	키보드로 회원 배경 사진 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 배경 사진 설정됨.
	*/
	void SetBackgroundPhotoFromKB();

	/**
	*	@brief	키보드로 회원 프로필 메시지 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 프로필 메시지 설정됨.
	*/
	void SetProfileMessageFromKB();

	/**
	*	@brief	키보드로 회원 정보 설정.
	*	@pre	없음.
	*	@post	키보드로 회원 정보 설정됨.
	*/
	void ReadMemberInfo();

	/**
	*	@brief	멤버의 친구 리스트에 Temp 추가
	*	@pre	친구 리스트에 Temp가 없어야 함
	*	@post	친구 리스트에 추가됨
	*	@param	Member* Temp
	*/
	void addFriend(Member* Temp);
	
	/**
	*	@biref	멤버의 친구 리스트에서 Temp 삭제
	*	@pre	해당하는 친구가 친구리스트에 존재
	*	@post	친구 리스트에서 삭제
	*	@param	Member* Temp
	*/
	void deleteFriend(Member *Temp);

	/**
	*	@brief	멤버의 친구 리스트를 가져옴
	*	@pre	멤버의 친구 리스트가 설정됨
	*	@post	없음.
	*	@return	LinkedList<Member*>
	*/
	LinkedList<Member*> getFriendList();

	/**
	*	@brief	채팅방에 Temp 추가
	*	@pre	없음.
	*	@post	채팅방 리스트에 추가됨
	*	@param	ChatRoom* Temp
	*/
	void addChatRoom(ChatRoom* Temp);

	/**
	*	@brief	멤버 채팅방 리스트에서 Temp 삭제
	*	@pre	없음.
	*	@post	채팅방 리스트에서 Temp 삭제됨
	*	@param	ChatRoom* Temp
	*/
	void deleteChatRoom(ChatRoom *Temp);

	/**
	*	@brief	멤버의 채팅방 리스트를 가져옴
	*	@pre	멤버의 채팅방 리스트 설정됨
	*	@post	없음.
	*	@return	LinkedList<ChatRoom*>
	*/
	LinkedList<ChatRoom*> getChatRoomList();

	/**
	*	@brief	유저의 채팅방 목록 출력함.
	*	@pre	없음.
	*	@post	채팅방 출력됨.
	*/
	void printChatRoom();

	/**
	*	@brief	채팅방에서 userId를 제거
	*	@pre	없음
	*	@post	채팅방 리스트에서 사용자 삭제됨
	*	@param	userId, int chatRoomId
	*/
	void deleteChatRoomInMember(string userId, int chatRoomId);

protected:
	string m_Id;			///< 카카오톡 아이디.
	string m_pw;		///< 카카오톡 비밀번호
	string m_Name;		///< 이름.
	string m_phoneNum;	///< 전화번호
	string m_birth;		///< 생년 월일 
	string m_profilePhoto;	///< 프로필 사진
	string m_backgroundPhoto;	///< 배경사진
	string m_profileMessage;	///< 프로필 메시지.

	LinkedList<Member*> friendList; // 유저의 친구 목록 리스트
	LinkedList<ChatRoom*> chatRoomList; // 채팅방을 저장하는 리스트 (친구 목록에서 선택한 친구와의 채팅방 리스트를 만든다)
};

