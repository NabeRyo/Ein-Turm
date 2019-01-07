#pragma once
#include <stdio.h>

typedef struct {
	int MAX_HP;
	int HP;
	int MAX_MP;
	int MP;
	int ATK;
	int ORI_HP;
	int ORI_ATK;
	const char* item[20] = {};
	int items;
	bool hAVE_ITEM;
	int money;
}character;
character Wizard;

typedef struct {
	const char* NAME;
	int UP_HP;
	int UP_ATK;
}wepon;
wepon w1, w2, w3, w4, w5, w6, w7, w8, w9, w10;

typedef struct {
	const char* NAME;
	int HP;
	int ATK;
}enemy;
enemy e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, boss;

typedef struct {
	const char* NAME;
	int Count;
}item;
item i1, i2, i3, i4, i5, i6, i7;

void chara_initialize();
void wepon_initialize();
void enemy_initialize();
void item_initialize();
void status_Display(character Wizard);
void rule_Display();
int dungeon_Display();
void event();
void shop();
void recovery();
void borderLine();
void noMoney();
void noItem();
void item_use();
void item_Display();
void calc_Recovery(int i);
int getRandom(int min, int max);
void status_Item(character Wizard);
void get_MoneyAndWepon();
void endDisplay();
void loseDisplay();
void item_Display2();


int enemy_saikoro();
void status_Enemy(enemy ENEMY);
void calc_Damege(int myDamage, int enemyDamage, enemy Enemy);

int getAttack();
int getSukill2();
void getWepon();
int Fight(enemy Enemy);
enemy setEnemy();
bool calc_Skill1();
bool calc_Skill2();
bool check_Item();

extern int dungeonflor;
