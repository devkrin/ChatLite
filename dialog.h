#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <informdialog.h>
#include <mediarcvdialog.h>
#include <mediasenddialog.h>
#include <historydialog.h>

struct User{
    bool    bOnline;			// 是否在线，在线为true
    int     iGroup;             // 所属分组的SQL index
    QString sId;                // 账号
    QString sIp;                // ip地址
    QString sName;              // 昵称
    QString sIcon;              // 头像路径
};

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:

    /*----------------------需被外部调用的接口 开始----------------------*/

    Dialog(QWidget *parent = nullptr, struct User *guest = nullptr, struct User *me = nullptr);     //传入对方用户构造体与本地用户构造体指针


    void recvMsg(QString msg);  //接受信息字符串接口，直接传入消息体

    void changeStatus();        //远程对话用户状态改变时通知(对方下线/上线)的接口, 根据创建时传入的user指针判断

    QString rcvFile(QString fileName);  //询问是否接收文件接口，传入文件名称以及保存函数指针，若接受则返回文件保存路径，否则返回空字符串

    /*----------------------需被外部调用的接口 结束---------------------*/



    /*----------------------会调用外部接口的方法(待配合实现) 开始----------------------*/

    void sendMsg(QString msg);
    void sendFile(QString filePath);
    void saveHistory(QString hisContent);
    QString getHistory();

    /*----------------------会调用外部接口的方法(待配合实现) 结束----------------------*/


    ~Dialog();

    void updateMsgBrowser(QString, bool = true);

private slots:
    void on_sendBtn_clicked();

    void on_mediaBtn_clicked();

    void on_exitBtn_clicked();

    void on_closeBtn_clicked();

    void on_pushButton_clicked();

    void on_historyBtn_clicked();

    void on_emojiBtn_clicked();

    void on_msgInput_textChanged();

private:
    Ui::Dialog *ui;

    InformDialog *popInfo;
    MediaRcvDialog *rcvMedia;
    MediaSendDialog *sendMedia;
    HistoryDialog *hisPanel;

    enum INFOTYPE {
        NORMAL = 0,
        USELESSINPUT = 1,
        FRIENDOFFLINE = 2,
        FRIENDONLINE = 3
    };

    struct User *guest, *me;

    void inform(INFOTYPE, QString = nullptr);
    void funcStatusChange(bool);
    void updateWindow();
};
#endif // DIALOG_H
