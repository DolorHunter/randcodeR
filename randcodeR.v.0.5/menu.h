#pragma once
#include<iostream>
#include"creatCode.h"
#include"lib.h"

using namespace std;

int index(FILE *fp, char *password);
void library(FILE *fp, char *password);
void donation(FILE *fp, char *password);
void creatPassword(FILE *fp, char *password);
void forgetCode(FILE *fp, char *password);

//�����(������->�����)
void library(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** �������������  v.0.5 ***************" << endl;
        cout << "*                                      Power by: Zhuxiong*" << endl;
        cout << "*��ǰλ��:������->�����                                 *" << endl;
        cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
        cout << "* -[ע��] ��һ��ʹ����������������ܳ�!                  *" << endl;
        cout << "* -[ע��] �ظ���������ᵼ���������д,��������ᱻɾ��, *" << endl;
        cout << "          �����Ѿ���������,�벻Ҫ�ظ�����!!              *" << endl;
        cout << "*1. ������                                               *" << endl;
        cout << "*2. ���ÿ�����                                           *" << endl;
        cout << "*3. ��������                                             *" << endl;
        cout << "*0. ����������                                           *" << endl;
        cout << "**********************************************************" << endl;
        cout << "���������:" ;

        int iChose;
        cin >> iChose;
        cin.get();

        switch(iChose){
            case 0:
                sign=false; break;///������һ��
            case 1:
                openLib(fp, password); break;
            case 2:
                setLibPassword(fp, password);
                sign=false; break;
            case 3:
                forgetCode(fp, password); break;
            default:
                sign=false; break;
        }
    }while(sign);
}

//��������(������->�����->��������)
void forgetCode(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** �������������  v.0.5 ***************" << endl;
        cout << "*                                      Power by: Zhuxiong*" << endl;
        cout << "*��ǰλ��:������->�����->��������                       *" << endl;
        cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
        cout << "[ע��]:ǿ�Ƹ��ܻ����������ļ����������!!              *" << endl;
        cout << "*0. ǿ�Ƹ���.                                            *" << endl;
        cout << "*                                                        *" << endl;
        cout << "*����. �������Գ�����ϵ�����Ի�ü���֧��.               *" << endl;
        cout << "*[��ϵ����]: DolorHunter@gmail.com                       *" << endl;
        cout << "*�ҽ��ᾡ��ظ��ʼ�!                                     *" << endl;
        cout << "**********************************************************" << endl;
        cout << endl;
        cout << "�����������ַ�����һ��." << endl;

        char iChose;
        cin >> iChose;
        cin.get();

        switch(iChose){
            case 0:
                setLibPassword(fp, password); break;
            default:
                sign=false; break;///������һ��
        }
    }while(sign);
}


//��������(������->��������)
void creatPassword(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** �������������  v.0.5 ***************" << endl;
        cout << "*                                      Power by: Zhuxiong*" << endl;
        cout << "*��ǰλ��:������->��������                               *" << endl;
        cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
        cout << "* -[ע��] ��һ��ʹ����������������ܳ�!                  *" << endl;
        cout << "*1. ������.                                              *" << endl;
        cout << "*2. ���� &Ӣ��Сд.                                      *" << endl;
        cout << "*3. ���� &Ӣ�Ļ�ƴ.                                      *" << endl;
        cout << "*4. ר��.                                                *" << endl;
        cout << "*0. ����������                                           *" << endl;
        cout << "**********************************************************" << endl;
        cout << "��ѡ�������������:" ;

        int iChose;
        cin >> iChose;
        cin.get();
        switch(iChose){
            case 0:
               sign=false; break;
            case 1:
            case 2:
            case 3:
            case 4:
                creatCode(fp, iChose); break;
            default:
                sign=false; break;///������һ��
        }
    }while(sign);
}

//��ϵ���߽���(������->��ϵ����)
void donation(FILE *fp, char *password){
    system("CLS");
    cout << "******************** �������������  v.0.5 ***************" << endl;
    cout << "*                                      Power by: Zhuxiong*" << endl;
    cout << "*��ǰλ��:������->��ϵ����                               *" << endl;
    cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
    cout << "[��ϵ����]: DolorHunter@gmail.com                        *" << endl;
    cout << "[������ַ]: paypal.me/dolorhunter                        *" << endl;
    cout << "��л�����Ͽ���֧��!                                      *" << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
    cout << "�����������ݷ�����һ��." << endl;
    getchar();
}

//������
int index(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** �������������  v.0.5 ***************" << endl;
        cout << "*                                      Power by: Zhuxiong*" << endl;
        cout << "*��ǰλ��:������                                         *" << endl;
        cout << "* -[ע��] ��һ��ʹ����������������ܳ�!                  *" << endl;
        cout << "*1. �����.                  <-�����������ܳ�            *" << endl;
        cout << "*2. ��������.                                            *" << endl;
        cout << "*3. ��ϵ����.                                            *" << endl;
        cout << "*0. �˳�.                                                *" << endl;
        cout << "**********************************************************" << endl;
        cout << "*���������:" ;

        int iChose;
        cin >> iChose;
        cin.get();
        switch(iChose){
            case 0:
               sign=false;
               break;
            case 1:
                library(fp, password); break;
            case 2:
                creatPassword(fp, password); break;
            case 3:
                donation(fp, password); break;
            default:
                sign=false; break;///������һ��
        }
    }while(sign);

    cout << "\n������ֹ." << endl;
    return 0;
}
