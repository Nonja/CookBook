#ifndef ADDINGREDIENT_H
#define ADDINGREDIENT_H

#include <QDialog>
#include <QtSql>

#include <QtWidgets>


class AddIngredient : public QDialog
{
    Q_OBJECT

public:
    explicit AddIngredient(QWidget *parent = 0);

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_helpButton_clicked();

private:
    QVBoxLayout *verticalLayout;
    QLabel *addIngredientLabel;
    QFrame *line;
    QFormLayout *formLayout_3;
    QLabel *nameLabel;
    QLineEdit *nameLine;
    QLabel *caloriesLabel;
    QLineEdit *caloriesLine;
    QLabel *proteinsLabel;
    QLineEdit *proteinsLine;
    QLabel *carbohydratesLabel;
    QLineEdit *carbohydratesLine;
    QLabel *fatLabel;
    QLineEdit *fatLine;
    QLabel *fiberLabel;
    QLineEdit *fiberLine;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *helpButton;

};

#endif // ADDINGREDIENT_H
