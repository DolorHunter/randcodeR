#pragma once
#include<cstdlib>
#include<iostream>
#include"animation.h"

using namespace std;

void creatLib(FILE *fp)
{
    if(fp = fopen("CodeX.dat", "ab"))
    {
        ;
    }
    else
    {
        printf("CANNOT NEW .dat.\n");//�ݴ���
        exit(1);
    }

    fclose(fp);
}

void openLib(FILE *fp, const char *password)//��ȡ�ļ����� �ȶ������Ƿ���ͬ
{
    char buff[4096];
    char inp_code[6];
    char tbuff[6];
    if(fp = fopen("CodeX.dat", "rb"))
    {
        cout << "���������������:" << endl;
        cin >> inp_code;
        cin.get();
        fread(tbuff, 6*sizeof(char), 1, fp);

        while(true)
        {
            bool sign=true;
            for(int i=0;i<6;i++){
                if(tbuff[i]!=inp_code[i]){
                    sign=false;
                }
            }
            if(sign)
            {
                cout << "������ȷ!" << endl;

                fseek(fp,6,SEEK_SET);
                fread(buff, 4096*sizeof(char), 1, fp);

                cout << "-----------------����������-----------------" << endl;
                cout << buff << endl;
                cout << "--------------------------------------------" << endl;
                cout << "����س�������һ��"<< endl;

                getchar();
                getchar();
                break;
            }
            else
            {
                cout << "�������!����������:" << endl;
                cin >> inp_code;
                cin.get();
            }
        }
    }
    else
    {
        printf("CANNOT OPEN\n");//�ݴ���
        exit(1);
    }

    fclose(fp);
}

void setLibPassword(FILE *fp, char *password)
{
    cout << "-[����] ������������������ʧ, ����ʧ���޷��������ܿ�!\n" << endl;
    cout << "����6λ����������Ϊ�򿪼��ܿ��Կ��:" << endl;
    cin>>password;
    cin.get();

    if(fp = fopen("CodeX.dat", "wb"))
    {
        fprintf(fp, "%s\n", password);
    }
    else
    {
        printf("CANNOT OPEN\n");//�ݴ���
        exit(1);
    }

    fclose(fp);
}

void saveToLib(FILE *fp, char *codeChose)
{
    cout <<"-���ڽ�������������.." << endl;

    if(fp = fopen("CodeX.dat", "ab"))
    {
        fprintf(fp, "��վ, ����\n");

        cout << "������վ��ַ�Ա�ע:" << endl;
        char webInf[80]={0};
        cin >> webInf;
        cin.get();

        fprintf(fp, "%s, %s\n", webInf, codeChose);

        saving();      //���ڱ���(����)
    }
    else
    {
        printf("CANNOT OPEN\n");//�ݴ���
        exit(1);
    }

    fclose(fp);
}
