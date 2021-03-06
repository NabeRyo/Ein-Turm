﻿#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "EinTurm.h"
#include "stdio.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>


int dungeonflor = 1;

int main() {
	enemy_initialize();
	item_initialize();
	chara_initialize();
	wepon_initialize();
	
	rule_Display();
	char  c;
	for (int i = 0; i < 10; i++) {

		if (Wizard.HP <= 0) {
			loseDisplay();
			Sleep(5000);
			exit(0);
		}
		do {
			printf("Enter");
			if (getchar() == '\n')
				continue;
		} while (getchar() != '\n');

		system("cls");

		borderLine();
		status_Display(Wizard);
		dungeon_Display();

		if (Wizard.HP <= 0) {
			loseDisplay();
			Sleep(5000);
			exit(0);
		}
		if (i == 4 || i == 9) {
			borderLine();
			do {
				printf("ショップイベントに入ります\n\n");
				if (getchar() == '\n')
					continue;
			} while (getchar() != '\n');
			printf("ショップイベント\n\n");
			shop();
		}
	}
	printf("あなたは最上階にたどり着いた…！\n");
	Fight(boss);
	if (Wizard.HP <= 0) loseDisplay();
	else {
		endDisplay();
		Sleep(5000);
	}
}

void wepon_initialize() {
	w1.NAME = "松明";
	w1.UP_ATK = 0;
	w1.UP_HP = 2;
	w2.NAME = "セスタス";
	w2.UP_ATK = 0;
	w2.UP_HP = 4;
	w3.NAME = "折れた直剣";
	w3.UP_ATK = 1;
	w3.UP_HP = 6;
	w4.NAME = "ブロードソード";
	w4.UP_ATK = 1;
	w4.UP_HP = 8;
	w5.NAME = "オーニクスブレード";
	w5.UP_ATK = 2;
	w5.UP_HP = 10;
	w6.NAME = "物干し竿";
	w6.UP_ATK = 2;
	w6.UP_HP = 11;
	w7.NAME = "罪の大剣";
	w7.UP_ATK = 2;
	w7.UP_HP = 12;
	w8.NAME = "ツヴァイヘンダー";
	w8.UP_ATK = 3;
	w8.UP_HP = 13;
	w9.NAME = "流刑人の大刀";
	w9.UP_ATK = 3;
	w9.UP_HP = 14;
	w10.NAME = "竜狩りの大鉈";
	w10.UP_ATK = 4;
	w10.UP_HP = 15;

}

void enemy_initialize() {
	e1.NAME = "亡者";
	e1.HP = 5;
	e1.ATK = 0;
	e2.NAME = "スケルトン戦士";
	e2.HP = 6;
	e2.ATK = 0;
	e3.NAME = "スケルトン弓兵";
	e3.HP = 7;
	e3.ATK = 0;
	e4.NAME = "スケルトン騎士";
	e4.HP = 8;
	e4.ATK = 0;
	e5.NAME = "不死人";
	e5.HP = 9;
	e5.ATK = 1;
	e6.NAME = "デスナイト";
	e6.HP = 10;
	e6.ATK = 2;
	e7.NAME = "巨人の戦士";
	e7.HP = 12;
	e7.ATK = 2;
	e8.NAME = "妄信の天使";
	e8.HP = 14;
	e8.ATK = 3;
	e9.NAME = "黒騎士";
	e9.HP = 16;
	e9.ATK = 3;
	e10.NAME = "竜狩りの鎧";
	e10.HP = 20;
	e10.ATK = 3;
	boss.NAME = "古の龍";
	boss.HP = 30;
	boss.ATK = 2;
}

void chara_initialize() {
	//構造体の定義
	Wizard.MAX_HP = 20;
	Wizard.HP = 20;
	Wizard.MAX_MP = 20;
	Wizard.MP = 20;
	Wizard.ATK = 0;
	Wizard.money = 0;
	Wizard.ORI_HP = 20;
	Wizard.ORI_ATK = 0;
};

void item_initialize() {
	i1.NAME = "回復薬G";
	i1.Count = 0;
	i2.NAME = "回復薬";
	i2.Count = 0;
	i3.NAME = "聖水G";
	i3.Count = 0;
	i4.NAME = "聖水";
	i4.Count = 0;
	i5.NAME = "生命の指輪";
	i5.Count = 0;
	i6.NAME = "精神の指輪";
	i6.Count = 0;
	i7.NAME = "戦士の指輪";
	i7.Count = 0;
}

