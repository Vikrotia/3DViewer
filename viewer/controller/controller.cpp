#include "controller.h"



void s21::controller::Processing(std::string file_path)
{
    p_->Processing(file_path);
}

s21::OBJFile s21::controller::get_obj()
{
    return p_->get_obj();
}

std::string s21::controller::FindFileName(std::string file_path)
{
    return p_->FindFileName(file_path);
}
