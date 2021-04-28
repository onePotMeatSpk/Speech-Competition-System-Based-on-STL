#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<numeric>
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

	//��ʼ��ϵͳ����
	void initSystem();

	//��ʾ�����溯��
	void showMenu();

	//�˳�ϵͳ����
	void exitMenu();

	//����Ա������
	void createSpeaker();

	//��ǩ���麯��
	void setGroup();

	//����ѡ�ִ�ֺ���
	double setSingleScore();

	//ȫԱ��ֽ�������
	void setAllScore();

	//չʾѡ����Ϣ����
	void showInfo();

	//���б�������
	void runCompetition();

public:

	//װ������ѡ�ֱ�ŵ�����
	vector<int>vectorSpeaker;

	//װ��һ��ѡ�ֱ�ŵ�����
	vector<int>vectorSpeaker1;

	//װ�ض���ѡ�ֱ�ŵ�����
	vector<int>vectorSpeaker2;

	//װ�ؽ���ѡ�ֱ�ŵ�����
	vector<int>vectorUpperSpeaker;

	//װ��ʤ��ѡ�ֱ�ŵ�����
	vector<int>vectorWinSpeaker;

	//װ������ѡ�ֱ�ź�ѡ�ֵ�����
	map<int, Speaker>mapSpeaker;

	//��ǰ��������
	int roundNum;

	//������ֱ�
	deque<double>dequeScore;
};
