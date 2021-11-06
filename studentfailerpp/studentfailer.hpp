#ifndef STUDENTFAILER_HPP
#define STUDENTFAILER_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentFailer; }
QT_END_NAMESPACE

class StudentFailer : public QMainWindow
{
    Q_OBJECT

public:
    StudentFailer(QWidget *parent = nullptr);
    ~StudentFailer();

private:
    Ui::StudentFailer *ui;
};
#endif // STUDENTFAILER_HPP
