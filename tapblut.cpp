#include "tapblut.h"
#include "ui_tapblut.h"

tapblut::tapblut(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tapblut)
    , agent(new QBluetoothDeviceDiscoveryAgent(this))
    , socket(new QBluetoothSocket)
{
    ui->setupUi(this);

    connect(agent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &tapblut::device_descovered);
    agent->start();
}

tapblut::~tapblut()
{
    delete agent;
    delete socket;
    delete ui;
}


void tapblut::on_find_clicked()
{
    ui->combo->show();
    ui->combo->clear();
    agent->stop();
    agent->start();
}


void tapblut::on_on_clicked()
{

}


void tapblut::on_off_clicked()
{

}

void tapblut::device_descovered(const QBluetoothDeviceInfo &device)
{
    ui->combo->addItem(device.address().toString());
}


void tapblut::on_combo_currentTextChanged(const QString &arg1)
{
    str = arg1;

    ui->combo->addItem(str);
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9bB34FB"));

    socket->connectToService(QBluetoothAddress(str), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);

}

