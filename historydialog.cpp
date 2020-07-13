#include "historydialog.h"
#include "ui_historydialog.h"

HistoryDialog::HistoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryDialog)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

HistoryDialog::~HistoryDialog()
{
    delete ui;
}

void HistoryDialog::print(QString hisText)
{
    ui->historyContent->clear();
    ui->historyContent->append(hisText);
}

void HistoryDialog::on_closeBtn_clicked()
{
    close();
}
