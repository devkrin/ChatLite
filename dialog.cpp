#include "dialog.h"
#include "ui_dialog.h"
#include <QDateTime>
#include <QFileDialog>

Dialog::Dialog(QWidget *parent, struct User *g, struct User *m)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    popInfo = new InformDialog(this);
    rcvMedia = new MediaRcvDialog(this);
    sendMedia = new MediaSendDialog(this);
    hisPanel = new HistoryDialog(this);

    ui->msgInput->clear();
    ui->mediaWidge->setVisible(false);

    /*--------------test only-------------*/
    struct User u1, u2;

    u1.bOnline = true;
    u1.sId = "lily@qq.com";
    u1.sIp = "192.168.31.1";
    u1.sName = "Lily";
    u1.sIcon = "D:/";
    u1.iGroup = 1;

    u2.bOnline = true;
    u2.sId = "11111";
    u2.sIp = "192.168.31.1";
    u2.sName = "Krin";
    u2.sIcon = "D:/";
    u2.iGroup = 1;

    g = &u1;
    m = &u2;
    /*--------------end-------------*/

    guest=g;
    me=m;

    if(guest==nullptr||me==nullptr) {
        qDebug("无效的参数，聊天窗口启动失败");
        exit(0);
    }

    changeStatus();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::recvMsg(QString msg)
{
    updateMsgBrowser(msg, false);
}

void Dialog::changeStatus()
{

    if (Dialog::guest->bOnline) {
        inform(INFOTYPE::FRIENDONLINE);
        funcStatusChange(true);
    } else {
        inform(INFOTYPE::FRIENDOFFLINE);
        funcStatusChange(false);
    }
    updateWindow();
}

QString Dialog::rcvFile(QString fileName)
{
    QString filePath = rcvMedia->saveFile(fileName);
    return filePath;
}

void Dialog::sendMsg(QString msg)
{

}

void Dialog::sendFile(QString filePath)
{
    updateMsgBrowser("发送了文件：" + filePath);
    //xxx.sendFile(guest, filePath);    // TODO 调用qt发送文件模块
}

void Dialog::saveHistory(QString hisContent)
{

}

QString Dialog::getHistory()
{
    //TODO
    return "这是一个测试";
}

void Dialog::updateMsgBrowser(QString msg, bool isLocal)
{
    QString preStr = isLocal ? "Dialog::me->sName" : "Dialog::guest->sName";    // 有bug, 还没容错
    QDateTime time = QDateTime::currentDateTime();
    preStr += time.toString(" yyyy-MM-dd hh:mm:ss");
    ui->winMsg->append(preStr);
    ui->winMsg->append(msg+"\n");
}

void Dialog::inform(Dialog::INFOTYPE msgType, QString info)
{
    switch (msgType) {
    case Dialog::INFOTYPE::NORMAL:
        popInfo->print(info);
        break;
    case Dialog::INFOTYPE::USELESSINPUT:
        popInfo->print("你还没有输入任何东西哦");
        break;
    case Dialog::INFOTYPE::FRIENDONLINE:
        popInfo->print("你的好友"+guest->sName+"上线了！");
        break;
    case Dialog::INFOTYPE::FRIENDOFFLINE:
        popInfo->print("你的好友"+guest->sName+"已下线！");
        break;
    default:
        break;
    }
}

void Dialog::funcStatusChange(bool isEnabled)
{
    ui->inputFrame->setEnabled(isEnabled);
}

void Dialog::updateWindow()
{
    ui->gStatus->setText((guest->bOnline)?("正在和"+guest->sName+"聊天"):(guest->sName+"已离线"));
    ui->gAccount->setText(guest->sId);
    ui->gIp->setText(guest->sIp);
    ui->gName->setText(guest->sName);
    ui->gGroup->setText("来自组：");
    ui->gIcon->setStyleSheet("image: url(:/assets/110.png);border-color: rgb(255, 255, 255);border: 10px;");
}

void Dialog::on_sendBtn_clicked()
{
    QString msgOut = ui->msgInput->toPlainText();
    if("" ==(msgOut = msgOut.trimmed())) {
        ui->msgInput->clear();
        inform(INFOTYPE::USELESSINPUT);
        return;
    }
    updateMsgBrowser(msgOut);

    sendMsg(msgOut);

    ui->msgInput->clear();

}

void Dialog::on_mediaBtn_clicked()
{
    ui->mediaWidge->setVisible(true);
}

void Dialog::on_exitBtn_clicked()
{
    saveHistory(ui->winMsg->toPlainText());
    exit(0);
}

void Dialog::on_closeBtn_clicked()
{
    ui->mediaWidge->setVisible(false);
}

void Dialog::on_pushButton_clicked()
{
    sendMedia->comfirm();
    ui->mediaWidge->setVisible(false);
}

void Dialog::on_historyBtn_clicked()
{
    hisPanel->print(getHistory());
    hisPanel->show();
}

void Dialog::on_emojiBtn_clicked()
{
    rcvMedia->show();
    ui->mediaWidge->close();
}

void Dialog::on_msgInput_textChanged()
{

}
