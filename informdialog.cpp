#include "informdialog.h"
#include "ui_informdialog.h"

InformDialog::InformDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

InformDialog::~InformDialog()
{
    delete ui;
}

void InformDialog::print(QString info)
{
    ui->infoContent->clear();
    ui->infoContent->insertPlainText(info);
    this->show();
}

void InformDialog::on_closeBtn_clicked()
{
    this->close();
}
