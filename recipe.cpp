#include "recipe.h"
#include "help.h"

#include <QApplication>

Recipe::Recipe(QWidget *parent) :
    QDialog(parent)
{
    //GUI -elementtien asettelu
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Recipe"));

    this->resize(800, 600);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    recipeLabel = new QLabel(this);
    recipeLabel->setObjectName(QStringLiteral("recipeLabel"));
    recipeLabel->setMinimumSize(QSize(300, 0));
    QFont font;
    font.setPointSize(24);
    recipeLabel->setFont(font);

    horizontalLayout->addWidget(recipeLabel);

    descLabel = new QLabel(this);
    descLabel->setObjectName(QStringLiteral("descLabel"));

    horizontalLayout->addWidget(descLabel);

    backButton = new QPushButton(this);
    backButton->setObjectName(QStringLiteral("backButton"));

    horizontalLayout->addWidget(backButton);


    verticalLayout->addLayout(horizontalLayout);

    line = new QFrame(this);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout->addWidget(line);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    findLabel = new QLabel(this);
    findLabel->setObjectName(QStringLiteral("findLabel"));

    horizontalLayout_2->addWidget(findLabel);

    findLine = new QLineEdit(this);
    findLine->setObjectName(QStringLiteral("findLine"));

    horizontalLayout_2->addWidget(findLine);


    verticalLayout_2->addLayout(horizontalLayout_2);

    recipeTable = new QTableView(this);
    recipeTable->setObjectName(QStringLiteral("recipeTable"));

    verticalLayout_2->addWidget(recipeTable);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QStringLiteral("cancelButton"));

    verticalLayout_2->addWidget(cancelButton);

    helpButton = new QPushButton(this);
    helpButton->setObjectName(QStringLiteral("helpButton"));

    verticalLayout_2->addWidget(helpButton);


    verticalLayout->addLayout(verticalLayout_2);


    setWindowTitle(QApplication::translate("Recipe", "Form", 0));
    recipeLabel->setText(QApplication::translate("Recipe", "Recipe", 0));
    descLabel->setText(QApplication::translate("Recipe", "TextLabel", 0));
    backButton->setText(QApplication::translate("Recipe", "Back to listing", 0));
    findLabel->setText(QApplication::translate("Recipe", "Find", 0));
    cancelButton->setText(QApplication::translate("Recipe", "Cancel", 0));
    helpButton->setText(QApplication::translate("Recipe", "Help", 0));

    QMetaObject::connectSlotsByName(this);

    QSqlQueryModel *table = new QSqlQueryModel();
    table->setQuery("select recipes.name, recipes.desc from RECIPES");
    recipeTable->setModel(table);
    descLabel->setText("");
}



void Recipe::on_findLine_textChanged(const QString &arg1)
{
    //päivittää taulun käyttäjän syöttämiin hakuehtoihin sopivaksi
    QSqlQueryModel *qry = new QSqlQueryModel();

    qry ->setQuery("select * from RECIPES where name LIKE '"+arg1+"%'");
    recipeTable->setModel(qry);
}

void Recipe::on_recipeTable_activated(const QModelIndex &index)
{
    //metodi vaihtaa taulunäkymän näyttämään käyttäjän valitseman reseptin raaka-aineet tietoineen sekä niiden määrät reseptissä
    QString val=recipeTable->model()->data(index).toString();

    QSqlQuery qry("select * from RECIPES JOIN INGREDIENTSINRECIPE ON RECIPE_ID = RECIPES.ID AND name ='"+val+"'");


    while(qry.next())
        {
            recipeLabel->setText(qry.value(1).toString());
            descLabel->setText(qry.value(2).toString());

        }

    QSqlQueryModel *summary = new QSqlQueryModel();
    summary->setQuery("SELECT ingredientsinrecipe.amount, ingredients.name, ingredients.calories, ingredients.proteins, ingredients.carbohydrates, ingredients.fat, ingredients.fiber FROM INGREDIENTS JOIN INGREDIENTSINRECIPE ON INGREDIENTS.ID = INGREDIENTSINRECIPE.INGREDIENT_ID JOIN RECIPES ON INGREDIENTSINRECIPE.RECIPE_ID = RECIPES.ID AND RECIPES.NAME ='"+val+"'");
    summary->setHeaderData(0, Qt::Horizontal, tr("Amount/g"));
    summary->setHeaderData(1, Qt::Horizontal, tr("Name"));
    summary->setHeaderData(2, Qt::Horizontal, tr("Calories/100g"));
    summary->setHeaderData(3, Qt::Horizontal, tr("Protein/100g"));
    summary->setHeaderData(4, Qt::Horizontal, tr("Carbohydrates/100g"));
    summary->setHeaderData(5, Qt::Horizontal, tr("Fat/100g"));
    summary->setHeaderData(6, Qt::Horizontal, tr("Fiber/100g"));

    recipeTable->setModel(summary);

}

void Recipe::on_cancelButton_clicked()
{
    //sulkee ikkunan
    this->hide();
}

void Recipe::on_backButton_clicked()
{
    //takaisin napin tarkoitus on palata reseptin sisältönäkymästä takaisin reseptilistaukseen
    QSqlQueryModel *table = new QSqlQueryModel();
    table->setQuery("select recipes.name, recipes.desc from RECIPES");
    recipeTable->setModel(table);
    descLabel->setText("");
}

void Recipe::on_helpButton_clicked()
{
    //avaa ohjeet -dialogin
    Help *help = new Help;
    help->exec();
}
