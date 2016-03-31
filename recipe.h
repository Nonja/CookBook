#ifndef RECIPE_H
#define RECIPE_H

#include <QDialog>
#include <QtSql>

#include <QtWidgets>


class Recipe : public QDialog
{
    Q_OBJECT

public:
    explicit Recipe(QWidget *parent = 0);


private slots:
    void on_findLine_textChanged(const QString &arg1);

    void on_recipeTable_activated(const QModelIndex &index);

    void on_cancelButton_clicked();

    void on_backButton_clicked();

    void on_helpButton_clicked();

private:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *recipeLabel;
    QLabel *descLabel;
    QPushButton *backButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *findLabel;
    QLineEdit *findLine;
    QTableView *recipeTable;
    QPushButton *cancelButton;
    QPushButton *helpButton;

};

#endif // RECIPE_H
