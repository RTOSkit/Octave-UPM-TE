/********************************************************************************
** Form generated from reading UI file 'settings-dialog.ui'
**
** Created: Fri Nov 1 20:07:13 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_2D_DIALOG_H
#define UI_SETTINGS_2D_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings_dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QFontComboBox *editor_fontName;
    QLabel *label_9;
    QSpinBox *editor_fontSize;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_8;
    QCheckBox *editor_showLineNumbers;
    QCheckBox *editor_highlightCurrentLine;
    QCheckBox *editor_codeCompletion;
    QCheckBox *editor_longWindowTitle;
    QFrame *line_9;
    QCheckBox *autosaveFiles;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_18;
    QSpinBox *autosavePeriod;
    QLabel *label_19;
    QFrame *line_16;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line_17;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *line_11;
    QCheckBox *showFilenames;
    QCheckBox *showFileSize;
    QCheckBox *showFileType;
    QCheckBox *showLastModified;
    QCheckBox *useAlternatingRowColors;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *file_fontNamelabel;
    QFontComboBox *file_fontName;
    QLabel *file_fontSizelabel;
    QSpinBox *file_fontSize;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *file_defaultFont;
    QFrame *line_6;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QFontComboBox *terminal_fontName;
    QLabel *label_12;
    QSpinBox *terminal_fontSize;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QFontComboBox *workspace_fontName;
    QLabel *label_4;
    QSpinBox *workspace_fontSize;
    QSpacerItem *horizontalSpacer;
    QCheckBox *workspace_defaultFont;
    QFrame *line_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *history_numberCommands;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QFontComboBox *history_fontName;
    QLabel *label_10;
    QSpinBox *history_fontSize;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *history_defaultFont;
    QFrame *line_4;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QFrame *line_10;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QComboBox *toolkit_cb;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_12;
    QLabel *label_15;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_17;
    QComboBox *broadcastingOption;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *matlabCompatible;
    QCheckBox *supressWarnings;
    QFrame *line_15;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    QFrame *line_13;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_20;
    QComboBox *languageComboBox;
    QSpacerItem *horizontalSpacer_11;
    QFrame *line_14;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *settings_dialog)
    {
        if (settings_dialog->objectName().isEmpty())
            settings_dialog->setObjectName(QString::fromUtf8("settings_dialog"));
        settings_dialog->setWindowModality(Qt::ApplicationModal);
        settings_dialog->resize(600, 400);
        settings_dialog->setMinimumSize(QSize(600, 400));
        settings_dialog->setMaximumSize(QSize(600, 400));
        verticalLayout_2 = new QVBoxLayout(settings_dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(settings_dialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        line_7 = new QFrame(tab);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        editor_fontName = new QFontComboBox(tab);
        editor_fontName->setObjectName(QString::fromUtf8("editor_fontName"));
        editor_fontName->setEditable(false);
        editor_fontName->setFontFilters(QFontComboBox::MonospacedFonts);

        horizontalLayout_4->addWidget(editor_fontName);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        editor_fontSize = new QSpinBox(tab);
        editor_fontSize->setObjectName(QString::fromUtf8("editor_fontSize"));
        editor_fontSize->setMinimum(2);
        editor_fontSize->setMaximum(96);
        editor_fontSize->setValue(10);

        horizontalLayout_4->addWidget(editor_fontSize);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_4);

        line_8 = new QFrame(tab);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_8);

        editor_showLineNumbers = new QCheckBox(tab);
        editor_showLineNumbers->setObjectName(QString::fromUtf8("editor_showLineNumbers"));
        editor_showLineNumbers->setEnabled(true);
        editor_showLineNumbers->setChecked(true);

        verticalLayout_5->addWidget(editor_showLineNumbers);

        editor_highlightCurrentLine = new QCheckBox(tab);
        editor_highlightCurrentLine->setObjectName(QString::fromUtf8("editor_highlightCurrentLine"));
        editor_highlightCurrentLine->setEnabled(true);
        editor_highlightCurrentLine->setChecked(true);

        verticalLayout_5->addWidget(editor_highlightCurrentLine);

        editor_codeCompletion = new QCheckBox(tab);
        editor_codeCompletion->setObjectName(QString::fromUtf8("editor_codeCompletion"));
        editor_codeCompletion->setEnabled(true);
        editor_codeCompletion->setChecked(true);

        verticalLayout_5->addWidget(editor_codeCompletion);

        editor_longWindowTitle = new QCheckBox(tab);
        editor_longWindowTitle->setObjectName(QString::fromUtf8("editor_longWindowTitle"));

        verticalLayout_5->addWidget(editor_longWindowTitle);

        line_9 = new QFrame(tab);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_9);

        autosaveFiles = new QCheckBox(tab);
        autosaveFiles->setObjectName(QString::fromUtf8("autosaveFiles"));
        autosaveFiles->setChecked(true);

        verticalLayout_5->addWidget(autosaveFiles);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_3->addWidget(label_18);

        autosavePeriod = new QSpinBox(tab);
        autosavePeriod->setObjectName(QString::fromUtf8("autosavePeriod"));
        autosavePeriod->setMinimum(1);
        autosavePeriod->setMaximum(120);
        autosavePeriod->setValue(2);

        horizontalLayout_3->addWidget(autosavePeriod);

        label_19 = new QLabel(tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_3->addWidget(label_19);

        line_16 = new QFrame(tab);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_16);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        line_17 = new QFrame(tab);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_17);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        line_11 = new QFrame(tab_2);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_11);

        showFilenames = new QCheckBox(tab_2);
        showFilenames->setObjectName(QString::fromUtf8("showFilenames"));
        showFilenames->setChecked(true);

        verticalLayout_3->addWidget(showFilenames);

        showFileSize = new QCheckBox(tab_2);
        showFileSize->setObjectName(QString::fromUtf8("showFileSize"));
        showFileSize->setChecked(true);

        verticalLayout_3->addWidget(showFileSize);

        showFileType = new QCheckBox(tab_2);
        showFileType->setObjectName(QString::fromUtf8("showFileType"));

        verticalLayout_3->addWidget(showFileType);

        showLastModified = new QCheckBox(tab_2);
        showLastModified->setObjectName(QString::fromUtf8("showLastModified"));

        verticalLayout_3->addWidget(showLastModified);

        useAlternatingRowColors = new QCheckBox(tab_2);
        useAlternatingRowColors->setObjectName(QString::fromUtf8("useAlternatingRowColors"));
        useAlternatingRowColors->setChecked(true);

        verticalLayout_3->addWidget(useAlternatingRowColors);

        line_5 = new QFrame(tab_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        file_fontNamelabel = new QLabel(tab_2);
        file_fontNamelabel->setObjectName(QString::fromUtf8("file_fontNamelabel"));
        file_fontNamelabel->setEnabled(false);

        horizontalLayout_8->addWidget(file_fontNamelabel);

        file_fontName = new QFontComboBox(tab_2);
        file_fontName->setObjectName(QString::fromUtf8("file_fontName"));
        file_fontName->setEnabled(false);
        file_fontName->setEditable(false);

        horizontalLayout_8->addWidget(file_fontName);

        file_fontSizelabel = new QLabel(tab_2);
        file_fontSizelabel->setObjectName(QString::fromUtf8("file_fontSizelabel"));
        file_fontSizelabel->setEnabled(false);

        horizontalLayout_8->addWidget(file_fontSizelabel);

        file_fontSize = new QSpinBox(tab_2);
        file_fontSize->setObjectName(QString::fromUtf8("file_fontSize"));
        file_fontSize->setEnabled(false);
        file_fontSize->setMinimum(2);
        file_fontSize->setMaximum(96);
        file_fontSize->setValue(10);

        horizontalLayout_8->addWidget(file_fontSize);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_8);

        file_defaultFont = new QCheckBox(tab_2);
        file_defaultFont->setObjectName(QString::fromUtf8("file_defaultFont"));
        file_defaultFont->setChecked(true);

        verticalLayout_3->addWidget(file_defaultFont);

        line_6 = new QFrame(tab_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout = new QVBoxLayout(tab_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(tab_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_5->addWidget(label_11);

        terminal_fontName = new QFontComboBox(tab_5);
        terminal_fontName->setObjectName(QString::fromUtf8("terminal_fontName"));
        terminal_fontName->setEditable(false);
        terminal_fontName->setFontFilters(QFontComboBox::MonospacedFonts);

        horizontalLayout_5->addWidget(terminal_fontName);

        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        terminal_fontSize = new QSpinBox(tab_5);
        terminal_fontSize->setObjectName(QString::fromUtf8("terminal_fontSize"));
        terminal_fontSize->setMinimum(2);
        terminal_fontSize->setMaximum(96);
        terminal_fontSize->setValue(10);

        horizontalLayout_5->addWidget(terminal_fontSize);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        line_2 = new QFrame(tab_5);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);

        horizontalLayout_2->addWidget(label_3);

        workspace_fontName = new QFontComboBox(tab_5);
        workspace_fontName->setObjectName(QString::fromUtf8("workspace_fontName"));
        workspace_fontName->setEnabled(false);
        workspace_fontName->setEditable(false);

        horizontalLayout_2->addWidget(workspace_fontName);

        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(false);

        horizontalLayout_2->addWidget(label_4);

        workspace_fontSize = new QSpinBox(tab_5);
        workspace_fontSize->setObjectName(QString::fromUtf8("workspace_fontSize"));
        workspace_fontSize->setEnabled(false);
        workspace_fontSize->setMinimum(2);
        workspace_fontSize->setMaximum(96);
        workspace_fontSize->setValue(10);

        horizontalLayout_2->addWidget(workspace_fontSize);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        workspace_defaultFont = new QCheckBox(tab_5);
        workspace_defaultFont->setObjectName(QString::fromUtf8("workspace_defaultFont"));
        workspace_defaultFont->setChecked(true);

        verticalLayout->addWidget(workspace_defaultFont);

        line_3 = new QFrame(tab_5);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        history_numberCommands = new QSpinBox(tab_5);
        history_numberCommands->setObjectName(QString::fromUtf8("history_numberCommands"));
        history_numberCommands->setMinimum(0);
        history_numberCommands->setMaximum(1024);
        history_numberCommands->setValue(128);

        horizontalLayout_6->addWidget(history_numberCommands);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(false);

        horizontalLayout_7->addWidget(label_7);

        history_fontName = new QFontComboBox(tab_5);
        history_fontName->setObjectName(QString::fromUtf8("history_fontName"));
        history_fontName->setEnabled(false);
        history_fontName->setEditable(false);

        horizontalLayout_7->addWidget(history_fontName);

        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(false);

        horizontalLayout_7->addWidget(label_10);

        history_fontSize = new QSpinBox(tab_5);
        history_fontSize->setObjectName(QString::fromUtf8("history_fontSize"));
        history_fontSize->setEnabled(false);
        history_fontSize->setMinimum(2);
        history_fontSize->setMaximum(96);
        history_fontSize->setValue(10);

        horizontalLayout_7->addWidget(history_fontSize);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_7);

        history_defaultFont = new QCheckBox(tab_5);
        history_defaultFont->setObjectName(QString::fromUtf8("history_defaultFont"));
        history_defaultFont->setChecked(true);

        verticalLayout->addWidget(history_defaultFont);

        line_4 = new QFrame(tab_5);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        tabWidget->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        line_10 = new QFrame(tab_3);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_10);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setWordWrap(true);

        verticalLayout_7->addWidget(label_13);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout->addWidget(label_14);

        toolkit_cb = new QComboBox(tab_3);
        toolkit_cb->setObjectName(QString::fromUtf8("toolkit_cb"));
        toolkit_cb->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(toolkit_cb);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_7->addLayout(horizontalLayout);

        line_12 = new QFrame(tab_3);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_12);

        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setScaledContents(false);
        label_15->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_15->setWordWrap(true);

        verticalLayout_7->addWidget(label_15);

        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setTextFormat(Qt::RichText);
        label_16->setOpenExternalLinks(true);
        label_16->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        verticalLayout_7->addWidget(label_16);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_9->addWidget(label_17);

        broadcastingOption = new QComboBox(tab_3);
        broadcastingOption->setObjectName(QString::fromUtf8("broadcastingOption"));
        broadcastingOption->setMinimumSize(QSize(220, 0));
        broadcastingOption->setMaximumSize(QSize(72, 16777215));

        horizontalLayout_9->addWidget(broadcastingOption);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_7->addLayout(horizontalLayout_9);

        matlabCompatible = new QCheckBox(tab_3);
        matlabCompatible->setObjectName(QString::fromUtf8("matlabCompatible"));

        verticalLayout_7->addWidget(matlabCompatible);

        supressWarnings = new QCheckBox(tab_3);
        supressWarnings->setObjectName(QString::fromUtf8("supressWarnings"));
        supressWarnings->setChecked(true);

        verticalLayout_7->addWidget(supressWarnings);

        line_15 = new QFrame(tab_3);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_15);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        line_13 = new QFrame(tab_4);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_13);

        label_21 = new QLabel(tab_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_4->addWidget(label_21);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_11->addWidget(label_20);

        languageComboBox = new QComboBox(tab_4);
        languageComboBox->setObjectName(QString::fromUtf8("languageComboBox"));
        languageComboBox->setMinimumSize(QSize(180, 0));

        horizontalLayout_11->addWidget(languageComboBox);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(horizontalLayout_11);

        line_14 = new QFrame(tab_4);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_14);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        tabWidget->addTab(tab_4, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        okButton = new QPushButton(settings_dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        horizontalLayout_10->addWidget(okButton);

        cancelButton = new QPushButton(settings_dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_10->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_10);


        retranslateUi(settings_dialog);
        QObject::connect(file_defaultFont, SIGNAL(toggled(bool)), file_fontNamelabel, SLOT(setDisabled(bool)));
        QObject::connect(file_defaultFont, SIGNAL(toggled(bool)), file_fontSize, SLOT(setDisabled(bool)));
        QObject::connect(workspace_defaultFont, SIGNAL(toggled(bool)), label_3, SLOT(setDisabled(bool)));
        QObject::connect(workspace_defaultFont, SIGNAL(toggled(bool)), label_4, SLOT(setDisabled(bool)));
        QObject::connect(file_defaultFont, SIGNAL(toggled(bool)), file_fontSizelabel, SLOT(setDisabled(bool)));
        QObject::connect(file_defaultFont, SIGNAL(toggled(bool)), file_fontName, SLOT(setDisabled(bool)));
        QObject::connect(workspace_defaultFont, SIGNAL(toggled(bool)), workspace_fontSize, SLOT(setDisabled(bool)));
        QObject::connect(workspace_defaultFont, SIGNAL(toggled(bool)), workspace_fontName, SLOT(setDisabled(bool)));
        QObject::connect(history_defaultFont, SIGNAL(toggled(bool)), label_7, SLOT(setDisabled(bool)));
        QObject::connect(history_defaultFont, SIGNAL(toggled(bool)), history_fontName, SLOT(setDisabled(bool)));
        QObject::connect(history_defaultFont, SIGNAL(toggled(bool)), label_10, SLOT(setDisabled(bool)));
        QObject::connect(history_defaultFont, SIGNAL(toggled(bool)), history_fontSize, SLOT(setDisabled(bool)));
        QObject::connect(autosaveFiles, SIGNAL(toggled(bool)), label_18, SLOT(setEnabled(bool)));
        QObject::connect(autosaveFiles, SIGNAL(toggled(bool)), autosavePeriod, SLOT(setEnabled(bool)));
        QObject::connect(autosaveFiles, SIGNAL(toggled(bool)), label_19, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(4);
        broadcastingOption->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(settings_dialog);
    } // setupUi

    void retranslateUi(QDialog *settings_dialog)
    {
        settings_dialog->setWindowTitle(QApplication::translate("settings_dialog", "Settings", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("settings_dialog", "Font ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("settings_dialog", "Font Size ", 0, QApplication::UnicodeUTF8));
        editor_showLineNumbers->setText(QApplication::translate("settings_dialog", "Show line numbers", 0, QApplication::UnicodeUTF8));
        editor_highlightCurrentLine->setText(QApplication::translate("settings_dialog", "Highlight current line", 0, QApplication::UnicodeUTF8));
        editor_codeCompletion->setText(QApplication::translate("settings_dialog", "Code completion", 0, QApplication::UnicodeUTF8));
        editor_longWindowTitle->setText(QApplication::translate("settings_dialog", "Show complete path in window title", 0, QApplication::UnicodeUTF8));
        autosaveFiles->setText(QApplication::translate("settings_dialog", "Automatically save backups of all open files", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("settings_dialog", "Autosave files every ", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("settings_dialog", "seconds", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("settings_dialog", "Editor", 0, QApplication::UnicodeUTF8));
        showFilenames->setText(QApplication::translate("settings_dialog", "Show filenames", 0, QApplication::UnicodeUTF8));
        showFileSize->setText(QApplication::translate("settings_dialog", "Show file size", 0, QApplication::UnicodeUTF8));
        showFileType->setText(QApplication::translate("settings_dialog", "Show file type", 0, QApplication::UnicodeUTF8));
        showLastModified->setText(QApplication::translate("settings_dialog", "Show date of last modification", 0, QApplication::UnicodeUTF8));
        useAlternatingRowColors->setText(QApplication::translate("settings_dialog", "Alternating row colors", 0, QApplication::UnicodeUTF8));
        file_fontNamelabel->setText(QApplication::translate("settings_dialog", "Font ", 0, QApplication::UnicodeUTF8));
        file_fontSizelabel->setText(QApplication::translate("settings_dialog", "Font size ", 0, QApplication::UnicodeUTF8));
        file_defaultFont->setText(QApplication::translate("settings_dialog", "Use default font", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("settings_dialog", "File Browser", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settings_dialog", "Terminal", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("settings_dialog", "Font ", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("settings_dialog", "Font Size ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settings_dialog", "Workspace", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("settings_dialog", "Font ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("settings_dialog", "Font Size ", 0, QApplication::UnicodeUTF8));
        workspace_defaultFont->setText(QApplication::translate("settings_dialog", "Use default font", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("settings_dialog", "Command history", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("settings_dialog", "Number of commands to remember", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("settings_dialog", "Font ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("settings_dialog", "Font size ", 0, QApplication::UnicodeUTF8));
        history_defaultFont->setText(QApplication::translate("settings_dialog", "Use default font", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("settings_dialog", "Other tools", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("settings_dialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Graphics</span></p><p>The graphics toolkit decides what program is used to display plots. For most of the systems, the recommended option is Gnuplot</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("settings_dialog", "Toolkit: ", 0, QApplication::UnicodeUTF8));
        toolkit_cb->clear();
        toolkit_cb->insertItems(0, QStringList()
         << QApplication::translate("settings_dialog", "Gnuplot (recommended)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settings_dialog", "Qt", 0, QApplication::UnicodeUTF8)
        );
        label_15->setText(QApplication::translate("settings_dialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Compatibility </span></p><p>Some operations in Octave are not MATLAB compatible. Most of these operations can be detected by Octave, showing a warning message. Some other MATLAB-incompatible operations (like broadcasting) are not detected as incompatible by Octave.</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("settings_dialog", "<html><head/><body><p>More info: <a href=\"http://mat.caminos.upm.es/octave/compatibilidad.html\"><span style=\" text-decoration: underline; color:#0000c0;\">mat.caminos.upm.es/octave/compatibilidad.html</span></a><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("settings_dialog", "Broadcasting operations: ", 0, QApplication::UnicodeUTF8));
        broadcastingOption->clear();
        broadcastingOption->insertItems(0, QStringList()
         << QApplication::translate("settings_dialog", "Do nothing (allow and ignore)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settings_dialog", "Show a warning message", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settings_dialog", "Raise an error (forbid operation)", 0, QApplication::UnicodeUTF8)
        );
        matlabCompatible->setText(QApplication::translate("settings_dialog", "Show a warning message if the operation is not compatible with MATLAB", 0, QApplication::UnicodeUTF8));
        supressWarnings->setText(QApplication::translate("settings_dialog", "Supress any other warning messages", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("settings_dialog", "Other options", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("settings_dialog", "Language change will be effective after you restart Octave UPM", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("settings_dialog", "Interface language: ", 0, QApplication::UnicodeUTF8));
        languageComboBox->clear();
        languageComboBox->insertItems(0, QStringList()
         << QApplication::translate("settings_dialog", "English", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settings_dialog", "Espa\303\261ol", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("settings_dialog", "Language", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("settings_dialog", "Ok", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("settings_dialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settings_dialog: public Ui_settings_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_2D_DIALOG_H
