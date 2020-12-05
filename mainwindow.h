#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "array.h"
#include "kitchenfurniture.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_add_clicked();

    void on_pushButton_check_clicked();

    void TableItemInsertFurniture(int);

    void on_pushButton_delete_clicked();

    void on_pushButton_delete_all_clicked();

    void on_pushButton_Save_clicked();

private:
    Ui::MainWindow *ui;
    Array arr;
};
#endif // MAINWINDOW_H
