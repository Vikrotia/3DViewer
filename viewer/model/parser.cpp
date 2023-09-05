#include "parser.h"

int s21::Parser::get_status() const { return status_; }
s21::OBJFile s21::Parser::get_obj() const { return obj_file_; }

bool s21::Parser::OpenFile(std::string file_path) {
  input_file_.open(file_path);
  return input_file_.is_open();
}

bool s21::Parser::Processing(std::string file_path) {
  clearData();
  if (OpenFile(file_path)) {
    ReadingFacetsAndVertexes(file_path);
  } else {
    status_ = 1;
  }
  return get_status();
}

void s21::Parser::ReadingFacetsAndVertexes(std::string file_path) {
  std::ifstream input_file(file_path);
  std::string file_line;

  while (std::getline(input_file, file_line)) {
    std::istringstream iss(file_line);
    std::string str_type;
    iss >> str_type;
    if (str_type == "v") {
      double x, y, z;
      if (iss >> x >> y >> z) {
        obj_file_.vertexes.push_back(x);
        obj_file_.vertexes.push_back(y);
        obj_file_.vertexes.push_back(z);
      }
    } else if (str_type == "f") {
      std::string index;
      std::vector<int> f_line;
      while (iss >> index) {
        f_line.push_back(std::stoi(index));
      }
      for (size_t i = 0; i < f_line.size(); ++i) {
        obj_file_.facets.push_back(f_line[i] - 1);
        obj_file_.facets.push_back(f_line[(i + 1) % f_line.size()] - 1);
      }
      obj_file_.num_facets++;
    }
  }
  obj_file_.num_vertexes = static_cast<int>(obj_file_.vertexes.size() / 3);
}

void s21::Parser::clearData() {
  obj_file_ = OBJFile{};
  status_ = 0;
}

std::string s21::Parser::FindFileName(std::string file_path) {
  std::string start;
  size_t lastSlashPos = file_path.find_last_of('/');
  size_t extPos = file_path.find_last_of('.');
  if (lastSlashPos != std::string::npos && extPos != std::string::npos) {
    start = file_path.substr(lastSlashPos + 1, extPos - lastSlashPos - 1);
  }
  return start;
}
void s21::Parser::set_obj(const std::vector<double> &new_vertexes){
    obj_file_.vertexes = new_vertexes;
}
