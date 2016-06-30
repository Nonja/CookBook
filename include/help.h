#ifndef HELP_H
#define HELP_H

#include <QDialog>

#include <QtWidgets>

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = 0);

private slots:
    void on_cancelButton_clicked();

private:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QFrame *line;
    QTextBrowser *helpText;
    QPushButton *cancelButton;
};

#endif // HELP_H
