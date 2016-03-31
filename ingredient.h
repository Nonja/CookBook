#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QDialog>
#include <QtSql>

#include <QtWidgets>

class Ingredient : public QDialog
{
    Q_OBJECT

public:
    explicit Ingredient(QWidget *parent = 0);


private slots:
    void on_findLine_textChanged(const QString &arg1);

    void on_ingredientList_activated(const QModelIndex &index);

    void on_cancelButton_clicked();

    void on_helpButton_clicked();

private:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *cancelButton;
    QPushButton *helpButton;
    QVBoxLayout *verticalLayout;
    QLabel *ingredientLabel;
    QFrame *line;
    QGroupBox *nutrientsBox;
    QGridLayout *gridLayout;
    QLabel *caloriesAmount;
    QLabel *carbohydratesAmount;
    QLabel *proteinsAmount;
    QLabel *proteinsLabel;
    QLabel *carbohydratesLabel;
    QLabel *fiberAmount;
    QLabel *fatLabel;
    QLabel *fiberLabel;
    QLabel *fatAmount;
    QLabel *caloriesLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *findLabel;
    QLineEdit *findLine;
    QListView *ingredientList;
    QFrame *line_2;
};

#endif // INGREDIENT_H
