#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "array.h"
#include "kitchenfurniture.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include <iostream>
#include <string>
#include "QMessageBox"

void MainWindow::TableItemInsertFurniture(int n){
    ui->tableWidget->insertRow(n);
    ui->tableWidget->setItem(n, 0, new QTableWidgetItem(QString::fromStdString(this->arr.indexSearch(n).getName())));
    ui->tableWidget->setItem(n, 1, new QTableWidgetItem(QString::fromStdString(this->arr.indexSearch(n).getMaterial())));
    ui->tableWidget->setItem(n, 7, new QTableWidgetItem(QString::number(this->arr.indexSearch(n).getCoordX())));
    ui->tableWidget->setItem(n, 2, new QTableWidgetItem(QString::number(this->arr.indexSearch(n).getHeight())));
    ui->tableWidget->setItem(n, 3, new QTableWidgetItem(QString::number(this->arr.indexSearch(n).getWidth())));
    ui->tableWidget->setItem(n, 4, new QTableWidgetItem(QString::number(this->arr.indexSearch(n).getLength())));
    ui->tableWidget->setItem(n, 5, new QTableWidgetItem(QString::number(this->arr.indexSearch(n).getCoordZ())));
    ui->tableWidget->setItem(n, 6, new QTableWidgetItem(QString::number(this->arr.indexSearch(n).getCoordY())));
    ui->label_n->setText("Введите элемент #" + QString::number(this->arr.getSize()+1));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->arr.cleanVector();
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setShowGrid(true);

    QStringList table_header;
    table_header<<"name"<<"material"<<"height"<<"length"<<"width"
              <<"z"<<"y"<<"x"<<"type";
    ui->tableWidget->setHorizontalHeaderLabels(table_header);
    ui->tableWidget->setColumnWidth(2,40);
    ui->tableWidget->setColumnWidth(3,40);
    ui->tableWidget->setColumnWidth(4,40);
    ui->tableWidget->setColumnWidth(5,40);
    ui->tableWidget->setColumnWidth(6,40);
    ui->tableWidget->setColumnWidth(7,40);
    ui->tableWidget->setColumnWidth(8,70);
    ui->tableWidget->setEditTriggers(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_add_clicked()
{
    int counter = this->arr.getSize();
        if((ui->comboBox->currentText().toStdString()=="Техника")&&
                (ui->lineEdit_name->text().toStdString()!="")&&
                (ui->lineEdit_height->text().toStdString()!="")&&
                (ui->lineEdit_length->text().toStdString()!="")&&
                (ui->lineEdit_width->text().toStdString()!="")&&
                (ui->lineEdit_z->text().toStdString()!="")&&
                (ui->lineEdit_y->text().toStdString()!="")&&
                (ui->lineEdit_x->text().toStdString()!=""))

        {
            this->arr.addAppliances(
                        ui->lineEdit_height->text().toFloat(),
                        ui->lineEdit_length->text().toFloat(),
                        ui->lineEdit_width->text().toFloat(),
                        ui->lineEdit_z->text().toFloat(),
                        ui->lineEdit_y->text().toFloat(),
                        ui->lineEdit_x->text().toFloat(),
                        ui->lineEdit_name->text().toStdString());
            TableItemInsertFurniture(counter);
            ui->tableWidget->setItem(counter, 8, new QTableWidgetItem(QString::fromStdString("Appliance")));
        }
        if((ui->comboBox->currentText().toStdString()=="Мебель")&&
                (ui->lineEdit_name->text().toStdString()!="")&&
                (ui->lineEdit_height->text().toStdString()!="")&&
                (ui->lineEdit_length->text().toStdString()!="")&&
                (ui->lineEdit_width->text().toStdString()!="")&&
                (ui->lineEdit_z->text().toStdString()!="")&&
                (ui->lineEdit_y->text().toStdString()!="")&&
                (ui->lineEdit_x->text().toStdString()!="")&&
                (ui->lineEdit_material->text().toStdString()!=""))
        {
            this->arr.addFurniture(
                        ui->lineEdit_height->text().toFloat(),
                        ui->lineEdit_length->text().toFloat(),
                        ui->lineEdit_width->text().toFloat(),
                        ui->lineEdit_z->text().toFloat(),
                        ui->lineEdit_y->text().toFloat(),
                        ui->lineEdit_x->text().toFloat(),
                        ui->lineEdit_name->text().toStdString(),
                        ui->lineEdit_material->text().toStdString());
            TableItemInsertFurniture(counter);
            ui->tableWidget->setItem(counter, 8, new QTableWidgetItem("Furniture"));
        }


    cout<<this->arr.indexSearch(counter).getCoordX()<<"\n"<<arr.getSize();
    ui->lineEdit_height->clear();
    ui->lineEdit_length->clear();
    ui->lineEdit_width->clear();
    ui->lineEdit_z->clear();
    ui->lineEdit_y->clear();
    ui->lineEdit_x->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_material->clear();
}


void MainWindow::on_pushButton_check_clicked()
{
    if(this->arr.arrayCheck()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ответ");
        msgBox.setText("Условие выполнено");
        msgBox.exec();
    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ответ");
        msgBox.setText("Условие не выполнено");
        msgBox.exec();
    }


}

void MainWindow::on_pushButton_delete_clicked()
{
    this->arr.deleteElement(ui->spinBox->text().toInt()-1);
    ui->tableWidget->clear();
    QStringList table_header;
    table_header<<"name"<<"material"<<"height"<<"length"<<"width"
              <<"z"<<"y"<<"x";
    ui->tableWidget->setHorizontalHeaderLabels(table_header);
    for(int i = 0; i<this->arr.getSize(); i++){
        TableItemInsertFurniture(i);
    }
}

void MainWindow::on_pushButton_delete_all_clicked()
{
    this->arr.cleanVector();
    ui->tableWidget->clear();
    QStringList table_header;
    table_header<<"name"<<"material"<<"height"<<"length"<<"width"
              <<"z"<<"y"<<"x";
    ui->tableWidget->setHorizontalHeaderLabels(table_header);
    for(int i = 0; i<this->arr.getSize(); i++){
        TableItemInsertFurniture(i);
    }
}


void MainWindow::on_pushButton_Save_clicked()
{
    arr.toFile(ui->lineEdit_path->text().toStdString());
}
