#pragma once
#include <iostream>
#include <string>

using namespace std;
//플레이어 클래스
 class Player {
	bool Oya; //선턴 여부
	bool Ko;
	int outcome = 0;
	int money;
	int betmoney;
	string name;
	int result_num;

public:
	Player() { money = 300000; name = ""; Oya = false; Ko = false; } //생성자
	~Player() {}; //소멸자

	void setName(string name); //플레이어 이름 설정
	string getName(); //이름 반환
	void plusMoney(int betmoney); //소지금 + 판돈
	void disMoney(int betmoney); //소지금 - 판돈
	int getMoney(); // 소지금 반환
	void setBetMoney(int bet); //판돈 설정
	int getBetMoney(); //판돈 반환
	void setOya(); // 부모 상태로 설정
	bool getOya(); // 부모 상태 반환
	void setKo(); // 자식 상태로 설정
	bool getKo(); // 자식 상태 반환
	void setResult_num(int result); // 결과 설정
	int getResult_num(); // 결과 반환
	void setOutcome(int n); //승패 여부 설정
	int getOutcome(); //승패 여부 반환

};