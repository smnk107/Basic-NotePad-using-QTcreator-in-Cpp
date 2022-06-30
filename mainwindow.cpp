#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include<QFont>
#include<QFontDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    filePath = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_2_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(fileName);
    filePath = fileName;

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"oops!","File Not open");
        return;
    }

    QTextStream content(&file);
    QString text = content.readAll();
    ui->textEdit->setText(text);

    file.close();
}


void MainWindow::on_actionSave_triggered()
{

    QFile file(filePath);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        //QMessageBox::warning(this,"oops!","File is not Saved ");
        MainWindow::on_actionSave_as_triggered();
        return;
    }

    QTextStream content(&file);
    QString text = ui->textEdit->toPlainText();

    content << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Open the file");

    QFile file(fileName);
    filePath = fileName;

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"oops!","File is not Saved ");
        return;
    }

    QTextStream content(&file);
    QString text = ui->textEdit->toPlainText();

    content << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionBold_triggered()
{
    QTextCursor selected = ui->textEdit->textCursor();
    QTextCharFormat style;

    if(!selected.charFormat().font().bold())
    {
        style.setFontWeight(QFont::Bold);
        selected.mergeCharFormat(style);

    }

}


void MainWindow::on_actionUnBold_triggered()
{
    QTextCursor selected = ui->textEdit->textCursor();
    QTextCharFormat style;


        style.setFontWeight(QFont::Normal);
        selected.mergeCharFormat(style);


}


void MainWindow::on_actionSuperscript_triggered()
{
    QTextCursor selected = ui->textEdit->textCursor();
    QTextCharFormat style;
    style.setVerticalAlignment(QTextCharFormat::AlignSuperScript);

    selected.mergeCharFormat(style);

}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCursor selected = ui->textEdit->textCursor();
    QTextCharFormat style;
    style.setVerticalAlignment(QTextCharFormat::AlignSubScript);

    selected.mergeCharFormat(style);
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}




void MainWindow::on_actionAbout_me_triggered()
{
    myResume = new Resume(this);
    myResume->show();
}


void MainWindow::on_actionFonts_triggered()
{
    bool isChoosen;
    QFont font = QFontDialog::getFont(&isChoosen,this);

    if(isChoosen)
    {
        ui->textEdit->setFont(font);
    }

}

