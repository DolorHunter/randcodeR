#include <iostream>
#include<cstdlib>
#include"menu.h"
#include"lib.h"

using namespace std;

int main()
{
    char password[6]={0};
    FILE *fp;
    creatLib(fp);                   //密码库初始化(防止写入失败)
    index(fp, password);                        //打开主菜单

    return 0;
}

