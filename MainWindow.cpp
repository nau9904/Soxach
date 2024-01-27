#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include<QDebug>
#include<QMessageBox>
#include <QButtonGroup>
#include<QRadioButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QButtonGroup *radioGroup = new QButtonGroup(this);

    //Set the date and time
    QDateTime dateTimeToSet = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(dateTimeToSet);
    ui->dateEdit_2->setDateTime(dateTimeToSet);
    // XuatChau::listXuatChau list;
    // list.tenChau = ui->tenChau->currentText();
    // list.soLuong = ui->soLuongXuatChau->value();
    QString doiTuong = ui->tueanh->isCheckable() ? "tue anh" : "khac";
    qDebug() << doiTuong;
    int tongTien = doiTuong != "tueanh" ? 1 : 0;
    // list.daTra = ui->daTra->toPlainText().toInt();

    _xuatChau.getInfo(ui->tenChau->currentText(), ui->soLuongXuatChau->value(),doiTuong, tongTien, ui->daTra->toPlainText().toInt());

}

MainWindow::~MainWindow()
{
    delete ui;
}

struct chiItemList{
    std::string itemName;
    std::string quantity;
    std::string totalmoney;
};

std::vector<chiItemList> chi_vector;


//Navigation swich chi-tieu and xuat-chau
void MainWindow::on_xuatchau1Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_thuchi2Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_dateEdit_dateTimeChanged(const QDateTime &dateTime)
{
    // Save date to database
}



void MainWindow::on_muaBtn_clicked()
{
    chiItemList chi_list;
    std::string name = ui->tenmua->toPlainText().toStdString();
    std::string quantity = std::to_string(ui->soluongmua->value());
    std::string totalmoney = ui->sotienmua->toPlainText().toStdString();

    if(name.empty() || totalmoney.empty() || quantity == "0"){
        QMessageBox::information(this,"Thông báo", "Vui lòng điền đầy đủ thông tin!", QMessageBox::Ok);
    }
    else{
        chi_list.itemName = name;
        chi_list.quantity = quantity;
        chi_list.totalmoney = totalmoney;
        chi_vector.push_back(chi_list);
        ui->tongchiList->clear();
        MainWindow::clear_chi_list_view();
        MainWindow::show_chi_list();
    }


}

void MainWindow::show_chi_list()
{
    std::string chi_list;
    for(uint i = 0; i < chi_vector.size(); i++){
        chi_list = chi_vector[i].itemName + ":  " + chi_vector[i].quantity + " -- tổng tiền: " + chi_vector[i].totalmoney;
        ui->tongchiList->addItem(chi_list.c_str());
    }
}

void MainWindow::clear_chi_list_view()
{
    ui->tenmua->clear();
    ui->soluongmua->clear();
    ui->sotienmua->clear();
}



void MainWindow::on_xuatchauBtn_clicked()
{
    QString str = _xuatChau.showListXuatChau();
    ui->listXuatChau->addItem(str);
}

