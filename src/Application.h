#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"Client.h"
using namespace std;

#define FILENAMESIZE 1024

/**
*	카카오톡 실행하는 클래스
*	@author	장규범
*	@date	20171027
*/
class Application: public Client
{
public:
	/**
	*	기본 생성자
	*/
	Application();

	/**
	*	소멸자
	*/
	~Application();

	/**
	*	@brief	프로그램 실행
	*	@pre	프로그램이 시작된다.
	*	@post	프로그램이 끝난다.
	*/
	void Run();

	/**
	*	@brief	로그인 한 유저만 이용 가능한 메뉴 출력
	*	@pre	로그인이 되어 있어야 한다.
	*	@post	로그인한 후 채팅과 친구 검색이 가능
	*/
	void LoginMenu();


	/**
	*	@brief	친구 목록 관리하는 메뉴(친구 목록 출력, 친구 검색, 친구 추가, 친구 삭제, 메시지 전송)
	*	@pre	유저가 친구 메뉴로 들어가야 한다
	*	@post	친구 메뉴 출력
	*/
	void FriendMenu();

	/**
	*	@brief	채팅방 메뉴(기존 채팅방 출력, 채팅방 아이디로 접속 및 채팅 가능)
	*	@pre	채팅방 기능 함수가 완성
	*	@post	채팅방 메뉴 출력
	*/
	void ChatRoomMenu();

	/**
	*	@brief	현재 로그인 한 유저의 정보 확인 및 수정 메뉴(현재 유저의 정보 출력 및 수정)
	*	@pre	로그인한 유저의 정보 출력, 수정하는 함수 구현
	*	@post	유저 메뉴 출력
	*/
	void UserMenu();

	/**
	*	@brief	에러 메시지 출력하는 함수
	*	@pre	없음.
	*	@post	에러 메시지 출력
	*/
	void ErrorMessage();
};

