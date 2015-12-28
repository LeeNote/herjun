//
//  dbrw.cpp
//  JosunDoctor
//
//  Created by 이재훈 on 2015. 12. 27..
//
//

#include "firstinput.h"


int firstinput::makeDB(){
    sqlite3 *pDB = NULL;
    char* errMsg = NULL;
    std::string sqlstr;
    int result;
    CCLOG("START TO OKAY");
    std::string dbPath = CCFileUtils::sharedFileUtils()->getWritablePath();
    dbPath.append("doctor.sqlite");
    result = sqlite3_open(dbPath.c_str(), &pDB);
    if(result!=SQLITE_OK)
        CCLOG("OPENING WRONG, %d, MSG: %s", result, errMsg);
    CCLOG("result %d",result);
    CCLOG("%s", dbPath.c_str());
    
    std::string sqlStr;
    sqlStr = "create table Student (_id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER);";
    
    result = sqlite3_exec(pDB, sqlStr.c_str(), nullptr, nullptr, &errMsg);
    if(result != SQLITE_OK){
        CCLOG("CREATE ERROR!!");
    }else if(result == SQLITE_OK){
        std::string insertStr1;
        std::string insertStr2;
        std::string insertStr3;
        insertStr1 = "INSERT INTO Student(name, age) values ('이재훈', 28);";
        insertStr2 = "INSERT INTO Student(name, age) values ('김승민', 31);";
        insertStr3 = "INSERT INTO Student(name, age) values ('송지훈', 36);";
        sqlite3_exec(pDB, insertStr1.c_str(), nullptr, nullptr, &errMsg);
        sqlite3_exec(pDB, insertStr2.c_str(), nullptr, nullptr, &errMsg);
        sqlite3_exec(pDB, insertStr3.c_str(), nullptr, nullptr, &errMsg);
    }
    
    sqlite3_close(pDB);
}

