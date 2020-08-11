#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>
Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkButtonStatus();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);
    checkButtonStatus();
}
void Widget::checkButtonStatus()
{
    if(money<100)
    {
        ui->pbcoffee->setEnabled(false);
        ui->pbtea->setEnabled(false);
        ui->pbmilk->setEnabled(false);
    }
    else if(money<150)
    {
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(false);
        ui->pbmilk->setEnabled(false);
    }
    else if(money<200)
    {
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbmilk->setEnabled(false);
    }
    else
    {
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbmilk->setEnabled(true);
    }
}
void Widget::calculateMoney()
{
    int retm=money;
    QString mText="";
    int money500=retm/500;
    retm-=money500*500;
    mText+="500: "+QString::number(money500)+", ";
    int money100=retm/100;
    retm-=money100*100;
    mText+="100: "+QString::number(money100)+", ";
    int money50=retm/50;
    retm-=money50*50;
    mText+="50: "+QString::number(money50)+", ";
    int money10=retm/10;
    retm-=money10*10;
    mText+="10: "+QString::number(money10);
    QMessageBox m;
    m.information(nullptr,"Calculate",mText);
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbtea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbmilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbreset_clicked()
{
    calculateMoney();
    changeMoney(-money);
}
