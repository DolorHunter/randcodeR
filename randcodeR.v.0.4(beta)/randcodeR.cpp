#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include"rand_num_type.h"
#include"rand_en_num_type.h"
#include"rand_en_num_pro_type.h"
#include"rand_expert.h"


using namespace std;

void creat_warehouse(FILE *);
void open_warehouse(FILE *, char [6]);
void set_password(FILE *, char [6]);
void save_warehouse(FILE *, char [80]);


int main(void)
{
    int bit;    //位数
    char code[10][80]={0};
    char code_chose[80]={0};
    char password[6]={0};
    FILE *fp;

    creat_warehouse(fp);//密码库初始化(防止写入失败)

    indexpage:  //goto回到主界面

    cout << "===随机密码生成器===\n" << endl;
    cout << "\t\t\t\tBy:Zhuxiong\n" << endl;
    cout << "-[注意] 第一次使用请先设置密码库密匙!\t(0.密码库 -> 1.设置密码)\n" << endl;
    cout << "选择密码生成规则:\n" << endl;
    cout << "0.密码库\n" << endl;
    cout << "1.纯数字\n" << endl;
    cout << "2.数字+英文小写\n" << endl;
    cout << "3.数字+英文混拼\n" << endl;
    cout << "4.专家\n" << endl;
    cout << "5.撒币支持!\n" << endl;
    cout << "请输入序号:" << endl;

    int rules;
    cin >> rules;
    system("CLS");
    srand((int)time(0));

    if(rules < 0 || rules > 5)
    {
        cout << "使用的规则错误!" << endl;
        return -1;
    }
    else
    {

        if(!rules)  //0.密码库
        {
            warehouse:  //回到密码库

            cout << "-[注意] 第一次使用请先设置密码库密匙!\t(0.密码库 -> 1.设置密码)\n" << endl;
            cout << "0.开启密码库\n" << endl;
            cout << "1.设置密码\n" << endl;
            cout << "2.忘记密码\n" << endl;
            cout << "3.返回主界面\n" << endl;
            cout << "请输入序号:" << endl;

            int chose;
            cin>>chose;

            system("CLS");

            if(chose < 0 || chose > 3)
            {
                cout << "使用的规则错误!" << endl;
                exit(1);
            }
            else
            {
                if(!chose)  //0.开启密码库
                {
                    open_warehouse(fp, password);
                    system("CLS");
                    goto warehouse;
                }
                else if(chose == 1) //1.设置密码
                {
                    set_password(fp, password);

                    system("CLS");

                    goto warehouse;
                }
                else if(chose == 2) //2.忘记密码
                {
                    cout << "-[联系作者]:\n-Mail:DolorHunter@gmail.com\n" << endl;
                    cout << "0.强制改密\t[特别注意]: 此操作会删除所有储存密码且不可恢复!\n" <<endl;
                    cout << "1.返回上级\n" << endl;

                    int chose1;
                    cin>>chose1;
                    if(!chose1) //0.强制改密
                    {
                        system("CLS");

                        set_password(fp, password);

                        system("CLS");

                        goto warehouse;
                    }
                    else    //1.返回上级
                    {
                        system("CLS");

                        goto warehouse;
                    }
                }
                else    //3.返回主界面
                {
                    system("CLS");

                    goto indexpage;
                }
            }
        }
        else if(rules != 5) //1~4生成密码
        {
            cout << "请输入密码位数:" << endl;
            cin >> bit;
            cout << "\n" << endl;

            char judge;

            do  //循环生成密码
            {
                if(rules==1)
                {
                    rand_num_type(bit, code);  //纯数字
                }
                else if(rules==2)
                {
                    rand_en_num_type(bit, code);   //英文+数字
                }
                else if(rules==3)
                {
                    rand_en_num_pro_type(bit, code);   //英文大小写+数字
                }
                else
                {
                    rand_expert( bit, code);    //ascii随机
                }

                cout <<  "请输入选择本轮密码的序号, 若不选择请输入其他字符." << endl;
                cin >> judge;

                if(judge >='0' && judge <='9')  //选中生成密码
                {
                    for(int i=0;i<bit;i++)
                    {
                        code_chose[i] = code[judge][i];
                        code_chose[i+1]='\0';
                    }

                    save_warehouse(fp, code_chose);

                    judge = 0;  //重置判定参数
                }
                else
                {
                    system("pause");
                    judge = 1;
                }
            }
            while(judge == 1);

            system("CLS");

            goto indexpage;

        }
        else    //5.捐助
        {
            cout << "感谢您的所有认可和捐助!\n" << endl;
            cout << "-[联系作者]:\nMailBox:DolorHunter@gmail.com\n" << endl;
            cout << "-[捐助地址]: paypal.me/dolor059\n" << endl;
            cout << "再次感谢您的认可和捐助!\n" << endl;
            cout << "\n#输入0返回主界面\n" << endl;

            int temp;
            cin >> temp;

            if(!temp)
            {
                system("CLS");
                goto indexpage;
            }
        }
    }

    return 0;
}



void creat_warehouse(FILE *fp)
{
    if(fp = fopen("CodeX.dat", "ab"))
    {
        ;
    }
    else
    {
        printf("CANNOT NEW\n");//容错处理
        exit(1);
    }

    fclose(fp);
}

void open_warehouse(FILE *fp, char *password)//读取文件首行 比对密码是否相同
{
    char buff[4096];
    char inp_code[6];
    char tbuff[6];
    if(fp = fopen("CodeX.dat", "rb"))
    {
        cout << "请输入密码库密码:" << endl;
        cin >> inp_code;
        fread(tbuff, 6*sizeof(char), 1, fp);

        while(true)
        {
            bool correct=true;
            for(int i=0;i<6;i++){
                if(tbuff[i]!=inp_code[i]){
                    correct=false;
                }
            }
            if(correct)
            {
                printf("密码正确！\n");

                fseek(fp,6,SEEK_SET);
                fread(buff, 4096*sizeof(char), 1, fp);

                cout << buff << endl;
                cout << "输入回车返回上一级"<< endl;

                getchar();
                getchar();
                break;
            }
            else
            {
                cout << "密码错误!请重新输入:" << endl;
                cin >> inp_code;
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

void set_password(FILE *fp, char *password)
{
    cout << "-[警告] 打开密码库的密码请勿遗失, 若遗失将无法开启加密库!\n" << endl;
    cout << "输入6位数字密码作为打开加密库的钥匙:" << endl;
    cin>>password;

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

void save_warehouse(FILE *fp, char *code_chose)
{
    cout <<"-正在将密码存入密码库.." << endl;

    if(fp = fopen("CodeX.dat", "ab"))
    {
        fprintf(fp, "网站, 密码\n");

        cout << "输入网站地址以备注:" << endl;
        char webInf[80]={0};
        cin >> webInf;

        fprintf(fp, "%s, %s\n", webInf, code_chose);
    }
    else
    {
        printf("CANNOT OPEN\n");//容错处理
        exit(1);
    }

    fclose(fp);
}
