#pragma once
#include<iostream>
#include"codeRules.h"
#include"lib.h"
#define MAXLEN 1024

void creatCode(FILE *fp, const int &rules){
    char code[10][MAXLEN]={0};
    char codeChose[MAXLEN]={0};

    int bit;
    cout << "����������λ��:" << endl;
    cin >> bit;
    cin.get();

    int judge;              //�ж��Ƿ񱣴�
    cout << "\n" << endl;

    do{  //ѭ����������
        switch(rules){
            case 1:
                rand_num(bit, code); break;                //������
            case 2:
                rand_en_num(bit, code); break;             //Ӣ��+����
            case 3:
                rand_en_num_pro(bit, code); break;         //Ӣ�Ĵ�Сд+����
            case 4:
                rand_expert(bit, code); break;             //ascii���
            default:
                break;
        }

        cout <<  "������ѡ������������, ����ѡ����������ĸ�����." << endl;
        cin >> judge;
        cin.get();

        if(judge >=0 && judge <=9)  //ѡ����������
        {
            for(int i=0; i<bit; i++)
            {
                codeChose[i] = code[judge][i];
                codeChose[i+1]='\0';
            }

            saveToLib(fp, codeChose);   //���������������

            judge = 0;  //�����ж�����
        }
        else
        {
            judge = 1;
        }
    }while(judge == 1);
}
