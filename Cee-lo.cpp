#include "Cee-lo.h"

void GameGuide() { //���� ����
	cout << "***���� ����***" << endl;
	cout << "  (1) �θ�(����)�� �ڽ�(����)�� ���Ѵ�." << endl;
	cout << "  (2) �ڽ��� �ǵ��� ���Ѵ�." << endl;
	cout << "  (3) �θ� �ֻ��� 3���� ������." << endl;
	cout << "  (4) �ڽ��� �ֻ��� 3���� ������." << endl;
	cout << "  (5) �ֻ����� ����� ���Ͽ� ���и� ������." << endl;
	cout << "  (6) ���п� ���� �θ�� �ڽ� ������ ��ȯ�Ѵ�." << endl << endl;

	cout << "***�ֻ��� ����***" << endl;
	cout << "  >> ������ : 1�� �� ���� ���[1, 1, 1], �ǵ��� 5�踦 ��´�." << endl;
	cout << "  >> �ƶ�� : �� ���� ���ڰ� ���� ���, �ǵ��� 3�踦 ��´�." << endl;
	cout << "   **��, 1�� ����" << endl;
	cout << "  >> �ð�� : �ֻ����� ���ڰ�[4, 5, 6]�� ���, �ǵ��� 2�踦 ��´�." << endl;
	cout << "  >> ���Ĺ� : �ֻ����� ���ڰ�[1, 2, 3]�� ���, �ǵ��� 2�踦 ��뿡�� �����Ѵ�." << endl;
	cout << "  >> ������ : �ֻ��� ���� �� �� ���� ��ġ�ϰ� �ϳ��� �ٸ� ���" << endl;
	cout << "     Ȧ�� �ٸ� ������ ũ��� �º�, �ǵ��� �״�� �̴�." << endl;
	cout << "   ** �θ� ������[1]�� ���� ��� ������ �й�, �ǵ��� �Ҵ´�." << endl;
	cout << "   ** �θ� ������[6]�� ���� ��� ������ �¸�, �ǵ��� ��´�." << endl;
	cout << "  >> ������ : ������ ���� �ֻ��� ����, �ǵ��� �Ҵ´�." << endl;
	cout << "  >> �� : �ֻ����� �׸� ������ ������ ���� �ǵ��� �Ҵ´�." << endl << endl;
}
void GameStart() { //���� ����
	string name;
	srand((unsigned int)time(0));
	Player p1; Player p2;
	Dice d1; Dice d2;
	cout << "player 1�� �̸� : ";
	cin >> name;
	p1.setName(name);
	cout << "player 2�� �̸� : ";
	cin >> name;
	p2.setName(name);

	cout << "-------------------------------------" << endl;
	game(p1, p2, d1, d2); //���� ����
}
void game(Player p1, Player p2, Dice d1, Dice d2) //���� ����
{
	int firstplayer = rand() % 2; //���� ���ϱ�
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
		cout <<">> "<< turnChange + 1 << " ��° ��" << endl;
		p1.setOutcome(0); p2.setOutcome(0); //���� ���� ����
		if (p1.getOya() == true) {
			cout << "�θ�� >> " << p1.getName() << " << �Դϴ�." << endl;
			cout << "-------------------------------------" << endl << endl;
			p2.setBetMoney(koBetting(p2)); //�ڽ� ����
			p1.setResult_num(Trun(p1, d1)); //���� �ֻ��� ����
			p1.setOutcome(isOyaWin(p1)); //�θ� ���� �Ǵ�
		}
		else if (p2.getOya() == true) {
			cout << "�θ�� >> " << p2.getName() << " << �Դϴ�." << endl;
			cout << "-------------------------------------" << endl << endl;
			p1.setBetMoney(koBetting(p1)); //�ڽ� ����
			p2.setResult_num(Trun(p2, d2)); //���� �ֻ��� ����
			p2.setOutcome(isOyaWin(p2)); //�θ� ���� �Ǵ�
		}
		cout << endl;

		// �θ� ���� ������ ���� ����
		int bet;
		if (p1.getOya() == true) {
			if (p1.getOutcome() == 0) { //������ ��� �������� ���� ���
				p2.setResult_num(Trun(p2, d2)); //�ڽ� �ֻ��� ����
				p2.setOutcome(isKoWin(p1, p2));
				//����
				bet = betResult(p2.getBetMoney(), p2.getResult_num());
				if (p2.getOutcome() == 2) { //�ڽ� �¸�
					p2.plusMoney(bet);
					p1.disMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| "<< p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else if (p2.getOutcome() == 1) { //�ڽ� �й�
					p2.disMoney(bet);
					p1.plusMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else {
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
			}
			else if (p1.getOutcome() == 2) { //������ ���
				//����
				//�θ� �¸�
				bet = betResult(p2.getBetMoney(), p1.getResult_num());
				p1.plusMoney(bet);
				p2.disMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
			else if (p1.getOutcome() == 1) { //�θ� �й�
				bet = betResult(p2.getBetMoney(), p1.getResult_num());
				p1.disMoney(bet);
				p2.plusMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
		}
		else if (p2.getOya() == true) {
			if (p2.getOutcome() == 0) { //������ ��� �������� ���� ���
				p1.setResult_num(Trun(p1, d1)); //�ڽ� �ֻ��� ����
				p1.setOutcome(isKoWin(p2, p1));
				//����
				bet = betResult(p1.getBetMoney(), p1.getResult_num());
				if (p1.getOutcome() == 2) { //�ڽ� �¸�
					p1.plusMoney(bet);
					p2.disMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else if (p1.getOutcome() == 1) { //�ڽ� �й�
					p1.disMoney(bet);
					p2.plusMoney(bet);
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
				else {
					cout << "-------------------------------------" << endl;
					cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
					cout << "|-----------------------------------|" << endl;
					cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
					cout << "-------------------------------------" << endl << endl;
				}
			}
			//������ ���
			else if (p2.getOutcome() == 2) { //�θ� �¸�
				cout << "asdf" << endl;
				//����
				bet = betResult(p1.getBetMoney(), p2.getResult_num());
				p2.plusMoney(bet);
				p1.disMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
			else if (p1.getOutcome() == 1) { //�θ� �й�
				bet = betResult(p1.getBetMoney(), p2.getResult_num());
				p2.disMoney(bet);
				p1.plusMoney(bet);
				cout << "-------------------------------------" << endl;
				cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
				cout << "|-----------------------------------|" << endl;
				cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
				cout << "-------------------------------------" << endl << endl;
			}
		}
		//�� Ƚ�� Ȯ��
		if (turnChange == 3) { // ��� �� ����
			cout << ">>---------------------------------<<" << endl;
			cout << "��� ���� ����Ǿ����ϴ�." << endl;
			cout << ">>---------------------------------<<" << endl;
			finalWinner(p1, p2);
			roof = false;
		}
		else // �� ���� ��
		{
			//�θ� ���� �Ǵ�
			int n;
			bool roof = true;
			if (p1.getOya() == true) { //p1�� �����̾��� ���
				if (p1.getOutcome() == 2 || p2.getOutcome() == 1) { //p1 �¸�
					while (roof) {
						cout << "���� �ѱ�ڽ��ϱ�. [1 : �ѱ��� ����  2 : �ѱ�]" << endl <<">> ";
						cin >> n;
						if (n == 1) {
							cout << "������� ������ ����մϴ�." << endl;
							cout << ">>---------------------------------<<" << endl<<endl;
							roof = false;
						}
						else if (n == 2) {
							cout << ">> �θ� <<�� ����˴ϴ�." << endl;
							cout << ">>---------------------------------<<" << endl << endl;
							p2.setOya();
							p1.setKo();
							turnChange += 1;
							roof = false;
						}
						else
							cout << "�ٽ� �Է����ּ���." << endl;
							continue;
						break;
					}
				}
				else if (p1.getOutcome() == 1 || p2.getOutcome() == 2) { //p1 �й�
					cout << "�θ� �й������Ƿ� >>�θ�<<�� ����˴ϴ�." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
					p2.setOya();
					p1.setKo();
					turnChange += 1;
				}
				else if (p2.getOutcome() == 0) { //���º�
					cout << "���º��̹Ƿ� ������� ������ ����մϴ�." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
				}
			}
			else if (p2.getOya() == true) { //p2�� �����̾��� ���
				if (p2.getOutcome() == 2 || p1.getOutcome() == 1) { //p2 �¸�
					
					while (roof) {
						cout << "���� �ѱ�ڽ��ϱ�. [1 : �ѱ��� ����  2 : �ѱ�]" << endl;
						cin >> n;
						if (n == 1) {
							cout << "������� ������ ����մϴ�." << endl;
							cout << ">>---------------------------------<<" << endl << endl;
							roof = false;
						}
						else if (n == 2) {
							cout << ">>�θ�<<�� ����˴ϴ�." << endl;
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
				else if (p2.getOutcome() == 1 || p1.getOutcome() == 2) { //p1 �й�
					cout << "�θ� �й������Ƿ� >>�θ�<<�� ����˴ϴ�." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
					p1.setOya();
					p2.setKo();
					turnChange += 1;
				}
				else if (p1.getOutcome() == 0) { //���º�
					cout << "���º��̹Ƿ� ������� ������ ����մϴ�." << endl;
					cout << ">>---------------------------------<<" << endl << endl;
				}

			}
		}
		Sleep(1000);
	}
}
int Trun(Player p, Dice d) //���� �ֻ��� ����
{
	cout << ">>---------------------------------<<" << endl;
	cout << ">> " << p.getName() << "�� �ֻ��� ���� " << endl;
	cout << ">>---------------------------------<<" << endl;
	
	d.dice_roll();
	cout << ">>---------------------------------<<" << endl;
	cout << p.getName() << "�� ��� : " << d.getResult();
	if (d.getResult_num() >= 1 && d.getResult_num() <= 6)
		cout << "[" << d.getResult_num() << "]";
	cout << endl <<">>---------------------------------<<" << endl;
	return d.getResult_num();

}

int koBetting(Player p) //�ڽ� ����
{
	cout << "�ڽ� >> " << p.getName() << "�� ���� ����" << endl;
	cout << "-------------------------------------" << endl;
	cout << "| " <<p.getName() << "�� ���� ������ : " << p.getMoney() << endl;
	cout << "-------------------------------------" << endl;
	int bet;

	cout << "������ �ݾ� : ";
	cin >> bet;
	cout << endl;
	return bet;
}
int isOyaWin(Player p) { //�θ� ���� �Ǵ�
	int win = 2, lose = 1, tie = 0;
	if (p.getResult_num() >= 6) {
		cout << "�θ� >> " << p.getName() << " �¸�!" << endl;
		return win;
	}
	else if (p.getResult_num() <= 1 && p.getResult_num() != 0) {
		cout << "�θ� >> " << p.getName() << " �й�!" << endl;
		return lose;
	}
	else
		return tie;
}
int isKoWin(Player Oya, Player Ko) { //���� �Ǵ�
	int win = 2, lose = 1, tie = 0;
	if (Ko.getResult_num() >= 6 || (Oya.getResult_num() < Ko.getResult_num())) {
		cout << "�ڽ� >> " << Ko.getName() << " �¸�!" << endl;
		cout << "�θ� >> " << Oya.getName() << " �й�!" << endl;
		return win;
	}
	else if ((Ko.getResult_num() <= 1 && Ko.getResult_num() != 0) || (Oya.getResult_num() > Ko.getResult_num())) {
		cout << "�θ� >> " << Oya.getName() << " �¸�!" << endl;
		cout << "�ڽ� >> " << Ko.getName() << " �й�!" << endl;
		return lose;
	}
	else {
		cout << "���º�!" << endl;
		return tie;
	}
}
int betResult(int betmoney, int result_num)
{
	if (result_num == 9) { //������
		betmoney = betmoney * 5;
	}
	else if (result_num == 8) { //�ƶ��
		betmoney = betmoney * 3;
	}
	else if (result_num == 7) { //�ð��
		betmoney = betmoney * 2;
	}
	else if (result_num >= 0 && result_num < 7 && result_num == -2) {
		betmoney = betmoney;
	}
	else if (result_num == -1) { //���Ĺ�
		betmoney = betmoney * (2);
	}
	return betmoney;
}
void finalWinner(Player p1, Player p2) {
	cout << "---------------�������---------------" << endl;
	cout << "-------------------------------------" << endl;
	cout << "| " << p1.getName() << "�� ���� ������ | " << p1.getMoney() << endl;
	cout << "|-----------------------------------|" << endl;
	cout << "| " << p2.getName() << "�� ���� ������ | " << p2.getMoney() << endl;
	cout << "-------------------------------------" << endl << endl;
	if (p1.getMoney() > p2.getMoney())
		cout << "���� �¸� *** " << p1.getName() << " ***" << endl << endl;
	else if (p1.getMoney() < p2.getMoney())
		cout << "���� �¸� *** " << p2.getName() << " ***" << endl << endl;
	else
		cout << "���� �¸� *** ���º� ***" << endl << endl;
	cout << "����� ���� ȭ������ ���ư��ϴ�." << endl << endl;
	Sleep(1000);
}
