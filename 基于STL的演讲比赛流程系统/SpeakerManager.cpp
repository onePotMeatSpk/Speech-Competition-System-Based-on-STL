#include"SpeakerManager.h"

string FIRST_NAME = "��Ǯ��������֣���������������";
string MID_NAME = "�����弾�����С���ұ����ӳ���î";
string LAST_NAME = "��漽�ݱ���������赤����������";

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
	//����ѡ�ֲ�����������
	for (int i = 0; i < 12; i++)
	{
		double score[] = { 0 , 0 };
		Speaker p("ѡ��", score);
	}
	

}


