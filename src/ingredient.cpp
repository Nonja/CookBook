#include "ingredient.h"
#include "help.h"

#include <QMessageBox>
#include <QApplication>

Ingredient::Ingredient(QWidget *parent) :
    QDialog(parent)
{
    //GUI -elementtien asettelu
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Ingredient"));

    resize(943, 600);
    gridLayout_2 = new QGridLayout(this);
    gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QStringLiteral("cancelButton"));

    verticalLayout_2->addWidget(cancelButton);

    helpButton = new QPushButton(this);
    helpButton->setObjectName(QStringLiteral("helpButton"));

    verticalLayout_2->addWidget(helpButton);


    gridLayout_2->addLayout(verticalLayout_2, 2, 0, 1, 3);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    ingredientLabel = new QLabel(this);
    ingredientLabel->setObjectName(QStringLiteral("ingredientLabel"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(ingredientLabel->sizePolicy().hasHeightForWidth());
    ingredientLabel->setSizePolicy(sizePolicy);
    ingredientLabel->setMinimumSize(QSize(300, 0));
    QFont font;
    font.setPointSize(24);
    ingredientLabel->setFont(font);

    verticalLayout->addWidget(ingredientLabel);

    line = new QFrame(this);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout->addWidget(line);

    nutrientsBox = new QGroupBox(this);
    nutrientsBox->setObjectName(QStringLiteral("nutrientsBox"));
    QFont font1;
    font1.setPointSize(10);
    nutrientsBox->setFont(font1);
    gridLayout = new QGridLayout(nutrientsBox);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    caloriesAmount = new QLabel(nutrientsBox);
    caloriesAmount->setObjectName(QStringLiteral("caloriesAmount"));
    caloriesAmount->setFont(font1);

    gridLayout->addWidget(caloriesAmount, 0, 1, 1, 1);

    carbohydratesAmount = new QLabel(nutrientsBox);
    carbohydratesAmount->setObjectName(QStringLiteral("carbohydratesAmount"));
    carbohydratesAmount->setFont(font1);

    gridLayout->addWidget(carbohydratesAmount, 2, 1, 1, 1);

    proteinsAmount = new QLabel(nutrientsBox);
    proteinsAmount->setObjectName(QStringLiteral("proteinsAmount"));
    proteinsAmount->setFont(font1);

    gridLayout->addWidget(proteinsAmount, 1, 1, 1, 1);

    proteinsLabel = new QLabel(nutrientsBox);
    proteinsLabel->setObjectName(QStringLiteral("proteinsLabel"));
    proteinsLabel->setFont(font1);

    gridLayout->addWidget(proteinsLabel, 1, 0, 1, 1);

    carbohydratesLabel = new QLabel(nutrientsBox);
    carbohydratesLabel->setObjectName(QStringLiteral("carbohydratesLabel"));
    carbohydratesLabel->setFont(font1);

    gridLayout->addWidget(carbohydratesLabel, 2, 0, 1, 1);

    fiberAmount = new QLabel(nutrientsBox);
    fiberAmount->setObjectName(QStringLiteral("fiberAmount"));
    fiberAmount->setFont(font1);

    gridLayout->addWidget(fiberAmount, 4, 1, 1, 1);

    fatLabel = new QLabel(nutrientsBox);
    fatLabel->setObjectName(QStringLiteral("fatLabel"));
    fatLabel->setFont(font1);

    gridLayout->addWidget(fatLabel, 3, 0, 1, 1);

    fiberLabel = new QLabel(nutrientsBox);
    fiberLabel->setObjectName(QStringLiteral("fiberLabel"));
    fiberLabel->setFont(font1);

    gridLayout->addWidget(fiberLabel, 4, 0, 1, 1);

    fatAmount = new QLabel(nutrientsBox);
    fatAmount->setObjectName(QStringLiteral("fatAmount"));
    fatAmount->setFont(font1);

    gridLayout->addWidget(fatAmount, 3, 1, 1, 1);

    caloriesLabel = new QLabel(nutrientsBox);
    caloriesLabel->setObjectName(QStringLiteral("caloriesLabel"));
    caloriesLabel->setFont(font1);

    gridLayout->addWidget(caloriesLabel, 0, 0, 1, 1);


    verticalLayout->addWidget(nutrientsBox);


    gridLayout_2->addLayout(verticalLayout, 0, 0, 2, 1);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    findLabel = new QLabel(this);
    findLabel->setObjectName(QStringLiteral("findLabel"));

    horizontalLayout_2->addWidget(findLabel);

    findLine = new QLineEdit(this);
    findLine->setObjectName(QStringLiteral("findLine"));

    horizontalLayout_2->addWidget(findLine);


    gridLayout_2->addLayout(horizontalLayout_2, 0, 2, 1, 1);

    ingredientList = new QListView(this);
    ingredientList->setObjectName(QStringLiteral("ingredientList"));

    gridLayout_2->addWidget(ingredientList, 1, 2, 1, 1);

    line_2 = new QFrame(this);
    line_2->setObjectName(QStringLiteral("line_2"));
    line_2->setFrameShape(QFrame::VLine);
    line_2->setFrameShadow(QFrame::Sunken);

    gridLayout_2->addWidget(line_2, 1, 1, 1, 1);

    setWindowTitle(QApplication::translate("Ingredient", "Form", 0));
    cancelButton->setText(QApplication::translate("Ingredient", "Cancel", 0));
    helpButton->setText(QApplication::translate("Ingredient", "Help", 0));
    ingredientLabel->setText(QApplication::translate("Ingredient", "Ingredient              ", 0));
    nutrientsBox->setTitle(QApplication::translate("Ingredient", "Nutrients", 0));
    caloriesAmount->setText(QApplication::translate("Ingredient", "TextLabel", 0));
    carbohydratesAmount->setText(QApplication::translate("Ingredient", "TextLabel", 0));
    proteinsAmount->setText(QApplication::translate("Ingredient", "TextLabel", 0));
    proteinsLabel->setText(QApplication::translate("Ingredient", "Proteins/100g:", 0));
    carbohydratesLabel->setText(QApplication::translate("Ingredient", "Carbohydrates/100g:", 0));
    fiberAmount->setText(QApplication::translate("Ingredient", "TextLabel", 0));
    fatLabel->setText(QApplication::translate("Ingredient", "Fat/100g:", 0));
    fiberLabel->setText(QApplication::translate("Ingredient", "Fiber/100g:", 0));
    fatAmount->setText(QApplication::translate("Ingredient", "TextLabel", 0));
    caloriesLabel->setText(QApplication::translate("Ingredient", "Calories/100g:", 0));
    findLabel->setText(QApplication::translate("Ingredient", "Find", 0));
    QMetaObject::connectSlotsByName(this);


    QSqlQueryModel *table = new QSqlQueryModel();
    table->setQuery("select name from INGREDIENTS");
    ingredientList->setModel(table);
}



void Ingredient::on_findLine_textChanged(const QString &arg1)
{
    //päivittää taulun käyttäjän syöttämiin hakuehtoihin sopivaksi
    QSqlQueryModel *qry = new QSqlQueryModel();

    qry->setQuery("select name from INGREDIENTS where name LIKE '"+arg1+"%'");
    ingredientList->setModel(qry);
}



void Ingredient::on_ingredientList_activated(const QModelIndex &index)
{
    //näyttää valitun raaka-aineen ravintoarvot
    QString val=ingredientList->model()->data(index).toString();

    QSqlQuery qry("select * from INGREDIENTS where name ='"+val+"' or calories ='"+val+"' or proteins ='"+val+"' or carbohydrates='"+val+"' or fat ='"+val+"' or fiber ='"+val+"'");


    while(qry.next())

    {
        ingredientLabel->setText(qry.value(1).toString());
        caloriesAmount->setText(qry.value(2).toString());
        proteinsAmount->setText(qry.value(3).toString());
        carbohydratesAmount->setText(qry.value(4).toString());
        fatAmount->setText(qry.value(5).toString());
        fiberAmount->setText(qry.value(6).toString());
    }

}

void Ingredient::on_cancelButton_clicked()
{
    //sulkee ikkunan
    hide();
}

void Ingredient::on_helpButton_clicked()
{
    //avaa ohjeet -dialogin
    Help *help = new Help;
    help->exec();
}
