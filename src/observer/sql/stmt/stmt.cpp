/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "rc.h"
#include "common/log/log.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/explain_stmt.h"

RC Stmt::create_stmt(Db *db, const Query &query, Stmt *&stmt)
{
  stmt = nullptr;

  switch (query.flag) {
    case SCF_INSERT: {
      return InsertStmt::create(db, query.insertion, stmt);
    }
    case SCF_DELETE: {
      return DeleteStmt::create(db, query.deletion, stmt);   
    }
    case SCF_SELECT: {
      return SelectStmt::create(db, query.selection, stmt);
    }

    case SCF_EXPLAIN: {
      return ExplainStmt::create(db, query.explain, stmt);
    }
    default: {
      LOG_WARN("unknown query command");
    }
    break;
  }
  return RC::UNIMPLENMENT;
}


