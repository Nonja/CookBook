#include "addrecipe.h"
#include "help.h"

#include <QMessageBox>
#include <QApplication>


AddRecipe::AddRecipe(QWidget *parent) :
    QDialog(parent)
{
    //GUI -elementtien asettelu
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("AddRecipe"));

    resize(800, 600);
    gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    formLayout = new QFormLayout();
    formLayout->setObjectName(QStringLiteral("formLayout"));
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    nameLabel = new QLabel(this);
    nameLabel->setObjectName(QStringLiteral("nameLabel"));

    formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

    nameLine = new QLineEdit(this);
    nameLine->setObjectName(QStringLiteral("nameLine"));

    formLayout->setWidget(0, QFormLayout::FieldRole, nameLine);

    descriptLabel = new QLabel(this);
    descriptLabel->setObjectName(QStringLiteral("descriptLabel"));

    formLayout->setWidget(1, QFormLayout::LabelRole, descriptLabel);

    descLine = new QLineEdit(this);
    descLine->setObjectName(QStringLiteral("descLine"));

    formLayout->setWidget(1, QFormLayout::FieldRole, descLine);


    gridLayout->addLayout(formLayout, 0, 0, 1, 2);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    addRecipeLabel = new QLabel(this);
    addRecipeLabel->setObjectName(QStringLiteral("addRecipeLabel"));
    QFont font;
    font.setPointSize(24);
    addRecipeLabel->setFont(font);

    horizontalLayout->addWidget(addRecipeLabel);

    descLabel = new QLabel(this);
    descLabel->setObjectName(QStringLiteral("descLabel"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(descLabel->sizePolicy().hasHeightForWidth());
    descLabel->setSizePolicy(sizePolicy);

    horizontalLayout->addWidget(descLabel);


    gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);

    ingredientButton = new QPushButton(this);
    ingredientButton->setObjectName(QStringLiteral("ingredientButton"));

    gridLayout->addWidget(ingredientButton, 7, 1, 1, 1);

    addButton = new QPushButton(this);
    addButton->setObjectName(QStringLiteral("addButton"));

    gridLayout->addWidget(addButton, 1, 0, 1, 1);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QStringLiteral("cancelButton"));

    gridLayout->addWidget(cancelButton, 1, 1, 1, 1);

    line = new QFrame(this);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    gridLayout->addWidget(line, 4, 0, 1, 2);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
    saveButton = new QPushButton(this);
    saveButton->setObjectName(QStringLiteral("saveButton"));

    horizontalLayout_5->addWidget(saveButton);


    gridLayout->addLayout(horizontalLayout_5, 7, 0, 1, 1);

    groupBox_2 = new QGroupBox(this);
    groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
    horizontalLayout_4 = new QHBoxLayout(groupBox_2);
    horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
    recipeTable = new QTableView(groupBox_2);
    recipeTable->setObjectName(QStringLiteral("recipeTable"));

    horizontalLayout_4->addWidget(recipeTable);


    gridLayout->addWidget(groupBox_2, 6, 0, 1, 1);

    groupBox = new QGroupBox(this);
    groupBox->setObjectName(QStringLiteral("groupBox"));
    QFont font1;
    font1.setBold(false);
    font1.setWeight(50);
    groupBox->setFont(font1);
    verticalLayout = new QVBoxLayout(groupBox);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    findLine = new QLineEdit(groupBox);
    findLine->setObjectName(QStringLiteral("findLine"));

    verticalLayout->addWidget(findLine);

    ingredientList = new QListView(groupBox);
    ingredientList->setObjectName(QStringLiteral("ingredientList"));

    verticalLayout->addWidget(ingredientList);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
    ingredientLine = new QLineEdit(groupBox);
    ingredientLine->setObjectName(QStringLiteral("ingredientLine"));
    ingredientLine->setMinimumSize(QSize(20, 0));
    QFont font2;
    font2.setBold(true);
    font2.setWeight(75);
    ingredientLine->setFont(font2);

    horizontalLayout_3->addWidget(ingredientLine);

    amountSpinbox = new QSpinBox(groupBox);
    amountSpinbox->setObjectName(QStringLiteral("amountSpinbox"));
    amountSpinbox->setMinimumSize(QSize(60, 0));
    amountSpinbox->setMaximum(10000);

    horizontalLayout_3->addWidget(amountSpinbox);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QStringLiteral("label_2"));
    label_2->setMinimumSize(QSize(20, 0));

    horizontalLayout_3->addWidget(label_2);


    verticalLayout->addLayout(horizontalLayout_3);


    gridLayout->addWidget(groupBox, 6, 1, 1, 1);

    helpButton = new QPushButton(this);
    helpButton->setObjectName(QStringLiteral("helpButton"));


    gridLayout->addWidget(helpButton, 8, 0, 1, 2);

    setWindowTitle(QApplication::translate("AddRecipe", "Dialog", 0));
    nameLabel->setText(QApplication::translate("AddRecipe", "Name", 0));
    descriptLabel->setText(QApplication::translate("AddRecipe", "Description", 0));
    addRecipeLabel->setText(QApplication::translate("AddRecipe", "Recipe", 0));
    descLabel->setText(QApplication::translate("AddRecipe", "TextLabel", 0));
    ingredientButton->setText(QApplication::translate("AddRecipe", "Add ingredient", 0));
    addButton->setText(QApplication::translate("AddRecipe", "Add recipe", 0));
    cancelButton->setText(QApplication::translate("AddRecipe", "Cancel", 0));
    saveButton->setText(QApplication::translate("AddRecipe", "Save", 0));
    groupBox_2->setTitle(QApplication::translate("AddRecipe", "Ingredients in recipe", 0));
    groupBox->setTitle(QApplication::translate("AddRecipe", "Add ingredients", 0));
    label_2->setText(QApplication::translate("AddRecipe", "grams", 0));
    helpButton->setText(QApplication::translate("AddRecipe", "Help", 0));

    QMetaObject::connectSlotsByName(this);

    ingredientButton->setDisabled(true);
    ingredientList->setDisabled(true);
    ingredientLine->setDisabled(true);
    saveButton->setDisabled(true);
    recipeTable->setDisabled(true);
    findLine->setDisabled(true);
    amountSpinbox->setDisabled(true);

    addRecipeLabel->setText("Resepti");
    descLabel->setText("");
}


