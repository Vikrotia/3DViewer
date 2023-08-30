#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void GLWidget::setVerticesAndFacets(const std::vector<double> &vertices,
                                    const std::vector<int> &facets, int f, int v) {
  this->vertices = vertices;
  this->facets = facets;
  this->num_facets = f;
  this->num_vertices = v;
  update();
}

void GLWidget::initializeGL() {
  glClearColor(c_red, c_green, c_blue, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glLoadIdentity();
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glVertexPointer(3, GL_DOUBLE, 0, vertices.data());
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

  glDrawElements(GL_LINES, facets.size(), GL_UNSIGNED_INT, facets.data());
  glColor3f(v_red, v_green, v_blue);
  glPointSize(verticle_width);
  verticleMode();
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::clearModel() {
    vertices.clear();
    facets.clear();
    num_vertices = 0;
    num_facets = 0;
    update();
}


void GLWidget::mouseMoveEvent(QMouseEvent *mo)
{
x_rot = 1/M_PI*(mo->pos().y()-m_pos.y());
y_rot = 1/M_PI*(mo->pos().x()-m_pos.x());
update();
}

void GLWidget::mousePressEvent(QMouseEvent *mo)
{
m_pos = mo->pos();
}



void GLWidget::stipple() {
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


void GLWidget::verticleMode() {
  if (verticle_mode == 1) {
    if (!glIsEnabled(GL_POINT_SMOOTH)) glEnable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, num_vertices);
  } else if (verticle_mode == 2) {
    if (glIsEnabled(GL_POINT_SMOOTH)) glDisable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, num_vertices);
  }
  update();
}


