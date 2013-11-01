/********************************************************************************
** Form generated from reading UI file 'welcome-wizard.ui'
**
** Created: Fri Nov 1 20:07:13 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_2D_WIZARD_H
#define UI_WELCOME_2D_WIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcome_wizard
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton1;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *previousButton2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextButton2;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *previousButton3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextButton3;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *previousButton4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *nextButton4;
    QWidget *page_5;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *finishButton;

    void setupUi(QDialog *welcome_wizard)
    {
        if (welcome_wizard->objectName().isEmpty())
            welcome_wizard->setObjectName(QString::fromUtf8("welcome_wizard"));
        welcome_wizard->resize(647, 400);
        welcome_wizard->setMinimumSize(QSize(647, 400));
        welcome_wizard->setMaximumSize(QSize(647, 400));
        verticalLayout_2 = new QVBoxLayout(welcome_wizard);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(welcome_wizard);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 218, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        nextButton1 = new QPushButton(page);
        nextButton1->setObjectName(QString::fromUtf8("nextButton1"));

        horizontalLayout_2->addWidget(nextButton1);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        previousButton2 = new QPushButton(page_2);
        previousButton2->setObjectName(QString::fromUtf8("previousButton2"));

        horizontalLayout->addWidget(previousButton2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextButton2 = new QPushButton(page_2);
        nextButton2->setObjectName(QString::fromUtf8("nextButton2"));

        horizontalLayout->addWidget(nextButton2);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_4 = new QHBoxLayout(page_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        previousButton3 = new QPushButton(page_3);
        previousButton3->setObjectName(QString::fromUtf8("previousButton3"));

        horizontalLayout_3->addWidget(previousButton3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        nextButton3 = new QPushButton(page_3);
        nextButton3->setObjectName(QString::fromUtf8("nextButton3"));

        horizontalLayout_3->addWidget(nextButton3);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_5);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        horizontalLayout_6 = new QHBoxLayout(page_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        previousButton4 = new QPushButton(page_4);
        previousButton4->setObjectName(QString::fromUtf8("previousButton4"));

        horizontalLayout_5->addWidget(previousButton4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        nextButton4 = new QPushButton(page_4);
        nextButton4->setObjectName(QString::fromUtf8("nextButton4"));

        horizontalLayout_5->addWidget(nextButton4);


        verticalLayout_6->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_6);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        horizontalLayout_8 = new QHBoxLayout(page_5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_5 = new QLabel(page_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(80, 65));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/media/EscUpmPolit.jpg")));
        label_5->setScaledContents(true);

        horizontalLayout_9->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        label_2 = new QLabel(page_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(20);
        label_2->setFont(font);

        horizontalLayout_9->addWidget(label_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_7->addLayout(horizontalLayout_9);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);

        label_3 = new QLabel(page_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setWordWrap(true);

        verticalLayout_7->addWidget(label_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);

        label_4 = new QLabel(page_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setWordWrap(true);
        label_4->setOpenExternalLinks(true);
        label_4->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        verticalLayout_7->addWidget(label_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        finishButton = new QPushButton(page_5);
        finishButton->setObjectName(QString::fromUtf8("finishButton"));

        horizontalLayout_7->addWidget(finishButton);


        verticalLayout_7->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_7);

        stackedWidget->addWidget(page_5);

        verticalLayout_2->addWidget(stackedWidget);


        retranslateUi(welcome_wizard);
        QObject::connect(finishButton, SIGNAL(clicked()), welcome_wizard, SLOT(accept()));

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(welcome_wizard);
    } // setupUi

    void retranslateUi(QDialog *welcome_wizard)
    {
        welcome_wizard->setWindowTitle(QApplication::translate("welcome_wizard", "Octave UPM", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("welcome_wizard", "It appears that you have launched Octave GUI for the first time on this computer, since no configuration file could be found at '~/.octave-gui'. This wizard will guide you through the essential settings you should make before you can start using Octave GUI. If you want to transfer your settings you have previously made just close this dialog and copy over the settings file to your home folder. The presence of that file will automatically be detected and will skip this wizard. IMPORTANT: This wizard is not fully functional yet. Just click your way to the end and it will create a standard settings file.", 0, QApplication::UnicodeUTF8));
        nextButton1->setText(QApplication::translate("welcome_wizard", "Next", 0, QApplication::UnicodeUTF8));
        previousButton2->setText(QApplication::translate("welcome_wizard", "Previous", 0, QApplication::UnicodeUTF8));
        nextButton2->setText(QApplication::translate("welcome_wizard", "Next", 0, QApplication::UnicodeUTF8));
        previousButton3->setText(QApplication::translate("welcome_wizard", "Previous", 0, QApplication::UnicodeUTF8));
        nextButton3->setText(QApplication::translate("welcome_wizard", "Next", 0, QApplication::UnicodeUTF8));
        previousButton4->setText(QApplication::translate("welcome_wizard", "Previous", 0, QApplication::UnicodeUTF8));
        nextButton4->setText(QApplication::translate("welcome_wizard", "Next", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_2->setText(QApplication::translate("welcome_wizard", "Octave UPM R8.2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("welcome_wizard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Este programa es una adaptaci\303\263n de GNU Octave 3.6.2, el entorno de matem\303\241tica computacional.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Se emplea en las clases de Inform\303\241tica de la ETSI de Caminos, Canales y Puertos de la Universidad Polit\303\251cnica de Madrid (curso 2012/2013), y contiene varios cambios sob"
                        "re la distribuci\303\263n oficial de GNU Octave.</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("welcome_wizard", "<html><head/><body><p>Para m\303\241s informaci\303\263n sobre Octave UPM y sobre las diferencias con GNU Octave, visita <a href=\"http://mat.caminos.upm.es/octave\"><span style=\" text-decoration: underline; color:#0057ae;\">http://mat.caminos.upm.es/octave</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        finishButton->setText(QApplication::translate("welcome_wizard", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class welcome_wizard: public Ui_welcome_wizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_2D_WIZARD_H
