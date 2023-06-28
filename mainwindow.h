#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trains.h"
#include "lab_exceptions.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void add_race_to_array(Trains race);
    Trains define_biggest_race();
    void display_biggest_race(Trains race);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Trains* array = nullptr;
    int size = 0;
};
#endif // MAINWINDOW_H
