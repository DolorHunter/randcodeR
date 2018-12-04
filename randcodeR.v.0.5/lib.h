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
        printf("CANNOT NEW .dat.\n");//容错处理
        exit(1);
    }

    fclose(fp);
}

void openLib(FILE *fp, const char *password)//读取文件首行 比对密码是否相同
{
    char buff[4096];
    char inp_code[6];
    char tbuff[6];
    if(fp = fopen("CodeX.dat", "rb"))
    {
        cout << "请输入密码库密码:" << endl;
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
                cout << "密码正确!" << endl;

                fseek(fp,6,SEEK_SET);
                fread(buff, 4096*sizeof(char), 1, fp);

                cout << "-----------------以下是密码-----------------" << endl;
                cout << buff << endl;
                cout << "--------------------------------------------" << endl;
                cout << "输入回车返回上一级"<< endl;

                getchar();
                getchar();
                break;
            }
            else
            {
                cout << "密码错误!请重新输入:" << endl;
                cin >> inp_code;
                cin.get();
            }
        }
    }
    else
    {
        printf("CANNOT OPEN\n");//容错处理
        exit(1);
    }

    fclose(fp);
}

void setLibPassword(FILE *fp, char *password)
{
    cout << "-[警告] 打开密码库的密码请勿遗失, 若遗失将无法开启加密库!\n" << endl;
    cout << "输入6位数字密码作为打开加密库的钥匙:" << endl;
    cin>>password;
    cin.get();

    if(fp = fopen("CodeX.dat", "wb"))
    {
        fprintf(fp, "%s\n", password);
    }
    else
    {
        printf("CANNOT OPEN\n");//容错处理
        exit(1);
    }

    fclose(fp);
}

void saveToLib(FILE *fp, char *codeChose)
{
    cout <<"-正在将密码存入密码库.." << endl;

    if(fp = fopen("CodeX.dat", "ab"))
    {
        fprintf(fp, "网站, 密码\n");

        cout << "输入网站地址以备注:" << endl;
        char webInf[80]={0};
        cin >> webInf;
        cin.get();

        fprintf(fp, "%s, %s\n", webInf, codeChose);

        saving();      //正在保存(动画)
    }
    else
    {
        printf("CANNOT OPEN\n");//容错处理
        exit(1);
    }

    fclose(fp);
}
