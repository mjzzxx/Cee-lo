using namespace std;
#include "Player.h"
#include "Cee-lo.h"
#include "Dice.h"

int main() {
	bool roof = true;

	while (roof) {
	int menu = 0;
	cout << "----------------------------------" << endl;
	cout << "|        Cee-lo(친치로링)        |" << endl;
	cout << "----------------------------------" << endl<<endl;
	cout << ">> 1 : 게임 시작" << endl;
	cout << ">> 2 : 게임 방법" << endl;
	cout << ">> (이외 숫자 : 게임 끝내기)" << endl;
	cout << ">>";
	cin >> menu;

	

		switch (menu)
		{
		case 1:
			cout << "----------->> 게임 시작 <<-----------" << endl << endl;
			GameStart();
			break;

		case 2:
			cout << "----------->> 게임 방법 <<-----------" << endl << endl;
			GameGuide();
			break;

		default:
			roof = false;
			break;
		}
	}
	
	return 0;
}
