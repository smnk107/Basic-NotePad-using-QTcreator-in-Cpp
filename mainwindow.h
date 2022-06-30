#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "resume.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionUndo_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_triggered();

    void on_actionUnBold_triggered();

    void on_actionSuperscript_triggered();

    void on_actionSubscript_triggered();

    void on_actionExit_triggered();

    void on_actionOpen_2_triggered();

    void on_actionAbout_me_triggered();

    void on_actionFonts_triggered();

private:
    Ui::MainWindow *ui;
    QString filePath;
    Resume *myResume;
};
#endif // MAINWINDOW_H