void rule_Display() {
	printf("魔法使い(あなた)は、「入った者は誰一人として帰ってくることはない」と古くから言い伝えられている古の塔へ、ある魔術を探しに挑戦することになりました。\n");
	printf("塔は全部で10階層存在し、更にその頂上には古の龍が存在すると言われています。\n");
	printf("あなたは果たして生還することが出来るのでしょうか…？\n");
	printf("******************************************************************************\n\n");
	printf("----TIPS----\n");
	printf("・この塔は全部で10階層存在し、その階層ごとに3つの選択肢の内一つを選んで進んでください。なお、選べるのは1階層につき1つだけです。\n");
	printf("・「回復」はHPを最大で60％、最低で10％回復し、MPは最高で6、最低でも1は回復します\n");
	printf("・「戦闘」ではその階層を徘徊しているモンスターとの戦闘を行います。戦闘に勝利した場合、相応の武器やお金がもらえたりします。\n");
	printf("・また、ターンが1経過するごとにMPが1回復します。\n");
	printf("・「イベント」を選択した場合、何かしらのイベントが始まります。基本的には良い効果が得られますが、時には悪い効果を得てしまうことも……\n");
	printf("・5の倍数の階層をクリアするごとにショップに行くことが出来ます。\n");
	printf("最後のボスを倒したらゲームクリアとなります。\n\n");
}

void endDisplay() {
	printf("あなたは激戦の末に古の龍を討伐し、秘宝を得ることができました。\nしかし、手に入れた秘宝は探し求めていた魔術ではなく、ただの黄金や金属等でした\n");
	printf("魔法使いは蘇生の魔術を探し求め、また世界を渡り歩くのでした…\n\nThanks You For Playing!");
}

void loseDisplay() {
	printf("あなたは薄れゆく意識の中、かつての恋人に手を伸ばした……\n");
	printf("G A M E O V E R !\n");
}

void status_Display(character Wizard) {
	//int x = 45, y = 6;
	//HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD pos;
	//pos.X = x;
	//pos.Y = y;
	//SetConsoleCursorPosition(hCons, pos);
	printf("現在のステータス\nHP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", Wizard.HP, Wizard.MAX_HP, Wizard.MP, Wizard.MAX_MP, Wizard.ATK, Wizard.money);
}

void status_Item(character Wizard) {
	//    int x = 45, y = 7;
	//HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD pos;
	//pos.X = x;
	//pos.Y = y;

	//SetConsoleCursorPosition(hCons, pos);
	printf("現在以下のアイテムを持っています\n\n");
}

void  status_Enemy(enemy ENEMY) {
	printf("モンスター名:%s\n\n", ENEMY.NAME);
}

int dungeon_Display() {
	borderLine();
	printf("現在の階層 %d階\n", dungeonflor);
	printf("進む道を選択してください\n1:回復 2:戦闘 3:イベント\n");

	int a;
	while (1) {
		printf("1から3までの数値を入力してください。\n\n");
		if (scanf("%d", &a) == 1 && a > 0 && a < 4) break;
		if (feof(stdin)) return 1;
		printf("数値が正しくありません。もう一度入力してください。\n");
		borderLine();
		scanf("%*[^\n]");
	}
	switch (a) {
	case 1:
		recovery();
		break;
	case 2:
		Fight(setEnemy());
		break;
	case 3:
		event();
		break;
	default:
		printf("もう1度入力してください\n");
		break;

	}
	dungeonflor++;
}

