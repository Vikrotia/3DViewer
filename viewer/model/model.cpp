#include "model.h"


bool s21::Model::Processing(const std::string& file_name){
    return parser_->Processing(file_name);
}

s21::OBJFile s21::Model::get_obj()
{
    return parser_->get_obj();
}

std::string s21::Model::FindFileName(std::string file_path)
{
    return parser_->FindFileName(file_path);
}

void s21::Model::ChangeScale(double value){
    affine_->set_vertices(parser_->get_obj().vertexes);
    affine_->ChangeScale(value);
    parser_->set_obj(affine_->get_vertices());
}

void s21::Model::ChangeRotateOnX(double value){
    affine_->set_vertices(parser_->get_obj().vertexes);
    affine_->ChangeRotateOnX(value);
    parser_->set_obj(affine_->get_vertices());
}

void s21::Model::ChangeRotateOnY(double value){
    affine_->set_vertices(parser_->get_obj().vertexes);
    affine_->ChangeRotateOnY(value);
    parser_->set_obj(affine_->get_vertices());
}

void s21::Model::ChangeRotateOnZ(double value){
    affine_->set_vertices(parser_->get_obj().vertexes);
    affine_->ChangeRotateOnZ(value);
    parser_->set_obj(affine_->get_vertices());
}

void s21::Model::MoveOnX(double value){
    affine_->set_vertices(parser_->get_obj().vertexes);
    affine_->MoveOnX(value);
    parser_->set_obj(affine_->get_vertices());
}

void s21::Model::MoveOnY(double value){
    affine_->set_vertices(parser_->get_obj().vertexes);
    affine_->MoveOnY(value);
    parser_->set_obj(affine_->get_vertices());
}

void s21::Model::MoveOnZ(double value) {
    affine_->set_vertices(parser_->get_obj().vertexes);
    affine_->MoveOnZ(value);
    parser_->set_obj(affine_->get_vertices());
}


void s21::Model::set_obj_parser(const std::vector<double> &new_vertexes){
    parser_->set_obj(new_vertexes);
}
