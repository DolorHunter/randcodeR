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

//密码库(主界面->密码库)
void library(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** 随机密码生成器  v.0.5 ***************" << endl;
        cout << "*                                  Power by: DolorHunter*" << endl;
        cout << "*当前位置:主界面->密码库                                 *" << endl;
        cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
        cout << "* -[注意] 第一次使用请先设置密码库密匙!                  *" << endl;
        cout << "* -[注意] 重复设置密码会导致密码库重写,库内密码会被删除, *" << endl;
        cout << "          若您已经设置密码,请不要重复设置!!              *" << endl;
        cout << "*1. 开启库                                               *" << endl;
        cout << "*2. 设置库密码                                           *" << endl;
        cout << "*3. 忘记密码                                             *" << endl;
        cout << "*0. 返回主界面                                           *" << endl;
        cout << "**********************************************************" << endl;
        cout << "请输入序号:" ;

        int iChose;
        cin >> iChose;
        cin.get();

        switch(iChose){
            case 0:
                sign=false; break;///返回上一级
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

//忘记密码(主界面->密码库->忘记密码)
void forgetCode(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** 随机密码生成器  v.0.5 ***************" << endl;
        cout << "*                                  Power by: DolorHunter*" << endl;
        cout << "*当前位置:主界面->密码库->忘记密码                       *" << endl;
        cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
        cout << "[注意]:强制改密会清除密码库文件以完成重置!!              *" << endl;
        cout << "*0. 强制改密.                                            *" << endl;
        cout << "*                                                        *" << endl;
        cout << "*或者. 您还可以尝试联系作者以获得技术支持.               *" << endl;
        cout << "*[联系作者]: DolorHunter@gmail.com                       *" << endl;
        cout << "*我将会尽快回复邮件!                                     *" << endl;
        cout << "**********************************************************" << endl;
        cout << endl;
        cout << "输入其他数字返回上一级." << endl;

        char iChose;
        cin >> iChose;
        cin.get();

        switch(iChose){
            case 0:
                setLibPassword(fp, password); break;
            default:
                sign=false; break;///返回上一级
        }
    }while(sign);
}


//生成密码(主界面->生成密码)
void creatPassword(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** 随机密码生成器  v.0.5 ***************" << endl;
        cout << "*                                  Power by: DolorHunter*" << endl;
        cout << "*当前位置:主界面->生成密码                               *" << endl;
        cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
        cout << "* -[注意] 第一次使用请先设置密码库密匙!                  *" << endl;
        cout << "*1. 纯数字.                                              *" << endl;
        cout << "*2. 数字 &英文小写.                                      *" << endl;
        cout << "*3. 数字 &英文混拼.                                      *" << endl;
        cout << "*4. 专家.                                                *" << endl;
        cout << "*0. 返回主界面                                           *" << endl;
        cout << "**********************************************************" << endl;
        cout << "请选择生成密码规则:" ;

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
                sign=false; break;///返回上一级
        }
    }while(sign);
}

//联系作者界面(主界面->联系作者)
void donation(FILE *fp, char *password){
    system("CLS");
    cout << "******************** 随机密码生成器  v.0.5 ***************" << endl;
        cout << "*                                  Power by: DolorHunter*" << endl;
    cout << "*当前位置:主界面->联系作者                               *" << endl;
    cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
    cout << "[联系作者]: DolorHunter@gmail.com                        *" << endl;
    cout << "[捐助地址]: paypal.me/dolor059                          *" << endl;
    cout << "感谢您的认可与支持!                                      *" << endl;
    cout << "**********************************************************" << endl;
    cout << endl;
    cout << "输入任意内容返回上一级." << endl;
    getchar();
}

//主界面
int index(FILE *fp, char *password){
    bool sign=true;
    do{
        system("CLS");
        cout << "******************** 随机密码生成器  v.0.5 ***************" << endl;
        cout << "*                                  Power by: DolorHunter*" << endl;
        cout << "*当前位置:主界面                                         *" << endl;
        cout << "* -[注意] 第一次使用请先设置密码库密匙!                  *" << endl;
        cout << "*1. 密码库.                  <-在这里设置密匙            *" << endl;
        cout << "*2. 生成密码.                                            *" << endl;
        cout << "*3. 联系作者.                                            *" << endl;
        cout << "*0. 退出.                                                *" << endl;
        cout << "**********************************************************" << endl;
        cout << "*请输入序号:" ;

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
                sign=false; break;///返回上一级
        }
    }while(sign);

    cout << "\n进程终止." << endl;
    return 0;
}