void event() {
	int input = 0, ranNum = 0, firstMoney = 2, secandMoney = 4;;

	//printf("Enterキーでサイコロを振ってください\n");

	while (true) {
		ranNum = getRandom(1, 6);
		switch (ranNum) {
		case 1:
			printf("宝箱を発見した！\n\n………武器らしきものを発見した！\n\n");
			getWepon();
			//武器を手に入れる処理r
			break;
		case 2:
			printf("階層全体に癒しの風が吹き荒れる！\n\n");
			//回復処理
			recovery();
			break;
		case 3:
			printf("嫌な臭いがする……\n\n");
			//MP20%減少
			Wizard.MP -= Wizard.MAX_MP * 2 / 10;
			printf("MPに%dのダメージを受けた…\n", Wizard.MAX_MP * 2 / 10);
			break;
		case 4:
			printf("宝箱を発見した！\n\n………不思議な色をしたポーションを発見した！\n\n");
			//上限アップ処理
			ranNum = getRandom(1, 3);
			if (ranNum == 4 || ranNum == 5 || ranNum == 6)
				ranNum = ranNum / 2;
			switch (ranNum) {
			case 1:
				printf("最大HPが5上昇しました！\n\n");
				Wizard.MAX_HP += 5;
				Wizard.HP += 5;
				Wizard.ORI_HP += 5;
				break;
			case 2:
				printf("最大MPが3上昇しました！\n\n");
				Wizard.MAX_MP += 3;
				Wizard.MP += 3;
				break;
			case 3:
				printf("最大ATKが1上昇しました！\n\n");
				Wizard.ATK += 1;
				Wizard.ORI_ATK += 1;
				break;
			default:
				printf("乱数エラー!\n");
				break;
			}
			break;
		case 5:
			printf("宝箱を発見した！\n\n………不思議な紙束を発見した\n\n");
			//金get処理

			if (dungeonflor <= 5) {
				printf("%d$手に入れた！\n\n", firstMoney * 3);
				Wizard.money += firstMoney * 3;
			}
			else if (5 < dungeonflor && dungeonflor < 11) {
				printf("%d$手に入れた!\n\n", secandMoney * 3);
				Wizard.money += secandMoney * 3;
			}
			break;
		case 6:
			printf("トラップだ！\n");
			//罠
			Wizard.HP -= Wizard.MAX_HP * 2 / 10;
			printf("%dのダメージを受けた…\n", Wizard.MAX_HP * 2 / 10);
			break;
		default:
			printf("乱数エラーです.管理者を呼んでください\n");
			break;
		}
		break;
	}
}

int getRandom(int min, int max) {
	//return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
	srand((unsigned)time(NULL));
	rand(); rand(); rand(); rand(); rand();
	Sleep(500);
	return (rand() % 6) + 1;
}

int enemy_getRandom(int min, int max) {
	//return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
	srand((unsigned)time(NULL * 2));
	rand(); rand(); rand(); rand(); rand();
	Sleep(500);
	return (rand() % 6) + 1;
}

enemy setEnemy() {
	switch (dungeonflor)
	{
	case 1:
		return e1;
		break;
	case 2:
		return e2;
		break;
	case 3:
		return e3;
		break;
	case 4:
		return e4;
		break;
	case 5:
		return e5;
		break;
	case 6:
		return e6;
		break;
	case 7:
		return e7;
		break;
	case 8:
		return e8;
		break;
	case 9:
		return e9;
		break;
	case 10:
		return e10;
		break;
	default:
		return boss;
		break;
	}
}

void borderLine() {
	char c;
	printf("*********************************************\n\n");
	//printf("Enter\n");
	//while (true) {
	//    if ((c = getchar()) == '\n')
	//        break;
	//}

	//system("cls");
}

