//
//  main.cpp
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "PControl.hpp"
#include "Copter.hpp"
#include "Jet.hpp"
/*2、写一个测试函数，完成飞机的控制系统测试：（20分）
 要求：a、创建飞机控制类对象；创建飞机类对象（使用动态内存）
 b、通过飞机控制类对象添加相关飞机对象（至少两个）
 c、飞机控制类中的飞机对象的两个指针分别指向：1、直升机对象；2、喷气式飞机对象；
 d、通过飞机控制类对象分别调用play_print、plane_fly、plane_land、plane_modal函数，实现飞机的全部操作功能
 e、整体设计避免内存泄漏以及相关bug。*/
void test_PControl()//测试函数
{
    //创建飞机控制器对象
    PControl ptr;
    //创建飞机对象
    Copter * copter = new Copter();
    Jet * jet = new Jet();
    Copter * cop1 = new Copter("C2","C-16","MK");
    //给控制器添加所控制的飞机
    ptr.addPlane(*copter);
    ptr.addPlane(*jet);
    ptr.addPlane(*cop1);
    cout<<"数量："<<ptr.getNum()<<endl;
    cout<<ptr.getIndex()<<endl;
    //飞机的功能实现
    for(int i=0; i<ptr.getNum();++i)
    {
        ptr.play_print(*ptr.getP()[i]);
        ptr.plane_fly(*ptr.getP()[i]);
        ptr.plane_land(*ptr.getP()[i]);
        ptr.plane_modal(*ptr.getP()[i]);
    }
    //释放飞机
    for(int i=0; i<ptr.getNum();++i)
    {
        Plane* p = &ptr.destroyPlane();
        delete p;
        p = NULL;
    }
}
int main(int argc, const char * argv[]) {
    test_PControl();
    return 0;
}
