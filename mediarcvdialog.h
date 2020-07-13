#ifndef MEDIARCVDIALOG_H
#define MEDIARCVDIALOG_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class MediaRcvDialog;
}

class MediaRcvDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MediaRcvDialog(QWidget *parent = nullptr);
    ~MediaRcvDialog();

    QString saveFile(QString fileName);
    QString openDir();

private slots:
    void on_cancelBtn_clicked();

    void on_acceptBtn_clicked();

private:
    Ui::MediaRcvDialog *ui;

    QString fileSavePath;
    bool isAnswered;
};

#endif // MEDIARCVDIALOG_H
