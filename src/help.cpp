#include "help.h"
#include <QApplication>

Help::Help(QWidget *parent) :
    QDialog(parent)
{
    //GUI -elementtien asettelu
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Help"));

    this->resize(800, 600);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    headerLabel = new QLabel(this);
    headerLabel->setObjectName(QStringLiteral("headerLabel"));
    QFont font;
    font.setPointSize(24);
    headerLabel->setFont(font);

    verticalLayout->addWidget(headerLabel);

    line = new QFrame(this);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout->addWidget(line);

    helpText = new QTextBrowser(this);
    helpText->setObjectName(QStringLiteral("helpText"));

    verticalLayout->addWidget(helpText);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QStringLiteral("cancelButton"));

    verticalLayout->addWidget(cancelButton);

    setWindowTitle(QApplication::translate("Help", "Dialog", 0));
    headerLabel->setText(QApplication::translate("Help", "Reseptipankin k\303\244ytt\303\266ohjeet", 0));
    helpText->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br />Reseptipankkiin voit tallentaa raaka-aineita ja koota niist\303\244 reseptej\303\244.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br /></span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Luo uusi</span><span style=\" font-size:8pt;\"> -toiminnolla p\303\244\303"
                    "\244set lis\303\244\303\244m\303\244\303\244n tietokantaa uuden raaka-aineen tai reseptin.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br /></span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Resepti\303\244 lis\303\244tess\303\244si </span><span style=\" font-size:8pt;\">t\303\244yt\303\244 v\303\244hint\303\244\303\244n nimikentt\303\244, kuvauksen voi halutessaan j\303\244tt\303\244\303\244 tyhj\303\244ksi. Ota huomioon, ett\303\244 lis\303\244t\303\244ksesi reseptin tulee sen raaka-aineet lis\303\244t\303\244 ensin tietokantaan. </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br /></span></p>\n"
"<p style=\" margin-top:12px; marg"
                    "in-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Raaka-ainetta lis\303\244tess\303\244si</span><span style=\" font-size:8pt;\">, tulee jokainen kentt\303\244 t\303\244ytt\303\244\303\244. Huomioi, ettei raaka-aine voi sis\303\244lt\303\244\303\244 yli 100 grammaa proteiinia, hiilihydraattia, rasvaa tai kuitua.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br /></span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Etsi -toiminnolla</span><span style=\" font-size:8pt;\"> voit selata raaka-aineita ja reseptej\303\244. Raaka-aineita sek\303\244 reseptej\303\244 voi etsi\303\244 niiden nimell\303\244. Reseptihaussa nime\303\244 klikkaamalla n\303\244et reseptin raaka-aineet.<"
                    "/span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br /></span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Ohjeet -napeilla </span><span style=\" font-size:8pt;\">p\303\244\303\244set t\303\244lle sivulle.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br /></span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Lopeta -toiminto </span><span style=\" font-size:8pt;\">etusivulta sulkee ohjelman.</span></p></body></html>", 0));
    cancelButton->setText(QApplication::translate("Help", "Cancel", 0));
    QMetaObject::connectSlotsByName(this);
}


void Help::on_cancelButton_clicked()
{
    //sulkee ikkunan
    this->hide();
}
