#include "addingredient.h"
#include "help.h"

#include <QMessageBox>
#include <QApplication>

AddIngredient::AddIngredient(QWidget *parent) :
    QDialog(parent)
{
    //GUI -elementtien asettelu
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("AddIngredient"));

    this->resize(800, 600);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    addIngredientLabel = new QLabel(this);
    addIngredientLabel->setObjectName(QStringLiteral("addIngredientLabel"));
    QFont font;
    font.setPointSize(24);
    addIngredientLabel->setFont(font);

    verticalLayout->addWidget(addIngredientLabel);

    line = new QFrame(this);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout->addWidget(line);

    formLayout_3 = new QFormLayout();
    formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
    formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    nameLabel = new QLabel(this);
    nameLabel->setObjectName(QStringLiteral("nameLabel"));

    formLayout_3->setWidget(0, QFormLayout::LabelRole, nameLabel);

    nameLine = new QLineEdit(this);
    nameLine->setObjectName(QStringLiteral("nameLine"));

    formLayout_3->setWidget(0, QFormLayout::FieldRole, nameLine);

    caloriesLabel = new QLabel(this);
    caloriesLabel->setObjectName(QStringLiteral("caloriesLabel"));

    formLayout_3->setWidget(1, QFormLayout::LabelRole, caloriesLabel);

    caloriesLine = new QLineEdit(this);
    caloriesLine->setObjectName(QStringLiteral("caloriesLine"));

    formLayout_3->setWidget(1, QFormLayout::FieldRole, caloriesLine);

    proteinsLabel = new QLabel(this);
    proteinsLabel->setObjectName(QStringLiteral("proteinsLabel"));

    formLayout_3->setWidget(2, QFormLayout::LabelRole, proteinsLabel);

    proteinsLine = new QLineEdit(this);
    proteinsLine->setObjectName(QStringLiteral("proteinsLine"));

    formLayout_3->setWidget(2, QFormLayout::FieldRole, proteinsLine);

    carbohydratesLabel = new QLabel(this);
    carbohydratesLabel->setObjectName(QStringLiteral("carbohydratesLabel"));

    formLayout_3->setWidget(3, QFormLayout::LabelRole, carbohydratesLabel);

    carbohydratesLine = new QLineEdit(this);
    carbohydratesLine->setObjectName(QStringLiteral("carbohydratesLine"));

    formLayout_3->setWidget(3, QFormLayout::FieldRole, carbohydratesLine);

    fatLabel = new QLabel(this);
    fatLabel->setObjectName(QStringLiteral("fatLabel"));

    formLayout_3->setWidget(4, QFormLayout::LabelRole, fatLabel);

    fatLine = new QLineEdit(this);
    fatLine->setObjectName(QStringLiteral("fatLine"));

    formLayout_3->setWidget(4, QFormLayout::FieldRole, fatLine);

    fiberLabel = new QLabel(this);
    fiberLabel->setObjectName(QStringLiteral("fiberLabel"));

    formLayout_3->setWidget(5, QFormLayout::LabelRole, fiberLabel);

    fiberLine = new QLineEdit(this);
    fiberLine->setObjectName(QStringLiteral("fiberLine"));

    formLayout_3->setWidget(5, QFormLayout::FieldRole, fiberLine);


    verticalLayout->addLayout(formLayout_3);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    saveButton = new QPushButton(this);
    saveButton->setObjectName(QStringLiteral("saveButton"));

    horizontalLayout_2->addWidget(saveButton);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QStringLiteral("cancelButton"));

    horizontalLayout_2->addWidget(cancelButton);


    verticalLayout->addLayout(horizontalLayout_2);

    helpButton = new QPushButton(this);
    helpButton->setObjectName(QStringLiteral("helpButton"));


    verticalLayout->addWidget(helpButton);

    setWindowTitle(QApplication::translate("AddIngredient", "Dialog", 0));
    addIngredientLabel->setText(QApplication::translate("AddIngredient", "Add ingredient", 0));
    nameLabel->setText(QApplication::translate("AddIngredient", "Name", 0));
    caloriesLabel->setText(QApplication::translate("AddIngredient", "Calories/100g", 0));
    proteinsLabel->setText(QApplication::translate("AddIngredient", "Protein/100g", 0));
    carbohydratesLabel->setText(QApplication::translate("AddIngredient", "Carbohydrates/100g", 0));
    fatLabel->setText(QApplication::translate("AddIngredient", "Fat/100g", 0));
    fiberLabel->setText(QApplication::translate("AddIngredient", "Fiber/100g", 0));
    saveButton->setText(QApplication::translate("AddIngredient", "Save", 0));
    cancelButton->setText(QApplication::translate("AddIngredient", "Cancel", 0));
    helpButton->setText(QApplication::translate("AddIngredient", "Help", 0));

    QMetaObject::connectSlotsByName(this);
}


void AddIngredient::on_saveButton_clicked()
{
    //lisää raaka-aineen tietokantaan
    QSqlQuery qry;
    qry.prepare("insert into INGREDIENTS values (NULL, :name, :calories, :proteins, :carbohydrates, :fat, :fiber)");

    qry.bindValue(":name", nameLine->text());
    qry.bindValue(":calories", caloriesLine->text());
    qry.bindValue(":proteins", proteinsLine->text());
    qry.bindValue(":carbohydrates", carbohydratesLine->text());
    qry.bindValue(":fat", fatLine->text());
    qry.bindValue(":fiber", fiberLine->text());


    if(qry.exec()){

        QMessageBox::information(this, tr("Save"), ("Ingredient added"));
        this->hide();
    }
    else {

        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }

}

void AddIngredient::on_cancelButton_clicked()
{
    //sulkee ikkunan
    this->hide();
}

void AddIngredient::on_helpButton_clicked()
{
    //avaa ohjeet -dialogin
    Help *help = new Help;
    help->exec();
}
