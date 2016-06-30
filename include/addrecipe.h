#ifndef ADDRECIPE_H
#define ADDRECIPE_H

#include <QDialog>
#include <QtSql>

#include <QtWidgets>

class AddRecipe : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipe(QWidget *parent = 0);

private slots:
    void on_addButton_clicked();

    void on_findLine_textChanged(const QString &arg1);

    void on_ingredientButton_clicked();

    void on_ingredientList_activated(const QModelIndex &index);

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_helpButton_clicked();

private:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLine;
    QLabel *descLabel;
    QLineEdit *descLine;
    QHBoxLayout *horizontalLayout;
    QLabel *addRecipeLabel;
    QLabel *descriptLabel;
    QPushButton *ingredientButton;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *saveButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QTableView *recipeTable;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *findLine;
    QListView *ingredientList;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *ingredientLine;
    QSpinBox *amountSpinbox;
    QLabel *label_2;
    QPushButton *helpButton;


};

#endif // ADDRECIPE_H
