#include "mediasenddialog.h"
#include "ui_mediasenddialog.h"
#include "dialog.h"

MediaSendDialog::MediaSendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MediaSendDialog)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->fileNameLabel->setAttribute(Qt::WA_TranslucentBackground);
}

MediaSendDialog::~MediaSendDialog()
{
    delete ui;
}

int MediaSendDialog::comfirm()
{
    QString fileName;
    if (""!=(fileName=  openFile())){
        ui->fileNameLabel->setPlainText(fileName);
        show();
    }
    return 0;
}

void MediaSendDialog::on_cancelBtn_clicked()
{
    close();
}

void MediaSendDialog::on_changeBtn_clicked()
{
    comfirm();
}

void MediaSendDialog::on_confirmBtn_clicked()
{
    QString filePath = ui->fileNameLabel->toPlainText();
    qobject_cast<Dialog*>(parentWidget())->sendFile(filePath);
    close();
}

QString MediaSendDialog::openFile()
{
    return QFileDialog::getOpenFileName(nullptr,"选择文件",QString("."),QString("*.*"),0,0);
}

