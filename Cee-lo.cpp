#include "Cee-lo.h"

void GameGuide() { //게임 설명
	cout << "***게임 순서***" << endl;
	cout << "  (1) 부모(선턴)와 자식(후턴)을 정한다." << endl;
	cout << "  (2) 자식이 판돈을 정한다." << endl;
	cout << "  (3) 부모가 주사위 3개를 굴린다." << endl;
	cout << "  (4) 자식이 주사위 3개를 굴린다." << endl;
	cout << "  (5) 주사위의 결과를 비교하여 승패를 가른다." << endl;
	cout << "  (6) 승패에 따라 부모와 자식 역할을 교환한다." << endl << endl;

	cout << "***주사위 족보***" << endl;
	cout << "  >> 핀조로 : 1이 세 개인 경우[1, 1, 1], 판돈의 5배를 얻는다." << endl;
	cout << "  >> 아라시 : 세 개의 숫자가 같은 경우, 판돈의 3배를 얻는다." << endl;
	cout << "   **단, 1은 제외" << endl;
	cout << "  >> 시고로 : 주사위의 숫자가[4, 5, 6]인 경우, 판돈의 2배를 얻는다." << endl;
	cout << "  >> 히후미 : 주사위의 숫자가[1, 2, 3]인 경우, 판돈의 2배를 상대에게 지불한다." << endl;
	cout << "  >> 눈있음 : 주사위 숫자 중 두 개가 일치하고 하나는 다른 경우" << endl;
	cout << "     홀로 다른 숫자의 크기로 승부, 판돈은 그대로 이다." << endl;
	cout << "   ** 부모가 눈있음[1]이 나올 경우 무조건 패배, 판돈을 잃는다." << endl;
	cout << "   ** 부모가 눈있음[6]이 나올 경우 무조건 승리, 판돈을 얻는다." << endl;
	cout << "  >> 눈없음 : 족보에 없는 주사위 조합, 판돈을 잃는다." << endl;
	cout << "  >> 숀벤 : 주사위가 그릇 밖으로 나가는 경우로 판돈을 잃는다." << endl << endl;
}
void GameStart() { //게임 시작
	string name;
	srand((unsigned int)time(0));
	Player p1; Player p2;
	Dice d1; Dice d2;
	cout << "player 1의 이름 : ";
	cin >> name;
	p1.setName(name);
	cout << "player 2의 이름 : ";
	cin >> name;
	p2.setName(name);

	cout << "-------------------------------------" << endl;
	game(p1, p2, d1, d2); //게임 진행
}
void game(Player p1, Player p2, Dice d1, Dice d2) //게임 진행
{
	int firstplayer = rand() % 2; //선턴 정하기
	if (firstplayer == 0) {
		p1.setOya();
		p2.setKo();
	}
	else if (firstplayer == 1) {
		p2.setOya();
		p1.setKo();
	}

	int turnChange = 0;
	bool roof = true;

	while (roof) {
		cout <<">> "<< turnChange + 1 << " 번째 판" << endl;
		p1.setOutcome(0); p2.setOutcome(0); //승패 여부 리셋
		if (p1.getOya() == true) {
			cout << "부모는 >> " << p1.getName() << " << 입니다." << endl;
			cout << "-------------------------------------" << endl << endl;
			p2.setBetMoney(koBetting(p2)); //자식 배팅
			p1.setResult_num(Trun(p1, d1)); //선턴 주사위 굴림
			p1.setOutcome(isOyaWin(p1)); //부모 승패 판단
		}
		else if (p2.getOya() == true) {
			cout << "부모는 >> " << p2.getName() << " << 입니다." << endl;
			cout << "-------------------------------------" << endl << endl;
			p1.setBetMoney(koBetting(p1)); //자식 배팅
			p2.setResult_num(Trun(p2, d2)); //선턴 주사위 굴림
			p2.setOutcome(isOyaWin(p2)); //부모 승패 판단
		}
		cout << endl;

		// 부모 승패 유무에 따른 진행
		int bet;
		if (p1.getOya() == true) {
			if (p1.getOutcome() == 0) { //선턴의 결과 정해지지 않은 경우
				p2.setResult_num(Trun(p2, d2)); //자식 주사위 굴림
				p2.setOutcome(isKoWin(p1, p2));
				//정산
				bet = betResult(p2.getBetMoney(), p2.getResult_num());
				if (p2.getOutcome() == 2) { //자식 승리
					p2.plusMoney(bet);
					p1.disMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| "<< p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else if (p2.getOutcome() == 1) { //자식 패배
					p2.disMoney(bet);
					p1.plusMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else {
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
			}
			else if (p1.getOutcome() == 2) { //정해진 경우
				//정산
				//부모 승리
				bet = betResult(p2.getBetMoney(), p1.getResult_num());
				p1.plusMoney(bet);
				p2.disMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
			else if (p1.getOutcome() == 1) { //부모 패배
				bet = betResult(p2.getBetMoney(), p1.getResult_num());
				p1.disMoney(bet);
				p2.plusMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
		}
		else if (p2.getOya() == true) {
			if (p2.getOutcome() == 0) { //선턴의 결과 정해지지 않은 경우
				p1.setResult_num(Trun(p1, d1)); //자식 주사위 굴림
				p1.setOutcome(isKoWin(p2, p1));
				//정산
				bet = betResult(p1.getBetMoney(), p1.getResult_num());
				if (p1.getOutcome() == 2) { //자식 승리
					p1.plusMoney(bet);
					p2.disMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else if (p1.getOutcome() == 1) { //자식 패배
					p1.disMoney(bet);
					p2.plusMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else {
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
			}
			//정해진 경우
			else if (p2.getOutcome() == 2) { //부모 승리
				cout << "asdf" << endl;
				//정산
				bet = betResult(p1.getBetMoney(), p2.getResult_num());
				p2.plusMoney(bet);
				p1.disMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
			else if (p1.getOutcome() == 1) { //부모 패배
				bet = betResult(p1.getBetMoney(), p2.getResult_num());
				p2.disMoney(bet);
				p1.plusMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "의 현재 소지금 | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "의 현재 소지금 | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
		}
		//턴 횟수 확인
		if (turnChange == 3) { // 모든 턴 종료
			cout << ">>---------------------------------<<" << endl;
			cout << "모든 턴이 종료되었습니다." << endl;
			cout << ">>---------------------------------<<" << endl;
			finalWinner(p1, p2);
			roof = false;
		}
		else // 턴 종료 전
		{
			//부모 변경 판단
			int n;
			bool roof = true;
			if (p1.getOya() == true) { //p1이 선턴이었을 경우
				if (p1.getOutcome() == 2 || p2.getOutcome() == 1) { //p1 승리
					while (roof) {
						cout << "턴을 넘기겠습니까. [1 : 넘기지 않음  2 : 넘김]" << endl <<">> ";
						cin >> n;
						if (n == 1) {
							cout << "변경없이 게임을 계속합니다." << endl;
							cout << ">>---------------------------------<<" << endl<<endl;
							roof = false;
						}
						else if (n == 2) {
							cout << ">> 부모 <<가 변경됩니다." << endl;
							cout << ">>---------------------------------<<" << endl << endl;
							p2.setOya();
							p1.setKo();
							turnChange += 1;
							roof = false;
						}
						else
							cout << "다시 입력해주세요." << endl;
							continue;
						break;
					}
				}
				else if (p1.getOutcome() == 1 || p2.getOutcome() == 2) { //p1 패배
					cout << "부모가 패배했으므로 >>부모<<가 변경됩니다." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
					p2.setOya();
					p1.setKo();
					turnChange += 1;
				}
				else if (p2.getOutcome() == 0) { //무승부
					cout << "무승부이므로 변경없이 게임을 계속합니다." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
				}
			}
			else if (p2.getOya() == true) { //p2이 선턴이었을 경우
				if (p2.getOutcome() == 2 || p1.getOutcome() == 1) { //p2 승리
					
					while (roof) {
						cout << "턴을 넘기겠습니까. [1 : 넘기지 않음  2 : 넘김]" << endl;
						cin >> n;
						if (n == 1) {
							cout << "변경없이 게임을 계속합니다." << endl;
							cout << ">>---------------------------------<<" << endl << endl;
							roof = false;
						}
						else if (n == 2) {
							cout << ">>부모<<가 변경됩니다." << endl;
							cout << ">>---------------------------------<<" << endl << endl;
							p1.setOya();
							p2.setKo();
							turnChange += 1;
							roof = false;
						}
						else
							continue;
					}
				}
				else if (p2.getOutcome() == 1 || p1.getOutcome() == 2) { //p1 패배
					cout << "부모가 패배했으므로 >>부모<<가 변경됩니다." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
					p1.setOya();
					p2.setKo();
					turnChange += 1;
				}
				else if (p1.getOutcome() == 0) { //무승부
					cout << "무승부이므로 변경없이 게임을 계속합니다." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
				}

			}
		}
		Sleep(1000);
	}
}
int Trun(Player p, Dice d) //선턴 주사위 굴림
{
	cout << ">>---------------------------------<<" << endl;
	cout << ">> " << p.getName() << "의 주사위 굴림 " << endl;
	cout << ">>---------------------------------<<" << endl;
	
	d.dice_roll();
	cout << ">>---------------------------------<<" << endl;
	cout << p.getName() << "의 결과 : " << d.getResult();
	if (d.getResult_num() >= 1 && d.getResult_num() <= 6)
		cout << "[" << d.getResult_num() << "]";
	cout << endl <<">>---------------------------------<<" << endl;
	return d.getResult_num();

}

int koBetting(Player p) //자식 배팅
{
	cout << "자식 >> " << p.getName() << "의 배팅 차례" << endl;
	cout << "-------------------------------------" << endl;
	cout << "| " <<p.getName() << "의 현재 소지금 : " << p.getMoney() << endl;
	cout << "-------------------------------------" << endl;
	int bet;

	cout << "배팅할 금액 : ";
	cin >> bet;
	cout << endl;
	return bet;
}
int isOyaWin(Player p) { //부모 승패 판단
	int win = 2, lose = 1, tie = 0;
	if (p.getResult_num() >= 6) {
		cout << "부모 >> " << p.getName() << " 승리!" << endl;
		return win;
	}
	else if (p.getResult_num() <= 1 && p.getResult_num() != 0) {
		cout << "부모 >> " << p.getName() << " 패배!" << endl;
		return lose;
	}
	else
		return tie;
}
int isKoWin(Player Oya, Player Ko) { //승패 판단
	int win = 2, lose = 1, tie = 0;
	if (Ko.getResult_num() >= 6 || (Oya.getResult_num() < Ko.getResult_num())) {
		cout << "자식 >> " << Ko.getName() << " 승리!" << endl;
		cout << "부모 >> " << Oya.getName() << " 패배!" << endl;
		return win;
	}
	else if ((Ko.getResult_num() <= 1 && Ko.getResult_num() != 0) || (Oya.getResult_num() > Ko.getResult_num())) {
		cout << "부모 >> " << Oya.getName() << " 승리!" << endl;
		cout << "자식 >> " << Ko.getName() << " 패배!" << endl;
		return lose;
	}
	else {
		cout << "무승부!" << endl;
		return tie;
	}
}
int betResult(int betmoney, int result_num)
{
	if (result_num == 9) { //판조로
		betmoney = betmoney * 5;
	}
	else if (result_num == 8) { //아라시
		betmoney = betmoney * 3;
	}
	else if (result_num == 7) { //시고로
		betmoney = betmoney * 2;
	}
	else if (result_num >= 0 && result_num < 7 && result_num == -2) {
		betmoney = betmoney;
	}
	else if (result_num == -1) { //히후미
		betmoney = betmoney * (2);
	}
	return betmoney;
}
void finalWinner(Player p1, Player p2) {
	cout << "---------------최종결과---------------" << endl;
	cout << "-------------------------------------" << endl;
	cout << "| " << p1.getName() << "의 최종 소지금 | " << p1.getMoney() << endl;
	cout << "|-----------------------------------|" << endl;
	cout << "| " << p2.getName() << "의 최종 소지금 | " << p2.getMoney() << endl;
	cout << "-------------------------------------" << endl << endl;
	if (p1.getMoney() > p2.getMoney())
		cout << "최종 승리 *** " << p1.getName() << " ***" << endl << endl;
	else if (p1.getMoney() < p2.getMoney())
		cout << "최종 승리 *** " << p2.getName() << " ***" << endl << endl;
	else
		cout << "최종 승리 *** 무승부 ***" << endl << endl;
	cout << "잠시후 시작 화면으로 돌아갑니다." << endl << endl;
	Sleep(1000);
}
