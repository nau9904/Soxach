#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTimeEdit>
#include <XuatChau.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:


private slots:


    void on_xuatchau1Button_clicked();

    void on_thuchi2Button_clicked();

    void on_dateEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_muaBtn_clicked();



    void on_xuatchauBtn_clicked();

private:
    Ui::MainWindow *ui;
    XuatChau _xuatChau;

    void show_chi_list();
    void clear_chi_list_view();

};
#endif // MAINWINDOW_H
