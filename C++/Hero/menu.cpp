//
//  menu.cpp
//  GameDrive
//
//  Created by mac on 18/3/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "menu.h"
HeroSet sets[5];
int _size = 0;
int _index = 0;
int _capacity = 4;
void Add_Hero()
{
lk:cout<<"ç≈ç≈ç≈ç≈ç≈ç≈AddMenu≈ç≈ç≈ç≈ç≈ç≈ç"<<endl;
    cout<<"†        1:Add_Hero.species   †"<<endl;
    cout<<"†        2:Add_Ultraman       †"<<endl;
    cout<<"†        3:Add_Rider          †"<<endl;
    cout<<"†        4:Add_Sentai         †"<<endl;
    cout<<"†        5:Add_MetalHero      †"<<endl;
    cout<<"†        6:Exit_AddMenu       †"<<endl;
    cout<<"ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç"<<endl;
ld:cout<<"Please choose:";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:{
            Hero* q1 = new Ultraman;
            cin>>*dynamic_cast<Ultraman*>(q1);
            cout<<*dynamic_cast<Ultraman*>(q1);
            break;}
        case 2:{
            
            break;}
        case 3:{
            
            break;}
        case 4:{
            
            break;}
        case 5:{
            
            break;}
        case 6:{
            menu();
            break;}
        default:
            cout<<"输入错误，重新输入"<<endl;
            goto ld;
            break;
    }
    goto lk;
    
}
void addHeroSetName()
{
    string name;
    cin>>name;
    sets[_index++].setName(name);
    cout<<"添加容器成功"<<endl;
}
void menu()
{
lj:cout<<"≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈Menu≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈"<<endl;
    cout<<"*            1:Add_Hero              *"<<endl;
    cout<<"*            2:Delete_Hero           *"<<endl;
    cout<<"*            3:Search_Hero           *"<<endl;
    cout<<"*            4:Print_Hero            *"<<endl;
    cout<<"*            5:Modify_Hero           *"<<endl;
    cout<<"*            6:About_Hero            *"<<endl;
    cout<<"*            0:Exit                  *"<<endl;
    cout<<"≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈"<<endl;
lk:cout<<"Please choose:";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:{
            Add_Hero();
            break;}
        case 2:{
            
            break;}
        case 3:{
            
            break;}
        case 4:{
            
            break;}
        case 5:{
            
            break;}
        case 6:{
            
            break;}
        case 0:{
            
            break;}
            
        default:
            cout<<"输入错误，重新输入"<<endl;
            goto lk;
            break;
    }
lm:cout<<"Whether or not to continue[Y/N]:";
    char yes;
    cin>>yes;
    if (yes=='y'||'Y'==yes) {
        goto lj;
    }else if (yes=='n'||'N'==yes){
        exit(0);
    }else{
        cout<<"输入错误，重新输入"<<endl;
        goto lm;
    }
}
