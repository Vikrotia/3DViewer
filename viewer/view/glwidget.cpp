#include "glwidget.h"

s21::GLWidget::GLWidget(QWidget *parent, s21::OBJFile *objData)
    : QOpenGLWidget(parent), objData_(objData) {}

void s21::GLWidget::initializeGL() {
  glClearColor(c_red, c_green, c_blue, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void s21::GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glLoadIdentity();
}

void s21::GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glVertexPointer(3, GL_DOUBLE, 0, objData_->vertexes.data());
  glClearColor(c_red, c_green, c_blue, 1.0f);
  glEnableClientState(GL_VERTEX_ARRAY);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);

  if (projection_type == 0)
    glOrtho(-5, 5, -5, 5, 0.1f, 2000);
  else
    gluPerspective(90.0f, width() / height(), 0.1f, 1000.0f);

  glTranslated(x_coord, y_coord, z_coord);
  glScaled(scale_x, scale_y, 1);

  glRotatef(y_rot, 1, 0, 0);
  glRotatef(y_rot, 0, 1, 0);
  glRotatef(z_coord_rotate, 0, 0, 1);

  glLineWidth(line_width);
  glColor3f(l_red, l_green, l_blue);
  stipple();

  glDrawElements(GL_LINES, objData_->facets.size(), GL_UNSIGNED_INT,
                 objData_->facets.data());
  glColor3f(v_red, v_green, v_blue);
  glPointSize(verticle_width);
  verticleMode();
  glDisableClientState(GL_VERTEX_ARRAY);
}

void s21::GLWidget::clearModel() {
  objData_->facets.clear();
  objData_->vertexes.clear();
  objData_->num_vertexes = 0;
  objData_->num_facets = 0;
  update();
}

void s21::GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  x_rot = 1 / M_PI * (mo->pos().y() - m_pos.y());
  y_rot = 1 / M_PI * (mo->pos().x() - m_pos.x());
  update();
}

void s21::GLWidget::mousePressEvent(QMouseEvent *mo) { m_pos = mo->pos(); }

void s21::GLWidget::stipple() {
  if (mode == 0) {
    if (glIsEnabled(GL_LINE_STIPPLE)) glDisable(GL_LINE_STIPPLE);
  } else {
    if (!glIsEnabled(GL_LINE_STIPPLE)) {
      glEnable(GL_LINE_STIPPLE);
    }
    glLineStipple(1, 1);
  }
  update();
}

void s21::GLWidget::verticleMode() {
  if (verticle_mode == 1 && file_exist) {
    if (!glIsEnabled(GL_POINT_SMOOTH)) glEnable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, objData_->num_vertexes);
  } else if (verticle_mode == 2 && file_exist) {
    if (glIsEnabled(GL_POINT_SMOOTH)) glDisable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, objData_->num_vertexes);
  }
  update();
}
