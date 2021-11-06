#include "studentfailer.hpp"
#include "ui_studentfailer.h"

StudentFailer::StudentFailer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentFailer)
{
    ui->setupUi(this);
}

StudentFailer::~StudentFailer()
{
    delete ui;
}

