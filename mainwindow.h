#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void on_actionQuit_triggered();

    void on_findButton_clicked();

    void on_addButton_clicked();

    void on_helpButton_clicked();

    void on_quitButton_clicked();

private:
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QPushButton *addButton;
    QPushButton *findButton;
    QPushButton *helpButton;
    QPushButton *quitButton;
    QFrame *line;
    QLabel *databaseStatus;
    QMenuBar *menuBar;
    QMenu *menuFile;

};

#endif // MAINWINDOW_H
