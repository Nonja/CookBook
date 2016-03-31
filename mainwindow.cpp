#include "mainwindow.h"
#include "add.h"
#include "find.h"
#include "help.h"

#include <QApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    //GUI -elementtien asettelu
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("MainWindow"));

    this->resize(400, 300);
    actionQuit = new QAction(this);
    actionQuit->setObjectName(QStringLiteral("actionQuit"));
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    verticalLayout = new QVBoxLayout(centralWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    splitter = new QSplitter(centralWidget);
    splitter->setObjectName(QStringLiteral("splitter"));
    splitter->setOrientation(Qt::Vertical);
    addButton = new QPushButton(splitter);
    addButton->setObjectName(QStringLiteral("addButton"));
    splitter->addWidget(addButton);
    findButton = new QPushButton(splitter);
    findButton->setObjectName(QStringLiteral("findButton"));
    splitter->addWidget(findButton);
    helpButton = new QPushButton(splitter);
    helpButton->setObjectName(QStringLiteral("helpButton"));
    splitter->addWidget(helpButton);
    quitButton = new QPushButton(splitter);
    quitButton->setObjectName(QStringLiteral("quitButton"));
    splitter->addWidget(quitButton);

    verticalLayout->addWidget(splitter);

    line = new QFrame(centralWidget);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout->addWidget(line);

    databaseStatus = new QLabel(centralWidget);
    databaseStatus->setObjectName(QStringLiteral("databaseStatus"));

    verticalLayout->addWidget(databaseStatus);

    setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 400, 21));
    menuFile = new QMenu(menuBar);
    menuFile->setObjectName(QStringLiteral("menuFile"));
    setMenuBar(menuBar);

    menuBar->addAction(menuFile->menuAction());
    menuFile->addAction(actionQuit);

    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
    addButton->setText(QApplication::translate("MainWindow", "Add new...", 0));
    findButton->setText(QApplication::translate("MainWindow", "Find...", 0));
    helpButton->setText(QApplication::translate("MainWindow", "Help", 0));
    quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
    databaseStatus->setText(QApplication::translate("MainWindow", "Database...", 0));
    menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));

    QMetaObject::connectSlotsByName(this);


    //luodaan tietokanta ja tarvittavat taulut

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("reseptipankki.db");

    if (!mydb.open()){
        databaseStatus->setText("Failed to open database");
    }
    else{
        databaseStatus->setText("Connected to database!");
        QSqlQuery qry;
                qry.exec("CREATE TABLE IF NOT EXISTS INGREDIENTS "
                         "(ID INTEGER PRIMARY KEY, "
                         "NAME TEXT NOT NULL, "
                         "CALORIES REAL NOT NULL, "
                         "PROTEINS REAL NOT NULL CHECK(PROTEINS<100), "
                         "CARBOHYDRATES REAL NOT NULL CHECK(CARBOHYDRATES<100), "
                         "FAT REAL NOT NULL CHECK(FAT<100), "
                         "FIBER REAL NOT NULL CHECK(FIBER<100))");

                qry.exec("CREATE TABLE IF NOT EXISTS RECIPES "
                         "(ID INTEGER PRIMARY KEY, "
                         "NAME TEXT NOT NULL, "
                         "DESC TEXT)");

                qry.exec("CREATE TABLE IF NOT EXISTS INGREDIENTSINRECIPE "
                         "(AMOUNT REAL NOT NULL, "
                         "RECIPE_ID INT, "
                         "INGREDIENT_ID INT, "
                         "FOREIGN KEY(RECIPE_ID) REFERENCES RECIPES(ID), "
                         "FOREIGN KEY(INGREDIENT_ID) REFERENCES INGREDIENTS(ID))");



    }
}


void MainWindow::on_actionQuit_triggered()
{
    //lopettaa ohjelman
    qApp->quit();
}


void MainWindow::on_findButton_clicked()
{
    //avaa etsi -dialogin
    Find *find = new Find();
    find->exec();
}

void MainWindow::on_addButton_clicked()
{
    //avaa luouusi -dialogin
    Add *add = new Add;
    add->exec();
}

void MainWindow::on_helpButton_clicked()
{
    //avaan ohjeet dialogin
    Help *help = new Help;
    help->exec();
}

void MainWindow::on_quitButton_clicked()
{
    //lopettaa ohjelman
    qApp->quit();
}
