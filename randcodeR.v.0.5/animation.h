#pragma once
#include<iostream>
#include<windows.h>

using namespace std;

void saving(){
    int i=0;
    while(i<2){
    cout << "saving." << endl;
    Sleep(200);
    system("CLS");
    cout << "saving.." << endl;
    Sleep(200);
    system("CLS");
    cout << "saving..." << endl;
    Sleep(200);
    system("CLS");
    i++;
    }
}
