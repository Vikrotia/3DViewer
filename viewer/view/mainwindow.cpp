#include "mainwindow.h"

#include "ui_mainwindow.h"

s21::MainWindow::MainWindow(QWidget *parent, controller *c1)
    : QMainWindow(parent), ui_(new Ui::MainWindow), c_(c1) {
  ui_->setupUi(this);


  LoadAndScaleImages();
  glWidget_ = new GLWidget(this, &obj_data_);

  ui_->layoutForOpenGL->addWidget(glWidget_);

  gif_ = new s21::Gif(this);
  gif_->setGLWidget(glWidget_);
  gif_->setUI(ui_);
}

s21::MainWindow::~MainWindow() {
  delete glWidget_;
  delete gif_;
//  delete c_;
  delete ui_;
}



void s21::MainWindow::SetImageForLabel(QLabel* label, const QString& imagePath) {
    QPixmap pixmap(imagePath);
    int w = label->width();
    int h = label->height();
    label->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
}

void s21::MainWindow::LoadAndScaleImages() {
    SetImageForLabel(ui_->label_2, ":/img/13.jpg");
    SetImageForLabel(ui_->label_3, ":/img/9.png");
    SetImageForLabel(ui_->label_4, ":/img/17.jpeg");
    SetImageForLabel(ui_->label_6, ":/img/1.png");
    SetImageForLabel(ui_->label_7, ":/img/7.png");
    SetImageForLabel(ui_->label_12, ":/img/8.png");
    SetImageForLabel(ui_->label_16, ":/img/16.webp");
    SetImageForLabel(ui_->label_5, ":/img/17.jpeg");
    SetImageForLabel(ui_->label_11, ":/img/17.jpeg");
    SetImageForLabel(ui_->label_17, ":/img/17.jpeg");
    SetImageForLabel(ui_->label_18, ":/img/21.png");
    SetImageForLabel(ui_->label_24, ":/img/22.png");
    SetImageForLabel(ui_->label_25, ":/img/17.jpeg");
    SetImageForLabel(ui_->label_31, ":/img/17.jpeg");
    SetImageForLabel(ui_->label_32, ":/img/23.png");
    SetImageForLabel(ui_->label_36, ":/img/17.jpeg");
    SetImageForLabel(ui_->label_37, ":/img/24.png");
}

void s21::MainWindow::on_load_clicked() {

  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open File"), "/home", tr("Object (*.obj)"));
  ui_->label->setText(fileName);
}

void s21::MainWindow::on_start_pressed() {
  std::string str = ui_->label->text().toStdString();
  glWidget_->clearModel();
  c_->Processing(str);
  obj_data_ = c_->get_obj();

  ui_->start->setDisabled(1);
  ui_->start->setDisabled(0);

  ui_->VerticesLabel->setText(QString::number(obj_data_.num_vertexes));
  ui_->EdgesLabel->setText(QString::number(obj_data_.num_facets / 3));

  std::string std_filename = ui_->label->text().toStdString();
  ui_->file_name->setText(QString::fromStdString(c_->FindFileName(std_filename)));

  glWidget_->update();
}

void s21::MainWindow::on_X_valueChanged(double arg1) {
  glWidget_->x_coord = arg1;
  glWidget_->update();
}

void s21::MainWindow::on_Y_valueChanged(double arg1) {
  glWidget_->y_coord = arg1;
  glWidget_->update();
}

void s21::MainWindow::on_Z_valueChanged(double arg1) {
  glWidget_->z_coord = arg1;
  glWidget_->update();
}

void s21::MainWindow::on_X_2_valueChanged(double arg1)
{
    glWidget_->x_coord_rotate = arg1;
    glWidget_->update();
}


void s21::MainWindow::on_Y_2_valueChanged(double arg1)
{
    glWidget_->y_coord_rotate = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_Z_2_valueChanged(double arg1)
{
    glWidget_->z_coord_rotate = arg1;
    glWidget_->update();
}


void s21::MainWindow::on_X_3_valueChanged(double arg1)
{
    glWidget_->scale_x = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_Y_3_valueChanged(double arg1)
{
    glWidget_->scale_y = arg1;
    glWidget_->update();
}


void s21::MainWindow::on_projection_type_toggled(bool checked)
{
    glWidget_->projection_type = 1;
    glWidget_->update();

}


void s21::MainWindow::on_radioButton_toggled(bool checked)
{
    glWidget_->projection_type = 0;
    glWidget_->update();

}


void s21::MainWindow::on_red_valueChanged(double arg1)
{
    glWidget_->c_red = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_gren_valueChanged(double arg1)
{
    glWidget_->c_green = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_blue_valueChanged(double arg1)
{
    glWidget_->c_blue = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_radioButton_2_toggled(bool checked)
{
    glWidget_->mode = 0;
}


void s21::MainWindow::on_radioButton_3_toggled(bool checked)
{
    glWidget_->mode = 1;
}


void s21::MainWindow::on_lineWidth_valueChanged(double arg1)
{
    glWidget_->line_width = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_verticle_Size_valueChanged(double arg1)
{
    glWidget_->verticle_width = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_red_verticle_valueChanged(double arg1)
{
    glWidget_->v_red = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_green_verticle_valueChanged(double arg1)
{
    glWidget_->v_green = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_blue_verticle_valueChanged(double arg1)
{
    glWidget_->v_blue = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_red_line_valueChanged(double arg1)
{
    glWidget_->l_red = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_green_line_valueChanged(double arg1)
{
    glWidget_->l_green = arg1;
    glWidget_->update();

}


void s21::MainWindow::on_blue_line_valueChanged(double arg1)
{
    glWidget_->l_blue = arg1;
    glWidget_->update();

}

void s21::MainWindow::on_radioButton_5_toggled(bool checked)
{
    glWidget_->verticle_mode = 1;
}


void s21::MainWindow::on_radioButton_6_toggled(bool checked)
{
    glWidget_->verticle_mode = 2;
}


void s21::MainWindow::on_screenshot_clicked()
{
    gif_->button_screen_pressed(this);

}


void s21::MainWindow::on_gif_clicked()
{
    gif_->button_pressed(this);
}

