using namespace std;
#include "Player.h"
#include "Cee-lo.h"
#include "Dice.h"

int main() {
	bool roof = true;

	while (roof) {
	int menu = 0;
	cout << "----------------------------------" << endl;
	cout << "|        Cee-lo(ģġ�θ�)        |" << endl;
	cout << "----------------------------------" << endl<<endl;
	cout << ">> 1 : ���� ����" << endl;
	cout << ">> 2 : ���� ���" << endl;
	cout << ">> (�̿� ���� : ���� ������)" << endl;
	cout << ">>";
	cin >> menu;

	

		switch (menu)
		{
		case 1:
			cout << "----------->> ���� ���� <<-----------" << endl << endl;
			GameStart();
			break;

		case 2:
			cout << "----------->> ���� ��� <<-----------" << endl << endl;
			GameGuide();
			break;

		default:
			roof = false;
			break;
		}
	}
	
	return 0;
}
