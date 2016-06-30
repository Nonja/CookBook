#include "find.h"
#include "ingredient.h"
#include "recipe.h"

#include <QApplication>

Find::Find(QWidget *parent) :
    QDialog(parent)
{
    //GUI -elementtien asettelu

    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Find"));

    this->resize(400, 300);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    ingredientsButton = new QPushButton(this);
    ingredientsButton->setObjectName(QStringLiteral("ingredientsButton"));

    horizontalLayout->addWidget(ingredientsButton);

    recipesButton = new QPushButton(this);
    recipesButton->setObjectName(QStringLiteral("recipesButton"));

    horizontalLayout->addWidget(recipesButton);


    verticalLayout->addLayout(horizontalLayout);

    line = new QFrame(this);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout->addWidget(line);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QStringLiteral("cancelButton"));

    verticalLayout->addWidget(cancelButton);


    setWindowTitle(QApplication::translate("Find", "Dialog", 0));
    ingredientsButton->setText(QApplication::translate("Find", "Find ingredients", 0));
    recipesButton->setText(QApplication::translate("Find", "Find recipes", 0));
    cancelButton->setText(QApplication::translate("Find", "Cancel", 0));
    QMetaObject::connectSlotsByName(this);

}


void Find::on_ingredientsButton_clicked()
{
    //avaa raaka-aike -dialogin
    Ingredient *ingredient = new Ingredient;
    ingredient->show();
    this->hide();
}

void Find::on_recipesButton_clicked()
{
    //avaa resepti -dialogin
    Recipe *recipe = new Recipe;
    recipe->show();
    this->hide();
}

void Find::on_cancelButton_clicked()
{
    //sulkee ikkunan
    this->hide();
}