void shop() {
	int bango, money, check_Money;
	check_Money = Wizard.money, money = Wizard.money;//残金

	do {
		status_Display(Wizard);
		printf("1: 5$ 回復薬G(HP全回復)\n");
		printf("2: 2$ 回復薬(HP50％回復)\n");
		printf("3: 5$ 聖水G(MP全回復)\n");
		printf("4: 2$ 聖水\(MP50％回復)\n");
		printf("5: 5$ 生命の指輪（HP上限UP）\n");
		printf("6: 5$ 精神の指輪（MP上限UP）\n");
		printf("7: 7$ 戦士の指輪（ATK上限UP）\n");
		printf("欲しい商品の番号を押してください\n");
		printf("欲しい商品がない場合は、10と入力して下さい\n");
		printf("残りのお金は%d$です\n", money);

		printf("*******************************************\n\n");

		scanf("%d", &bango);//欲しい商品の番号を入力してもらう
		switch (bango) {
		case 1:
			if (5 <= money) {
				printf("回復薬Gを買いました\n\n");
				money -= 5;
				i1.Count += 1;
				if (i1.Count >= 1) {
					printf("回復薬Gを%d個持っています\n", i1.Count);
					Wizard.hAVE_ITEM = true;
				}
			}
			else {
				noMoney();
			}
			break;
		case 2:
			if (2 <= money) {
				money -= 2;
				printf("回復薬を買いました\n\n");
				i2.Count += 1;
				if (i2.Count >= 1) {
					printf("回復薬を%d個持っています\n", i2.Count);
					Wizard.hAVE_ITEM = true;
				}
			}
			else {
				noMoney();
			}
			break;
		case 3:
			if (5 <= money) {
				printf("聖水Gを買いました\n\n");
				money -= 5;
				i3.Count += 1;
				if (i3.Count >= 1) {
					printf("聖水Gを%d個持っています\n", i3.Count);
					Wizard.hAVE_ITEM = true;
				}
			}
			else {
				noMoney();
			}
			break;
		case 4:
			if (2 <= money) {
				printf("聖水を買いました\n\n");
				money -= 2;
				i4.Count += 1;
				if (i4.Count >= 1) {
					printf("聖水を%d個持っています\n", i4.Count);
					Wizard.hAVE_ITEM = true;
				}
			}
			else {
				noMoney();
			}
			break;
		case 5:
			if (5 <= money) {
				if (i5.Count >= 1) {
					printf("生命の指輪は1個しか持てません\n", i5.Count);
					break;
				}
				printf("生命の指輪を買いました\n\n");
				money -= 5;
				i5.Count += 1;
				Wizard.MAX_HP += 5;
				Wizard.HP += 5;
				Wizard.ORI_HP += 5;
			}
			else {
				noMoney();
			}
			break;
		case 6:
			if (5 <= money) {
				if (i6.Count >= 1) {
					printf("精神の指輪は1個しか持てません\n");
					break;
				}
				printf("精神の指輪を買いました\n");
				money -= 5;
				i6.Count += 1;
				Wizard.MAX_MP += 3;
				Wizard.MP += 3;

			}
			else {
				noMoney();
			}
			break;
		case 7:
			if (7 <= money) {
				if (i7.Count >= 1) {
					printf("戦士の指輪は1個しか持てません\n");
					break;
				}
				printf("戦士の指輪を買いました\n");
				money -= 7;
				i7.Count += 1;
				Wizard.ATK += 1;
				Wizard.ORI_ATK += 1;
			}
			else {
				noMoney();
			}
			break;
		case 10:
			printf("買いたい商品はないみたいですね\n");
			break;
		default:
			printf("その商品はありません\n");
			break;
		}
	} while (money != 0 && bango != 10);//残金が0になったら

	Wizard.money = money;
	printf("ありがとうございました\n");
	borderLine();
}

void item_Display() {
	int x = 45, y = 8;
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;

	//SetConsoleCursorPosition(hCons, pos); pos.Y++;
	printf("持っているアイテムは,\n");
	//SetConsoleCursorPosition(hCons, pos); pos.Y++;
	printf("1.%sが%d個\n", i1.NAME, i1.Count);
	//SetConsoleCursorPosition(hCons, pos); pos.Y++;
	printf("2.%s  が%d個\n", i2.NAME, i2.Count);
	//SetConsoleCursorPosition(hCons, pos); pos.Y++;
	printf("3.%s が%d個\n", i3.NAME, i3.Count);
	//SetConsoleCursorPosition(hCons, pos); pos.Y++;
	printf("4.%s   が%d個\n", i4.NAME, i4.Count);
}

void item_Display2() {
	printf("持っている指輪は\n");
	//SetConsoleCursorPosition(hCons, pos); pos.Y++;
	printf("5.%s が%d個\n", i5.NAME, i5.Count);
	//SetConsoleCursorPosition(hCons, pos); pos.Y++;
	printf("6.%sが%d個\n", i6.NAME, i6.Count);
	//SetConsoleCursorPosition(hCons, pos);
	printf("7.%sが%d個です\n", i7.NAME, i7.Count);
}

void noMoney() {
	printf("お金が足りません\n\n");
	borderLine();
}

