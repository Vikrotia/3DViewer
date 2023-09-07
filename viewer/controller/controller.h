#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"
namespace s21 {
class Controller
{

private:
    Model *m_;
    Controller(Model *mod);
    static Controller* instance_;
public:
    static Controller* getInstance(Model* mod);
    bool Processing(std::string file_path);
    s21::OBJFile get_obj();
    std::string FindFileName(std::string file_path);
    void ChangeScale(double value);
    void ChangeRotateOnX(double value);
    void ChangeRotateOnY(double value);
    void ChangeRotateOnZ(double value);
    void MoveOnX(double value);
    void MoveOnY(double value);
    void MoveOnZ(double value);
    std::vector<double>::value_type *GetVerticesData();
    std::vector<int>::value_type *GetFacetsData();
    size_t GetVerticesSize();
    size_t GetFacetsSize();
    void ClearData();
};

}

#endif // CONTROLLER_H
