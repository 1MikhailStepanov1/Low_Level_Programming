#ifndef LOW_LEVEL_PROGRAMMING_REQUESTINVOKER_H
#define LOW_LEVEL_PROGRAMMING_REQUESTINVOKER_H

#include <string>
#include <stdbool.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iterator>
#include "../../common/request_schema.hxx"
#include "../../common/response_schema.hxx"
#include "../../exceptions/exceptions.h"
#include "../../../Lab1/include/database.h"
#include "../../../Lab1/include/meta.h"


class RequestInvoker {
private:
    struct database db;

public:
    RequestInvoker(struct database db);
    response_t parse_and_execute_query(request_t request);
    void close_db();
    response_t convert_to_XML_format();
};

#endif
