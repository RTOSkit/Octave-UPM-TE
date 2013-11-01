/********************************************************************************
** Form generated from reading UI file 'graphics-editor.ui'
**
** Created: Fri Nov 1 20:07:13 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICS_2D_EDITOR_H
#define UI_GRAPHICS_2D_EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GraphicsEditor
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QDoubleSpinBox *axisWidth;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_3;
    QSpinBox *axisFontSize;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_4;
    QComboBox *axisFontWeight;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QPushButton *xcolor;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QPushButton *ycolor;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *toggleGrid;
    QCheckBox *showGridMinor;
    QGroupBox *plotAllBox;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QComboBox *plotComboBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_8;
    QDoubleSpinBox *plotWidth;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_9;
    QComboBox *plotLine;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_10;
    QPushButton *plotColor;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_12;
    QComboBox *markerType;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_13;
    QSpinBox *markerSize;
    QHBoxLayout *horizontalLayout_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GraphicsEditor)
    {
        if (GraphicsEditor->objectName().isEmpty())
            GraphicsEditor->setObjectName(QString::fromUtf8("GraphicsEditor"));
        GraphicsEditor->resize(800, 700);
        horizontalLayout = new QHBoxLayout(GraphicsEditor);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_4 = new QGroupBox(GraphicsEditor);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        graphicsView = new QGraphicsView(groupBox_4);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_7->addWidget(graphicsView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label, 0, Qt::AlignHCenter);

        axisWidth = new QDoubleSpinBox(groupBox);
        axisWidth->setObjectName(QString::fromUtf8("axisWidth"));
        axisWidth->setMaximumSize(QSize(75, 16777215));
        axisWidth->setDecimals(1);
        axisWidth->setSingleStep(0.5);

        verticalLayout_4->addWidget(axisWidth, 0, Qt::AlignHCenter);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_3);

        axisFontSize = new QSpinBox(groupBox);
        axisFontSize->setObjectName(QString::fromUtf8("axisFontSize"));
        axisFontSize->setMaximumSize(QSize(75, 16777215));

        verticalLayout_9->addWidget(axisFontSize, 0, Qt::AlignHCenter);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_4);

        axisFontWeight = new QComboBox(groupBox);
        axisFontWeight->setObjectName(QString::fromUtf8("axisFontWeight"));
        axisFontWeight->setMaximumSize(QSize(75, 16777215));

        verticalLayout_10->addWidget(axisFontWeight, 0, Qt::AlignHCenter);


        horizontalLayout_5->addLayout(verticalLayout_10);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_5);

        xcolor = new QPushButton(groupBox_3);
        xcolor->setObjectName(QString::fromUtf8("xcolor"));
        xcolor->setMaximumSize(QSize(60, 16777215));
        xcolor->setAutoFillBackground(true);

        verticalLayout_6->addWidget(xcolor, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_6);

        ycolor = new QPushButton(groupBox_3);
        ycolor->setObjectName(QString::fromUtf8("ycolor"));
        ycolor->setMaximumSize(QSize(60, 16777215));
        ycolor->setAutoFillBackground(true);

        verticalLayout_5->addWidget(ycolor, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_5);


        horizontalLayout_9->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toggleGrid = new QPushButton(groupBox_2);
        toggleGrid->setObjectName(QString::fromUtf8("toggleGrid"));

        verticalLayout_3->addWidget(toggleGrid);

        showGridMinor = new QCheckBox(groupBox_2);
        showGridMinor->setObjectName(QString::fromUtf8("showGridMinor"));

        verticalLayout_3->addWidget(showGridMinor);


        verticalLayout->addLayout(verticalLayout_3);


        horizontalLayout_9->addWidget(groupBox_2);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_4->addWidget(groupBox);

        plotAllBox = new QGroupBox(groupBox_4);
        plotAllBox->setObjectName(QString::fromUtf8("plotAllBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plotAllBox->sizePolicy().hasHeightForWidth());
        plotAllBox->setSizePolicy(sizePolicy1);
        verticalLayout_11 = new QVBoxLayout(plotAllBox);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_11 = new QLabel(plotAllBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_8->addWidget(label_11);

        plotComboBox = new QComboBox(plotAllBox);
        plotComboBox->setObjectName(QString::fromUtf8("plotComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plotComboBox->sizePolicy().hasHeightForWidth());
        plotComboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(plotComboBox);


        verticalLayout_11->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_8 = new QLabel(plotAllBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_12->addWidget(label_8, 0, Qt::AlignHCenter);

        plotWidth = new QDoubleSpinBox(plotAllBox);
        plotWidth->setObjectName(QString::fromUtf8("plotWidth"));
        plotWidth->setMaximumSize(QSize(60, 16777215));
        plotWidth->setDecimals(1);
        plotWidth->setSingleStep(0.5);

        verticalLayout_12->addWidget(plotWidth, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_12);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_9 = new QLabel(plotAllBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_14->addWidget(label_9, 0, Qt::AlignHCenter);

        plotLine = new QComboBox(plotAllBox);
        plotLine->setObjectName(QString::fromUtf8("plotLine"));

        verticalLayout_14->addWidget(plotLine);


        horizontalLayout_6->addLayout(verticalLayout_14);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_10 = new QLabel(plotAllBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_13->addWidget(label_10, 0, Qt::AlignHCenter);

        plotColor = new QPushButton(plotAllBox);
        plotColor->setObjectName(QString::fromUtf8("plotColor"));
        plotColor->setMaximumSize(QSize(60, 16777215));
        plotColor->setAutoFillBackground(true);

        verticalLayout_13->addWidget(plotColor, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_13);


        verticalLayout_11->addLayout(horizontalLayout_6);

        groupBox_5 = new QGroupBox(plotAllBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_18->addWidget(label_12, 0, Qt::AlignHCenter);

        markerType = new QComboBox(groupBox_5);
        markerType->setObjectName(QString::fromUtf8("markerType"));

        verticalLayout_18->addWidget(markerType, 0, Qt::AlignHCenter);


        horizontalLayout_7->addLayout(verticalLayout_18);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_17->addWidget(label_13, 0, Qt::AlignHCenter);

        markerSize = new QSpinBox(groupBox_5);
        markerSize->setObjectName(QString::fromUtf8("markerSize"));
        markerSize->setMaximumSize(QSize(60, 16777215));

        verticalLayout_17->addWidget(markerSize, 0, Qt::AlignHCenter);


        horizontalLayout_7->addLayout(verticalLayout_17);


        verticalLayout_11->addWidget(groupBox_5);


        horizontalLayout_4->addWidget(plotAllBox);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        buttonBox = new QDialogButtonBox(groupBox_4);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_7->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(groupBox_4);


        retranslateUi(GraphicsEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), GraphicsEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GraphicsEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphicsEditor);
    } // setupUi

    void retranslateUi(QDialog *GraphicsEditor)
    {
        GraphicsEditor->setWindowTitle(QApplication::translate("GraphicsEditor", "Graphics editor", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("GraphicsEditor", "Preview", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GraphicsEditor", "Axis", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GraphicsEditor", "Line width", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GraphicsEditor", "Font size", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GraphicsEditor", "Font weight", 0, QApplication::UnicodeUTF8));
        axisFontWeight->clear();
        axisFontWeight->insertItems(0, QStringList()
         << QApplication::translate("GraphicsEditor", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Bold", 0, QApplication::UnicodeUTF8)
        );
        groupBox_3->setTitle(QApplication::translate("GraphicsEditor", "Font colors", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GraphicsEditor", "X", 0, QApplication::UnicodeUTF8));
        xcolor->setText(QString());
        label_6->setText(QApplication::translate("GraphicsEditor", "Y", 0, QApplication::UnicodeUTF8));
        ycolor->setText(QString());
        groupBox_2->setTitle(QApplication::translate("GraphicsEditor", "Grid", 0, QApplication::UnicodeUTF8));
        toggleGrid->setText(QApplication::translate("GraphicsEditor", "Toggle", 0, QApplication::UnicodeUTF8));
        showGridMinor->setText(QApplication::translate("GraphicsEditor", "Apply to minor lines", 0, QApplication::UnicodeUTF8));
        plotAllBox->setTitle(QApplication::translate("GraphicsEditor", "Plots", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("GraphicsEditor", "Plot series:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("GraphicsEditor", "Line width", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("GraphicsEditor", "Line type", 0, QApplication::UnicodeUTF8));
        plotLine->clear();
        plotLine->insertItems(0, QStringList()
         << QApplication::translate("GraphicsEditor", "Continuous", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Dashed (-----)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Dotted (......)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Dash-point (-.-.-.-.-)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "None", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("GraphicsEditor", "Color", 0, QApplication::UnicodeUTF8));
        plotColor->setText(QString());
        groupBox_5->setTitle(QApplication::translate("GraphicsEditor", "Markers", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("GraphicsEditor", "Type", 0, QApplication::UnicodeUTF8));
        markerType->clear();
        markerType->insertItems(0, QStringList()
         << QApplication::translate("GraphicsEditor", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "*", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "o", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Triangles ^", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Points", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Squares", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Diamonds", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Triangles v", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Pentagram", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GraphicsEditor", "Hexagram", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("GraphicsEditor", "Size", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GraphicsEditor: public Ui_GraphicsEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICS_2D_EDITOR_H