void AddRecipe::on_addButton_clicked()
{
    //lisää reseptin tietokantaan
    QSqlQuery addqry;
    addqry.prepare("insert into RECIPES values(NULL, :name, :desc)");
    addqry.bindValue(":name", nameLine->text());
    addqry.bindValue(":desc", descLine->text());

    if(addqry.exec()){

        QMessageBox::information(this, tr("Save"), ("Recipe added"));
        addRecipeLabel->setText(nameLine->text());
        descLabel->setText(descLine->text());
        addButton->setDisabled(true);
        ingredientList->setDisabled(false);
        saveButton->setDisabled(false);
        recipeTable->setDisabled(false);
        findLine->setDisabled(false);
        cancelButton->setDisabled(true);

        QSqlQueryModel *qry = new QSqlQueryModel();

        qry->setQuery("select name from INGREDIENTS");
        ingredientList->setModel(qry);


    }
    else {

        QMessageBox::critical(this, tr("Error"), addqry.lastError().text());
    }
}


void AddRecipe::on_findLine_textChanged(const QString &arg1)
{
    //päivittää taulun käyttäjän syöttämiin hakuehtoihin sopivaksi
    QSqlQueryModel *qry = new QSqlQueryModel();

    qry->setQuery("select name from INGREDIENTS where name LIKE '"+arg1+"%'");
    ingredientList->setModel(qry);
}


void AddRecipe::on_ingredientButton_clicked()
{
    //lisää raaka-aineen valittuun reseptiin
    QSqlQuery qry;
    qry.prepare("insert into INGREDIENTSINRECIPE (AMOUNT, RECIPE_ID, INGREDIENT_ID) SELECT :amount, re.id, (select ra.id FROM INGREDIENTS ra WHERE ra.name = :val)from RECIPES re WHERE re.name = :name");

    qry.bindValue(":name", nameLine->text());
    qry.bindValue(":val", ingredientLine->text());
    qry.bindValue(":amount", amountSpinbox->text());

    if(qry.exec()){

        QMessageBox::information(this, tr("Save"), ("Ingredient added to recipe"));

        QSqlQueryModel *haku = new QSqlQueryModel();

        QString name;
        name=nameLine->text();
        haku->setQuery("SELECT INGREDIENTS.name, INGREDIENTSINRECIPE.amount FROM INGREDIENTS JOIN INGREDIENTSINRECIPE ON INGREDIENTS.ID = INGREDIENTSINRECIPE.INGREDIENT_ID JOIN RECIPES ON INGREDIENTSINRECIPE.RECIPE_ID = RECIPES.ID AND RECIPES.name = '"+name+"'");
        haku->setHeaderData(0, Qt::Horizontal, tr("Nimi"));
        haku->setHeaderData(1, Qt::Horizontal, tr("Amount/g"));
        recipeTable->setModel(haku);

    }
    else {

        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}

void AddRecipe::on_ingredientList_activated(const QModelIndex &index)
{
    //vapauttaa raaka-aineen lisäykseen tarvittavia nappeja
    QString val=ingredientList->model()->data(index).toString();
    ingredientLine->setDisabled(false);
    ingredientLine->setText(val);
    ingredientButton->setDisabled(false);
    amountSpinbox->setDisabled(false);
}

void AddRecipe::on_cancelButton_clicked()
{
    //sulkee ikkunan
    this->hide();
}

void AddRecipe::on_saveButton_clicked()
{
    //ilmoittaa käyttäjälle reseptin tallennuksesta sekä sulkee ikkunan
    QMessageBox::information(this, tr("Save"), ("Recipe added"));
    this->hide();

}


void AddRecipe::on_helpButton_clicked()
{
    //avaa ohjeet -dialogin
    Help *help = new Help;
    help->exec();
}
