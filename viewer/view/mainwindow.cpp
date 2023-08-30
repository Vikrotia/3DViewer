#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QPixmap label_2(":/img/13.jpg");
  int w = ui->label_2->width();
  int h = ui->label_2->height();
  ui->label_2->setPixmap(label_2.scaled(w, h, Qt::KeepAspectRatio));

  QPixmap label_3(":/img/9.png");
  int w1 = ui->label_3->width();
  int h1 = ui->label_3->height();
  ui->label_3->setPixmap(label_3.scaled(w1, h1, Qt::KeepAspectRatio));

  QPixmap label_4(":/img/17.jpeg");
  int w6 = ui->label_4->width();
  int h6 = ui->label_4->height();
  ui->label_4->setPixmap(label_4.scaled(w6, h6, Qt::KeepAspectRatio));

  QPixmap label_6(":/img/1.png");
  int w2 = ui->label_6->width();
  int h2 = ui->label_6->height();
  ui->label_6->setPixmap(label_6.scaled(w2, h2, Qt::KeepAspectRatio));

  QPixmap label_7(":/img/7.png");
  int w3 = ui->label_7->width();
  int h3 = ui->label_7->height();
  ui->label_7->setPixmap(label_7.scaled(w3, h3, Qt::KeepAspectRatio));

  QPixmap label_12(":/img/8.png");
  int w4 = ui->label_12->width();
  int h4 = ui->label_12->height();
  ui->label_12->setPixmap(label_12.scaled(w4, h4, Qt::KeepAspectRatio));

  QPixmap label_16(":/img/16.webp");
  int w5 = ui->label_16->width();
  int h5 = ui->label_16->height();
  ui->label_16->setPixmap(label_16.scaled(w5, h5, Qt::KeepAspectRatio));

  QPixmap label_5(":/img/17.jpeg");
  int w8 = ui->label_5->width();
  int h8 = ui->label_5->height();
  ui->label_5->setPixmap(label_5.scaled(w8, h8, Qt::KeepAspectRatio));

  QPixmap label_11(":/img/17.jpeg");
  int w9 = ui->label_11->width();
  int h9 = ui->label_11->height();
  ui->label_11->setPixmap(label_11.scaled(w9, h9, Qt::KeepAspectRatio));

  QPixmap label_17(":/img/17.jpeg");
  int w10 = ui->label_17->width();
  int h10 = ui->label_17->height();
  ui->label_17->setPixmap(label_17.scaled(w10, h10, Qt::KeepAspectRatio));

  QPixmap label_18(":/img/21.png");
  int w11 = ui->label_18->width();
  int h11 = ui->label_18->height();
  ui->label_18->setPixmap(label_18.scaled(w11, h11, Qt::KeepAspectRatio));

  QPixmap label_24(":/img/22.png");
  int w12 = ui->label_24->width();
  int h12 = ui->label_24->height();
  ui->label_24->setPixmap(label_24.scaled(w12, h12, Qt::KeepAspectRatio));

  QPixmap label_25(":/img/17.jpeg");
  int w13 = ui->label_25->width();
  int h13 = ui->label_25->height();
  ui->label_25->setPixmap(label_25.scaled(w13, h13, Qt::KeepAspectRatio));

  QPixmap label_31(":/img/17.jpeg");
  int w14 = ui->label_31->width();
  int h14 = ui->label_31->height();
  ui->label_31->setPixmap(label_31.scaled(w14, h14, Qt::KeepAspectRatio));

  QPixmap label_32(":/img/23.png");
  int w15 = ui->label_32->width();
  int h15 = ui->label_32->height();
  ui->label_32->setPixmap(label_32.scaled(w15, h15, Qt::KeepAspectRatio));

  QPixmap label_36(":/img/17.jpeg");
  int w16 = ui->label_36->width();
  int h16 = ui->label_36->height();
  ui->label_36->setPixmap(label_36.scaled(w16, h16, Qt::KeepAspectRatio));

  QPixmap label_37(":/img/24.png");
  int w17 = ui->label_37->width();
  int h17 = ui->label_37->height();
  ui->label_37->setPixmap(label_37.scaled(w17, h17, Qt::KeepAspectRatio));

  glWidget = new GLWidget(this);

  ui->layoutForOpenGL->addWidget(glWidget);

  p_ = new s21::Parser();
}

