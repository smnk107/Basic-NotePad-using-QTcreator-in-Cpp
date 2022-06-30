#include "resume.h"
#include "ui_resume.h"

Resume::Resume(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resume)
{
    ui->setupUi(this);

}

Resume::~Resume()
{
    delete ui;
}
