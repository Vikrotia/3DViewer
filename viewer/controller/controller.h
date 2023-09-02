#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/parser.h"
namespace s21 {
class controller
{

private:
    Parser *p_;
public:
    controller(Parser *par): p_(par){};

    void Processing(std::string file_path);
    s21::OBJFile get_obj();
    std::string FindFileName(std::string file_path);

};
}

#endif // CONTROLLER_H
