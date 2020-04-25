#pragma once
#include "gameobject.h"
#include<string>
#include<fstream>
#include<list>

/* �ؿ��࣬�Զ��ڴ���� */
class Stage {
public:
	Stage(int no, Mode mode);
	void Run();
private:
	void LoadStage(int no);	//����ؿ�
	void AddEnemy();
	std::shared_ptr<Number> score;
	std::shared_ptr<Number> playerNum;
	std::shared_ptr<Number> stageNum;
	std::list<COORD> enemyPoint;	//���˵����ɵ�
	COORD playerPoint;				//��ҵĳ�����
	Buffer buf;
	Mode mode;
};
