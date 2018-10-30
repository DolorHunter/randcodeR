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
    int bit;    //λ��
    char code[10][80]={0};
    char code_chose[80]={0};
    char password[6]={0};
    FILE *fp;

    creat_warehouse(fp);//������ʼ��(��ֹд��ʧ��)

    indexpage:  //goto�ص�������

    cout << "===�������������===\n" << endl;
    cout << "\t\t\t\tBy:Zhuxiong\n" << endl;
    cout << "-[ע��] ��һ��ʹ����������������ܳ�!\t(0.����� -> 1.��������)\n" << endl;
    cout << "ѡ���������ɹ���:\n" << endl;
    cout << "0.�����\n" << endl;
    cout << "1.������\n" << endl;
    cout << "2.����+Ӣ��Сд\n" << endl;
    cout << "3.����+Ӣ�Ļ�ƴ\n" << endl;
    cout << "4.ר��\n" << endl;
    cout << "5.����֧��!\n" << endl;
    cout << "���������:" << endl;

    int rules;
    cin >> rules;
    system("CLS");
    srand((int)time(0));

    if(rules < 0 || rules > 5)
    {
        cout << "ʹ�õĹ������!" << endl;
        return -1;
    }
    else
    {

        if(!rules)  //0.�����
        {
            warehouse:  //�ص������

            cout << "-[ע��] ��һ��ʹ����������������ܳ�!\t(0.����� -> 1.��������)\n" << endl;
            cout << "0.���������\n" << endl;
            cout << "1.��������\n" << endl;
            cout << "2.��������\n" << endl;
            cout << "3.����������\n" << endl;
            cout << "���������:" << endl;

            int chose;
            cin>>chose;

            system("CLS");

            if(chose < 0 || chose > 3)
            {
                cout << "ʹ�õĹ������!" << endl;
                exit(1);
            }
            else
            {
                if(!chose)  //0.���������
                {
                    open_warehouse(fp, password);
                    system("CLS");
                    goto warehouse;
                }
                else if(chose == 1) //1.��������
                {
                    set_password(fp, password);

                    system("CLS");

                    goto warehouse;
                }
                else if(chose == 2) //2.��������
                {
                    cout << "-[��ϵ����]:\n-Telegram:Zhuxiong\n-Mail:DolorHunter@gmail.com\n" << endl;
                    cout << "0.ǿ�Ƹ���\t[�ر�ע��]: �˲�����ɾ�����д��������Ҳ��ɻָ�!\n" <<endl;
                    cout << "1.�����ϼ�\n" << endl;

                    int chose1;
                    cin>>chose1;
                    if(!chose1) //0.ǿ�Ƹ���
                    {
                        system("CLS");

                        set_password(fp, password);

                        system("CLS");

                        goto warehouse;
                    }
                    else    //1.�����ϼ�
                    {
                        system("CLS");

                        goto warehouse;
                    }
                }
                else    //3.����������
                {
                    system("CLS");

                    goto indexpage;
                }
            }
        }
        else if(rules != 5) //1~4��������
        {
            cout << "����������λ��:" << endl;
            cin >> bit;
            cout << "\n" << endl;

            char judge;

            do  //ѭ����������
            {
                if(rules==1)
                {
                    rand_num_type(bit, code);  //������
                }
                else if(rules==2)
                {
                    rand_en_num_type(bit, code);   //Ӣ��+����
                }
                else if(rules==3)
                {
                    rand_en_num_pro_type(bit, code);   //Ӣ�Ĵ�Сд+����
                }
                else
                {
                    rand_expert( bit, code);    //ascii���
                }

                cout <<  "������ѡ������������, ����ѡ�������������ַ�." << endl;
                cin >> judge;

                if(judge >='0' && judge <='9')  //ѡ����������
                {
                    for(int i=0;i<bit;i++)
                    {
                        code_chose[i] = code[judge][i];
                        code_chose[i+1]='\0';
                    }

                    save_warehouse(fp, code_chose);

                    judge = 0;  //�����ж�����
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
        else    //5.����
        {
            cout << "��л���������Ͽɺ;���!\n" << endl;
            cout << "-[��ϵ����]:\nTelegram:Zhuxiong\nMailBox:DolorHunter@gmail.com\n" << endl;
            cout << "-[������ַ]: paypal.me/dolorhunter\n" << endl;
            cout << "�ٴθ�л�����Ͽɺ;���!\n" << endl;
            cout << "\n#����0����������\n" << endl;

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
        printf("CANNOT NEW\n");//�ݴ���
        exit(1);
    }

    fclose(fp);
}

void open_warehouse(FILE *fp, char *password)//��ȡ�ļ����� �ȶ������Ƿ���ͬ
{
    char buff[4096];
    char inp_code[6];
    char tbuff[6];
    if(fp = fopen("CodeX.dat", "rb"))
    {
        cout << "���������������:" << endl;
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
                printf("������ȷ��\n");

                fseek(fp,6,SEEK_SET);
                fread(buff, 4096*sizeof(char), 1, fp);

                cout << buff << endl;
                cout << "����س�������һ��"<< endl;

                getchar();
                getchar();
                break;
            }
            else
            {
                cout << "�������!����������:" << endl;
                cin >> inp_code;
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

void set_password(FILE *fp, char *password)
{
    cout << "-[����] ������������������ʧ, ����ʧ���޷��������ܿ�!\n" << endl;
    cout << "����6λ����������Ϊ�򿪼��ܿ��Կ��:" << endl;
    cin>>password;

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

void save_warehouse(FILE *fp, char *code_chose)
{
    cout <<"-���ڽ�������������.." << endl;

    if(fp = fopen("CodeX.dat", "ab"))
    {
        fprintf(fp, "��վ, ����\n");

        cout << "������վ��ַ�Ա�ע:" << endl;
        char webInf[80]={0};
        cin >> webInf;

        fprintf(fp, "%s, %s\n", webInf, code_chose);
    }
    else
    {
        printf("CANNOT OPEN\n");//�ݴ���
        exit(1);
    }

    fclose(fp);
}
