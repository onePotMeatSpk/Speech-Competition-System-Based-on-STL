#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include"Speaker.h"
using namespace std;

//�궨���ա���
#define FIRST_NAME "��Ǯ��������֣���������������"
#define MID_NAME "�����弾�����С���ұ����ӳ���î"
#define LAST_NAME  "��漽�ݱ���������赤����������"



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

	//չʾѡ����Ϣ����
	void showInfo();

public:

	//����һ��װ������ѡ�ֱ�ŵ�����
	vector<int>vectorSpeaker;

	//����һ��װ�ؽ���ѡ�ֱ�ŵ�����
	vector<int>vectorUpperSpeaker;

	//����һ��װ��ʤ��ѡ�ֱ�ŵ�����
	vector<int>vectorWinSpeaker;

	//����һ��װ������ѡ�ֱ�ź�ѡ�ֵ�����
	map<int, Speaker>mapSpeaker;

};
