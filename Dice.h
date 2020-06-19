#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;
// 주사위 클래스
class Dice {

	int dice[3]; // 주사위 눈
	int chance = 2;
	bool shonben = false;
	string result;
	int result_num;

public:
	Dice() { dice[3]; result = ""; } //생성자
	~Dice() {}; //소멸자

	void dice_roll(); //주사위 굴리기
	void check_dice(); //주사위 족보 확인
	void check_chance(); //눈없음의 경우 남은 기회 확인
	bool check_shonben(); //숀벤 판정
	string getResult(); //결과 반환
	int getResult_num(); //결과 반환
};
void diceDelay(); //주사위 결과 출력 딜레이
void shonbenNotice(); //숀벤 발생 시 문구 출력