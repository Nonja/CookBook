#include "add.h"
#include "addingredient.h"
#include "addrecipe.h"

#include <QApplication>

Add::Add(QWidget *parent) :
    QDialog(parent)

{
    //GUI -elementtien asettelu
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Add"));

    resize(400, 300);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    addLabel = new QLabel(this);
    addLabel->setObjectName(QStringLiteral("addLabel"));
    QFont font;
    font.setPointSize(24);
    addLabel->setFont(font);

    verticalLayout->addWidget(addLabel);

    splitter = new QSplitter(this);
    splitter->setObjectName(QStringLiteral("splitter"));
    splitter->setOrientation(Qt::Horizontal);
    addIngredientButton = new QPushButton(splitter);
    addIngredientButton->setObjectName(QStringLiteral("addIngredientButton"));
    splitter->addWidget(addIngredientButton);
    addRecipeButton = new QPushButton(splitter);
    addRecipeButton->setObjectName(QStringLiteral("addRecipeButton"));
    splitter->addWidget(addRecipeButton);

    verticalLayout->addWidget(splitter);

    line = new QFrame(this);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout->addWidget(line);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QStringLiteral("cancelButton"));

    verticalLayout->addWidget(cancelButton);

    setWindowTitle(QApplication::translate("Add", "Dialog", 0));
    addLabel->setText(QApplication::translate("Add", "Add new..", 0));
    addIngredientButton->setText(QApplication::translate("Add", "Ingredient", 0));
    addRecipeButton->setText(QApplication::translate("Add", "Recipe", 0));
    cancelButton->setText(QApplication::translate("Add", "Cancel", 0));

    QMetaObject::connectSlotsByName(this);

}


void Add::on_addIngredientButton_clicked()
{
    //avaa uusiraakaaine -dialogin
    this->hide();
    AddIngredient *addIngredient = new AddIngredient;
    addIngredient->exec();
}

void Add::on_addRecipeButton_clicked()
{
    //avaa uusiresepti -dialogin
    this->hide();
    AddRecipe *addRecipe = new AddRecipe;
    addRecipe->exec();
}

void Add::on_cancelButton_clicked()
{
    //sulkee ikkunan
    this->hide();

}
