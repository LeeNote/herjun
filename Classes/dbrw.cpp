//
//  dbrw.cpp
//  JosunDoctor
//
//  Created by 이재훈 on 2015. 12. 27..
//
//

#include "dbrw.h"


int dbrw::selectData(){
    
    sqlite3 *pDB = NULL;
    char* errMsg = NULL;
    std::string sqlstr;
    int result;
    CCLOG("START TO OKAY");
    std::string dbPath = CCFileUtils::sharedFileUtils()->getWritablePath();
    dbPath.append("doctor.sqlite");
    result = sqlite3_open(dbPath.c_str(), &pDB);
    
    sqlite3_stmt* statement;
    std::string selectStr;
    selectStr = "SELECT * FROM Student;";
    int row3;
    if(sqlite3_prepare_v2(pDB, selectStr.c_str(), -1, &statement, nullptr)== SQLITE_OK){
        while(sqlite3_step(statement) == SQLITE_ROW){
            int row1 = sqlite3_column_int(statement, 0);
            char* row2 = (char*)sqlite3_column_text(statement, 1);
            row3 = sqlite3_column_int(statement, 2);
            
            CCLOG("%d, %s, %d", row1, row2, row3);
        }
    }
    sqlite3_finalize(statement);
    
    sqlite3_close(pDB);

    return row3;
    
}



