#ifndef XUATCHAU_H
#define XUATCHAU_H

#include <QObject>

class XuatChau : public QObject
{
    Q_OBJECT


public:
    explicit XuatChau(QObject *parent = nullptr);
    struct listXuatChau{
        QString tenChau;
        int soLuong;
        QString doiTuong;
        int tongTien;
        int daTra;
    };

    void getInfo(QString tenChau, int soLuong, QString doiTuong, int tongTien, int daTra);
    void saveInfo(XuatChau::listXuatChau);
    QString showListXuatChau();


};


#endif // XUATCHAU_H
