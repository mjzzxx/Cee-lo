#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;
// �ֻ��� Ŭ����
class Dice {

	int dice[3]; // �ֻ��� ��
	int chance = 2;
	bool shonben = false;
	string result;
	int result_num;

public:
	Dice() { dice[3]; result = ""; } //������
	~Dice() {}; //�Ҹ���

	void dice_roll(); //�ֻ��� ������
	void check_dice(); //�ֻ��� ���� Ȯ��
	void check_chance(); //�������� ��� ���� ��ȸ Ȯ��
	bool check_shonben(); //�� ����
	string getResult(); //��� ��ȯ
	int getResult_num(); //��� ��ȯ
};
void diceDelay(); //�ֻ��� ��� ��� ������
void shonbenNotice(); //�� �߻� �� ���� ���