void recovery() {
	char c;
	//srand((unsigned)time(NULL)); //乱数の初期化

	int ranNum = 0;

	while (true) { //Enterキーが押されたら実行
		ranNum = getRandom(1, 6);
		switch (ranNum) {  //1～6までの乱数の表示
		case 1:
			//printf("1が出ました\n");
			//printf("MAX_HP×１０%%回復します\n");
			calc_Recovery(1);
			break;
		case 2:
			//printf("2が出ました\n");
			//printf("MAX_HP×２０%%回復します\n");
			calc_Recovery(2);
			break;
		case 3:
			//printf("3が出ました\n");
			//printf("MAX_HP×３０%%回復します\n");
			calc_Recovery(3);
			break;
		case 4:
			//printf("4が出ました\n");
			//printf("MAX_HP×４０%%回復します\n");
			calc_Recovery(4);
			break;
		case 5:
			//printf("5が出ました\n");
			//printf("MAX_HP×５０%%回復します\n");
			calc_Recovery(5);
			break;
		case 6:
			//printf("6が出ました\n");
			//printf("MAX_HP×６０%%回復します\n");
			calc_Recovery(6);
			break;
		}
		break;
	}
}
//回復量を計算し、ステータスに反映した後に回復量を返す
void calc_Recovery(int i) {
	int beforHP = Wizard.HP, beforMP = Wizard.MP, printHP = 0, printMP = 0;

	switch (i) {
	case 1:
		Wizard.HP += (int)(Wizard.MAX_HP * 0.1);
		Wizard.MP += 1;
		break;
	case 2:
		Wizard.HP += (int)(Wizard.MAX_HP * 0.2);
		Wizard.MP += 2;
		break;
	case 3:
		Wizard.HP += (int)(Wizard.MAX_HP * 0.3);
		Wizard.MP += 3;
		break;
	case 4:
		Wizard.HP += (int)(Wizard.MAX_HP * 0.4);
		Wizard.MP += 4;
		break;
	case 5:
		Wizard.HP += (int)(Wizard.MAX_HP * 0.5);
		Wizard.MP += 5;
		break;
	case 6:
		Wizard.HP += (int)(Wizard.MAX_HP * 0.6);
		Wizard.MP += 6;
		break;
	default:
		printf("回復計算エラー\n");
		break;
	}
	if (Wizard.HP > Wizard.MAX_HP) {
		Wizard.HP = Wizard.MAX_HP;
	}
	if (Wizard.MP > Wizard.MAX_MP) {
		Wizard.MP = Wizard.MAX_MP;
	}
	printHP = (int)(Wizard.HP) - beforHP;
	printMP = Wizard.MP - beforMP;
	printf("HPを%d、MPを%d回復しました。\n", printHP, printMP);
}

