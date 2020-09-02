#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QDebug>

using namespace std;

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    //String notation
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeText()));

    //Functor notation : Regular slots
    //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::changeText);

    //Functor notation : Lambdas
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->label->setText("Lambda");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
   qDebug() << "Secret Number generated: ";
   ui->label->setText("Hello there");
}



