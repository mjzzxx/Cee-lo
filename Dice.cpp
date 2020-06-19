#include "Dice.h"

void Dice::dice_roll() {

	int temp = 0;
	diceDelay();
	for (int i = 0; i < 3; i++) { //�ֻ��� ����
		temp = rand() % 6+1;
		dice[i] = temp;
		cout << "[" << temp << "]";
	}
	cout << endl<<endl;
	check_dice(); //�� Ȯ��
	check_chance();
}
void Dice::check_dice() {
	bool shonben = check_shonben();
	result = "";
	if(shonben == false) 
	{
		if (dice[0] == dice[1] && dice[0] == dice[2] && dice[1] == dice[2]) {
			if (dice[0] == 1) {
				result = "������";
				result_num = 9;
			}
			else {
				result = "�ƶ��";
				result_num = 8;
			}
		}
		else if ((dice[0] == 4 && dice[1] == 5 && dice[2] == 6) || (dice[0] == 4 && dice[1] == 6 && dice[2] == 5)
			|| (dice[0] == 5 && dice[1] == 4 && dice[2] == 6) || (dice[0] == 5 && dice[1] == 6 && dice[2] == 4)
			|| (dice[0] == 6 && dice[1] == 4 && dice[2] == 5) || (dice[0] == 6 && dice[1] == 5 && dice[2] == 4))
		{
			result = "�ð��";
			result_num = 7;
		}
		else if ((dice[0] == 1 && dice[1] == 2 && dice[2] == 3) || (dice[0] == 1 && dice[1] == 3 && dice[2] == 2)
			|| (dice[0] == 2 && dice[1] == 1 && dice[2] == 3) || (dice[0] == 2 && dice[1] == 3 && dice[2] == 1)
			|| (dice[0] == 3 && dice[1] == 1 && dice[2] == 2) || (dice[0] == 3 && dice[1] == 2 && dice[2] == 1))
		{
			result = "���Ĺ�";
			result_num = -1;
		}
		else if ((dice[0] == dice[1] && dice[0] != dice[2]) || (dice[0] == dice[2] && dice[0] != dice[1]) || (dice[1] == dice[2] && dice[1] != dice[0])) {
			result = "������";
			if (dice[0] == dice[1] && dice[0] != dice[2]) {
				result_num = dice[2];
			}
			else if (dice[0] == dice[2] && dice[0] != dice[1]) {
				result_num = dice[1];
			}
			else if (dice[1] == dice[2] && dice[1] != dice[0]) {
				result_num = dice[0];
			}
		}
		else {
			result = "������";
			result_num = 0;
		}
	}
	else 
	{
		shonbenNotice();
		result = "��";
		result_num = -2;
	}
}
void Dice::check_chance() {
	if (result == "������") {
		if (chance > 0) {
			cout << "�ֻ����� �ٽ� �����ϴ�. (���� ��ȸ : " << chance << ")" << endl;
			chance -= 1;
			dice_roll();
		}
		else if (chance == 0) {
			cout << "���� ����� ������ �Դϴ�." << endl;
		}
	}
}
bool Dice::check_shonben() {
	int shonben = rand() % 10;
	if (shonben == 0)
		return true;
	else
		return false;
}
string Dice::getResult()
{
	return this->result;
}
int Dice::getResult_num()
{
	return this->result_num;
}

void diceDelay()
{
	const char* delay = "...�ֻ��� ������ ��...";
	int len = strlen(delay);
	for (int i = 0; i < len; i++) {
		cout << delay[i];
		Sleep(250);
	}
	cout << endl;
}
void shonbenNotice()
{
	const char* delay = "��... �ֻ����� �׸��� �����!";
	int len = strlen(delay);
	for (int i = 0; i < len; i++) {
		cout << delay[i];
		Sleep(100);
	}
	cout << endl;
}