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

	//��ʾ�����溯��
	void showMenu();

	//�˳�ϵͳ����
	void exitMenu();

	//����Ա������
	void createSpeaker();

	//����һ��װ��ѡ�ֱ�ŵ�����
	vector<int>vectorSpeaker;

	//����һ��װ��ѡ�ֱ�ź�ѡ�ֵ�����
	map<int, Speaker>mapSpeaker;

};
