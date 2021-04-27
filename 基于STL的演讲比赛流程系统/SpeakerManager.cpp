#include"SpeakerManager.h"


SpeakerManager::SpeakerManager()
{
}

SpeakerManager::~SpeakerManager()
{
}

//��ʾ�����溯��
void SpeakerManager::showMenu()
{
	cout << "**************************************" << endl;
	cout << "**/----------��������ϵͳ----------\\**" << endl;
	cout << "**|          1.��ʼ����            |**" << endl;
	cout << "**|          2.�鿴�����¼        |**" << endl;
	cout << "**|          3.��ձ�����¼        |**" << endl;
	cout << "**|          0.�˳�ϵͳ            |**" << endl;
	cout << "**\\--------------------------------/**" << endl;
	cout << "**************************************" << endl;
}

//�˳�ϵͳ����
void SpeakerManager::exitMenu()
{
	cout << "**************************************" << endl;
	cout << "******  ллʹ�ã�ϵͳ���ڹر�  ******"<<endl;
	cout << "**************************************" << endl;
	system("pause");
	exit(0);
}

//����ѡ�ֺ���
void SpeakerManager::createSpeaker()
{
	//ȷ��������Ϊ��
	vectorSpeaker.clear();
	vectorUpperSpeaker.clear();
	vectorWinSpeaker.clear();
	mapSpeaker.clear();

	//�궨��Ĭ�Ϸ���
	double defaultScore[] { 0 , 0 };

	//����ѡ�ֲ�����������
	for (int i = 0; i < 12; i++)
	{
		//��ʼ��ѡ��
		Speaker s("", defaultScore);
		
		//Ϊѡ�ַ�����������
		int randNum = rand() % 16;
		s.s_name += FIRST_NAME[randNum * 2];
		s.s_name += FIRST_NAME[randNum * 2 + 1];
		randNum = rand() % 16;
		s.s_name += MID_NAME[randNum * 2];
		s.s_name += MID_NAME[randNum * 2 + 1];
		randNum = rand() % 16;
		s.s_name += LAST_NAME[randNum * 2];
		s.s_name += LAST_NAME[randNum * 2 + 1];

		//��ѡ�ֵı��װ���vector������
		vectorSpeaker.push_back(i);

		//��ѡ�ֱ�ź�ѡ��װ���pair��
		pair<int, Speaker>p(i, s);

		//��pairװ���map������
		mapSpeaker.insert(p);
		cout << mapSpeaker.at(i).s_name << endl;
	}
}

//չʾѡ����Ϣ����
void showInfo()
{
	
}


