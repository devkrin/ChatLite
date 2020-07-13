#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QDialog>

namespace Ui {
class HistoryDialog;
}

class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryDialog(QWidget *parent = nullptr);
    ~HistoryDialog();

    void print(QString hisText);

private slots:
    void on_closeBtn_clicked();

private:
    Ui::HistoryDialog *ui;
};

#endif // HISTORYDIALOG_H
