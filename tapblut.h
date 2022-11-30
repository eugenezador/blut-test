#ifndef TAPBLUT_H
#define TAPBLUT_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QtBluetooth>

QT_BEGIN_NAMESPACE
namespace Ui { class tapblut; }
QT_END_NAMESPACE

class tapblut : public QMainWindow
{
    Q_OBJECT

public:
    tapblut(QWidget *parent = nullptr);
    ~tapblut();

private slots:
    void on_find_clicked();

    void on_on_clicked();

    void on_off_clicked();

    void device_descovered(const QBluetoothDeviceInfo &device);


    void on_combo_currentTextChanged(const QString &arg1);

private:
    Ui::tapblut *ui;

    QBluetoothDeviceDiscoveryAgent *agent = nullptr;

    QBluetoothSocket *socket = nullptr;

    QString str;
};
#endif // TAPBLUT_H
