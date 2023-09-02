#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <QDateTime>
#include <QSettings>


#include <qgifimage.h>
#include "glwidget.h"
#include "../controller/controller.h"
#include "gif.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr, controller *c1 = nullptr);
  ~MainWindow();

 private slots:
  void on_load_clicked();
  void on_start_pressed();
  void on_X_valueChanged(double arg1);
  void on_Y_valueChanged(double arg1);
  void on_Z_valueChanged(double arg1);
  void on_X_2_valueChanged(double arg1);
  void on_Y_2_valueChanged(double arg1);
  void on_Z_2_valueChanged(double arg1);
  void on_X_3_valueChanged(double arg1);
  void on_Y_3_valueChanged(double arg1);
  void on_projection_type_toggled(bool checked);
  void on_radioButton_toggled(bool checked);
  void on_red_valueChanged(double arg1);
  void on_gren_valueChanged(double arg1);
  void on_blue_valueChanged(double arg1);
  void on_radioButton_2_toggled(bool checked);
  void on_radioButton_3_toggled(bool checked);
  void on_lineWidth_valueChanged(double arg1);
  void on_verticle_Size_valueChanged(double arg1);
  void on_red_verticle_valueChanged(double arg1);
  void on_green_verticle_valueChanged(double arg1);
  void on_blue_verticle_valueChanged(double arg1);
  void on_red_line_valueChanged(double arg1);
  void on_green_line_valueChanged(double arg1);
  void on_blue_line_valueChanged(double arg1);
  void on_radioButton_5_toggled(bool checked);
  void on_radioButton_6_toggled(bool checked);
  void SetImageForLabel(QLabel* label, const QString& imagePath);
  void LoadAndScaleImages();
  void on_screenshot_clicked();
  void on_gif_clicked();
  void load_settings();
  void save_settings();


private:
  OBJFile obj_data_;
  Ui::MainWindow *ui_;
  GLWidget *glWidget_;
  controller *c_;
  s21::Gif *gif_;
  QSettings *settings_;
};

}// namespace s21

#endif  // MAINWINDOW_H
