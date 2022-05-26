#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("年龄计算器-程序员小刘");
    this->setMinimumSize(400, 300);
    this->setMaximumSize(400, 300);

    ui->ageLine->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));

    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        QDateTime dateTime(QDateTime::currentDateTime());
        unsigned int age = dateTime.toString("yyyy").toUInt() - ui->ageLine->text().toUInt();
        QString resultText = "你的年龄是";
        resultText += QString::number(age);
        resultText += "岁";
        ui->resultLab->setText(resultText);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

