#include "mediarcvdialog.h"
#include "ui_mediarcvdialog.h"
#include "dialog.h"

MediaRcvDialog::MediaRcvDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MediaRcvDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->discInfoLabel->setAttribute(Qt::WA_TranslucentBackground);
    ui->fileNameLabel->setAttribute(Qt::WA_TranslucentBackground);

    fileSavePath = "";
    isAnswered = false;
}

MediaRcvDialog::~MediaRcvDialog()
{
    delete ui;
}

QString MediaRcvDialog::saveFile(QString fileName)
{
    ui->fileNameLabel->setText(fileName);
    show();
    do {
        if (isAnswered){
            isAnswered=false;
            qobject_cast<Dialog*>(parentWidget())->updateMsgBrowser("接收了文件：" + fileName);
            return fileSavePath;
        }
    }while (!isAnswered);
}

QString MediaRcvDialog::openDir()
{
    return QFileDialog::getSaveFileName(nullptr,"选择保存的位置",QString("."),QString("*.*"),0,0);
}

void MediaRcvDialog::on_cancelBtn_clicked()
{
    fileSavePath="";
    isAnswered=false;
    close();
}

void MediaRcvDialog::on_acceptBtn_clicked()
{
    fileSavePath= openDir();
    isAnswered=true;
    close();
}
