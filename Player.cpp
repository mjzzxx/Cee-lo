#include "Player.h"

void Player::setName(string name) 
{
	this->name = name;
}
string Player::getName()
{
	return name;
}
void Player::plusMoney(int betmoney)
{
	this->money = money + betmoney;
}
void Player::disMoney(int betmoney)
{
	this->money = money - betmoney;
}
int Player::getMoney()
{
	return money;
}
void Player::setBetMoney(int bet)
{
	this->betmoney = bet;
}
int Player::getBetMoney()
{
	return betmoney;
}
void Player::setOya()
{
	this->Oya = true;
	this->Ko = false;
}
bool Player::getOya()
{
	return Oya;
}
void Player::setKo()
{
	this->Ko = true;
	this->Oya = false;
}
bool Player::getKo()
{
	return Ko;
}
void Player::setResult_num(int result)
{
	this->result_num = result;
}
int Player::getResult_num()
{
	return result_num;
}
void Player::setOutcome(int n)
{
	this->outcome = n;
}
int Player::getOutcome() 
{
	return outcome;
}

