#ifndef VIEWER_MODEL_H
#define VIEWER_MODEL_H

#include "parser.h"
#include "affine.h"

namespace s21 {
    class Model {
    public:
        bool Processing(const std::string& file_name);
        s21::OBJFile get_obj();
        void set_obj_parser(const std::vector<double> &new_vertexes);
        std::string FindFileName(std::string file_path);
        void ChangeScale(double value);
        void ChangeRotateOnX(double value);
        void ChangeRotateOnY(double value);
        void ChangeRotateOnZ(double value);
        void MoveOnX(double value);
        void MoveOnY(double value);
        void MoveOnZ(double value);
//        void ApplyChanges();

    private:
        Parser* parser_;
        Affine* affine_;

    };

} //namespace s21
#endif //VIEWER_MODEL_H
