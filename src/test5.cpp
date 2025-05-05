#include <iostream>
#include <string>
#include "address.h"

using namespace std;

int main()
{
    system("chcp 65001");

    struct addressBooks abs;
    abs.size = 0;
    int select = 0;
    while(true)
    {
        showMeau();
        cin >> select;

        switch (select)
        {
            case 1: //添加联系人
                addPerson(&abs);
                break;
            case 2: //显示联系人
                showPerson(abs);
                break;
            case 3: //删除联系人
                removePerson(&abs);
                break;
            case 4: //查找联系人
                searchPerson(abs);
                break;
            case 5: //修改联系人
                changePerson(&abs);
                break;
            case 6: //清空联系人
                deleteallPerson(&abs);
                break;
            case 0: //退出通讯录
                cout << "感谢您的使用!" << endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}