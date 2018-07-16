/********************************************************************************
** Form generated from reading UI file 'huffman.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUFFMAN_H
#define UI_HUFFMAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HuffmanClass
{
public:
    QWidget *centralWidget;
    QTextEdit *text_input;
    QLabel *label;
    QTextBrowser *text_statistics;
    QPushButton *button_statistics;
    QPushButton *button_codec;
    QPushButton *button_transcode;
    QTextBrowser *text_codec;
    QTextBrowser *text_output;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HuffmanClass)
    {
        if (HuffmanClass->objectName().isEmpty())
            HuffmanClass->setObjectName(QStringLiteral("HuffmanClass"));
        HuffmanClass->resize(1041, 498);
        centralWidget = new QWidget(HuffmanClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        text_input = new QTextEdit(centralWidget);
        text_input->setObjectName(QStringLiteral("text_input"));
        text_input->setGeometry(QRect(50, 50, 941, 131));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 371, 16));
        text_statistics = new QTextBrowser(centralWidget);
        text_statistics->setObjectName(QStringLiteral("text_statistics"));
        text_statistics->setGeometry(QRect(50, 230, 101, 221));
        button_statistics = new QPushButton(centralWidget);
        button_statistics->setObjectName(QStringLiteral("button_statistics"));
        button_statistics->setGeometry(QRect(50, 190, 101, 28));
        button_codec = new QPushButton(centralWidget);
        button_codec->setObjectName(QStringLiteral("button_codec"));
        button_codec->setGeometry(QRect(180, 190, 101, 28));
        button_transcode = new QPushButton(centralWidget);
        button_transcode->setObjectName(QStringLiteral("button_transcode"));
        button_transcode->setGeometry(QRect(350, 190, 161, 28));
        text_codec = new QTextBrowser(centralWidget);
        text_codec->setObjectName(QStringLiteral("text_codec"));
        text_codec->setGeometry(QRect(180, 230, 141, 221));
        text_output = new QTextBrowser(centralWidget);
        text_output->setObjectName(QStringLiteral("text_output"));
        text_output->setGeometry(QRect(350, 230, 641, 221));
        HuffmanClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(HuffmanClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HuffmanClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HuffmanClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HuffmanClass->setStatusBar(statusBar);

        retranslateUi(HuffmanClass);

        QMetaObject::connectSlotsByName(HuffmanClass);
    } // setupUi

    void retranslateUi(QMainWindow *HuffmanClass)
    {
        HuffmanClass->setWindowTitle(QApplication::translate("HuffmanClass", "Huffman Codec", 0));
        text_input->setPlaceholderText(QApplication::translate("HuffmanClass", "Note: Only alphabets are valid.", 0));
        label->setText(QApplication::translate("HuffmanClass", "Please input the text to be encoded:", 0));
        text_statistics->setPlaceholderText(QApplication::translate("HuffmanClass", "a: 17...", 0));
        button_statistics->setText(QApplication::translate("HuffmanClass", "Statistics:", 0));
        button_codec->setText(QApplication::translate("HuffmanClass", "Codec:", 0));
        button_transcode->setText(QApplication::translate("HuffmanClass", "Transcode: Encode", 0));
        text_codec->setPlaceholderText(QApplication::translate("HuffmanClass", "a: 011...", 0));
        text_output->setPlaceholderText(QApplication::translate("HuffmanClass", "Encoded or decoded text will be displayed here.", 0));
    } // retranslateUi

};

namespace Ui {
    class HuffmanClass: public Ui_HuffmanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUFFMAN_H