void getWepon() {
	int originalHP = Wizard.ORI_HP, originalATK = Wizard.ORI_ATK, newHP = Wizard.HP, newMP = Wizard.MP, newMAX_HP = Wizard.MAX_HP, newMAX_MP = Wizard.MAX_MP, newATK = Wizard.ATK;

	if (dungeonflor == 1) {
		printf("%sを手に入れた！\n\n", w1.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w1.UP_HP;
		newMAX_HP = originalHP + w1.UP_HP;
		newATK = originalATK + w1.UP_ATK;
		if (newHP > newMAX_HP)
			newHP = newMAX_HP;

	}

	else if (dungeonflor == 2) {
		printf("%sを手に入れた！\n\n", w2.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w2.UP_HP;
		newMAX_HP = originalHP + w2.UP_HP;
		newATK = originalATK + w2.UP_ATK;
		if (newHP > newMAX_HP)
			newHP = newMAX_HP;
	}
	else if (dungeonflor == 3) {
		printf("%sを手に入れた！\n\n", w3.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w3.UP_HP;
		newMAX_HP = originalHP + w3.UP_HP;
		newATK = originalATK + w3.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 4) {
		printf("%sを手に入れた！\n\n", w4.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w4.UP_HP;
		newMAX_HP = originalHP + w4.UP_HP;
		newATK = originalATK + w4.UP_ATK;
		if (newHP > newMAX_HP)
			newHP = newMAX_HP;
	}
	else if (dungeonflor == 5) {
		printf("%sを手に入れた！\n\n", w5.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w5.UP_HP;
		newMAX_HP = originalHP + w5.UP_HP;
		newATK = originalATK + w5.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 6) {
		printf("%sを手に入れた！\n\n", w6.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w6.UP_HP;
		newMAX_HP = originalHP + w6.UP_HP;
		newATK = originalATK + w6.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 7) {
		printf("%sを手に入れた！\n\n", w7.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w7.UP_HP;
		newMAX_HP = originalHP + w7.UP_HP;
		newATK = originalATK + w7.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 8) {
		printf("%sを手に入れた！\n\n", w8.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w8.UP_HP;
		newMAX_HP = originalHP + w8.UP_HP;
		newATK = originalATK + w8.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 9) {
		printf("%sを手に入れた！\n\n", w9.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w9.UP_HP;
		newMAX_HP = originalHP + w9.UP_HP;
		newATK = originalATK + w9.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}

	}
	else if (dungeonflor == 10) {
		printf("%sを手に入れた！\n\n", w10.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w10.UP_HP;
		newMAX_HP = originalHP + w10.UP_HP;
		newATK = originalATK + w10.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	Wizard.HP = newHP, Wizard.MP = newMP, Wizard.MAX_HP = newMAX_HP, Wizard.MAX_MP = newMAX_MP, Wizard.ATK = newATK;
	printf("変化後　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);
}

void noItem() {
	printf("アイテムがありません\n\n");
	borderLine();
}

void item_use() {
	int bango;
	bool used = false;
	printf("使いたいアイテムの番号を入力してください\n\n");
	item_Display();
	scanf("%d", &bango);
	while (!used) {
		switch (bango) {
		case 1://回復薬G
			if (i1.Count >= 1) {
				Wizard.HP = Wizard.MAX_HP;
				if (Wizard.HP > Wizard.MAX_HP)
					Wizard.HP = Wizard.MAX_HP;
				i1.Count -= 1;
				used = true;
				printf("%sを使いました、HPは%dになりました\n", i1.NAME, Wizard.HP);
				printf("残り%d個です\n\n", i1.Count);
			}
			else {
				noItem();
			}
			break;
		case 2://回復薬
			if (i2.Count >= 1) {
				Wizard.HP += (int)(Wizard.MAX_HP * 0.5);
				if (Wizard.HP > Wizard.MAX_HP)
					Wizard.HP = Wizard.MAX_HP;
				i2.Count -= 1;
				used = true;
				printf("%sを使いました、HPは%dになりました\n", i2.NAME, Wizard.HP);
				printf("残り%d個です\n", i2.Count);
			}
			else {
				noItem();
			}
			break;
		case 3://聖水G
			if (i3.Count >= 1) {
				Wizard.MP = Wizard.MAX_MP;
				if (Wizard.MP > Wizard.MAX_MP)
					Wizard.MP = Wizard.MAX_MP;
				i3.Count -= 1;
				used = true;
				printf("%sを使いました,MPは%dになりました\n", i3.NAME, Wizard.MP);
				printf("残り%d個です\n", i3.Count);
			}
			else {
				noItem();
			}
			break;
		case 4://聖水
			if (i4.Count >= 1) {
				Wizard.MP += (int)(Wizard.MAX_MP * 0.5);
				if (Wizard.MP > Wizard.MAX_MP)
					Wizard.MP = Wizard.MAX_MP;
				i4.Count -= 1;
				used = true;
				printf("%sを使いました,MPは%dになりました\n", i4.NAME, Wizard.MP);
				printf("残り%d個です\n", i4.Count);
			}
			else {
				noItem();
			}
			break;
		default:
			printf("対応してない番号です\n");
			break;
		}
	}
	if (i1.Count == 0 && i2.Count == 0 && i3.Count == 0 && i4.Count == 0)
		Wizard.hAVE_ITEM = false;
}

void get_MoneyAndWepon() {
	int    firstMoney = 2, secandMoney = 4;
	int originalHP = Wizard.ORI_HP, originalATK = Wizard.ORI_ATK, newHP = Wizard.HP, newMP = Wizard.MP, newMAX_HP = Wizard.MAX_HP, newMAX_MP = Wizard.MAX_MP, newATK = Wizard.ATK;


	if (dungeonflor <= 5) {
		printf("%d$手に入れた！\n\n", firstMoney);
		
		if (dungeonflor == 1) {
			printf("%sを手に入れた！\n\n", w1.NAME);
			printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

			//newHP = newHP + w1.UP_HP;
			newMAX_HP = originalHP + w1.UP_HP;
			newATK = originalATK + w1.UP_ATK;
			if (newHP > newMAX_HP)
				newHP = newMAX_HP;

		}

		else if (dungeonflor == 2) {
			printf("%sを手に入れた！\n\n", w2.NAME);
			printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

			//newHP = newHP + w2.UP_HP;
			newMAX_HP = originalHP + w2.UP_HP;
			newATK = originalATK + w2.UP_ATK;
			if (newHP > newMAX_HP)
				newHP = newMAX_HP;
		}
		else if (dungeonflor == 3) {
			printf("%sを手に入れた！\n\n", w3.NAME);
			printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

			//newHP = newHP + w3.UP_HP;
			newMAX_HP = originalHP + w3.UP_HP;
			newATK = originalATK + w3.UP_ATK;
			if (newHP > newMAX_HP) {
				newHP = newMAX_HP;
			}
		}
		else if (dungeonflor == 4) {
			printf("%sを手に入れた！\n\n", w4.NAME);
			printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

			//newHP = newHP + w4.UP_HP;
			newMAX_HP = originalHP + w4.UP_HP;
			newATK = originalATK + w4.UP_ATK;
			if (newHP > newMAX_HP)
				newHP = newMAX_HP;
		}
		else if (dungeonflor == 5) {
			printf("%sを手に入れた！\n\n", w5.NAME);
			printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

			//newHP = newHP + w5.UP_HP;
			newMAX_HP = originalHP + w5.UP_HP;
			newATK = originalATK + w5.UP_ATK;
			if (newHP > newMAX_HP) {
				newHP = newMAX_HP;
			}
		}
		
		
		Wizard.money += firstMoney;

		

	}
	if (5 < dungeonflor && dungeonflor < 11) {
		printf("%d$手に入れた!\n\n", secandMoney);
	if (dungeonflor == 6) {
		printf("%sを手に入れた！\n\n", w6.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w6.UP_HP;
		newMAX_HP = originalHP + w6.UP_HP;
		newATK = originalATK + w6.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 7) {
		printf("%sを手に入れた！\n\n", w7.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w7.UP_HP;
		newMAX_HP = originalHP + w7.UP_HP;
		newATK = originalATK + w7.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 8) {
		printf("%sを手に入れた！\n\n", w8.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w8.UP_HP;
		newMAX_HP = originalHP + w8.UP_HP;
		newATK = originalATK + w8.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}
	else if (dungeonflor == 9) {
		printf("%sを手に入れた！\n\n", w9.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w9.UP_HP;
		newMAX_HP = originalHP + w9.UP_HP;
		newATK = originalATK + w9.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}

	}
	else if (dungeonflor == 10) {
		printf("%sを手に入れた！\n\n", w10.NAME);
		printf("変化前　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);

		//newHP = newHP + w10.UP_HP;
		newMAX_HP = originalHP + w10.UP_HP;
		newATK = originalATK + w10.UP_ATK;
		if (newHP > newMAX_HP) {
			newHP = newMAX_HP;
		}
	}

		Wizard.money += secandMoney;
		
	}
	Wizard.HP = newHP, Wizard.MP = newMP, Wizard.MAX_HP = newMAX_HP, Wizard.MAX_MP = newMAX_MP, Wizard.ATK = newATK;
	printf("変化後　HP:%d/%d MP:%d/%d ATK:%d money:%d$ \n\n", newHP, newMAX_HP, newMP, newMAX_MP, newATK, Wizard.money);
}

int Fight(enemy Enemy) {
	int c = 0, a = 0, enemyHP = Enemy.HP, enemyATK = Enemy.ATK;
	const char* enemyNAME = Enemy.NAME;
	int ranNUM = getRandom(1, 6);

	while (true) {
		int myDamage = 0, enemyDamage = 0;
		while (1) {
			borderLine();
			status_Display(Wizard);
			status_Enemy(Enemy);
			printf("行動を選択してください。\n\n");
			printf("１：通常攻撃(サイコロの数 + 基礎ATK)\n２：ライフドレイン MP6(敵に与えたダメージ分回復)\n３：オールソレイユ MP15((サイコロの数×３)+基礎ATKダメージ)\n４：アイテム使用\n");
			if (scanf("%d", &a) == 1 && a >= 1 && a <= 4) break;
			if (feof(stdin)) return 1;
			printf("数値が正しくありません。もう一度入力してください。\n");
			borderLine();
			scanf("%*[^\n]");
		}
		borderLine();
		switch (a) {
		case 1:
			//自サイコロ処理
			myDamage = getAttack();
			break;
		case 2:
			if (calc_Skill1() == false) {
				//再入力処理
				printf("MPが足りない！\n");
				goto loop;
			}
			else {
				//自サイコロ処理
				myDamage = getAttack();
				printf("魔法使いのHPが%d回復した！\n", myDamage);
				Wizard.HP += myDamage;
				if (Wizard.HP > Wizard.MAX_HP)
					Wizard.HP = Wizard.MAX_HP;
			}
			break;
		case 3:
			if (calc_Skill2() == false) {
				//再入力処理
				printf("MPが足りない！\n");
				goto loop;
			}
			else {
				//自サイコロ処理
				myDamage = getSukill2();
			}
			break;
		case 4:
			if (Wizard.hAVE_ITEM == false) {
				//再入力処理
				printf("アイテムを持っていません\n\n");
				goto loop;
			}
			else {
				item_use();
				//選択&使用処理
			}
			break;
		default:
			//再入力処理
			goto loop;
			break;
		}
		enemyDamage = enemy_saikoro();
		//ダメージ処理

		Wizard.HP -= enemyDamage;
		Enemy.HP -= myDamage;

		printf("魔法使いに%dのダメージ！\n\n%sに%dのダメージ！\n\n", enemyDamage, Enemy.NAME, myDamage);
		//calc_Damege(myDamage, enemyDamage, Enemy);
		Wizard.MP++;
		if (Wizard.MP > Wizard.MAX_MP)
			Wizard.MP = Wizard.MAX_MP;

		if (Wizard.HP <= 0) {
			borderLine();
			printf("戦闘に敗北した…\n\n");
			break;
		}
		if (Enemy.HP <= 0) {
			borderLine();
			printf("勝利した!\n\n");
			get_MoneyAndWepon();
			break;
		}
	loop:;
	}
}

//void calc_Damege(int myDamage, int enemyDamage, enemy Enemy) {
//    Wizard.HP -= enemyDamage;
//    Enemy.HP -= myDamage;
//    printf("%s:%d\n",Enemy.NAME,e1.HP);
//
//    printf("魔法使いに%dのダメージ！\n\n%sに%dのダメージ！\n\n",enemyDamage,Enemy.NAME,myDamage);
//
//    
//}

bool calc_Skill1() {
	if (Wizard.MP >= 6) {
		Wizard.MP -= 6;
		return true;
	}
	else {
		return false;
	}
}

bool calc_Skill2() {
	if (Wizard.MP >= 15) {
		Wizard.MP -= 15;
		return true;
	}
	else {
		return false;
	}
}

bool check_Item() {
	if (Wizard.hAVE_ITEM) {
		return true;
	}
	else {
		return false;
	}
}

int enemy_saikoro() {
	char c;
	int ATK;

	if (dungeonflor == 1) {
		ATK = e1.ATK;
	}
	else if (dungeonflor == 2) {
		ATK = e2.ATK;
	}
	else if (dungeonflor == 3) {
		ATK = e3.ATK;
	}
	else if (dungeonflor == 4) {
		ATK = e4.ATK;
	}
	else if (dungeonflor == 5) {
		ATK = e5.ATK;
	}
	else if (dungeonflor == 6) {
		ATK = e6.ATK;
	}
	else if (dungeonflor == 7) {
		ATK = e7.ATK;
	}
	else if (dungeonflor == 8) {
		ATK = e8.ATK;
	}
	else if (dungeonflor == 9) {
		ATK = e9.ATK;
	}
	else if (dungeonflor == 10) {
		ATK = e10.ATK;
	}
	else if (dungeonflor == 11) {
		ATK = boss.ATK;
	}

	//printf("敵がさいころを振ります\n");
	//printf("エンターを押してください\n");
	int ranNum = 0;
	int rand = 0;

	//if ((c = getchar()) == '\n') { Enterキーが押されたら実行

	ranNum = enemy_getRandom(1, 6);

	switch (ranNum) {  //1〜6までの乱数の表示
	case 1:
		rand = 1;
		break;
	case 2:
		rand = 2;
		break;
	case 3:
		rand = 3;
		break;
	case 4:
		rand = 4;
		break;
	case 5:
		rand = 5;
		break;
	case 6:
		rand = 6;
		break;

	}
	if (dungeonflor == 11) {
		return ((rand * 2) + ATK);
	}
	return rand + ATK;

}
//}

//通常攻撃
int getAttack() { //通常攻撃とスキル１の関数
	return getRandom(1, 6) + Wizard.ATK;
}

//スキル2攻撃
int getSukill2() {//スキル2関数
	return getRandom(1, 6) * 3 + Wizard.ATK;
}
//};

