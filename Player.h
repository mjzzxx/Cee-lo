#pragma once
#include <iostream>
#include <string>

using namespace std;
//�÷��̾� Ŭ����
 class Player {
	bool Oya; //���� ����
	bool Ko;
	int outcome = 0;
	int money;
	int betmoney;
	string name;
	int result_num;

public:
	Player() { money = 300000; name = ""; Oya = false; Ko = false; } //������
	~Player() {}; //�Ҹ���

	void setName(string name); //�÷��̾� �̸� ����
	string getName(); //�̸� ��ȯ
	void plusMoney(int betmoney); //������ + �ǵ�
	void disMoney(int betmoney); //������ - �ǵ�
	int getMoney(); // ������ ��ȯ
	void setBetMoney(int bet); //�ǵ� ����
	int getBetMoney(); //�ǵ� ��ȯ
	void setOya(); // �θ� ���·� ����
	bool getOya(); // �θ� ���� ��ȯ
	void setKo(); // �ڽ� ���·� ����
	bool getKo(); // �ڽ� ���� ��ȯ
	void setResult_num(int result); // ��� ����
	int getResult_num(); // ��� ��ȯ
	void setOutcome(int n); //���� ���� ����
	int getOutcome(); //���� ���� ��ȯ

};