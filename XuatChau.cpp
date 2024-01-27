#include "XuatChau.h"
#include <QDebug>


std::vector<XuatChau::listXuatChau> vector;

XuatChau::XuatChau(QObject *parent) : QObject{parent}{

}


void XuatChau::getInfo(QString tenChau, int soLuong, QString doiTuong, int tongTien, int daTra)
{
    listXuatChau lsXuatChau;
    lsXuatChau.tenChau = tenChau;
    lsXuatChau.soLuong = soLuong;
    lsXuatChau.doiTuong = doiTuong;
    lsXuatChau.tongTien = tongTien;
    lsXuatChau.daTra = daTra;
    vector.push_back(lsXuatChau);
}

void XuatChau::saveInfo(XuatChau::listXuatChau list)
{
    vector.push_back(list);
}

QString XuatChau::showListXuatChau()
{
    QString list;
    for(uint i = 0; i < vector.size(); i++){
        list = "Đã xuất: "
               + QString("%1").arg(vector[i].soLuong)
               + vector[i].tenChau
               + "(" + vector[i].doiTuong + ")"
               + QString().arg(vector[i].daTra) + "/"
               + QString().arg(vector[i].tongTien);
    }
    return list;
}
