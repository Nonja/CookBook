#ifndef ADD_H
#define ADD_H

#include <QDialog>

#include <QtWidgets>

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = 0);

private slots:
    void on_addIngredientButton_clicked();

    void on_addRecipeButton_clicked();

    void on_cancelButton_clicked();

private:
    QVBoxLayout *verticalLayout;
    QLabel *addLabel;
    QSplitter *splitter;
    QPushButton *addIngredientButton;
    QPushButton *addRecipeButton;
    QFrame *line;
    QPushButton *cancelButton;
};

#endif // ADD_H
