#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "textfinder.h"
#include "ui_textfinder.h"

TextFinder::TextFinder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TextFinder)


{
    ui->setupUi(this);
    getTextFile();
}



TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::on_pushButton_clicked()
{
    QString word = ui->lineEdit->text();
    ui->textEdit->find(word, QTextDocument::FindWholeWords );

}
void TextFinder :: getTextFile(){
    QFile myFile(":/myinfo.txt");
    myFile.open(QIODevice::ReadOnly);

    QTextStream textStream(&myFile);
    QString line = textStream.readAll();
    myFile.close();
    ui->textEdit->setPlainText(line);
    QTextCursor textCourser = ui->textEdit->textCursor();
    textCourser.movePosition(QTextCursor:: Start, QTextCursor:: MoveAnchor, 1);

}
