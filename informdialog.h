#ifndef INFORMDIALOG_H
#define INFORMDIALOG_H

#include <QDialog>

namespace Ui {
class InformDialog;
}

class InformDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InformDialog(QWidget *parent = nullptr);
    ~InformDialog();

    void print(QString innfo);

private slots:
    void on_closeBtn_clicked();

private:
    Ui::InformDialog *ui;
};

#endif // INFORMDIALOG_H
