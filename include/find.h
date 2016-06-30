#ifndef FIND_H
#define FIND_H

#include <QDialog>
#include <QtSql>

#include <QtWidgets>



class Find : public QDialog
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = 0);

private slots:

    void on_ingredientsButton_clicked();

    void on_recipesButton_clicked();

    void on_cancelButton_clicked();

private:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ingredientsButton;
    QPushButton *recipesButton;
    QFrame *line;
    QPushButton *cancelButton;



};

#endif // FIND_H
