#ifndef MEDIASENDDIALOG_H
#define MEDIASENDDIALOG_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class MediaSendDialog;
}

class MediaSendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MediaSendDialog(QWidget *parent = nullptr);
    ~MediaSendDialog();

    int comfirm();

private slots:
    void on_cancelBtn_clicked();

    void on_changeBtn_clicked();

    void on_confirmBtn_clicked();

private:
    Ui::MediaSendDialog *ui;

    QString openFile();
};

#endif // MEDIASENDDIALOG_H
