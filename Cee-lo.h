#pragma once
#include "Player.h"
#include "Dice.h"
#include <cstring>


using namespace std;

void GameGuide(); //게임 방법 출력
void GameStart(); //게임 시작
void game(Player p1, Player p2, Dice d1, Dice d2); //게임 진행
int Trun(Player p, Dice d); //플레이어의 주사위 굴림
int koBetting(Player p); // 자식 플레이어의 판돈 걸기
int isOyaWin(Player p); // 부모 플레이어의 승패 판정
int isKoWin(Player Oya, Player Ko); // 자식 플레이어의 승패 판정
int betResult(int betmoney, int result_num); // 주사위 족보에 따른 판돈 변화 반영
void finalWinner(Player p1, Player p2); // 최종 승자 판별