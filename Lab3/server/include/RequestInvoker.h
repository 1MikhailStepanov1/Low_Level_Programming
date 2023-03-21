#ifndef LOW_LEVEL_PROGRAMMING_REQUESTINVOKER_H
#define LOW_LEVEL_PROGRAMMING_REQUESTINVOKER_H

#include "../../../Lab1/include/database.h"
#include "../../../Lab1/include/meta.h"
#include <string>
#include <stdbool.h>
#include "../../common/request_schema.hxx"
#include "../../common/response_schema.hxx"
#incldue "../../exceptions/exceptions.h"


class RequestInvoker {
private:
    struct database db;

public:
    RequestInvoker(std::string file);
    void parse_and_execute_query(request_t request);
    void close_db();
    response_t convert_to_XML_format();
};

#endif