MainWindow::~MainWindow() {
  delete glWidget;
  delete p_;
  delete ui;
}

void MainWindow::on_load_clicked() {

  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open File"), "/home", tr("Object (*.obj)"));
  ui->label->setText(fileName);
}

void MainWindow::on_start_pressed() {
  std::string str = ui->label->text().toStdString();
  int status_ = 0;
  s21::OBJFile obj_file_ ;
  std::ifstream input_file_;
  glWidget->clearModel();
  p_->clearData();
  p_->Processing(str);
  s21::OBJFile objData = p_->get_obj();

  glWidget->setVerticesAndFacets(objData.vertexes, objData.facets,
                                 objData.num_facets, objData.num_vertexes);

  ui->start->setDisabled(1);
  ui->start->setDisabled(1);
  ui->start->setDisabled(0);

  int numVertices = objData.num_vertexes;
  int numFacets = objData.num_facets / 3;

  ui->VerticesLabel->setText(QString::number(numVertices));
  ui->EdgesLabel->setText(QString::number(numFacets));

  glWidget->update();
}

void MainWindow::on_X_valueChanged(double arg1) {
  glWidget->x_coord = arg1;
  glWidget->update();
}

void MainWindow::on_Y_valueChanged(double arg1) {
  glWidget->y_coord = arg1;
  glWidget->update();
}

void MainWindow::on_Z_valueChanged(double arg1) {
  glWidget->z_coord = arg1;
  glWidget->update();
}

void MainWindow::on_X_2_valueChanged(double arg1)
{
    glWidget->x_coord_rotate = arg1;
    glWidget->update();
}


void MainWindow::on_Y_2_valueChanged(double arg1)
{
    glWidget->y_coord_rotate = arg1;
    glWidget->update();

}


void MainWindow::on_Z_2_valueChanged(double arg1)
{
    glWidget->z_coord_rotate = arg1;
    glWidget->update();
}


void MainWindow::on_X_3_valueChanged(double arg1)
{
    glWidget->scale_x = arg1;
    glWidget->update();

}


void MainWindow::on_Y_3_valueChanged(double arg1)
{
    glWidget->scale_y = arg1;
    glWidget->update();
}


void MainWindow::on_projection_type_toggled(bool checked)
{
    glWidget->projection_type = 1;
    glWidget->update();

}


void MainWindow::on_radioButton_toggled(bool checked)
{
    glWidget->projection_type = 0;
    glWidget->update();

}


void MainWindow::on_red_valueChanged(double arg1)
{
    glWidget->c_red = arg1;
    glWidget->update();

}


void MainWindow::on_gren_valueChanged(double arg1)
{
    glWidget->c_green = arg1;
    glWidget->update();

}


void MainWindow::on_blue_valueChanged(double arg1)
{
    glWidget->c_blue = arg1;
    glWidget->update();

}


void MainWindow::on_radioButton_2_toggled(bool checked)
{
    glWidget->mode = 0;
}


void MainWindow::on_radioButton_3_toggled(bool checked)
{
    glWidget->mode = 1;
}


void MainWindow::on_lineWidth_valueChanged(double arg1)
{
    glWidget->line_width = arg1;
    glWidget->update();

}


void MainWindow::on_verticle_Size_valueChanged(double arg1)
{
    glWidget->verticle_width = arg1;
    glWidget->update();

}


void MainWindow::on_red_verticle_valueChanged(double arg1)
{
    glWidget->v_red = arg1;
    glWidget->update();

}


void MainWindow::on_green_verticle_valueChanged(double arg1)
{
    glWidget->v_green = arg1;
    glWidget->update();

}


void MainWindow::on_blue_verticle_valueChanged(double arg1)
{
    glWidget->v_blue = arg1;
    glWidget->update();

}


void MainWindow::on_red_line_valueChanged(double arg1)
{
    glWidget->l_red = arg1;
    glWidget->update();

}


void MainWindow::on_green_line_valueChanged(double arg1)
{
    glWidget->l_green = arg1;
    glWidget->update();

}


void MainWindow::on_blue_line_valueChanged(double arg1)
{
    glWidget->l_blue = arg1;
    glWidget->update();

}

void MainWindow::on_radioButton_5_toggled(bool checked)
{
    glWidget->verticle_mode = 1;
}


void MainWindow::on_radioButton_6_toggled(bool checked)
{
    glWidget->verticle_mode = 2;
}

