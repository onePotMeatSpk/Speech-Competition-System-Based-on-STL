#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"Speaker.h"
using namespace std;

class SpeakerManager
{
public:
	SpeakerManager();
	~SpeakerManager();

	//显示主界面函数
	void showMenu();

	//退出系统函数
	void exitMenu();

	//创建员工函数
	void createSpeaker();

	//创建一个装载选手编号的容器
	vector<int>vectorSpeaker;

	//创建一个装载选手编号和选手的容器
	map<int, Speaker>mapSpeaker;

};
