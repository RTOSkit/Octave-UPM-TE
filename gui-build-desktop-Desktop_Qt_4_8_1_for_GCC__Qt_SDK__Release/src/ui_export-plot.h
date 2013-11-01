/********************************************************************************
** Form generated from reading UI file 'export-plot.ui'
**
** Created: Fri Nov 1 20:07:13 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_2D_PLOT_H
#define UI_EXPORT_2D_PLOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_export_plot
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QComboBox *formatCombo;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *filenameEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *export_plot)
    {
        if (export_plot->objectName().isEmpty())
            export_plot->setObjectName(QString::fromUtf8("export_plot"));
        export_plot->resize(800, 600);
        verticalLayout = new QVBoxLayout(export_plot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(export_plot);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(verticalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formatCombo = new QComboBox(export_plot);
        formatCombo->setObjectName(QString::fromUtf8("formatCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(formatCombo->sizePolicy().hasHeightForWidth());
        formatCombo->setSizePolicy(sizePolicy);
        formatCombo->setMinimumSize(QSize(150, 0));
        formatCombo->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(formatCombo, 2, 1, 1, 1);

        label_2 = new QLabel(export_plot);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(export_plot);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        filenameEdit = new QLineEdit(export_plot);
        filenameEdit->setObjectName(QString::fromUtf8("filenameEdit"));

        gridLayout->addWidget(filenameEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        groupBox = new QGroupBox(export_plot);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        graphicsView = new QGraphicsView(groupBox);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_2->addWidget(graphicsView);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(export_plot);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(export_plot);
        QObject::connect(buttonBox, SIGNAL(rejected()), export_plot, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), export_plot, SLOT(accept()));

        QMetaObject::connectSlotsByName(export_plot);
    } // setupUi

    void retranslateUi(QDialog *export_plot)
    {
        export_plot->setWindowTitle(QApplication::translate("export_plot", "Export plot", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("export_plot", "File will be saved to the current directory", 0, QApplication::UnicodeUTF8));
        formatCombo->clear();
        formatCombo->insertItems(0, QStringList()
         << QApplication::translate("export_plot", "PNG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("export_plot", "JPG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("export_plot", "PDF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("export_plot", "Encapsulated Postscript (EPS)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("export_plot", "Postscript (PS)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("export_plot", "Enhanced Metafile (EMF)", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("export_plot", "Format:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("export_plot", "Filename:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("export_plot", "Preview", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class export_plot: public Ui_export_plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_2D_PLOT_H
