#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWidget>
#include <vector>
#include <GLUT/glut.h>
#include "../model/parser.h"

#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl.h>
namespace s21{
class GLWidget : public QOpenGLWidget {
  Q_OBJECT
 public:
    explicit GLWidget(QWidget* parent = nullptr, s21::OBJFile *objData = nullptr);

 public slots:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void stipple();
  void verticleMode();
  void clearModel();

 private:
  void mouseMoveEvent(QMouseEvent *mo) override;
  void mousePressEvent(QMouseEvent *mo) override;
  s21::OBJFile *objData_;

 public:
  float x_coord = 0, y_coord = 0, z_coord = -10;
  float x_coord_rotate = 0, y_coord_rotate = 0, z_coord_rotate = 0;
  float scale_x = 1, scale_y = 1;
  int projection_type = 0, mode = 0, verticle_mode = 0;
  float line_width = 1;
  float verticle_width = 1;
  float c_red = 0.0, c_blue = 0.0, c_green = 0.0;
  float v_red = 1.0, v_blue = 0.0, v_green = 0.0;
  float l_red = 0.0, l_blue = 0.0, l_green = 1.0;


  float x_rot, y_rot;
  QPoint m_pos;
};
} //namespace s21
#endif  // GLWIDGET_H
