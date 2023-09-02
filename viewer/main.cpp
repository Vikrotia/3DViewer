#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Parser p;
  s21::controller c(&p);
  s21::MainWindow w(nullptr, &c);
  w.show();
  return a.exec();
}
