#pragma once
#include "Player.h"
#include "Dice.h"
#include <cstring>


using namespace std;

void GameGuide(); //���� ��� ���
void GameStart(); //���� ����
void game(Player p1, Player p2, Dice d1, Dice d2); //���� ����
int Trun(Player p, Dice d); //�÷��̾��� �ֻ��� ����
int koBetting(Player p); // �ڽ� �÷��̾��� �ǵ� �ɱ�
int isOyaWin(Player p); // �θ� �÷��̾��� ���� ����
int isKoWin(Player Oya, Player Ko); // �ڽ� �÷��̾��� ���� ����
int betResult(int betmoney, int result_num); // �ֻ��� ������ ���� �ǵ� ��ȭ �ݿ�
void finalWinner(Player p1, Player p2); // ���� ���� �Ǻ