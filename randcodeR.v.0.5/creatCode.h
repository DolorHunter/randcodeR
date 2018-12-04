#pragma once
#include<iostream>
#include"codeRules.h"
#include"lib.h"
#define MAXLEN 1024

void creatCode(FILE *fp, const int &rules){
    char code[10][MAXLEN]={0};
    char codeChose[MAXLEN]={0};

    int bit;
    cout << "请输入密码位数:" << endl;
    cin >> bit;
    cin.get();

    int judge;              //判断是否保存
    cout << "\n" << endl;

    do{  //循环生成密码
        switch(rules){
            case 1:
                rand_num(bit, code); break;                //纯数字
            case 2:
                rand_en_num(bit, code); break;             //英文+数字
            case 3:
                rand_en_num_pro(bit, code); break;         //英文大小写+数字
            case 4:
                rand_expert(bit, code); break;             //ascii随机
            default:
                break;
        }

        cout <<  "请输入选择本轮密码的序号, 若不选择请输入字母或符号." << endl;
        cin >> judge;
        cin.get();

        if(judge >=0 && judge <=9)  //选中生成密码
        {
            for(int i=0; i<bit; i++)
            {
                codeChose[i] = code[judge][i];
                codeChose[i+1]='\0';
            }

            saveToLib(fp, codeChose);   //保存密码与密码库

            judge = 0;  //重置判定参数
        }
        else
        {
            judge = 1;
        }
    }while(judge == 1);
}
